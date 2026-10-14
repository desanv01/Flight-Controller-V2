/*
 * iNAV target.c for FCV2
 * Based on MATEKH743 pattern
 *
 * Motor outputs (DSHOT via TIM1):
 *   M1 → PE14 (TIM1_CH4) — FR CCW — J6 pin 5
 *   M2 → PE13 (TIM1_CH3) — RL CCW — J6 pin 6
 *   M3 → PE11 (TIM1_CH2) — FL CW  — J6 pin 7
 *   M4 → PE9  (TIM1_CH1) — RR CW  — J6 pin 8
 *
 * Aux outputs (TIM8):
 *   M5 → PC6  (TIM8_CH1)
 *   M6 → PC7  (TIM8_CH2)
 *   M7 → PC8  (TIM8_CH3)
 *   M8 → PC9  (TIM8_CH4)
 *
 * Servo outputs (TIM4):
 *   S1 → PD12 (TIM4_CH1)
 *   S2 → PD13 (TIM4_CH2)
 *   S3 → PD14 (TIM4_CH3)
 *   S4 → PD15 (TIM4_CH4)
 *
 * NOTE: This iNAV target is retained as non-production legacy source. The
 *       production ArduPilot target implements ICM42688P/SPI6 plus BMI270/SPI3.
 */

 #include <stdint.h>
 #include "platform.h"
 #include "drivers/bus.h"
 #include "drivers/io.h"
 #include "drivers/pwm_mapping.h"
 #include "drivers/timer.h"
 #include "drivers/sensor.h"
 
 // BMI270 on SPI3 — CS=PD3, INT=PD2
 
 timerHardware_t timerHardware[] = {
     // ---- Primary quad motors on TIM1 (DSHOT capable) ----
     DEF_TIM(TIM1, CH4, PE14, TIM_USE_OUTPUT_AUTO, 0, 3),   // M1 FR / J6.5
     DEF_TIM(TIM1, CH3, PE13, TIM_USE_OUTPUT_AUTO, 0, 2),   // M2 RL / J6.6
     DEF_TIM(TIM1, CH2, PE11, TIM_USE_OUTPUT_AUTO, 0, 1),   // M3 FL / J6.7
     DEF_TIM(TIM1, CH1, PE9,  TIM_USE_OUTPUT_AUTO, 0, 0),   // M4 RR / J6.8
 
     // ---- Aux outputs on TIM8 ----
     DEF_TIM(TIM8, CH1, PC6,  TIM_USE_OUTPUT_AUTO, 0, 0),   // M5
     DEF_TIM(TIM8, CH2, PC7,  TIM_USE_OUTPUT_AUTO, 0, 1),   // M6
     DEF_TIM(TIM8, CH3, PC8,  TIM_USE_OUTPUT_AUTO, 0, 2),   // M7
     DEF_TIM(TIM8, CH4, PC9,  TIM_USE_OUTPUT_AUTO, 0, 3),   // M8
 
     // ---- Servo outputs on TIM4 ----
     DEF_TIM(TIM4, CH1, PD12, TIM_USE_OUTPUT_AUTO, 0, 6),   // S1
     DEF_TIM(TIM4, CH2, PD13, TIM_USE_OUTPUT_AUTO, 0, 7),   // S2
     DEF_TIM(TIM4, CH3, PD14, TIM_USE_OUTPUT_AUTO, 0, 0),   // S3
     DEF_TIM(TIM4, CH4, PD15, TIM_USE_OUTPUT_AUTO, 0, 0),   // S4
 };
 
 const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
