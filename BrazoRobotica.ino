#include <SoftwareSerial.h>
#include <String.h>
#include <VarSpeedServo.h> 

SoftwareSerial mySerial(11,10);

char Arreglo[50];
int tope=0;
int parte1, parte2, parte3, parte4, parte5, parte6, parte7;
int parte8, parte9, parte10, parte11, parte12, parte13, parte14, parte15;
int AnguloServo1, AnguloServo2, AnguloServo3, AnguloServo4, AnguloServo5;

VarSpeedServo myservo1; 
VarSpeedServo myservo2;
VarSpeedServo myservo3;
VarSpeedServo myservo4;
VarSpeedServo myservo5;
 
const int servoPin1 = 2; // the digital pin used for the first servo
const int servoPin2 = 3; // the digital pin used for the second servo
const int servoPin3 = 4;
const int servoPin4 = 5;
const int servoPin5 = 6;

void setup() {
  
 Serial.begin(4800); //57600
  while (!Serial) {
  }
  mySerial.begin(9600);//9600
  }

void loop() {
 if (mySerial.available()>0) {
  //Serial.write(mySerial.read());
 char lectura=mySerial.read();
 
 if(lectura=='*'){
   tope=0;
 }else if(lectura=='#')
 {
        parte1= ((Arreglo[0]-48));
        parte2= ((Arreglo[1]-48));
        parte3= ((Arreglo[2]-48));
        parte4= ((Arreglo[3]-48));
        parte5= ((Arreglo[4]-48));
        parte6= ((Arreglo[5]-48));
        parte7= ((Arreglo[6]-48));
        parte8= ((Arreglo[7]-48));
        parte9= ((Arreglo[8]-48));
        parte10= ((Arreglo[9]-48));
        parte11= ((Arreglo[10]-48));
        parte12= ((Arreglo[11]-48));
        parte13= ((Arreglo[12]-48));
        parte14= ((Arreglo[13]-48));
        parte15= ((Arreglo[14]-48));

         AnguloServo1= ((parte1*100)+(parte2*10)+(parte3));
         AnguloServo2= ((parte4*100)+(parte5*10)+(parte6));
         AnguloServo3= ((parte7*100)+(parte8*10)+(parte9));
         AnguloServo4= ((parte10*100)+(parte11*10)+(parte12));
         AnguloServo5= ((parte13*100)+(parte14*10)+(parte15));

        Serial.print(parte1);
        Serial.print(parte2);
        Serial.print(parte3);
        Serial.print(parte4);
        Serial.print(parte5);
        Serial.print(parte6);
        Serial.print(parte7);
        Serial.print(parte8);
        Serial.print(parte9);
        Serial.print(parte10);
        Serial.print(parte11);
        Serial.print(parte12);
        Serial.print(parte13);
        Serial.print(parte14);
        Serial.println(parte15);

        myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
        myservo1.write(AnguloServo1,20,true); // set the intial position of the servo, as fast as possible, run in background
        myservo2.attach(servoPin2);  // attaches the servo on pin 9 to the servo object
        myservo2.write(AnguloServo2,20,true);  // set the intial position of the servo, as fast as possible, wait until done
        myservo3.attach(servoPin3);  // attaches the servo on pin 9 to the servo object
        myservo3.write(AnguloServo3,20,true);  // set the intial position of the serv
        myservo4.attach(servoPin4);  // attaches the servo on pin 9 to the servo object
        myservo4.write(AnguloServo4,20,true); 
        myservo5.attach(servoPin5);  // attaches the servo on pin 9 to the servo object
        myservo5.write(AnguloServo5,20,true); 
 }else{
 Arreglo[tope++]=lectura;  
 }
 }

      
}
