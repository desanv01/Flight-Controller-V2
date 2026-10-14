# Architecture

The STM32H743 controller owns real-time stabilization, motor-waveform generation, arming and failsafe. Receiver input, sensor data and external navigation interfaces terminate at the controller. Companion perception/navigation is advisory and separately powered; its failure must not defeat stabilization or safe shutdown.

External battery/power distribution supplies the ESC; the FC/ESC boundary is motor signals and common ground. Controller supply is externally regulated. USB is data/debug and is not a controller power supply.

The retained reference architecture includes ICM42688P, BMI270, BMP388, flash and analog OSD circuitry. EVT1 removes USB/onboard-buck backfeed paths, adds exact Nano-Fit input, and constrains the ESC cable to four motor signals plus ground.

Read [source pinouts](connector-pinouts.md), [power/interface boundaries](power-and-interfaces.md) and the staged development records. Requirements/calculations are not a substitute for physical qualification.
