/*
 * File:           main.cpp
 * Autor:          Ahmad Ali 
 * Datum:          2025-12-15
 * Version:        2.3V
 * Lizenz:         MIT
 * 
 * Beschreibung: If the water level is too low the LED will BLink RED, the buzzer will buzz,
 *  the LCD will show a message and the reill process will start (servo opens a valve). 
 * If there is enough water then the LED will blink GREEN and The LCD will show the waterlevel.
 */
#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define sensorPower 7  
#define sensor A1
#define piezo 11  
#define LCD_Adresse 0x27

Servo servo;
int servo_angle; // servo    

/* Prototype functions */
int readSensor();
void setColor(int, int, int);

int redPin = 7;
int greenPin = 6;
int bluePin = 5;

LiquidCrystal_I2C lcd(LCD_Adresse, 16, 2);  

void setup() 
{
  lcd.init();
  lcd.clear();
  lcd.backlight();

  pinMode(sensor, OUTPUT); 		
  pinMode(piezo, OUTPUT); 

  servo.attach(8);
  servo.write(servo_angle);

  digitalWrite(sensorPower, LOW);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() 
{
  int waterlevel = readSensor();

  if (waterlevel <= 100)
  {
    lcd.setCursor(2, 0);
    lcd.print("waterlevel low starting refill");
    lcd.scrollDisplayLeft();

    tone(11, 500);
    delay(1);
    noTone(11);

    setColor(255, 0, 0);
    delay(100);

    servo_angle = 90;

  }
  else
  {
    setColor(0, 255, 0);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("waterlevel: ");
    lcd.print(waterlevel);
    lcd.scrollDisplayLeft();
    delay(100);

    servo_angle = 0;
  }

  servo.write(servo_angle);
}

void setColor(int redValue, int greenValue, int blueValue)
{
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

int readSensor()
{
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);                        // wait 10 milliseconds

  int val = analogRead(A1);         // Read the analog value form sensor

  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;
}
