#!/usr/bin/env bash
set -euo pipefail
publication_root="$(cd "$(dirname "$0")/../.." && pwd)"
git clone --recurse-submodules https://github.com/ArduPilot/ardupilot.git ardupilot-fcv2
cd ardupilot-fcv2
git checkout dbe792162d06cab66c3475fd5556bf7a120f119e
git submodule update --init --recursive
cp -R "$publication_root/firmware/targets/FCV2" libraries/AP_HAL_ChibiOS/hwdef/FCV2
printf '\nAP_HW_FCV2 1241\n' >> Tools/AP_Bootloader/board_types.txt
python3 ./waf configure --board FCV2 --bootloader
python3 ./waf bootloader
cp build/FCV2/bin/AP_Bootloader.bin Tools/bootloaders/FCV2_bl.bin
python3 ./waf configure --board FCV2
python3 ./waf copter -j4
