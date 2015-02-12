// Send AT command.
void BtSetCmdMode(int i_cmdMode = 1)
{
  //Serial.print("BtSetCmdMode ");    
  //Serial.println(i_cmdMode);    
  digitalWrite(gKeyPin, (1 == i_cmdMode) ? HIGH : LOW);
  //BtReset();
  Serial1.print("AT+RESET\r\n");
  //Serial1.begin((1 == i_cmdMode) ? 38400 : 57600);
  Serial1.begin((1 == i_cmdMode) ? 38400 : 9600);
}

// Reset the BT module over the reset pin.
void BtReset(void)
{
  //Serial.println("BtReset");    
  Serial1.flush();
  delay(200);
  // Using the reset pin
  digitalWrite(gResetPin, LOW);
  delay(2000);
  digitalWrite(gResetPin, HIGH);
  delay(500);
}

// Send the command to BT
void BtSendCommand(String command)
{
  Serial1.begin(38400);
  BtSetCmdMode(1);
  //Serial1.println("AT");
  //Serial.println("AT");
  //delay(ATdelay);
  Serial1.print(command+"\r\n");
  Serial.println(command);
  delay(retDelay);
  BtSetCmdMode(0); 
}
