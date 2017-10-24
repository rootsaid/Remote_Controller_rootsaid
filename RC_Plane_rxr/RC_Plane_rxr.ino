//Receiver
//Visit www.rootsaid.com for full tutorial
//For Video Demo and tutorials Visit www.youtube.com/c/rootsaid

#include <SoftwareSerial.h>
#include<Servo.h>          

Servo esc; 

Servo ele;
Servo ruddr;

String input;
int throttle, th;
int aileron, ail;
int elevator, el;
int rudder, rud;

int boundLow;
int boundHigh;
const char delimiter = ',';

SoftwareSerial hc12(4, 5);

void setup()
{
ele.attach(9);
ruddr.attach(11);

esc.attach(10);
Serial.begin(9600);
hc12.begin(9600);
esc.write(170);
delay(2000);
esc.write(90);
delay(2000);
esc.write(140);
delay(2000);
esc.write(90);
delay(2000);
}

void loop()
{

if(Serial.available())
  {
  input = Serial.readStringUntil('\n');
  if (input.length() > 0)
      {
       // Serial.println(input);
       
        boundLow = input.indexOf(delimiter);
        throttle = input.substring(0, boundLow).toInt();
    
        boundHigh = input.indexOf(delimiter, boundLow+1);
        aileron = input.substring(boundLow+1, boundHigh).toInt();
    
        boundLow = input.indexOf(delimiter, boundHigh+1);
        elevator = input.substring(boundHigh+1, boundLow).toInt();
    
        rudder = input.substring(boundLow+1).toInt();

       esc.write(throttle);
       ele.write(elevator);
       ruddr.write(rudder);
       delay(10);      }

  }

}

