	/**
		------ ------ ------ ------ ------ ------ DEFINES for library ------ ------ ------ ------ ------ ------ 
	*/
	#include "serialFeedback_EN.h"				// language file for serial feedback
	
	#define DEBUG_LVL					2		// Debug level: 0 - 3 | none - max
	#define SERIAL_SPEED				115200
	#define BOOTSTATISTICS				true
	

	// config 
	#define CFG_STORAGE					CLOUD	// CLOUD / SPIFSS / HYBRID
	#define INC_CONFIG 					true  	// include Config mode (Wifimanager!!!)
	#define CFG_AUTHENTICATE			false	// Set authentication | Default: admin - admin | Password can be changed when in config mode | max 16 char
	#define CFG_PAGE_INFO				true	// include the info page in Config mode
	#define CFG_PAGE_IAS 				true  	// include the IAS page in Config mode
	

	// Wifi defines
	#define SMARTCONFIG					false	// Set to true to enable smartconfig by smartphone app "ESP Smart Config" or "ESP8266 SmartConfig" | This will add (2%) of program storage space and 1%) of dynamic memory
	#define WIFI_MULTI					true	// false: only 1 ssid & pass will be used | true: 3 sets of ssid & pass will be used
	#define MAX_WIFI_RETRIES 			20		// sets the maximum number of retries when trying to connect to the wifi
	#define USEMDNS 					true  	// include MDNS responder http://yourboard.local
	#define DNS_PORT					53
	#define UDP_PORT      				514
	
	
	// OTA defines
	#define HTTPS         				true	// Use HTTPS for OTA updates
	#define SPIFFS_OTA					true	// Do you want to OTA update SPIFFS? | true / false
	#define NEXT_OTA					false	// Do you want to OTA update your Nextion display? | true / false

	
	// Nextion display defines
	#if defined  ESP8266
		#define NEXT_RES				5		// Nextion reset pin | Default 5 / D1 | Use this pin to control a transistor or relay to "hard" reset your display(power) after updates
		#define NEXT_RX					14		// Nextion RX pin | Default 14 / D5
		#define NEXT_TX					12		// Nextion TX pin | Default 12 / D6
		#define NEXT_BAUD				115200	// Nextion baudrate | 115200 / 57600
	#elif defined ESP32
		#define NEXT_RES				5		// Nextion reset pin | Default 5 / D1 | Use this pin to control a transistor or relay to "hard" reset your display(power) after updates
		#define NEXT_RX					16		// Nextion RX pin | Default 14 / D5
		#define NEXT_TX					17		// Nextion TX pin | Default 12 / D6
		#define NEXT_BAUD				115200	// Nextion baudrate | 115200 / 57600
	#endif
 
 
	// EERPOM & max nr of addable fields
	#if defined  ESP8266
		#define EEPROM_SIZE 			4096	// EEPROM_SIZE depending on device
		#define MAXNUMEXTRAFIELDS 		8		// wifimanger | max num of fields that can be added
	#elif defined ESP32
		#define EEPROM_SIZE		 		1984
		#define MAXNUMEXTRAFIELDS 		12
	#else
		#define EEPROM_SIZE 			1024
		#define MAXNUMEXTRAFIELDS 		8
	#endif

	#define MAGICBYTES    				"CFG" 
	#define MAGICEEP      				"%"
	#define MAGICBYTE     				85
	#define RTCMEMBEGIN   				68

	
	// length of config variables
	#define STRUCT_CHAR_ARRAY_SIZE  50
	#define STRUCT_PASSWORD_SIZE	64		// Thankyou reibuehl
	#define STRUCT_COMPDATE_SIZE    20
	#define STRUCT_BNAME_SIZE       30
	#define STRUCT_HOST_SIZE        24
	#define STRUCT_FILE_SIZE        31

	
	// constants used to define the status of the mode button based on the time it was pressed. (miliseconds)
	#define MODE_BUTTON_SHORT_PRESS       500
	#define MODE_BUTTON_LONG_PRESS        4000
	#define MODE_BUTTON_VERY_LONG_PRESS   10000
