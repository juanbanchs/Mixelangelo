/*
  Code for our Mixelangelo Project [June 2022]
  Members: Alexandra Orloff, Kate Pihl, Shushig Lokmanian,
  Robert Valencia, Krystal Tsoi, Joelle Narducci, Juan Banchs
*/

// Global Variables
const int NUM_MOTORS = 4;
const int NUM_MOTORS_AND_MIXER = NUM_MOTORS + 1;
double paintLeftInSyringes[5] = {90, 80, 70, 60, 0}; // Cyan, Magenta, Yellow, White, Mixer [CMYK,Mixer]
const String PAINT_COLOUR[5] = {"Cyan  ", "Magenta", "Yellow ", "White  ", "Mixer  "};
double paintLeftForDC[5][5] = { {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0} }; // {Cyan, Magenta, Yellow, White, Mixer}, {...}, {...}, {...}
int num_colours = 0;
//const int MOTOR_PINS[5][2] = { {2, 3}, {4, 5}, {6, 7}, {34, 35}, {36, 33} };
const int MOTOR_PINS[5][2] = { {34, 35}, {36, 37}, {38, 39}, {50, 51}, {40, 41} };
const int MIXER_PIN = 13;

const int ML_NUM_STEPS = 38; // Not tested on paint
const double SPIN_TIME = 3000; // milliseconds
const double MIXING_SPEED = 255; // From 0 to 255 (analog)

// Mixer Global Variables
double PLUNGE_DISTANCE = 70; //ml 
double RETRACT_DISTANCE = 30; //ml

// Delays
int MOTOR_DELAY = 1000; // milliseconds
int MIXER_DELAY = 1000; // milliseconds
int TURNER_DELAY = 1000; // milliseconds
int MOTOR_SPEED_DELAY = 1500; // microseconds

void setup() {
  // Sets the pins as output
  pinMode(MIXER_PIN, OUTPUT); //The 2nd PWM Pin as output. You can use any PWM Pin.
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

  digitalWrite(MOTOR_PINS[0][0], LOW);
  digitalWrite(MOTOR_PINS[0][1], LOW);
  digitalWrite(MOTOR_PINS[1][0], LOW);
  digitalWrite(MOTOR_PINS[1][1], LOW);
  digitalWrite(MOTOR_PINS[2][0], LOW);
  digitalWrite(MOTOR_PINS[2][1], LOW);
  digitalWrite(MOTOR_PINS[3][0], LOW);
  digitalWrite(MOTOR_PINS[3][1], LOW);
  digitalWrite(MOTOR_PINS[4][0], LOW);
  digitalWrite(MOTOR_PINS[4][1], LOW);

  Serial.begin(9600);



  Serial.println("Starting delaying of 5 seconds"); delay(5000); // Delay for 100 seconds

  // ------------------------------------ Test Land ------------------------------------------
  //  int colour_test = 0;
  //  int mlConsumed_test = 10;
  //  AMotorActuation(colour_test, MOTOR_PINS[colour_test][0], MOTOR_PINS[colour_test][1], mlConsumed_test);
  ////  AMotorActuation(int colour, int motorPinA, int motorPinB, double mlConsumed) // steps_disp + to go down, steps_disp - to go down
  //  Serial.print("Delaying for 100 seconds"); delay(100000); // Delay for 100 seconds

  //  int DC1Location2 = 0;
  //  DC1Location2 = BottomTurn(4, -1, DC1Location2);
  //  DC1Location2 = BottomTurn(4, 1, DC1Location2);
  //  Serial.print("Delaying for 100 seconds"); delay(100000); // Delay for 100 seconds

  //  int DC1Location2 = 0;
  //  Serial.print("-------- Now beginning colour mixing -------- DC1Location: "); Serial.println(DC1Location2);
  //  DC1Location2 = mix_all_colours(DC1Location2);
  //  Serial.print("Delaying for 100 seconds"); delay(100000); // Delay for 100 seconds

  //  TransistorCircuit(SPIN_TIME);
  //  Serial.print("Delaying for 100 seconds"); delay(100000); // Delay for 100 seconds
//
//  int DC1Location2 = 0;
//  int colour2 = 4;
//  int mlConsumed2 = 5;
//  Serial.print("-------- Testing colour mixing -------- DC1Location: "); Serial.println(DC1Location2);
//  //  DC1Location2 = mix_all_colours(DC1Location2);
//  //  MotorActuation(colour2, MOTOR_PINS[colour2][0], MOTOR_PINS[colour2][1], mlConsumed2); //mL_disp + to go down, mL_disp - to go down
//  //  MixerMotorSpinner(SPIN_TIME);
//  BottomTurn(1, -1, DC1Location2);
//  Serial.print("Delaying for 1000 seconds"); delay(1000000); // Delay for 100 seconds

  // ------------------------------------------------------------------------------------------
  // Refill if desired
  begin_refilling(0); //1 for yes, 0 for no

  // ------------------------------------------------------------------------------------------
  // Starting State
  Serial.println("Initial State: ");
  print_current_state();

  // Robert and Krystal send the String
  String receivedString = wait_for_string();

  // Parse the String into an array
  num_colours = read_string(receivedString);
  Serial.println("After parsing the string. We now have this state: ");
  print_current_state();

  // ------------------------------------------------------------------------------------------
  // Now we start the Paint Dispensing Process
  delay(1000); Serial.println("-------- Now beginning paint dispensing process -------- ");
  int DC1Location = 0; // Define the location that our first DC ("Desired Colour") is at (0 is the first position)

  for (int colour = 0; colour < NUM_MOTORS_AND_MIXER; colour++)
  {
    Serial.print("Starting motor actuation for 'Colour Generation Step "); Serial.print(colour); Serial.println("'.");
    ActuateAllMotors(DC1Location); // Calls the motor actuation and edits paint left in syringes 4 times

    if (DC1Location != 4) {
      DC1Location = BottomTurn(1, 1, DC1Location); // Turn the cups in preparation next step.
    }
    else {
      Serial.print("Bottom motor not rotated. Now DC1Location = ");  // Skip last turn
      Serial.println(DC1Location);
    }

    Serial.print("\nState after Colour Generation Step "); Serial.print(colour);  Serial.println(".");
    print_current_state();
  }

  // ------------------------------------------------------------------------------------------
  // Now we start the Paint Mixing Process
  Serial.print("-------- Now beginning colour mixing -------- DC1Location: "); Serial.println(DC1Location);
  DC1Location = mix_all_colours(DC1Location);

  // ------------------------------------------------------------------------------------------
  // Job Done!
  Serial.print("-------- We are done! Beginning a 100 second delay -------- DC1Location: "); Serial.println(DC1Location);
  delay(100000);
}

void loop() {
}
