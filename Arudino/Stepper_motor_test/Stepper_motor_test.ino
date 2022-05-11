/*     Simple Stepper Motor Control Exaple Code

    by Dejan Nedelkovski, www.HowToMechatronics.com

*/

// defines pins numbers
const int stepPin1 = 2;
const int dirPin1 = 3;

const int stepPin2 = 4;
const int dirPin2 = 5;

const int stepPin3 = 6;
const int dirPin3 = 7;

//const int stepPin = 8;
//const int dirPin = 9;
const int stepPin4 = 34;
const int dirPin4 = 35;

//const int stepPin = 10;
//const int dirPin = 11;
const int stepPin5 = 32;
const int dirPin5 = 33;

const int MOTOR_PINS[5][2] = { {2, 3}, {4, 5}, {6, 7}, {34, 35}, {32, 33} };

void setup() {
  // Sets the two pins as Outputs
  pinMode(MOTOR_PINS[0][0], OUTPUT);
  pinMode(MOTOR_PINS[0][1], OUTPUT);
  pinMode(MOTOR_PINS[1][0], OUTPUT);
  pinMode(MOTOR_PINS[1][1], OUTPUT);
  pinMode(MOTOR_PINS[2][0], OUTPUT);
  pinMode(MOTOR_PINS[2][1], OUTPUT);
  pinMode(MOTOR_PINS[3][0], OUTPUT);
  pinMode(MOTOR_PINS[3][1], OUTPUT);
  pinMode(MOTOR_PINS[4][0], OUTPUT);
  pinMode(MOTOR_PINS[4][1], OUTPUT);
  Serial.begin(9600);

}
void loop() {
  
  Serial.println("Running");
  Move(MOTOR_PINS[0][1], MOTOR_PINS[0][0]);
  Move(MOTOR_PINS[1][1], MOTOR_PINS[1][0]);
  Move(MOTOR_PINS[2][1], MOTOR_PINS[2][0]);
  Move(MOTOR_PINS[3][1], MOTOR_PINS[3][0]);
  Move(MOTOR_PINS[4][1], MOTOR_PINS[4][0]);
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
