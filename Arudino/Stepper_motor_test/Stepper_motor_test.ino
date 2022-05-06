/*     Simple Stepper Motor Control Exaple Code

    by Dejan Nedelkovski, www.HowToMechatronics.com

*/

// defines pins numbers
const int stepPin = 2;
const int dirPin = 3;

//const int stepPin = 4;
//const int dirPin = 5;

//const int stepPin = 6;
//const int dirPin = 7;

//const int stepPin = 8;
//const int dirPin = 9;
const int stepPin2 = 34;
const int dirPin2 = 35;

//const int stepPin = 10;
//const int dirPin = 11;
//const int stepPin = 32;
//const int dirPin = 33;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

}
void loop() {
  Serial.println("Running");
  Move(dirPin, stepPin);
  Move(dirPin2, stepPin2);
}

void Move(int dirPin, int stepPin)
 {  
  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 200; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
    delay(1000); // One second delay
  digitalWrite(dirPin, LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for (int x = 0; x < 200; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
