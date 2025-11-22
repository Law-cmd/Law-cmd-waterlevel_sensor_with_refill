#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>



#define sensorPower 7  //watersensor
Servo servo; int angle;//servo
/*funktionen*/
int readSensor();
void setColor(int, int, int) ;
/*funktionen*/

int redPin= 7;
int greenPin = 6;
int  bluePin = 5;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display


void setup() 
{
  lcd.init();
  lcd.clear();         
  lcd.backlight();   

  pinMode(A1, OUTPUT);//sensor

  pinMode(11, OUTPUT);//piezo

  servo.attach(8);
  servo.write(angle);

  digitalWrite(sensorPower, LOW);
  pinMode(redPin, OUTPUT); pinMode(greenPin, OUTPUT); pinMode(bluePin, OUTPUT);
}

void loop() 
{   

    int waterlevel = readSensor();
     
   
    if(waterlevel<=100)
    {  
     lcd.setCursor(2,0); 
     lcd.print("waterlevel low starting refill");
     lcd.scrollDisplayLeft();   // scroll everything to the left by one position
     
     tone(11, 500);delay(1);noTone(11); 
     setColor(255,0 ,0 );
     delay(100);
     angle=90 ;
      
    }
    else
    {  
     setColor(0,255,0);  
     lcd.clear();
     lcd.setCursor(2,0); 
     lcd.print("waterlevel: ");lcd.print(waterlevel);
     lcd.scrollDisplayLeft();   // scroll everything to the left by one position
     delay(100); 
     angle=0;
    
    }
    
    servo.write(angle);
     
}   



void setColor(int redValue, int greenValue,  int blueValue) 
{
 analogWrite(redPin, redValue);
 analogWrite(greenPin,  greenValue);
 analogWrite(bluePin, blueValue);
}
 int readSensor() 
 {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);                        // wait 10 milliseconds
  int val = analogRead(A1);      // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val; 
 }