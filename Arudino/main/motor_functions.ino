void ActuateAllMotors(int DC1Location)
{
  // Call the motor actuation and edits paint left in syringes 4 times

  // To be changed
  for (int colour = 0; colour < NUM_MOTORS; colour++)
  {
    int arrayToUse = colour - DC1Location;
    if (arrayToUse < 0){arrayToUse = arrayToUse + 5;}
    
    int mlConsumed = paintLeftForDC[arrayToUse][colour];
    MotorActuation(colour, motorPins[colour][0], motorPins[colour][1], mlConsumed); //mL_disp + to go down, mL_disp - to go down
    consume_paint(arrayToUse, colour, mlConsumed); // Cyan, Magenta, Yellow, White, Mixer [CMYK,Mixer] (0,1,2,3,4)
  }
}

int MotorActuation(int colour, int motorPinA, int motorPinB, int mlConsumed) //mL_disp + to go down, mL_disp - to go down
{
  Serial.print(PAINT_COLOUR[colour]); Serial.print(" motor actuated (Pins ["); Serial.print(motorPinA); Serial.print("]["); Serial.print(motorPinB); Serial.print("]). Dispensed "); Serial.print(mlConsumed); 
  Serial.print("mL, equivalent to "); Serial.print(mlConsumed*ML_NUM_STEPS); Serial.println(" steps."); 
}


// Prep for BottomTurn Function
#include <Stepper.h> // Include the Arduino Stepper.h library:
const int STEPS_PER_REVOLUTION = 411; // Define number of steps per rotation:
Stepper myStepper = Stepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11); // Create stepper object called 'myStepper', note the pin order.

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
  return DC1Location;
}

void MixerMotorSpinner(int seconds)
{
  Serial.println("Mixed for 5 seconds");
}
