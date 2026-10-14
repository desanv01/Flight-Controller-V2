# FCV2 — ArduPilot firmware

Pinned ArduPilot Copter 4.7.1 source: `dbe792162d06cab66c3475fd5556bf7a120f119e`. Public target: **FCV2**. Build status: **SUCCESS**. [Build manifest](build/manifest.json).

Bootloader, BIN and APJ were built in a fresh container from the pinned local worktree. The bootloader was copied to the expected upstream bootloader path before the Copter configuration step. Binary identity was checked, including the decompressed APJ payload. Successful build logs and hashes are included.

## Source and configuration

- [Target](targets/FCV2/hwdef.dat)
- [Bootloader target](targets/FCV2/hwdef-bl.dat)
- [Initial defaults](targets/FCV2/defaults.parm)
- [Post-qualification bidirectional defaults](targets/FCV2/defaults-postqual-bidir.parm)
- [Reproduction script](build/build.sh)

Use a Linux/WSL or container environment with upstream ArduPilot prerequisites. The recorded container is `ardupilot/ardupilot-dev-chibios:v0.2.0` at the digest in the manifest. The script clones clean upstream source, checks out the exact revision and initializes its submodules. It adds a local `AP_HW_FCV2` mapping to numeric **1241**. This number is not upstream-reserved; do not distribute it as an accepted global board identity.

The repository input is a complete board-specific target; ArduPilot/ChibiOS/compiler dependencies come from pinned upstream/build environment and retain their licenses. The underlying hardware is the published V2 source only, not V1.

## Runtime boundaries

The active 8 MHz oscillator uses HSE bypass. ICM42688P/SPI6, BMI270/SPI3 and BMP388/I2C2 remain configured. Motor numbering is PE14/PE13/PE11/PE9, four outputs. Battery monitoring and bidirectional telemetry remain disabled until qualified; review defaults rather than copying a configuration from another board.

## Props-off flashing and verification

Confirm exact V2 hardware, external regulated POWER1 and USB/SWD wiring first. USB alone cannot power this design. Follow [bring-up](../docs/bring-up.md), enter the documented bootloader/DFU mode, and use STM32CubeProgrammer for the matching bootloader where needed. Load the matching APJ through Mission Planner after bootloader installation; preserve the controlled defaults. Record tool version, firmware hash, flash log, sensor detection, serial/failsafe checks and motor order with propellers removed.

Compilation is not powered-board qualification. No flight approval is granted by these binaries. Legacy Betaflight/iNAV/HAL targets in the historical source archive are not asserted compatible with final EVT1.
