#!/bin/bash

source ~/emsdk/emsdk_env.sh
export platform=emscripten
export DEBUG=1
find | grep '\.o$' | xargs rm
# make clean
emmake make -f Makefile.libretro -j3
cp pcsx_rearmed_libretro.so ~/RetroArch/dist-scripts/pcsx_rearmed_libretro_emscripten.bc
