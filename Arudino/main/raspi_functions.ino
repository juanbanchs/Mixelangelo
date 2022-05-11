String wait_for_string()
{
  String receivedString = "4111222333150111222333150111222333150111222333150";
  Serial.print("String was received and reads: "); Serial.println(receivedString);
  return receivedString;
}
