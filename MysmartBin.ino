#include <HCSR04.h>
#include <Servo.h>


UltraSonicDistanceSensor radar(13,9);  //pin Trig, Echo
Servo myservo;    


void setup() {

myservo.attach(3);   //pin Servo
Serial.begin(9600);
myservo.write(110);  //Debug per il servo, posizione nel mio caso 110°  \\ Debug for Servo, when you plug the current it closes the bin
}

void loop() {

  int measure = radar.measureDistanceCm();
  Serial.println(measure);  //measure for debug  \\ misura per il debug, per vedere quanto lontano si aprirà
   
 if(measure < 20){
  
    myservo.write(0);
    delay(6000);    //questo delay permette di far rimanere aperto il cestino per il tempo che volete \\ in this delay the bin will stay open
    myservo.write(110); 
   delay(1000);  // Delay di 1 secondo per permettere una corretta chiusura.
   }  
   }
  

 
