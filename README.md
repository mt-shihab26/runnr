# runnr

A 3D endless runner game written in C with raylib. Obstacles come from a recycled object pool, and the game is compiled to WebAssembly with Emscripten so it can be played in the browser.

## Development

### Linux

#### Dependencies

Before you start development, install these on your Linux OS:

| Dependency                                           | Version    | Used for                                        | How to install                                                               |
| ---------------------------------------------------- | ---------- | ----------------------------------------------- | ---------------------------------------------------------------------------- |
| [Git](https://git-scm.com/)                          | any        | Cloning the repository and its submodules       | Install `git` with your package manager                                      |
| [premake5](https://premake.github.io/)               | 5.0-beta3+ | Generating the Makefiles from `build.lua`       | Install `premake` with your package manager, or download it from the website |
| [GNU Make](https://www.gnu.org/software/make/)       | any        | Running the generated Makefiles                 | Install `make` with your package manager                                     |
| [GCC](https://gcc.gnu.org/)                          | 14+        | Compiling the C sources (`-std=c23`)            | Install `gcc` with your package manager                                      |
| [Bash](https://www.gnu.org/software/bash/)           | any        | Running the scripts in `script/linux`           | Already installed on most Linux distributions                                |
| [coreutils](https://www.gnu.org/software/coreutils/) | any        | Providing `nproc` and `dirname` for the scripts | Already installed on most Linux distributions                                |

All of these binaries should be in your `PATH`.

raylib is built from source, so you also need the X11 and OpenGL development headers. On Arch Linux:

```sh
sudo pacman -S --needed libx11 libxrandr libxinerama libxcursor libxi mesa
```

#### Cloning

All third-party libraries are included as git submodules in `vendor/`. Clone the repository with its submodules:

```sh
git clone --recursive https://github.com/mt-shihab26/runnr.git
```

If you already cloned it without `--recursive`, fetch the submodules:

```sh
git submodule update --init --recursive
```

The pinned version and commit of each vendored library are listed in `vendor/versions`.

#### Building

```sh
script/linux/dev.sh       # build debug and run
script/linux/debug.sh     # build debug
script/linux/release.sh   # build release
script/linux/clean.sh     # remove generated build files
```

Binaries are written to `build/linux-x86_64/bin/<config>/runnr`.
