String wait_for_string()
{
//  String receivedString = "4100100100150111222333000111222333000111222333000";
//  String receivedString "4111222333444111222333444111222333444111222333444";
  String receivedString = "2000100100100000000000000000000000000000000000000";
  Serial.print("String was received and reads: "); Serial.println(receivedString);
  return receivedString;
}
