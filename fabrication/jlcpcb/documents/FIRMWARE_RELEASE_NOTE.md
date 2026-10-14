# FCV2 ArduPilot EVT1 firmware

Production target: ArduPilot Copter-4.7.1 at source commit
`dbe792162d06cab66c3475fd5556bf7a120f119e`.

The board directory is `FCV2`. Both hwdef files use
`AP_HW_FCV2`; numeric 1241 is a checked, temporary local-development
mapping only. Upstream reservation remains pending.

Implemented firmware hardware:

- active 8 MHz CMOS oscillator with `STM32_HSE_BYPASS`;
- ICM42688P on SPI6 using Invensensev3 plus BMI270 on SPI3;
- BMP388 on I2C2 at 0x76;
- CRSF receiver on USART3 / SERIAL2;
- TIM1 outputs 1-4 in J6 order PE14, PE13, PE11, PE9 with BIDIR capability;
- `BATT_MONITOR=0`, no PC3 current sensor, and analog OSD disabled by default.

Only binaries built from the pinned source and included in EVT1 are release
artifacts. Older APJ/BIN/HEX files elsewhere in the repository are excluded.
Install the bootloader through SWD, then load the APJ through the externally
powered data-only USB connection. All motor tests require propellers removed.

