# runnr

A 3D endless runner game written in C with raylib. Obstacles come from a recycled object pool, and the game is compiled to WebAssembly with Emscripten so it can be played in the browser.

## Getting started

### Cloning

All third-party libraries are included as git submodules in `vendor/`. Clone the repository with its submodules:

```sh
git clone --recursive https://github.com/mt-shihab26/runnr.git
```

If you already cloned it without `--recursive`, fetch the submodules:

```sh
git submodule update --init --recursive
```

The pinned version and commit of each vendored library are listed in `vendor/versions`.

### Linux

#### Dependencies

On Arch Linux, install the tools to build the project: premake generates the Makefiles from `build.lua`, make and gcc compile the C23 sources, and bash runs the scripts in `scripts/linux`.

```sh
sudo pacman -S --needed git premake make gcc bash
```

raylib is built from source along with the game, so it also needs the X11 and OpenGL development headers.

```sh
sudo pacman -S --needed libx11 libxrandr libxinerama libxcursor libxi mesa
```

#### Building

```sh
scripts/linux/dev.sh       # build debug and run
scripts/linux/debug.sh     # build debug
scripts/linux/release.sh   # build release
scripts/linux/clean.sh     # remove generated build files
```

Binaries are written to `build/linux-x86_64/bin/<config>/runnr`.

## Project layout

```
src/        game sources
assets/     models, textures, sounds and fonts loaded by the game
vendor/     third-party libraries as git submodules, versions in vendor/versions
scripts/    build scripts, one folder per platform
docs/       project notes, like the candidate asset packs in docs/assets.md
build.lua   premake build definition
```

## License

runnr is released under the [MIT License](LICENSE).
