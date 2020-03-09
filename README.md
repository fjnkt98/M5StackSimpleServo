# M5StackSimpleServo

A library for controlling servo motor in M5Stack.

This library has been tested on the M5Stack Gray.

## Quick Start

### Download Library

Download this library from [the repository](https://github.com/fjnkt98/M5StackSimpleServo) as ZIP, and place in `~/Documents/Arduino/libraries/`.

<img src="https://user-images.githubusercontent.com/50233866/76162594-8304e400-6182-11ea-848a-f3021da26a2c.png" width="500px">

### Connect Servo Motor to M5Stack

Connect 5V and GND, and connect the signal wire to GPIO 5.

<img src="https://user-images.githubusercontent.com/50233866/76162618-a7f95700-6182-11ea-88bb-f6b9eb7ac1a2.jpg" width="400px">

### Write Sample Sketch

Include this library, and open sample sketch.

<img src="https://user-images.githubusercontent.com/50233866/76162712-b3994d80-6183-11ea-9ca2-61c6d15de801.png" width="400px">


<img src="https://user-images.githubusercontent.com/50233866/76162737-d166b280-6183-11ea-9ab3-6796fcc58487.png" width="400px">

Write the sketch to M5Stack, then the servo motor should work!

## Class Reference

### Member Functions

#### M5StackSimpleServo::M5StackSimpleServo

##### Description

A constructor that initializes the ledc configuration.

##### args

- `ledc_channel`: Number of Channel to use.
- `pwm_min_width`: Minimum duty ratio of the control pluse of servo motor. default is 0.5
- `pwm_max_width`: Maximum duty ratio of the control pluse of servo motor. default is 2.4
- `ledc_freq`: PWM freqency. default is 50.0
- `ledc_timer_bit`: Number of full scale bits for duty indication. default is 16

#### M5StackSimpleServo::attach(uint8_t output_pin)

##### Description

A function to assign a pin to the PWM channel.

##### arg

- `output_pin`: Number of GPIO to use.

#### M5StackSimpleServo::write(int angle)

##### Description

A function to write signals to the servo motor.

##### arg

- `angle`: the value to write to the servo motor, from 0 to 180

#### M5StackSimpleServo::detach

A function to detach the pin from the PWM channel.