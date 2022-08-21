#include <Servo.h>

// יצירת משתנים 

Servo servo;

int prPin1 = A0;
int prPin2 = A1;
int prPin3 = A2;
int prPin4 = A3;

int prValue1 = 0;
int prValue2 = 0;
int prValue3 = 0;
int prValue4 = 0;

float kp = 0.2;
float ki = 0;
float kd = 0.1;

int error;

int sum_error;
int last_error;
int de;

void setup() {
  // מתחיל תקשור עם מחשב ומתחבר למנוע
  
  Serial.begin(9600);
  servo.attach(9);
           
     
}

void loop() {
  
  // קורא מהחיישנים ומדפיס למחשב

  prValue1 = analogRead(prPin1);
  prValue2 = analogRead(prPin2);
  
  Serial.print(prValue1);
  Serial.print("\t");
  Serial.print(prValue2);
  Serial.print("\n");

  // PID חישובי

  error = (prValue2 - prValue1);

  sum_error += error;
  
  de = error - last_error;

  servo.write((error*kp + sum_error*ki + de*kd) + 45);

  last_error = error;

}
