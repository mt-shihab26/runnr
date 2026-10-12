# runnr

A 3D endless runner game written in C with raylib. Obstacles come from a recycled object pool, and the game is compiled to WebAssembly with Emscripten so it can be played in the browser.

### Development

#### Linux

##### Dependencies

Before you start development, install these on your Linux OS:

| Dependency                                                                                          | Version    | Used for                                  |
| --------------------------------------------------------------------------------------------------- | ---------- | ----------------------------------------- |
| [premake5](https://premake.github.io/)                                                              | 5.0-beta3+ | Generating the Makefiles from `build.lua` |
| [GNU Make](https://www.gnu.org/software/make/)                                                      | any        | Running the generated Makefiles           |
| [GCC](https://gcc.gnu.org/)                                                                         | 14+        | Compiling the C sources (`-std=c23`)      |
| [Bash](https://www.gnu.org/software/bash/) and [coreutils](https://www.gnu.org/software/coreutils/) | any        | Running the scripts in `scripts/linux`    |

##### Building

```sh
scripts/linux/dev.sh      # build debug and run
scripts/linux/debug.sh    # build debug
scripts/linux/release.sh  # build release
scripts/linux/clean.sh    # remove generated build files
```

Binaries are written to `build/linux-x86_64/bin/<config>/runnr`.
