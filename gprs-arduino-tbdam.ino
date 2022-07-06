
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
String recipientNumber[] = { "+919611839500", "+919663325288", "+919886022284", "+919611126362","+917411100645"};
const int levelstatus = 2; // INput level is monitored on pin 2
const int siren =4; // Output siren is connected to pin 4

int i;
String msg;
String replyfrommodem;
String sendto;
int count; 


#include "modemresponse.h"
#include "sendmsg.h"


void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);  // Setting the baud rate of Serial Monitor (Arduino)
mySerial.begin(9600);
pinMode(levelstatus, INPUT);
pinMode(siren, OUTPUT); 
}

void loop() 
{
  // put your main code here, to run repeatedly:
int levelread= digitalRead(levelstatus);
Serial.println(levelread);
count=0;
if (levelread== HIGH)
{
digitalWrite(siren, HIGH);
SendMessage();
delay(3000);
digitalWrite(siren, LOW);
count=count+1;
while((levelread == HIGH)&&(count!=0))
{
  levelread= digitalRead(levelstatus);
}

}

}
