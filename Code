#include <Servo.h>

Servo horizontal; // Horizontal servo
int servoh = 90; // Initial horizontal angle
int servohLimitHigh = 180; // Maximum horizontal angle
int servohLimitLow = 0; // Minimum horizontal angle

Servo vertical; // Vertical servo
int servov = 90; // Initial vertical angle
int servovLimitHigh = 120; // Maximum vertical angle
int servovLimitLow = 15; // Minimum vertical angle

// LDR sensor connections
int ldrTR = A3; // LDR top right
int ldrTL = A2; // LDR top left
int ldrBR = A1; // LDR bottom right
int ldrBL = A0; // LDR bottom left

void setup() {
  Serial.begin(9600);
  horizontal.attach(9); // Attach horizontal servo to pin 9
  vertical.attach(10); // Attach vertical servo to pin 10
  horizontal.write(90); // Set initial position of horizontal servo
  vertical.write(45); // Set initial position of vertical servo
  delay(3000); // Wait for 3 seconds
}

void loop() {
  int tr = analogRead(ldrTR); // Read value from top right LDR
  int tl = analogRead(ldrTL); // Read value from top left LDR
  int br = analogRead(ldrBR); // Read value from bottom right LDR
  int bl = analogRead(ldrBL); // Read value from bottom left LDR

  int dtime = 0; // Delay time for debugging purposes
  int tol = 50; // Tolerance value

  int avt = (tl + tr) / 2; // Average value of top sensors
  int avd = (bl + br) / 2; // Average value of bottom sensors
  int avl = (tl + bl) / 2; // Average value of left sensors
  int avr = (tr + br) / 2; // Average value of right sensors

  int dvert = avt - avd; // Difference between top and bottom averages
  int dhoriz = avl - avr; // Difference between left and right averages

  // Print sensor values to the serial monitor
  Serial.print("TL: ");
  Serial.print(tl);
  Serial.print(", TR: ");
  Serial.print(tr);
  Serial.print(", BL: ");
  Serial.print(bl);
  Serial.print(", BR: ");
  Serial.println(br);

  // Check if vertical difference is within tolerance
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
    vertical.write(servov); // Move vertical servo
  }

  // Check if horizontal difference is within tolerance
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
    horizontal.write(servoh); // Move horizontal servo
  }

  delay(dtime); // Short delay for stability
}
