String wait_for_string()
{
  String receivedString = "0111222333444111222333444111222333444111222333444";
  Serial.print("String was received and reads: "); Serial.println(receivedString);
  return receivedString;
}
