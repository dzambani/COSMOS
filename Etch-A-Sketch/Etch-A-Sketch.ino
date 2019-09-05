#include <Servo.h>

Servo servo1; //declare servo objects
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

//analog pins on arduino to read from potentiometers
const int potpinupdown = A0; //moves pen up and down
const int potpinlr = A1; //moves pen left and right

int val1 = 0;
int val2 = 0;


int potvalueupdown; 
int potvaluelr;

void setup() {

  servo1.attach(11); //set servoes to pins on arduino
  servo2.attach(10);
  servo3.attach(8);
  servo4.attach(7);
  servo5.attach(4);
  servo6.attach(2);
  Serial.begin(9600);

  servo1.write(0); //initialize servo positions
  servo2.write(0);
  servo3.write(180);
  servo4.write(180);
  servo5.write(0);
  servo6.write(180);
}

void loop() {
  val1 = analogRead(potpinupdown); //read from potentiometers
  val2 = analogRead(potpinlr);

 
  potvalueupdown = map(val1,0,1023,0,180); //maps potentiometer values to servoes
  potvaluelr = map(val2,0,1023,0,180);

  servo1.write(potvalueupdown); //move servoes correspondingly
  servo2.write(potvalueupdown);
  servo3.write(180-potvalueupdown);
  servo4.write(180-potvalueupdown);
  servo5.write(potvaluelr);
  servo6.write(180-potvaluelr);
   
  /*Serial.print("Servo angle 1 and 2: ");
  Serial.println(potvalueupdown);
  Serial.print("Servo angle 3 and 4: ");
  Serial.println(180-potvalueupdown);*/
  
  /*Serial.print("Servo angle 5 and 6: ");
  Serial.println(potvaluelr);*/

  delay(100);
}
