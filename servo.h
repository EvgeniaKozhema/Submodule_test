typedef struct 
{
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    float min_dutyCycle;
    float max_dutyCycle;
} Servomotor;

void servo_init(Servomotor *servo, 
                TIM_HandleTypeDef *htim, 
                uint32_t channel, 
                float min_dutyCycle, 
                float max_dutyCycle);

void setPWMToServo(Servomotor *servo, float persent);