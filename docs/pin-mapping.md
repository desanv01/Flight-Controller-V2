# MCU resource mapping

| Function | MCU resource |
|---|---|
| M1 / J6.5 | PE14 / TIM1_CH4 |
| M2 / J6.6 | PE13 / TIM1_CH3 |
| M3 / J6.7 | PE11 / TIM1_CH2 |
| M4 / J6.8 | PE9 / TIM1_CH1 |
| ICM42688P SPI6 | PB3 SCK, PB4 MISO, PB5 MOSI; PD7 CS, PE4 DRDY |
| BMI270 SPI3 | PC10 SCK, PC11 MISO, PC12 MOSI; PD3 CS, PD2 DRDY |
| BMP388 I2C2 | PB10 SCL, PB11 SDA; 0x76 |
| CRSF USART3 | PD8 TX, PD9 RX |
| USART2 | PA2 TX, PA3 RX |
| UART4 | PA0 TX, PA1 RX |
| UART5 | PB13 TX, PB12 RX |
| UART7 | PE8 TX, PE7 RX |
| UART8 | PE1 TX, PE0 RX |
| USART1 | PB14 TX, PB15 RX |
| External I2C4 | PB6 SCL, PB7 SDA |
| USB | PA11 DM, PA12 DP |
| SWD | PA13 SWDIO, PA14 SWCLK |

ArduPilot Quad-X ordering: 1 front-right CCW, 2 rear-left CCW, 3 front-left CW, 4 rear-right CW. Validate order/direction with propellers removed. These four outputs are the controlled harness; retained upstream pad/timer resources are not automatically qualified extra outputs. See FCV2 target/defaults for exact serial order, clock and DMA policy.

[Actual connector nets](connector-pinouts.md).
