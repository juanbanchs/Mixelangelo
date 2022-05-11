void AMotorActuation(int colour, int motorPinA, int motorPinB, double mlConsumed) // steps_disp + to go down, steps_disp - to go down
{
  // Need 2 inputs for the 2 numbers that represent which motor is gonna be dispensing
  // Need input on how many ml need to be dispensed

  // declare the 2 pins of the motor we're using
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
  
  if (mlConsumed > 0) // going down //CHANGED
  {
    for (int x = 0; x < mlConsumed*ML_NUM_STEPS; x++)  //CHANGED
    {
      digitalWrite(motorPinA, HIGH);
      digitalWrite(motorPinB, LOW);
      delayMicroseconds(500);
    }
  
    // both pins high now to stop motor
    digitalWrite(motorPinA, LOW); //CHANGED
  
    // return how many mL are left
//    mL_final = mL_initial - mL_disp;
//    return mL_final;
  }
  
  if (mlConsumed < 0) // going up //CHANGED
    {
    for (int x = 0; x < mlConsumed*ML_NUM_STEPS; x++) //CHANGED
    {
      digitalWrite(motorPinA, HIGH); //CHANGED
      digitalWrite(motorPinB, HIGH);
      delayMicroseconds(500);
    }
  
    // both pins low now to stop motor
    digitalWrite(motorPinA, LOW); //CHANGED
  
    // return how many mL are left
//    return mL_final = mL_initial;
  }
}
