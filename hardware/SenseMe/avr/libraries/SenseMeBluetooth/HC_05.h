/* Bluetooth HC_05 driver 
   \author: Venus Shum
*/

#include <Arduino.h>

#define BTSERIAL Serial1
#define sdelay	200


#define ATSETMASTER "AT+ROLE=1"
#define ATGETMODULENAME "AT+NAME?"
#define ATSETMODULENAME "AT+NAME="
#define ATGETVERSION "AT+VERSION?"

enum pairingMode {
	RANDOM,
	SPECIFIC
};

class HC_05 
{
public:
    HC_05(int cmdPin, int statePin, int resetPin, int enablePin);
	void begin(void);
	void start(void);
	void stop(void);
	void reset(void);
	void printVersion(void);
	void setCmdMode(int);
	void setModuleName(String name);
	void getModuleName();
	void getDeviceAddr();
	void setMaster();
	void setSlave();
	void setPairingMode(pairingMode mode);
	char readChar();
	void getDeviceList();
	void sendCommand(String);
private:
	bool cmdMode;
    int _cmdPin;
	int _resetPin;
    int _statePin;
	int _enablePin;
	int _bufsize;
    char _buffer[32];
	void cmdStart();
	void cmdEnd();
};

