# runnr

<!--toc:start-->

- [runnr](#runnr)
    - [Getting started](#getting-started)
        - [Cloning](#cloning)
        - [Linux](#linux)
            - [Dependencies](#dependencies)
            - [Building](#building)
    - [Project layout](#project-layout)
    - [License](#license)

<!--toc:end-->

A 3D endless runner game written in C/C++ with raylib.

Obstacles come from a recycled object pool, and the game is compiled to WebAssembly with Emscripten so it can be played in the browser.

## Getting started

### Cloning

All third-party libraries are included as git submodules in `vendor/upstream`. Clone the repository with its full history, then fetch only the pinned commit of each submodule:

```sh
git clone https://github.com/mt-shihab26/runnr.git
cd runnr
git submodule update --init --recursive --depth 1 --single-branch
```

Keep `--single-branch`. Without it git fetches the tip of every branch of every submodule, which makes raylib about 260 MB instead of about 54 MB. `git clone --recursive` has no flag for this, which is why the submodules are fetched as a separate step.

The pinned version and commit of each vendored library are listed in `vendor/versions`.

### Linux

#### Dependencies

On Arch Linux, install the tools to build the project: premake generates the Makefiles from `build.lua`, make and clang (clang++) compile the C++23 game sources and the C99 raylib sources, and bash runs the scripts in `scripts/linux`. gcc is needed as well, because clang uses its C++ standard library (libstdc++).

```sh
sudo pacman -S --needed git premake make clang gcc bash
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
include/    game headers
assets/     models, textures, sounds and fonts loaded by the game
vendor/     third-party libraries as git submodules, versions in vendor/versions
scripts/    build scripts, one folder per platform
docs/       project notes, like the candidate asset packs in docs/assets.md
build.lua   premake build definition
```

## License

runnr is released under the [MIT License](LICENSE).
