#include <Servo.h>

Servo horizontal; 
int servoh = 90;
int servohLimitHigh = 180;
int servohLimitLow = 0; 

Servo vertical;
int servov = 90; 
int servovLimitHigh = 120; 
int servovLimitLow = 15; 


int ldrTR = A3; 
int ldrTL = A2; 
int ldrBR = A1; 
int ldrBL = A0; 

void setup() {
  Serial.begin(9600);
  horizontal.attach(9); 
  vertical.attach(10); 
  horizontal.write(90); 
  vertical.write(45); 
  delay(3000); 
}

void loop() {
  int tr = analogRead(ldrTR); 
  int tl = analogRead(ldrTL); 
  int br = analogRead(ldrBR); 
  int bl = analogRead(ldrBL);

  int dtime = 0; 
  int tol = 50; 

  int avt = (tl + tr) / 2; 
  int avd = (bl + br) / 2; 
  int avl = (tl + bl) / 2;
  int avr = (tr + br) / 2;

  int dvert = avt - avd; 
  int dhoriz = avl - avr; 

 
  Serial.print("TL: ");
  Serial.print(tl);
  Serial.print(", TR: ");
  Serial.print(tr);
  Serial.print(", BL: ");
  Serial.print(bl);
  Serial.print(", BR: ");
  Serial.println(br);

  if (-1 * tol > dvert || dvert > tol) {
    if (avt > avd) {
      servov = ++servov;
      if (servov > servovLimitHigh) {
        servov = servovLimitHigh;
      }
    } else if (avt < avd) {
      servov = --servov;
      if (servov < servovLimitLow) {
        servov = servovLimitLow;
      }
    }
    vertical.write(servov); 
  }

  
  if (-1 * tol > dhoriz || dhoriz > tol) {
    if (avl > avr) {
      servoh = --servoh;
      if (servoh < servohLimitLow) {
        servoh = servohLimitLow;
      }
    } else if (avl < avr) {
      servoh = ++servoh;
      if (servoh > servohLimitHigh) {
        servoh = servohLimitHigh;
      }
    }
    horizontal.write(servoh); 
  }

  delay(dtime); 
}
