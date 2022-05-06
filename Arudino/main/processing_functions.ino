void string_to_array(String receivedString)
{
    // Parse received String

  // Place in the global array
  // paintLeftForDC[4][5]={ {1, 1, 1, 0, 0}, {2, 2, 0, 2, 0}, {3, 0, 3, 3,0 }, {0, 4, 4, 4, 0} }; // {Cyan, Magenta, Yellow, White, Mixer}, {...}, {...}, {...}
  
  int test_num = 20;
  for (int i = 0; i < NUM_MOTORS; i++)
  {
    for (int j = 0; j < NUM_MOTORS_AND_MIXER; j++)
    {
      paintLeftForDC[i][j] = test_num;
      test_num = test_num -1;
    }
  }
}

void consume_paint(int arrayToUse, int colour, int mlConsumed)
{
  paintLeftInSyringes[colour] = paintLeftInSyringes[colour]-mlConsumed; // Remove Paint used from Syrinces
  paintLeftForDC[arrayToUse][colour] = paintLeftForDC[arrayToUse][colour]-mlConsumed; // Remove paint used from DC array
//  Serial.print(PAINT_COLOUR[colour]); Serial.print(" paint removed from arrays:"); Serial.print(mlConsumed); Serial.println(" mL");
}

void print_current_state() 
{
  Serial.println("----------------------------");
  // Shows the state of our setup
  
  // Say how much paint we have left in each Syringe
  Serial.println("Paint left in syringes (mL):"); for (int i = 0; i < NUM_MOTORS_AND_MIXER; i++) {Serial.print(paintLeftInSyringes[i]); Serial.print(" ");}; Serial.println(" ");
  
  // Say how much paint is left to dispense in the desired colours
  Serial.println("paintLeftForDC: ");
  for (int i = 0; i < NUM_MOTORS_AND_MIXER; i++) {for (int j = 0; j < NUM_MOTORS_AND_MIXER; j++){Serial.print(paintLeftForDC[i][j]); Serial.print(", ");} Serial.println(" ");}
  
  Serial.println("----------------------------\n");
}
