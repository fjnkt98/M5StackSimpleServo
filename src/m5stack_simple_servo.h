#ifndef M5STACK_SIMPLE_SERVO_LIBRARY
#define M5STACK_SIMPLE_SERVO_LIBRARY

#include <Arduino.h>

class M5StackSimpleServo {
  private:
    uint8_t ledc_channel_;
    uint8_t ledc_timer_bit_;
    double ledc_freq_;
    double pwm_min_width_;
    double pwm_max_width_;
    uint8_t output_pin_;

  public:
    M5StackSimpleServo(uint8_t ledc_channel, double pwm_min_width=0.5, double pwm_max_width=2.4, double ledc_freq=50.0, uint8_t ledc_timer_bit=16);
    void attach(uint8_t output_pin);
    void write(int angle);
    void detach();
};

#endif