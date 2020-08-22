#include <Servo.h>//servo library
Servo servoMain; //object for server motor
int trigpin = 9; //sending signal pin
int echopin = 8;//rec signal pin
int distance;
float duration;


void setup()
{
servoMain.attach(7); //set a pin
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
}

void loop()
{
digitalWrite(trigpin, LOW);// clear a pin
    delay(2);

 digitalWrite(trigpin, HIGH);//send a signal fro 10 microseconds and the clear;
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
    
duration = pulseIn(echopin, HIGH);//get a out from a echo pin;
                                    
distance= duration*0.034/2;
                          //vel=dist/time;
                          //dis=time*vel;
                         //vel=0.034cm/micro sec;

 if(distance<30)
  { 
    servoMain.write(180); // delay(3000); 
  } 
 else
   { 
     servoMain.write(0); 
     delay(50); 
   } 
}
