#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
   
Servo servo;
int angle = 10;

void setup() {
    Serial.begin(115200);
    servo.attach(8);
    servo.write(angle);
}

void loop() {
   static int water_level;
}


