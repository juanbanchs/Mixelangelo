/*
Code for our Mixelangelo Project [June 2022]
Members: Alexandra Orloff, Kate Pihl, Shushig Lokmanian, 
Robert Valencia, Krystal Tsoi, Joelle Narducci, Juan Banchs
*/

// Global Variables
int NUM_MOTORS = 4;
int NUM_MOTORS_AND_MIXER = NUM_MOTORS+1;
int paintLeftInSyringes[5] = {90, 80, 70, 60, 0}; // Cyan, Magenta, Yellow, White, Mixer [CMYK,Mixer]
String PAINT_COLOUR[5] = {"Cyan  ", "Magenta", "Yellow ", "White  ", "Mixer  "};
int paintLeftForDC[5][5]={ {1, 1, 1, 0, 0}, {2, 2, 0, 2, 0}, {3, 0, 3, 3,0 }, {0, 4, 4, 4, 0}, {0, 0, 0, 0, 0} }; // {Cyan, Magenta, Yellow, White, Mixer}, {...}, {...}, {...}
int motorPins[4][2] = { {2, 3}, {4, 5}, {6, 7}, {7, 8} };
int ML_NUM_STEPS = 40; //TBD
//int STEPS_NUM_ML = 1/40; //TBD
  
void setup() {
  Serial.begin(9600);
}

void loop() {

  // Starting State
  Serial.println("Initial State: ");
  print_current_state();
  
  // Robert and Krystal send the String
  String receivedString = wait_for_string();
//  Serial.print("The 'inputString' is now in the main loop and reads: "); Serial.println(receivedString);

  // Parse the String into an array
  string_to_array(receivedString);
  Serial.println("After parsing the string. We now have this state: ");
  print_current_state();

  
  // ----------  Now we start the Paint Dispensing Process ---------- 
  delay(1000); Serial.println("-------- Now beginning paint dispensing process. -------- ");
  int DC1Location = 0; // Define the location that our first DC ("Desired Colour") is at (0 is the first position)

  for (int colour = 0; colour < NUM_MOTORS_AND_MIXER; colour++)
  {
    Serial.print("Starting motor actuation for 'Colour Generation Step "); Serial.print(colour); Serial.println("'.");
    ActuateAllMotors(DC1Location); // Calls the motor actuation and edits paint left in syringes 4 times
    
    if (DC1Location != 4) {DC1Location = BottomTurn(1,1,DC1Location);} // Turn the cups in preparation next step.
    else {Serial.print("Bottom motor not rotated. Now DC1Location = "); Serial.println(DC1Location);} // Skip last turn
    
    Serial.print("\nState after Colour Generation Step "); Serial.print(colour);  Serial.println(".");
    print_current_state();
  }
  
  Serial.print("Time to begin colour mixing. DC1Location: "); Serial.println(DC1Location);
  
  // Mix Colour 1
  MixerMotorSpinner(5);
  DC1Location = BottomTurn(1, 1, DC1Location);
  MixerMotorSpinner(5); //Cleanup

  // Mix Colour 2
  DC1Location = BottomTurn(2, -1, DC1Location);
  MixerMotorSpinner(5);
  DC1Location = BottomTurn(2, 1, DC1Location);
  MixerMotorSpinner(5); //Cleanup

  // Mix Colour 3
  DC1Location = BottomTurn(2, 1, DC1Location);
  MixerMotorSpinner(5);
  DC1Location = BottomTurn(2, -1, DC1Location);
  MixerMotorSpinner(5); //Cleanup

  // Mix Colour 4
  DC1Location = BottomTurn(1, 1, DC1Location);
  MixerMotorSpinner(5);
  DC1Location = BottomTurn(1, -1, DC1Location);
  MixerMotorSpinner(5); //Cleanup

  //Ready at the start!
  delay(10000);
  }
