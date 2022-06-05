void consume_paint(int arrayToUse, int colour, double mlConsumed)
{
  paintLeftInSyringes[colour] = paintLeftInSyringes[colour]-mlConsumed; // Remove Paint used from Syrinces
  paintLeftForDC[arrayToUse][colour] = paintLeftForDC[arrayToUse][colour]-mlConsumed; // Remove paint used from DC array
//  Serial.print(PAINT_COLOUR[colour]); Serial.print(" paint removed from arrays:"); Serial.print(mlConsumed); Serial.println(" mL");
}

void print_current_state() 
{
  Serial.println("----------------------------");
  // Shows the state of our setup
  
  //Number of colours
  Serial.print("Number of colours selected: "); Serial.println(num_colours);
  
  // Say how much paint we have left in each Syringe
  Serial.println("Paint left in syringes (mL):"); for (int i = 0; i < NUM_MOTORS_AND_MIXER; i++) {Serial.print(paintLeftInSyringes[i]); Serial.print(" ");}; Serial.println(" ");
  
  // Say how much paint is left to dispense in the desired colours
  Serial.println("paintLeftForDC: ");
  for (int i = 0; i < NUM_MOTORS_AND_MIXER; i++) {for (int j = 0; j < NUM_MOTORS_AND_MIXER; j++){Serial.print(paintLeftForDC[i][j]); Serial.print(", ");} Serial.println(" ");}
  
  Serial.println("----------------------------\n");
}

