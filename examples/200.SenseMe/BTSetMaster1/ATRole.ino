#define SETMASTER "AT+ROLE=1"
// Set Master
void BTSetMaster()
{
  BtSendCommand(SETMASTER);
  //
}


