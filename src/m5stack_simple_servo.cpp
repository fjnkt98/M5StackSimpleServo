#include "m5stack_simple_servo.h"

M5StackSimpleServo::M5StackSimpleServo(uint8_t ledc_channel, double pwm_min_width, double pwm_max_width, double ledc_freq, uint8_t ledc_timer_bit)
  :ledc_channel_(ledc_channel),
  ledc_timer_bit_(ledc_timer_bit),
  ledc_freq_(ledc_freq),
  pwm_min_width_(pwm_min_width),
  pwm_max_width_(pwm_max_width)
{
  ledcSetup(ledc_channel_, ledc_freq_, ledc_timer_bit_);
}

void M5StackSimpleServo::attach(uint8_t output_pin){
  output_pin_ = output_pin;
  ledcAttachPin(output_pin_, ledc_channel_);
}

void M5StackSimpleServo::write(int angle){
  int duty_min = (int)(65535 * pwm_min_width_ * ledc_freq_ / 1000);
  int duty_max = (int)(65535 * pwm_max_width_ * ledc_freq_ / 1000);

  uint32_t output = (uint32_t)((duty_max - duty_min) * angle / 180 + duty_min);

  if (angle < 0) {
    ledcWrite(ledc_channel_, 0);
  } else if (angle > 180) {
    ledcWrite(ledc_channel_, 0);
  } else {
    ledcWrite(ledc_channel_, output);
  }
}

void M5StackSimpleServo::detach(){
  ledcDetachPin(output_pin_);
}