int read_string(String color) 
{

//  int test_num = 20;
//  for (int i = 0; i < NUM_MOTORS; i++)
//  {
//    for (int j = 0; j < NUM_MOTORS_AND_MIXER; j++)
//    {
//      paintLeftForDC[i][j] = test_num;
//      test_num = test_num -1;
//    }
//  }
    char num_colours_p = color.charAt(0);
    String num_colours_pp = String(num_colours_p);
    int num_colours_ppp = num_colours_pp.toInt();
    Serial.print("num_colours is in the string: "); Serial.println(num_colours_ppp);

// cyan of color 1
    char cyan_11 = color.charAt(1);
    String cy_11 = String(cyan_11);
    int c_11 = cy_11.toDouble()*100;

    char cyan_12 = color.charAt(2);
    String cy_12 = String(cyan_12);
    int c_12 = cy_12.toDouble()*10;

    char cyan_13 = color.charAt(3);
    String cy_13 = String(cyan_13);
    int c_13 = cy_13.toDouble();

    int c1 = c_11 + c_12 + c_13;
    //paintLeftForDC[0][0] = c1;

// magenta of color 1
    char mag_11 = color.charAt(4);
    String ma_11 = String(mag_11);
    int m_11 = ma_11.toDouble()*100;

    char mag_12 = color.charAt(5);
    String ma_12 = String(mag_12);
    int m_12 = ma_12.toDouble()*10;

    char mag_13 = color.charAt(6);
    String ma_13 = String(mag_13);
    int m_13 = ma_13.toDouble();

    int m1 = m_11 + m_12 + m_13;
    //paintLeftForDC[0][1] = m1;
    

// yellow of color 1
    char yel_11 = color.charAt(7);
    String ye_11 = String(yel_11);
    int y_11 = ye_11.toDouble()*100;

    char yel_12 = color.charAt(8);
    String ye_12 = String(yel_12);
    int y_12 = ye_12.toDouble()*10;

    char yel_13 = color.charAt(9);
    String ye_13 = String(yel_13);
    int y_13 = ye_13.toDouble();

    int y1 = y_11 + y_12 + y_13;
    //paintLeftForDC[0][2] = y1;


// volume of color 1
    char vol_11 = color.charAt(10);
    String vo_11 = String(vol_11);
    int v_11 = vo_11.toDouble()*100;

    char vol_12 = color.charAt(11);
    String vo_12 = String(vol_12);
    int v_12 = vo_12.toDouble()*10;

    char vol_13 = color.charAt(12);
    String vo_13 = String(vol_13);
    int v_13 = vo_13.toDouble();

    double v1 = v_11 + v_12 + v_13;
    double vol1 = v1/10;


//-------------------------------------------------------------
//-------------------------------------------------------------


// cyan of color 2
    char cyan_21 = color.charAt(13);
    String cy_21 = String(cyan_21);
    int c_21 = cy_21.toDouble()*100;

    char cyan_22 = color.charAt(14);
    String cy_22 = String(cyan_22);
    int c_22 = cy_22.toDouble()*10;

    char cyan_23 = color.charAt(15);
    String cy_23 = String(cyan_23);
    int c_23 = cy_23.toDouble();

    int c2 = c_21 + c_22 + c_23;
    //paintLeftForDC[1][0] = c2;
    

// magenta of color 2
    char mag_21 = color.charAt(16);
    String ma_21 = String(mag_21);
    int m_21 = ma_21.toDouble()*100;

    char mag_22 = color.charAt(17);
    String ma_22 = String(mag_22);
    int m_22 = ma_22.toDouble()*10;

    char mag_23 = color.charAt(18);
    String ma_23 = String(mag_23);
    int m_23 = ma_23.toDouble();

    int m2 = m_21 + m_22 + m_23;
    //paintLeftForDC[1][1] = m2;
    

// yellow of color 2
    char yel_21 = color.charAt(19);
    String ye_21 = String(yel_21);
    int y_21 = ye_21.toDouble()*100;

    char yel_22 = color.charAt(20);
    String ye_22 = String(yel_22);
    int y_22 = ye_22.toDouble()*10;

    char yel_23 = color.charAt(21);
    String ye_23 = String(yel_23);
    int y_23 = ye_23.toDouble();

    int y2 = y_21 + y_22 + y_23;
    //paintLeftForDC[1][2] = y2;


// volume of color 2
    char vol_21 = color.charAt(22);
    String vo_21 = String(vol_21);
    int v_21 = vo_21.toDouble()*100;

    char vol_22 = color.charAt(23);
    String vo_22 = String(vol_22);
    int v_22 = vo_22.toDouble()*10;

    char vol_23 = color.charAt(24);
    String vo_23 = String(vol_23);
    int v_23 = vo_23.toDouble();

    double v2 = v_21 + v_22 + v_23;
    double vol2 = v2/10;


//-------------------------------------------------------------
//-------------------------------------------------------------


// cyan of color 3
    char cyan_31 = color.charAt(25);
    String cy_31 = String(cyan_31);
    int c_31 = cy_31.toDouble()*100;

    char cyan_32 = color.charAt(26);
    String cy_32 = String(cyan_32);
    int c_32 = cy_32.toDouble()*10;

    char cyan_33 = color.charAt(27);
    String cy_33 = String(cyan_33);
    int c_33 = cy_33.toDouble();

    int c3 = c_31 + c_32 + c_33;
    //paintLeftForDC[2][0] = c3;
    

// magenta of color 3
    char mag_31 = color.charAt(28);
    String ma_31 = String(mag_31);
    int m_31 = ma_31.toDouble()*100;

    char mag_32 = color.charAt(29);
    String ma_32 = String(mag_32);
    int m_32 = ma_32.toDouble()*10;

    char mag_33 = color.charAt(30);
    String ma_33 = String(mag_33);
    int m_33 = ma_33.toDouble();

    int m3 = m_31 + m_32 + m_33;
    //paintLeftForDC[2][1] = m3;
    

// yellow of color 3
    char yel_31 = color.charAt(31);
    String ye_31 = String(yel_31);
    int y_31 = ye_31.toDouble()*100;

    char yel_32 = color.charAt(32);
    String ye_32 = String(yel_32);
    int y_32 = ye_32.toDouble()*10;

    char yel_33 = color.charAt(33);
    String ye_33 = String(yel_33);
    int y_33 = ye_33.toDouble();

    int y3 = y_31 + y_32 + y_33;
    //paintLeftForDC[2][2] = y3;


// volume of color 3
    char vol_31 = color.charAt(34);
    String vo_31 = String(vol_31);
    int v_31 = vo_31.toDouble()*100;

    char vol_32 = color.charAt(35);
    String vo_32 = String(vol_32);
    int v_32 = vo_32.toDouble()*10;

    char vol_33 = color.charAt(36);
    String vo_33 = String(vol_33);
    int v_33 = vo_33.toDouble();

    double v3 = v_31 + v_32 + v_33;
    double vol3 = v3/10;


//-------------------------------------------------------------
//-------------------------------------------------------------


// cyan of color 4
    char cyan_41 = color.charAt(37);
    String cy_41 = String(cyan_41);
    int c_41 = cy_41.toDouble()*100;

    char cyan_42 = color.charAt(38);
    String cy_42 = String(cyan_42);
    int c_42 = cy_42.toDouble()*10;

    char cyan_43 = color.charAt(39);
    String cy_43 = String(cyan_43);
    int c_43 = cy_43.toDouble();

    int c4 = c_41 + c_42 + c_43;
    //paintLeftForDC[3][0] = c4;
    

// magenta of color 4
    char mag_41 = color.charAt(40);
    String ma_41 = String(mag_41);
    int m_41 = ma_41.toDouble()*100;

    char mag_42 = color.charAt(41);
    String ma_42 = String(mag_42);
    int m_42 = ma_42.toDouble()*10;

    char mag_43 = color.charAt(42);
    String ma_43 = String(mag_43);
    int m_43 = ma_43.toDouble();

    int m4 = m_41 + m_42 + m_43;
    //paintLeftForDC[3][1] = m4;
    

// yellow of color 4
    char yel_41 = color.charAt(43);
    String ye_41 = String(yel_41);
    int y_41 = ye_41.toDouble()*100;

    char yel_42 = color.charAt(44);
    String ye_42 = String(yel_42);
    int y_42 = ye_42.toDouble()*10;

    char yel_43 = color.charAt(45);
    String ye_43 = String(yel_43);
    int y_43 = ye_43.toDouble();

    int y4 = y_41 + y_42 + y_43;
    //paintLeftForDC[3][2] = y4;


// volume of color 4
    char vol_41 = color.charAt(46);
    String vo_41 = String(vol_41);
    int v_41 = vo_41.toDouble()*100;

    char vol_42 = color.charAt(47);
    String vo_42 = String(vol_42);
    int v_42 = vo_42.toDouble()*10;

    char vol_43 = color.charAt(48);
    String vo_43 = String(vol_43);
    int v_43 = vo_43.toDouble();

    double v4 = v_41 + v_42 + v_43;
    double vol4 = v4/10;


    //---------------------------------------------
    //---------------------------------------------
    
    //now we have all cmyk and input volume values
    //need to convert them to individual color volumes and values for the linear motors
    
    double tot1 = c1 + m1 + y1; //adding up CMYK values 

    double c1vol = (c1/tot1); //finding fraction of each color 
    double m1vol = (m1/tot1);
    double y1vol = (y1/tot1);
      
    double C1 = c1vol*vol1; //how much of each color needed to make user specified volyume
    double M1 = m1vol*vol1;
    double Y1 = y1vol*vol1;

    if (tot1 == 0)
    {
      C1 = 0; M1 = 0; Y1 = 0;
    }


    //---------------------------------------------
    
    double tot2 = c2 + m2 + y2; //adding up CMYK values 
    
    double c2vol = (c2/tot2); //finding fraction of each color 
    double m2vol = (m2/tot2);
    double y2vol = (y2/tot2);
    
    double C2 = c2vol*vol2; //how much of each color needed to make user specified volume, this will go into int mL_disp in paint motor actuation
    double M2 = m2vol*vol2;
    double Y2 = y2vol*vol2;
   
    //---------------------------------------------    
    
    double tot3 = c3 + m3 + y3; //adding up CMYK values 
    
    double c3vol = (c3/tot3); //finding fraction of each color 
    double m3vol = (m3/tot3);
    double y3vol = (y3/tot3);
    
    double C3 = c3vol*vol3; //
    double M3 = m3vol*vol3;
    double Y3 = y3vol*vol3;
   
    //---------------------------------------------    
    
    double tot4 = c4 + m4 + y4; //adding up CMYK values 
    
    double c4vol = (c4/tot4); //finding fraction of each color 
    double m4vol = (m4/tot4);
    double y4vol = (y4/tot4);
    
    double C4 = c4vol*vol4; //actual volume of each color in mL
    double M4 = m4vol*vol4;
    double Y4 = y4vol*vol4;

    // Remove Extra Colours
    if (tot1 == 0) {C1 = 0; M1 = 0; Y1 = 0;}
    if (tot2 == 0) {C2 = 0; M2 = 0; Y2 = 0;}
    if (tot3 == 0) {C3 = 0; M3 = 0; Y3 = 0;}
    if (tot4 == 0) {C4 = 0; M4 = 0; Y4 = 0;}
    
    //---------------------------------------------        
    
    //update array that keeps track of how much paint still needs to be dispensed for each desired color
    //paintLeftForDC[4][5] = { {C1, M1, Y1, 0, 0}, {C2, M2, Y2, 0, 0}, {C3, M3, Y3, 0,0 }, {C4, M4, Y4, 0, 0} };

    paintLeftForDC[0][0] = C1;
    paintLeftForDC[0][1] = M1;
    paintLeftForDC[0][2] = Y1;
    paintLeftForDC[1][0] = C2;
    paintLeftForDC[1][1] = M2;
    paintLeftForDC[1][2] = Y2;
    paintLeftForDC[2][0] = C3;
    paintLeftForDC[2][1] = M3;
    paintLeftForDC[2][2] = Y3;
    paintLeftForDC[3][0] = C4;
    paintLeftForDC[3][1] = M4;
    paintLeftForDC[3][2] = Y4;

    return num_colours_ppp;
    
}
