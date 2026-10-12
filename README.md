# runnr

A 3D endless runner game written in C with raylib. Obstacles come from a recycled object pool, and the game is compiled to WebAssembly with Emscripten so it can be played in the browser.

### Development

#### Linux

##### Dependencies

Before you start development, install these on your Linux OS:

| Dependency                                                                                          | Version    | Used for                                  | How to install                                                               |
| --------------------------------------------------------------------------------------------------- | ---------- | ----------------------------------------- | ---------------------------------------------------------------------------- |
| [premake5](https://premake.github.io/)                                                              | 5.0-beta3+ | Generating the Makefiles from `build.lua` | Install `premake` with your package manager, or download it from the website |
| [GNU Make](https://www.gnu.org/software/make/)                                                      | any        | Running the generated Makefiles           | Install `make` with your package manager                                     |
| [GCC](https://gcc.gnu.org/)                                                                         | 14+        | Compiling the C sources (`-std=c23`)      | Install `gcc` with your package manager                                      |
| [Bash](https://www.gnu.org/software/bash/) and [coreutils](https://www.gnu.org/software/coreutils/) | any        | Running the scripts in `scripts/linux`    | Already installed on most Linux distributions                                |

All of these binaries should be in your `PATH`.

##### Building

```sh
scripts/linux/dev.sh      # build debug and run
scripts/linux/debug.sh    # build debug
scripts/linux/release.sh  # build release
scripts/linux/clean.sh    # remove generated build files
```

Binaries are written to `build/linux-x86_64/bin/<config>/runnr`.
