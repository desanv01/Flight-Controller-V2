# FC Rev A - ENGINEERING VALIDATION EVT1 change manifest

Status: **fabrication package completed after local prefab checks; not flight
released.** The fabricated EVT1 article must pass the physical validation
worksheet.

| Area | EVT1 implementation |
|---|---|
| USB power | D3 and all USB-VBUS-to-+5V copper removed. USB-C remains data/debug only. |
| Onboard buck | U4/AP63205, L2, C14 and the exclusive output path removed. External POWER1 is the sole FC +5V source. |
| POWER1 | Molex Nano-Fit 105311-1202, pin 1 +5V and pin 2 GND; 105307-1202 housing, 105300-2200 gold contacts and 105325-1002 TPA. |
| Load basis | 3.0 A continuous, 4.0 A for 100 ms; local copper/vias sized on a 5 A basis. |
| Connector tab | Integral filleted 11.0 x 10.0 mm tab occupied by the real connector model and retention features. |
| OpenESC J6 | 1 NC, 2 GND, 3 NC, 4 NC, 5 M1, 6 M2, 7 M3, 8 M4; no battery, current or 5 V conductor. |
| Analog FPV/OSD | Hardware retained unchanged by instruction; disabled at runtime by default. |
| Clock | ASE active 8 MHz CMOS oscillator; HSE bypass enabled in both ArduPilot hwdefs. |
| Sensors | ICM42688P/SPI6 primary plus BMI270/SPI3 fallback; BMP388/I2C2 at 0x76. |
| Battery monitor | PC3 current input removed from hwdef; BATT_MONITOR=0 pending a qualified source. |
| Motors | Output 1 FR CCW; output 2 RL CCW; output 3 FL CW; output 4 RR CW. |
| Firmware | ArduPilot Copter-4.7.1, exact source SHA in manifest; old binaries excluded. |
| Board ID | AP_HW_FCV2, local-development numeric 1241; upstream reservation pending. |
| USB impedance | JLC06161H-3313 result: 0.1537 mm width / 0.2032 mm edge gap for 90 ohm differential. |

Completed checks: ERC 0 errors, DRC 0 violations/unconnected items, and scripted
connectivity/implementation assertions 42/42. The 40 ERC warnings and
project-configured DRC ignored checks are individually categorized in the
prefab verification report.
