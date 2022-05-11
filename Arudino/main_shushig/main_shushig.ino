/*
Initialization Code Test (Main Body)
*/

void setup() {
    Serial.begin(9600); 
}

void loop () {

  // ------------------------------------ Test Land ------------------------------------------
  int colour_test = 0;
  int mlConsumed_test = 10;
  AMotorActuation(colour_test, MOTOR_PINS[colour_test][0], MOTOR_PINS[colour_test][1], mlConsumed_test);
//  AMotorActuation(int colour, int motorPinA, int motorPinB, double mlConsumed) // steps_disp + to go down, steps_disp - to go down
  Serial.print("Delaying for 100 seconds"); delay(100000); // Delay for 100 seconds
  // ------------------------------------------------------------------------------------------
    
}
