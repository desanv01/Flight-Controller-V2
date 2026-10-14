/*
 * motor_mix.c
 *
 *  Created on: Apr 2026
 *      Author: Saleh
 *
 * @brief X-frame quadcopter motor mixer.
 *
 * Converts throttle + roll/pitch/yaw demands into individual
 * DSHOT throttle values for each motor.
 *
 * LEGACY NON-PRODUCTION STM32Cube reference. The ArduPilot FCV2
 * hwdef/defaults are authoritative for EVT1. Motor layout (top view):
 *
 *   M3 (FL, CW)  |  M1 (FR, CCW)
 *   --------------+--------------
 *   M2 (RL, CCW) |  M4 (RR, CW)
 *
 * TIM1 channel mapping:
 *   TIM1_CH1 (PE9)  → M4 (RR)
 *   TIM1_CH2 (PE11) → M3 (FL)
 *   TIM1_CH3 (PE13) → M2 (RL)
 *   TIM1_CH4 (PE14) → M1 (FR)
 */

#include "motor_mix.h"

/* DSHOT range for actual throttle (0 = disarm, 48-2047 = throttle) */
#define DSHOT_RANGE  ((float)(DSHOT_MAX_THROTTLE - DSHOT_MIN_THROTTLE))

/* Maximum authority given to roll/pitch/yaw relative to throttle.
 * 0.5 means PID terms can use up to ±50% of the DSHOT range.
 * Keep this conservative until PID is tuned.                       */
#define MIX_AUTHORITY  0.5f

static uint16_t _clamp_dshot(float val)
{
    if (val < DSHOT_MIN_THROTTLE) return DSHOT_MIN_THROTTLE;
    if (val > DSHOT_MAX_THROTTLE) return DSHOT_MAX_THROTTLE;
    return (uint16_t)val;
}

void MOTOR_Mix(float throttle, float roll, float pitch, float yaw)
{
    /* Convert 0-1 throttle to DSHOT range */
    float thr = DSHOT_MIN_THROTTLE + throttle * DSHOT_RANGE;

    /* Scale PID terms to DSHOT units */
    float r = roll  * MIX_AUTHORITY * DSHOT_RANGE;
    float p = pitch * MIX_AUTHORITY * DSHOT_RANGE;
    float y = yaw   * MIX_AUTHORITY * DSHOT_RANGE;

    /* ArduPilot Quad X output order — M1 FR, M2 RL, M3 FL, M4 RR
     *          Thr   Roll  Pitch  Yaw  */
    float m1 = thr  -  r  +  p  +  y;   /* FR CCW */
    float m2 = thr  +  r  -  p  +  y;   /* RL CCW */
    float m3 = thr  +  r  +  p  -  y;   /* FL CW  */
    float m4 = thr  -  r  -  p  -  y;   /* RR CW  */

    /* Driver arguments follow TIM1 CH1, CH2, CH3, CH4. */
    DSHOT_SendThrottle(_clamp_dshot(m4),
                       _clamp_dshot(m3),
                       _clamp_dshot(m2),
                       _clamp_dshot(m1));
}

void MOTOR_Disarm(void)
{
    DSHOT_SendThrottle(DSHOT_DISARM, DSHOT_DISARM, DSHOT_DISARM, DSHOT_DISARM);
}
