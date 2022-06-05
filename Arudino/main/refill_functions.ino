void begin_refilling(int choice) 
{
  if (choice == 1)
  {
    Serial.println("Refill Starting...");  
 // ------------------------------ Refill amounts ------------------------------
    double cyan = 0; //ml
    double magenta = 0; //ml
    double yellow = 0; //ml
    double white = 0; //ml
    double mixer_movement = 5; //
 // ----------------------------------------------------------------------------
    refill_syringes(cyan, magenta, yellow, white, mixer_movement);
    Serial.println("Refill Complete!");  
    Serial.println("Delaying for 1000 seconds"); delay(1000000); // Delay for 100 seconds
  }
  else 
  {
    Serial.println("No refill started \n");  
  }
}


void refill_syringes(int cyan, int magenta, int yellow, int white, int mixer_movement)
{
  //Make it negative to go backwards
  double refill_amounts[5] = {cyan, magenta, yellow, white, mixer_movement}; // Cyan, Magenta, Yellow, White, Mixer [CMYK,Mixer]
  
  for (int colour = 0; colour < NUM_MOTORS_AND_MIXER; colour++)
  {
    double mlConsumed = refill_amounts[colour];
    MotorActuation(colour, MOTOR_PINS[colour][0], MOTOR_PINS[colour][1], mlConsumed); //mL_disp + to go down, mL_disp - to go down
//    consume_paint(arrayToUse, colour, mlConsumed); // Cyan, Magenta, Yellow, White, Mixer [CMYK,Mixer] (0,1,2,3,4)
  }
}
