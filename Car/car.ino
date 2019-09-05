#include <CurieBLE.h>
#define BLE_SERVICE_UUID                      "19B10010-E8F2-537E-4F6C-D104768AFF12"
#define BLE_CHARACTERISTIC_PHONE2ARD01_UUID   "19B10010-E8F2-537E-4F6C-D104768AFF13"
#include <Servo.h>                        

int servoPin = 13;                        
Servo servo;    
bool connected;

const int Ain1Pin = 7;
const int Ain2Pin = 8;
const int PwmAPin = 9;
const int Bin1Pin = 4;
const int Bin2Pin = 5;
const int PwmBPin = 6;

void setup() {

  Serial.begin(9600);
  setupBLE("ARDUINO-OCTOGON");
  Serial.print("starting");
  connected = false;

  //move forward:  pin 1 = HIGH and pin 2 = LOW
  //move backward: pin 1 = LOW  and pin 2 = HIGH
  //stop or break: pin 1 = LOW  and pin 2 = LOW
  pinMode(Ain1Pin, OUTPUT);
  pinMode(Ain2Pin, OUTPUT);
  pinMode(PwmAPin, OUTPUT);
  pinMode(Bin1Pin, OUTPUT);
  pinMode(Bin2Pin, OUTPUT);
  pinMode(PwmBPin, OUTPUT);
  servo.attach(servoPin); 
}



void loop() {
  int receivedValue;
  BLECentral phone = initBLE();
  if (connectedBLE(phone)) {

    if (!connected) {
      Serial.println("Connected to the phone");
      connected = true;
    }

    if (writtenBLE()) {
      receivedValue = receivedBLE();
      Serial.print("Received value: ");
      Serial.print(receivedValue);

      if (receivedValue == 11) {
        //up arrow pressed
        // Move motor A forward at full speed
        digitalWrite(Ain1Pin, LOW);
        digitalWrite(Ain2Pin, HIGH);
        analogWrite(PwmAPin, 255);
        // Move motor B forward at full speed
        digitalWrite(Bin1Pin, LOW);
        digitalWrite(Bin2Pin, HIGH);
        analogWrite(PwmBPin, 255);
      }

      else if (receivedValue == 12) {
        //up arrow released
        // Stop motor B
        digitalWrite(Bin1Pin, LOW);
        digitalWrite(Bin2Pin, LOW);
        analogWrite(PwmBPin, 0);
        // Stop motor A
        digitalWrite(Ain1Pin, LOW);
        digitalWrite(Ain2Pin, LOW);
        analogWrite(PwmAPin, 0);
      }

      else if (receivedValue == 21) {
        //right arrow pressed
        // Move motor A forward at full speed
        digitalWrite(Ain1Pin, LOW);
        digitalWrite(Ain2Pin, HIGH);
        analogWrite(PwmAPin, 255);
        // No motor B
        digitalWrite(Bin1Pin, LOW);
        digitalWrite(Bin2Pin, LOW);
        analogWrite(PwmBPin, 255);
      }

      else if (receivedValue == 22) {
        //right arrow released
        // Stop motor B
        digitalWrite(Bin1Pin, LOW);
        digitalWrite(Bin2Pin, LOW);
        analogWrite(PwmBPin, 0);
        // Stop motor A
        digitalWrite(Ain1Pin, LOW);
        digitalWrite(Ain2Pin, LOW);
        analogWrite(PwmAPin, 0);
      }

      else if (receivedValue == 31) {
        //down arrow pressed
        // Move motor B backward at full speed
        digitalWrite(Bin1Pin, HIGH);
        digitalWrite(Bin2Pin, LOW);
        analogWrite(PwmBPin, 255);
        // Move motor A backward at half speed
        digitalWrite(Ain1Pin, HIGH);
        digitalWrite(Ain2Pin, LOW);
        analogWrite(PwmAPin, 255);
      }

      else if (receivedValue == 32) {
        //down arrow released
        // Stop motor B
        digitalWrite(Bin1Pin, LOW);
        digitalWrite(Bin2Pin, LOW);
        analogWrite(PwmBPin, 0);
        // Stop motor A
        digitalWrite(Ain1Pin, LOW);
        digitalWrite(Ain2Pin, LOW);
        analogWrite(PwmAPin, 0);
      }

      else if (receivedValue == 41) {
        //left arrow pressed
        // No motor A
        digitalWrite(Ain1Pin, LOW);
        digitalWrite(Ain2Pin, LOW);
        analogWrite(PwmAPin, 255);
        // Move motor B forward at full speed
        digitalWrite(Bin1Pin, LOW);
        digitalWrite(Bin2Pin, HIGH);
        analogWrite(PwmBPin, 255);
      }

      else if (receivedValue == 42) {
        //left arrow released
        // Stop motor B
        digitalWrite(Bin1Pin, LOW);
        digitalWrite(Bin2Pin, LOW);
        analogWrite(PwmBPin, 0);
        // Stop motor A
        digitalWrite(Ain1Pin, LOW);
        digitalWrite(Ain2Pin, LOW);
        analogWrite(PwmAPin, 0);
      }

      else if (receivedValue == 51) {
        //center button pressed
       servo.write(30); 
      }

      else if (receivedValue == 52) {
        //center button released
        servo.write(90); 
      }
    }
  }
  else {
    if (connected) {
      //not connected to phone
      connected = false;
    }
  }
}
