// Print version of the BT module.
void BtPrintVersion()
{
  Serial1.begin(38400);
  BtSetCmdMode(1);
  Serial1.println("AT");
  Serial.println("AT");
  delay(ATdelay);
  Serial1.println("AT+VERSION?");
  Serial.println("AT+VERSION?");
  delay(1000);
  BtSetCmdMode(0); 
}

// Set the name of the BT module.
void BtSetModuleName(String name)
{
  Serial1.begin(38400);
  BtSetCmdMode(1);
  Serial1.println("AT");
  Serial.println("AT");
  delay(ATdelay);
  Serial1.print("AT+NAME=");
  Serial1.println(name);
  Serial.print("AT+NAME=");
  Serial.println(name);
  delay(1000);
  BtSetCmdMode(0); 
}

// Get the name of the BT module.
void BtGetModuleName()
{
  Serial1.begin(38400);
  BtSetCmdMode(1);
  Serial1.println("AT");
  Serial.println("AT");
  delay(ATdelay);
  Serial1.println("AT+NAME?");
  Serial.println("AT+NAME?");
  delay(1000);
  BtSetCmdMode(0); 
}

// Get the name of the BT module.
void BtGetDeviceAddr()
{
  Serial1.begin(38400);
  BtSetCmdMode(1);
  Serial1.println("AT");
  Serial.println("AT");
  delay(ATdelay);
  Serial.println("AT+ADDR?");
  Serial1.println("AT+ADDR?");
  delay(1000);
  BtSetCmdMode(0); 
}
