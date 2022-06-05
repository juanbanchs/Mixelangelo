void ActuateAllMotors(int DC1Location)
{
  // Call the motor actuation and edits paint left in syringes 4 times
  
  for (int colour = 0; colour < NUM_MOTORS; colour++)
  {
    int arrayToUse = colour - DC1Location;
    if (arrayToUse < 0){arrayToUse = arrayToUse + 5;}
    
    double mlConsumed = paintLeftForDC[arrayToUse][colour];
    MotorActuation(colour, MOTOR_PINS[colour][0], MOTOR_PINS[colour][1], mlConsumed); //mL_disp + to go down, mL_disp - to go down
    consume_paint(arrayToUse, colour, mlConsumed); // Cyan, Magenta, Yellow, White, Mixer [CMYK,Mixer] (0,1,2,3,4)
  }
}

int mix_all_colours(int DC1Location) 
{
  // Prepare Mixer
  move_mixer(PLUNGE_DISTANCE);
  
  // Mix Colour 1
  MixerMotorSpinner(SPIN_TIME);
  move_mixer(-RETRACT_DISTANCE); 
  DC1Location = BottomTurn(1, 1, DC1Location);
  move_mixer(RETRACT_DISTANCE);
  MixerMotorSpinner(SPIN_TIME); //Cleanup
  move_mixer(-RETRACT_DISTANCE);

  // Mix Colour 2
  DC1Location = BottomTurn(2, -1, DC1Location);
  move_mixer(RETRACT_DISTANCE); 
  MixerMotorSpinner(SPIN_TIME);
  move_mixer(-RETRACT_DISTANCE); 
  DC1Location = BottomTurn(2, 1, DC1Location);
  move_mixer(RETRACT_DISTANCE); 
  MixerMotorSpinner(SPIN_TIME); //Cleanup
  move_mixer(-RETRACT_DISTANCE); 

  // Mix Colour 3
  DC1Location = BottomTurn(2, 1, DC1Location);
  move_mixer(RETRACT_DISTANCE); 
  MixerMotorSpinner(SPIN_TIME);
  move_mixer(-RETRACT_DISTANCE); 
  DC1Location = BottomTurn(2, -1, DC1Location);
  move_mixer(RETRACT_DISTANCE); 
  MixerMotorSpinner(SPIN_TIME); //Cleanup
  move_mixer(-RETRACT_DISTANCE); 

  // Mix Colour 4
  DC1Location = BottomTurn(1, 1, DC1Location);
  move_mixer(RETRACT_DISTANCE); 
  MixerMotorSpinner(SPIN_TIME);
  move_mixer(-RETRACT_DISTANCE); 
  DC1Location = BottomTurn(1, -1, DC1Location);
  move_mixer(RETRACT_DISTANCE); 
  MixerMotorSpinner(SPIN_TIME); //Cleanup
  move_mixer(-PLUNGE_DISTANCE); 
}

void MotorActuation(int colour, int motorPinA, int motorPinB, double mlConsumed) // steps_disp + to go down, steps_disp - to go down
{
  // Need 2 inputs for the 2 numbers that represent which motor is gonna be dispensing
  // Need input on how many ml need to be dispensed

  Serial.print(PAINT_COLOUR[colour]); Serial.print(" motor actuated (Pins ["); Serial.print(motorPinA); Serial.print("]["); Serial.print(motorPinB); Serial.print("]). Dispensed "); Serial.print(mlConsumed); 
  Serial.print("mL, equivalent to "); Serial.print(mlConsumed*ML_NUM_STEPS); Serial.println(" steps."); 
  Serial.print("Delaying for MOTOR_DELAY ("); Serial.print(MOTOR_DELAY); Serial.println(" ms)."); delay(MOTOR_DELAY); 

  if (mlConsumed > 0.0) // going down //CHANGED
  {
    digitalWrite(motorPinB, HIGH);
  } else {
    digitalWrite(motorPinB, LOW);
    mlConsumed = -mlConsumed;
  }

  for (int x = 0; x < mlConsumed*ML_NUM_STEPS; x++)  //CHANGED
  {
    digitalWrite(motorPinA, HIGH);
    delayMicroseconds(MOTOR_SPEED_DELAY);
    digitalWrite(motorPinA, LOW);
    delayMicroseconds(MOTOR_SPEED_DELAY);
//    Serial.print("In Loop A motor actuation. X = "); Serial.print(x); Serial.print(". mlConsumed*ML_NUM_SETPS = "); Serial.println(mlConsumed*ML_NUM_STEPS);
  }
}


// Prep for BottomTurn Function
#include <Stepper.h> // Include the Arduino Stepper.h library:
const int STEPS_PER_REVOLUTION = 411; // Define number of steps per rotation:
Stepper myStepper = Stepper(STEPS_PER_REVOLUTION, 8, 9, 10, 12); // Create stepper object called 'myStepper', note the pin order.

int BottomTurn(int num_steps,int way, int DC1Location)
{
  // Set the speed to 5 rpm:
  myStepper.setSpeed(27);
 
  //Turn motor 
  int turn = num_steps*STEPS_PER_REVOLUTION*way;
  myStepper.step(turn);

  //Tracker
  int locationTracker = num_steps*way;

  DC1Location = DC1Location+locationTracker;
  if (DC1Location > 4){DC1Location = DC1Location-5;}   
  if (DC1Location < 0){DC1Location = DC1Location + 5;} // TBD. Shouldn't it be 1? and the above may be 4? I eddited it.

  Serial.print("Bottom motor rotated by "); Serial.print(num_steps); Serial.print(" in direction "); Serial.print(way); Serial.print(". Now DC1Location = "); Serial.println(DC1Location);
  Serial.print("Delaying for TURNER_DELAY ("); Serial.print(TURNER_DELAY); Serial.println(" ms)."); delay(TURNER_DELAY); 
  return DC1Location;
}

void TransistorCircuit(int totalSpinTime)
{
  analogWrite(MIXER_PIN, MIXING_SPEED);
  delay(totalSpinTime);
  analogWrite(MIXER_PIN, 0);
  
//  for(int i = 0; i < 255; i++) //Counting from 0 to 255.
//  {
//    analogWrite(MIXER_PIN, i); //Give the "i" value to the signal contact.
//    delay(10); //Wait 10 milliseconds.
//  }
//  delay(totalSpinTime/2); //One second at the maximum speed.
//  
//  for(int i = 255; i > 0; i--) //Counting from 255 to 0.
//  {
//    analogWrite(MIXER_PIN, i); //Give the "i" value to the signal contact.
//    delay(10); //Wait 10 milliseconds.
//  }
//  delay(totalSpinTime/2); //Stop for a second
} 

void MixerMotorSpinner(int seconds)
{
  Serial.print("Mixing for "); Serial.print(seconds/1000); Serial.println(" seconds");
  TransistorCircuit(seconds);
  Serial.print("Delaying for MIXER_DELAY ("); Serial.print(MIXER_DELAY); Serial.println(" ms)."); delay(MIXER_DELAY); 
}

void move_mixer(int mlMoved)
{
  MotorActuation(4, MOTOR_PINS[4][0], MOTOR_PINS[4][1], mlMoved);
}
