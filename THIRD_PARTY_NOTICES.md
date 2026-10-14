# Source and license notices

## KiCad libraries

Project-local libraries contain KiCad-derived symbols, footprints and models. KiCad library contributors retain authorship. The library license is [CC-BY-SA-4.0 with the KiCad libraries exception](https://www.kicad.org/libraries/license/). Original symbol/library identifiers are retained wherever possible. Manufacturer-derived geometry is documented in source parameters; manufacturer data/model notices remain applicable.

## Hardware sources

Flight Controller V2 derives from [upstream hardware](https://api.github.com/repositories/1095062995), archived source commit `0a60da1767061623549253d3cef8649f93ea052c`. Preserve its CERN-OHL-S-2.0 license and credits: Saleh Alhomeidy (project lead, PCB design, firmware porting), Akaki Gvelesiani (mechanical/technical lead, propulsion testing, sensor fusion), and Levani Kazaishvili (schematic capture, soldering, hardware verification).

## Firmware

ArduPilot is GPL-3.0; ChibiOS, STM32 libraries and other upstream dependencies retain their own licenses. Build from pinned upstream source with its complete notices. Included historical engineering scripts retain any source headers; otherwise no new blanket relicensing is asserted.

## Publication transformation

Neutral naming, private-context removal and metadata reconciliation are documented separately from engineering implementation. No upstream author is credited as the author of publication changes. Desan Vasu is the project contributor and publication owner; physical fabrication was performed externally.
