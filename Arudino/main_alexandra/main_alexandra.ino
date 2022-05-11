/*
Initialization Code Test (Main Body)
*/
void read_array(String);
double PaintLeftInDC[4][5] = { {1,1,1,0,0}, {2,2,2,0,0}, {3,3,3,0,0}, {4,4,4,0,0} };

void setup() {
  
      Serial.begin(9600);
        
}

void loop () {

    String a = "2638163482117272847228091834691875075265419345105"; 
    read_string(a);
    Serial.println(PaintLeftInDC[0][2]);
    delay(100000);

    
}
