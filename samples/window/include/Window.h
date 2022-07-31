#ifndef _WINDOW_H
#define _WINDOW_H

bool TLN_CreateWindow (const char* overlay, int flags);
bool TLN_ProcessWindow (void);
bool TLN_GetInput (TLN_Input id);
void TLN_DrawFrame (int frame);
void TLN_DeleteWindow (void);
void TLN_SetSDLCallback(TLN_SDLCallback);
void TLN_Delay (uint32_t msecs);
uint32_t TLN_GetTicks (void);
int TLN_GetWindowWidth(void);
int TLN_GetWindowHeight(void);

#endif
