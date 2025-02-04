/******************************************************************************
*
* Tilengine sample
* 2015 Marc Palacios
* http://www.tilengine.org
*
* This example show a classic Mode 7 perspective projection plane like the 
* one seen in SNES games like Super Mario Kart. It uses a single transformed
* layer with a raster effect setting the scaling factor for each line
*
******************************************************************************/

/* Mode7.c was always my favorite demo. But why does it use fixed-point math???
 * The 20th century is long-gone. Computers half as powerful as the cheapest
 * Chromebook on the market were able to do real-time floating-point math in the
 * 2000s. Let's bring this demo into the 21st century to make it a bit less scary.
 */

#define _XOPEN_SOURCE 500

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Tilengine.h"
#include "Window.h"
#include <math.h>

#define WIDTH	400
#define HEIGHT	240

/* linear interploation */
#define lerp(x, x0,x1, fx0,fx1) \
	(fx0) + ((fx1) - (fx0))*((x) - (x0))/((x1) - (x0))

/*
/* layers */
enum
{
	LAYER_FOREGROUND,
	LAYER_BACKGROUND,
	MAX_LAYER
};

enum
{
	MAP_HORIZON,
	MAP_TRACK,
	MAX_MAP
};

int pos_foreground = {0};
int pos_background[6] = {0};
int inc_background[6] = {0};

float x, y, s, a;

static TLN_Tilemap road, horizon;
static int angle;

static void raster_callback (int line);

/* entry point */
int main (int argc, char* argv[])
{
	/* setup engine */
	TLN_Init (WIDTH,HEIGHT, MAX_LAYER, 0, 0);
	TLN_SetRasterCallback (raster_callback);
	TLN_SetBGColor (0,0,0);

	/* load resources*/
	TLN_SetLoadPath ("assets/smk");
	road = TLN_LoadTilemap ("track1.tmx", NULL);
	horizon = TLN_LoadTilemap ("track1_bg.tmx", NULL);

	/* startup display */
	TLN_CreateWindow (NULL, 0);

	x = -136.f;
	y = 336.f;
	s = 0;
	a = 0.2f;
	angle = 0;

	/* main loop */
	while (TLN_ProcessWindow ())
	{
		TLN_SetLayerTilemap (LAYER_FOREGROUND, horizon);
		TLN_SetLayerTilemap (LAYER_BACKGROUND, horizon);
		TLN_SetLayerPosition (LAYER_FOREGROUND, lerp(angle*2, 0,360, 0,256), 24);
		TLN_SetLayerPosition (LAYER_BACKGROUND, lerp(angle, 0,360, 0,256), 0);
		TLN_ResetLayerMode (LAYER_BACKGROUND);

		/* input */		
		if (TLN_GetInput (INPUT_LEFT))
			angle-=2;
		else if (TLN_GetInput (INPUT_RIGHT))
			angle+=2;
		if (TLN_GetInput (INPUT_UP))
		{
			s += a;
			if (s > 2)
				s = 2;
		}
		else if (s > 0)
			s -= fminf(s, a);
		if (TLN_GetInput (INPUT_DOWN))
		{
			s -= a;
			if (s < -2)
				s = -2;
		}
		else if (s < 0)
			s -= fmaxf(s, -a);

		if (s != 0)
		{
			angle = angle%360;
			if (angle < 0)
				angle += 360;

			x += sinf(angle*M_PI/180.f)*s;
			y -= cosf(angle*M_PI/180.f)*s;
		}

		/* render to window */
		TLN_DrawFrame (0);
	}

	/* deinit */
	TLN_DeleteTilemap (road);
	TLN_DeleteTilemap (horizon);
	TLN_DeleteWindow ();
	TLN_Deinit ();
	return 0;
}

/* raster callback (virtual HBLANK) */
static void raster_callback (int line)
{
	if (line == 24)
	{
		TLN_SetLayerTilemap (LAYER_BACKGROUND, road);
		TLN_SetLayerPosition (LAYER_BACKGROUND, (int)roundf(x), (int)roundf(y));
		TLN_DisableLayer (LAYER_FOREGROUND);
	}

	if (line >= 24)
	{
		float scale = lerp(line, 24, HEIGHT, 0.2f, 5.0f);
		TLN_SetLayerTransform (LAYER_BACKGROUND, (float)angle, WIDTH/2, HEIGHT, scale, scale);
	}
}
