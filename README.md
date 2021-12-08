# neotile

neotile is my fork of the [Tilengine](https://github.com/megamarc/Tilengine) library with the goal of making it more readily integrable into large-scale projects. Some plans for this fork:

  - keep in sync with fixes from upstream
    - we'll wait and see
  - switch the build system from bespoke makefiles and visual studio projects to CMake
    - done, i think
  - remove first class support for visual studio
    - done
  - keep it cross-platform
    - samples run well under wine but with some graphical glitches, I hope it's just a wine issue
    - i have no way of testing on macOS or other platforms
  - remove the window library (and thus neotile's dependency on SDL2) and make samples use SDL2 directly
    - lol i haven't done this yet
  - (possibly) reformat the samples
    - i was never the fan of the "space after function name" thing
    - i don't intend to reformat the core code to make merging upstream changes less painful

What this fork is NOT:

  - a drop-in replacement for Tilengine
    - though I intend to keep the API consistent with upstream, I also intend on removing functionality that I believe doesn't belong in the library and adds cruft.
    - you should still be able to migrate a Tilengine project to neotile with only minor modifications if you aren't using the window functions
  - a dynamic library
    - Tilengine officially only supports using it as a dynamic library on all of Windows, macOS, and Linux.
    - i find that, especially if you're dealing with Linux, something like Tilengine/neotile should be statically linked if you intend to keep the game closed-source as it's not in package managers, unlike its primary dependencies of zlib, libpng, and SDL2. therefore, neotile will only support static linking.
      - this might be helpful for windows or steam as well
  - something i can give support for
    - i'll try to help whenever possible, but i'm busy with college and stuff, so i might not be able to help promptly if at all
      - additionally, since i'm trying to not modify the core code too much, your problem is likely from upstream anyway
  - something i'm taking money for
    - donate it to charity or the original developer instead

## Building

these worked for me on linux, they might work for you as well

    git clone https://github.com/robbie01/neotile.git
    cd neotile
    mkdir build
    cd build
    cmake -G "Unix Makefiles" ..
    make -C samples

you might also want to check out ninja; the benefits are more negligible because this is a relatively small c project, but it's still pretty cool just because it's wicked fast

    git clone https://github.com/robbie01/neotile.git
    cd neotile
    mkdir build
    cd build
    cmake -G Ninja ..
    ninja samples/all

you can also build the library and actually use it. not going to give real instructions because i'm not supporting it outside of my own projects, but it shouldn't be too hard to integrate.

also, i've had success running those with fedora 35's `mingw64-cmake` instead of `cmake` proper. additionally, they seem to function under wine, albeit with the aforementioned graphical glitches.