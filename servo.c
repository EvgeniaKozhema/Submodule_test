#include "servo.h"

void servo_init(Servomotor *servo, 
                TIM_HandleTypeDef *htim, 
                uint32_t channel, 
                float min_dutyCycle, 
                float max_dutyCycle)
{
    servo->htim=htim;
    servo->channel=channel;
    sevo->min_dutyCycle=min_dutyCycle;
    servo->max_dutyCycle=max_dutyCycle;

    HAL_TIM_PWM_Start_IT(htim, channel);
}   

void setPWMToServo(Servomotor *servo, float persent)
{
    uint32_t pwm;
    pwm=500+persent*20;

    if(pwm<servo->min_dutyCycle) pwm = servo->min_dutyCycle;
    if(pwm>servo->max_dutyCycle) pwm = servo->max_dutyCycle;

    switch(servo->channel)
    {
        case TIM_CHANNEL_1:
        {
            servo->htim->Instance->CCR1=pwm;
            break;
        }

        case TIM_CHANNEL_2:
        {
            servo->htim->Instance->CCR2=pwm;
            break;
        }

        case TIM_CHANNEL_3:
        {
            servo->htim->Instance->CCR3=pwm;
            break;
        }

        case TIM_CHANNEL_4:
        {
            servo->htim->Instance->CCR4=pwm;
            break;
        }

        default:
            break;
    }

}