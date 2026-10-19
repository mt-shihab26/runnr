# runnr.

A 3D endless runner game written in C/C++ with raylib.

Obstacles come from a recycled object pool, and the game is compiled to WebAssembly with Emscripten so it can be played in the browser.

Play it at [runnr.developershihab.com](https://runnr.developershihab.com).

[![runnr.](scripts/web/preview.svg)](https://runnr.developershihab.com)

<!--toc:start-->

- [Platforms](#platforms)
- [Getting started](#getting-started)
    - [Linux](#linux)
        - [Dependencies](#dependencies)
        - [Cloning](#cloning)
        - [Building](#building)
    - [Web](#web)
        - [Dependencies](#dependencies-1)
        - [Building](#building-1)
- [License](#license)

<!--toc:end-->

## Platforms

| Platform | Architecture | Compiler  | Standard library    | Build system        | Define           |
| -------- | ------------ | --------- | ------------------- | ------------------- | ---------------- |
| Linux    | x86_64       | `clang++` | libstdc++ (GCC)     | GNU Make            | `PLATFORM_LINUX` |
| Web      | wasm32       | `emcc`    | libc++ (Emscripten) | GNU Make (`emmake`) | `PLATFORM_WEB`   |

On Linux, Clang uses GCC's libstdc++ headers and library by default. On the web, Emscripten's `emcc` is built on Clang and uses the libc++ headers and library that come with Emscripten, so both builds use Clang.

Only the game includes dependency headers, raylib is built from source as a static library and linked into it.

## Getting started

### Linux

#### Dependencies

- [`git`](https://git-scm.com) clones the repository and raylib
- [`premake`](https://premake.github.io) is Premake 5, its `premake5` command generates the Makefiles from `build.lua`
- [`make`](https://www.gnu.org/software/make) builds the generated Makefiles
- [`clang`](https://clang.llvm.org) is the compiler, and provides [clang-format](https://clang.llvm.org/docs/ClangFormat.html) for `scripts/linux/format.sh` and [clangd](https://clangd.llvm.org) for editors
- [`gcc`](https://gcc.gnu.org) provides [libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++), the C++ standard library Clang uses on Linux
- [X11](https://www.x.org) and [OpenGL](https://www.opengl.org) headers, as raylib is built from source along with the game

On Arch Linux:

- for the project:
    ```sh
    sudo pacman -S --needed git premake make clang gcc
    ```
- for raylib:
    ```sh
    sudo pacman -S --needed libx11 libxrandr libxinerama libxcursor libxi mesa
    ```

#### Cloning

```sh
git clone https://github.com/mt-shihab26/runnr.git
cd runnr
git submodule update --init --recursive --depth 1 --single-branch
```

Keep `--single-branch`, without it raylib takes about 260 MB instead of about 54 MB.

#### Building

```sh
scripts/linux/dev.sh        # build debug and run
scripts/linux/debug.sh      # build debug
scripts/linux/release.sh    # build release
scripts/linux/generate.sh   # generate the Makefiles only
scripts/linux/clean.sh      # remove generated build files
scripts/linux/format.sh     # format sources with clang-format
```

Binaries are written to `.build/linux-x86_64/bin/<config>/runnr`.

`scripts/linux/debug.json` is a debugger launch configuration that builds debug and starts the game, used by [my Neovim setup](https://github.com/mt-shihab26/dotfiles).

### Web

#### Dependencies

- [`git`](https://git-scm.com) clones the repository and raylib
- [`premake`](https://premake.github.io) is Premake 5, its `premake5` command generates the Makefiles from `build.lua`
- [`make`](https://www.gnu.org/software/make) builds the generated Makefiles
- [`emscripten`](https://emscripten.org) is the compiler, its `emcc` compiles to WebAssembly and `emmake` runs `make` with it
- [`librsvg`](https://gitlab.gnome.org/GNOME/librsvg) provides `rsvg-convert`, which renders the share preview `scripts/web/preview.svg` to PNG
- [`noto-fonts`](https://fonts.google.com/noto) provides Noto Sans, the font of the share preview
- [`bun`](https://bun.com) runs the http server in `scripts/web/serve.sh`

On Arch Linux:

- for the project:
    ```sh
    sudo pacman -S --needed git premake make emscripten
    ```
- for the share preview and serving:
    ```sh
    sudo pacman -S --needed librsvg noto-fonts bun
    ```

#### Building

```sh
scripts/web/serve.sh     # build release, serve it and open it in the browser
scripts/web/release.sh   # build release
```

The page is written to `.build/web-wasm32/bin/release/runnr.html`. It must be served over http, as it can't load its files from disk. `serve.sh` serves it at [localhost:8080/runnr.html](http://localhost:8080/runnr.html).

## License

runnr. is released under the [MIT License](LICENSE).
