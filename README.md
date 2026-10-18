# runnr.

A 3D endless runner game written in C/C++ with raylib.

Obstacles come from a recycled object pool, and the game is compiled to WebAssembly with Emscripten so it can be played in the browser.

Play it at [runnr.developershihab.com](https://runnr.developershihab.com/).

<!--toc:start-->

- [Getting started](#getting-started)
    - [Cloning](#cloning)
    - [Linux](#linux)
        - [Dependencies](#dependencies)
        - [Building](#building)
    - [Web](#web)
        - [Dependencies](#dependencies-1)
        - [Building](#building-1)
- [Project layout](#project-layout)
- [License](#license)

<!--toc:end-->

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

On Arch Linux, install the tools to build the project: premake generates the Makefiles from `build.lua`, make and gcc (g++) compile the C++23 game sources and the C99 raylib sources, and bash runs the scripts in `scripts/linux`.

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

Binaries are written to `.build/linux-x86_64/bin/<config>/runnr`.

### Web

#### Dependencies

On Arch Linux, install the tools to build for the web: premake generates the Makefiles from `build.lua`, make and Emscripten (`emcc`) compile the game and raylib to WebAssembly, bash runs the scripts in `scripts/web`, and librsvg (`rsvg-convert`) renders the share preview image `scripts/web/preview.svg` to PNG in release builds, using the Noto Sans font. gcc is not needed, Emscripten brings its own clang, and it pulls in nodejs and python which it runs on.

```sh
sudo pacman -S --needed git premake make bash emscripten librsvg noto-fonts
```

The package puts `emcc`, `emmake` and `emrun` in `/usr/lib/emscripten`, which is only on `PATH` after a new login. The scripts in `scripts/web` add it themselves when `emcc` isn't found, so they work right after installing.

raylib uses its `PLATFORM_WEB` backend with WebGL (OpenGL ES 2), and GLFW comes from Emscripten, so no X11 or OpenGL headers are needed. `scripts/web/dev.sh` also needs a browser with WebGL to open the game in.

#### Building

```sh
scripts/web/dev.sh       # build debug and open it in the browser
scripts/web/debug.sh     # build debug
scripts/web/release.sh   # build release
scripts/linux/clean.sh   # remove generated build files, shared with the Linux build
```

The page is written to `.build/web-wasm32/bin/<config>/runnr.html`, next to `runnr.js`, `runnr.wasm` and `runnr.data`, which holds the `assets/` folder. Serve the folder over http, `dev.sh` does it with `emrun`, as the page can't load its files when opened directly from disk.

The Linux and web scripts generate the same `Makefile` for their own target, so run either one at any time, they don't need a clean in between.

## Project layout

```
src/        game sources
include/    game headers
assets/     models, textures, sounds, fonts and shaders loaded by the game
vendor/     third-party libraries as git submodules, versions in vendor/versions
scripts/    build scripts, one folder per platform
build.lua   premake build definition
```

## License

runnr. is released under the [MIT License](LICENSE).
