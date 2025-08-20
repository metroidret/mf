# Metroid Fusion Decomp

This is a work in progress decompilation of Metroid Fusion.

1025/3607 functions decompiled (28.42%, 2582 left)

0x3290e/0x6f9d24 bytes of data not in blobs (2.83%, 0x6c7416 left)

Progress can be seen here: https://docs.google.com/spreadsheets/d/19pUPm1dp-7IY9iCeJJA412dwgD2f1M6A1QafzlRV8ic/edit#gid=0

**This decomp is not shiftable, don't use it as a base to work on anything**

This repository can be used to build multiple ROMs. The ROMs are named like this: `mf_{region}.gba` (or `mf_{region}_debug.gba`)

Region indicates which region the ROM targets:
- us: USA, North America `sha1: ca33f4348c2c05dd330d37b97e2c5a69531dfe87`
- eu: Europe **(Not yet supported)**
- jp: Japan **(Not yet supported)**
- cn: China **(Not yet supported)**
- eu_beta: Europe beta version **(Not yet supported)**

Debug simply indicates whether the ROM contains the debug features, it is optional.

**Debug is not supported yet**

The default built ROM is mf_us.gba

**Discords**: 
- https://discord.gg/2MGB9Xbr9y Metroidret
- https://discord.gg/WtekHKb MAGConst

## Dependencies

- [agbcc](https://github.com/pret/agbcc)
- `binutils-arm-none-eabi`
- A baserom for each ROM desired to be built (i.e.`mf_us_baserom.gba` if you wish to build `mf_us.gba`).
- `python3`
- `g++`

## Setup

- **WINDOWS ONLY**: Install and setup [WSL](https://docs.microsoft.com/en-us/windows/wsl/install)
- Run `sudo apt update` just in case
- Install `binutils-arm-none-eabi` by running this command: `sudo apt-get install binutils-arm-none-eabi`
- Install `git` by running this command: `sudo apt-get install git`
- Install `make` by running this command: `sudo apt-get install make`

- Clone [agbcc](https://github.com/pret/agbcc) by running this command: `git clone https://github.com/pret/agbcc`
- Enter the agbcc folder (run `cd agbcc`) and build it (run `./build.sh`)
- Add agbcc to your path (`export PATH="<agbcc_path>:$PATH"`, where `<agbcc_path>` is the full path to the agbcc directory)
- Locate yourself in the decompilation root, and then build preproc (run `cd tools/preproc && make`)

## Build

- Run `make clean` if necessary
  - Use `make clean DATA=1` to remove data as well
- Run the data extractor if necessary: `python3 tools/extractor.py`
  - Use the `-r` flag to specify a region other than `us` (ex: `-r jp`)
  - Use the `-d` flag to extract only debug data from the US beta ROM (required for building a ROM with debug features)
- Run `make` (using the `-j` option is recommended to speed up the process)
- To build another version of the ROM you can do either of the following:
  - Specify it directly (ex: `make us_debug` for the US ROM with debug features)
  - Specify the flags, REGION (takes the region name, defaults to `us`) and DEBUG (takes 0 or 1, defaults to 0)
- Optionally, you can combine the commands to make it easier: `python3 tools/extractor.py && make -j`

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md)
