  // Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define number of steps per rotation:
const int stepsPerRevolution = 411;

// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

int BottomTurn(int num_steps,int way, int DC1Location)
{

  // Set the speed to 5 rpm:
  myStepper.setSpeed(27);
  
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
 
//Turn motor 
int turn = num_steps*stepsPerRevolution*way;
 myStepper.step(turn);

 //Tracker
int locationTracker = num_steps*way;

  
    DC1Location = DC1Location+locationTracker;
    if (DC1Location > 5)
    {
      DC1Location = DC1Location-5;
    }
    
    if (DC1Location < 1)
    {
      DC1Location = DC1Location + 5 ;
    }

return DC1Location;
}
