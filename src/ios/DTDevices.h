#import <Foundation/Foundation.h>

//backward compatibility defines
#define buttonPressed lineaButtonPressed
#define buttonReleased lineaButtonReleased
#define btmSetEnabled btSetEnabled
#define btmGetEnabled btGetEnabled
#define btmWrite btWrite
#define btmRead btRead
#define btmReadLine btReadLine
#define btmGetLocalName btGetLocalName
#define prnDiscoverPrinters btDiscoverPrinters
#define prnDiscoverPrintersInBackground btDiscoverPrintersInBackground

#define barcodeEngineSetInitString barcodeOpticonSetInitString

#define msStartScan msEnable
#define msStopScan msDisable
#define setMSCardDataMode msSetCardDataMode
#define getMSCardDataMode msGetCardDataMode
#define startScan barcodeStartScan
#define stopScan barcodeStopScan
#define getScanTimeout barcodeGetScanTimeout
#define setScanTimeout barcodeSetScanTimeout
#define getScanButtonMode barcodeGetScanButtonMode
#define setScanButtonMode barcodeSetScanButtonMode
#define setScanBeep barcodeSetScanBeep
#define getScanMode barcodeGetScanMode
#define setScanMode barcodeSetScanMode
#define enableBarcode barcodeEnableBarcode
#define isBarcodeEnabled barcodeIsBarcodeEnabled
#define isBarcodeSupported barcodeIsBarcodeSupported
#define getBarcodeTypeMode barcodeGetTypeMode
#define setBarcodeTypeMode barcodeSetTypeMode

#define cryptoRawAuthenticateLinea cryptoRawAuthenticateDevice
#define cryptoRawAuthenticateiPod cryptoRawAuthenticateHost
#define cryptoAuthenticateLinea cryptoAuthenticateDevice
#define cryptoAuthenticateiPod cryptoAuthenticateHost

#define btConnectPrinter btConnectSupportedDevice

/**
 * Device type
 */
typedef enum {
    /**
     Linea Pro 1,2,3,4,4s, LineaTab
     */
	DEVICE_TYPE_LINEA=0,
    /**
     Any of the supported printers - PP-60, DPP-250, DPP-350, DPP-450
     */
	DEVICE_TYPE_PRINTER,
    /**
     Any of the supported pinpads - MPED-400, PPAD1
     */
	DEVICE_TYPE_PINPAD,
    /**
     Transport device for connecting to other devices via bluetooth
     */
    DEVICE_TYPE_ISERIAL,
}SUPPORTED_DEVICE_TYPES;

#ifndef STRUCTURES_DEFINED
#define STRUCTURES_DEFINED
typedef enum {
	BAR_ALL=0, 
	BAR_UPC,
	BAR_CODABAR,
	BAR_CODE25_NI2OF5,
	BAR_CODE25_I2OF5,
	BAR_CODE39,
	BAR_CODE93,
	BAR_CODE128,
	BAR_CODE11,
	BAR_CPCBINARY,
	BAR_DUN14,
	BAR_EAN2,
	BAR_EAN5,
	BAR_EAN8,
	BAR_EAN13,
	BAR_EAN128,
	BAR_GS1DATABAR,
	BAR_ITF14,
	BAR_LATENT_IMAGE,
	BAR_PHARMACODE,
	BAR_PLANET,
	BAR_POSTNET,
	BAR_INTELLIGENT_MAIL,
	BAR_MSI,
	BAR_POSTBAR,
	BAR_RM4SCC,
	BAR_TELEPEN,
	BAR_PLESSEY,
	BAR_PDF417,
	BAR_MICROPDF417,
	BAR_DATAMATRIX,
	BAR_AZTEK,
	BAR_QRCODE,
	BAR_MAXICODE,
	BAR_LAST
}BARCODES;

typedef enum {
	BAR_EX_ALL=0, 
	BAR_EX_UPCA,
	BAR_EX_CODABAR,
	BAR_EX_CODE25_NI2OF5,
	BAR_EX_CODE25_I2OF5,
	BAR_EX_CODE39,
	BAR_EX_CODE93,
	BAR_EX_CODE128,
	BAR_EX_CODE11,
	BAR_EX_CPCBINARY,
	BAR_EX_DUN14,
	BAR_EX_EAN2,
	BAR_EX_EAN5,
	BAR_EX_EAN8,
	BAR_EX_EAN13,
	BAR_EX_EAN128,
	BAR_EX_GS1DATABAR,
	BAR_EX_ITF14,
	BAR_EX_LATENT_IMAGE,
	BAR_EX_PHARMACODE,
	BAR_EX_PLANET,
	BAR_EX_POSTNET,
	BAR_EX_INTELLIGENT_MAIL,
	BAR_EX_MSI_PLESSEY,
	BAR_EX_POSTBAR,
	BAR_EX_RM4SCC,
	BAR_EX_TELEPEN,
	BAR_EX_UK_PLESSEY,
	BAR_EX_PDF417,
	BAR_EX_MICROPDF417,
	BAR_EX_DATAMATRIX,
	BAR_EX_AZTEK,
	BAR_EX_QRCODE,
	BAR_EX_MAXICODE,
	BAR_EX_RESERVED1,
	BAR_EX_RESERVED2,
	BAR_EX_RESERVED3,
	BAR_EX_RESERVED4,
	BAR_EX_RESERVED5,
	BAR_EX_UPCA_2,
	BAR_EX_UPCA_5,
	BAR_EX_UPCE,
	BAR_EX_UPCE_2,
	BAR_EX_UPCE_5,
	BAR_EX_EAN13_2,
	BAR_EX_EAN13_5,
	BAR_EX_EAN8_2,
	BAR_EX_EAN8_5,
	BAR_EX_CODE39_FULL,
	BAR_EX_ITA_PHARMA,
	BAR_EX_CODABAR_ABC,
	BAR_EX_CODABAR_CX,
	BAR_EX_SCODE,
	BAR_EX_MATRIX_2OF5,
	BAR_EX_IATA,
	BAR_EX_KOREAN_POSTAL,
	BAR_EX_CCA,
	BAR_EX_CCB,
	BAR_EX_CCC,
	BAR_EX_LAST
}BARCODES_EX;

/**
 * Connection state
 */
typedef enum {
    /**
     Device is disconnected, no automatic connection attempts will be made
     */
	CONN_DISCONNECTED=0,
    /**
     The SDK is trying to connect to the device
     */
	CONN_CONNECTING,
    /**
     Device is connected
     */
	CONN_CONNECTED
}CONN_STATES;

/**
 Filtering bluetooth devices to discover
 */
typedef enum {
    /**
     Include all supported devices (default)
     */
	BLUETOOTH_FILTER_ALL=-1,
    /**
     Include supported printers
     */
	BLUETOOTH_FILTER_PRINTERS=1,
    /**
     Include supported pinpads
     */
	BLUETOOTH_FILTER_PINPADS=2,
    /**
     Include supported barcode scanners
     */
	BLUETOOTH_FILTER_BARCODE_SCANNERS=4,
}BLUETOOTH_FILTER;

/**
 Barcode scan modes
 */
typedef enum {
    /**
     The scan will be terminated after successful barcode recognition (default)
     */
	MODE_SINGLE_SCAN=0,
    /**
     Scanning will continue unless either scan button is releasd, or stop scan function is called
     */
	MODE_MULTI_SCAN,
    /**
     For as long as scan button is pressed or stop scan is not called the engine will operate in low power scan mode trying to detect objects entering the area, then will turn on the lights and try to read the barcode. Supported only on Code engine.
     */
	MODE_MOTION_DETECT,
    /**
     Pressing the button/start scan will enter aim mode, while a barcode scan will actually be performed upon button release/stop scan.
     */
	MODE_SINGLE_SCAN_RELEASE,
    /**
     Same as multi scan mode, but allowing no duplicate barcodes to be scanned
     */
	MODE_MULTI_SCAN_NO_DUPLICATES,
}SCAN_MODES;

/**
 Button modes
 */
typedef enum {
    /**
     Button is disabled
     */
	BUTTON_DISABLED=0,
    /**
     Button is enabled (default)
     */
	BUTTON_ENABLED
}BUTTON_STATES;

/**
 Card data mode
 */
typedef enum {
    /**
     Card data is processed and tracks are extracted (default)
     */
	MS_PROCESSED_CARD_DATA=0,
    /**
     Card data will be returned as RAW sequence of bits
     */
	MS_RAW_CARD_DATA=1,
    /**
     Card data will be returned as processed, but only track 2 will be read
     */
	MS_PROCESSED_TRACK2_DATA=3,
}MS_MODES;

/**
 The way to return barcode types
 */
typedef enum {
    /**
     Barcode types are returned from the BAR_* list (default)
     */
	BARCODE_TYPE_DEFAULT=0,
    /**
     Barcode types are returned from the extended barcode list - BAR_EX_*
     */
	BARCODE_TYPE_EXTENDED,
    /**
     Barcode types are returned as ISO 15424 format
     */
    BARCODE_TYPE_ISO15424
}BT_MODES;

/**
 Firmware update phases
 */
typedef enum {
    /**
     Initializing update
     */
	UPDATE_INIT=0,
    /**
     Erasing old firmware/preparing memory
     */
	UPDATE_ERASE,
    /**
     Writing data
     */
    UPDATE_WRITE,
    /**
     Update complete, this is the final phase
     */
    UPDATE_FINISH,
    /**
     Post-update operations
     */
    UPDATE_COMPLETING
}UPDATE_PHASES;

/**
 AES 256 encryption algorithm
 */
#define ALG_AES256		0
/**
 Encrypted Head ECC encryption algorithm
 */
#define ALG_EH_ECC      1
/**
 Encrypted Head AES256 encryption algorithm. Encryption type is CBC.
 After decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Processed track data in the format: 0xF1 (track1 data), 0xF2 (track2 data) 0xF3 (track3 data). It is possible some of the tracks will be empty, then the identifier will not be present too, for example 0xF1 (track1 data) 0xF3 (track3 data)
 - End of track data (byte 0x00)
 - CRC16CCIT (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data (including the 0x00 byte).
 The data block is rounded to 16 bytes
 */
#define ALG_EH_AES256   2
/**
 Encrypted Head IDTECH encryption algorithm, please refer to IDTECH documentation for detailed format and examples.
 Data, that is received via magneticCardEncryptedData has the following format:
 - (1 byte) card encoding type, can ignore
 - (1 byte) bits marking which track is present
 - (1 byte) track 1 UNENCRYPTED length
 - (1 byte) track 2 UNENCRYPTED length
 - (1 byte) track 3 UNENCRYPTED length
 - (track 1 UNENCRYPTED length bytes) track 1 masked data
 - (track 2 UNENCRYPTED length bytes) track 2 masked data
 - (track 3 UNENCRYPTED length bytes) track 3 masked data
 - (variable bytes) Track 1 + Track 2 encrypted data, the length of this block is calculated by substracting from the end
 - (20 bytes) track 1 sha1
 - (20 bytes) track 2 sha1
 - (10 bytes) KSN
 
 Encrypted block contents after decryption (3DES):
 - (track 1 UNENCRYPTED length bytes) track 1 data
 - (track 2 UNENCRYPTED length bytes) track 2 data
 */
#define ALG_EH_IDTECH   3
/**
 Encrypted Head MAGTEK encryption algorithm
 */
#define ALG_EH_MAGTEK   4
/**
 Encrypted Head 3DES encryption algorithm
 */
#define ALG_EH_3DES   5
/**
 Encrypted Head RSA encryption algorithm
 */
#define ALG_EH_RSA_OAEP   6
/**
 Pinpad 3DES format, containing:
 - random data (4 bytes)
 - unique ID (4 bytes) - same ID you have sent to the function
 - payload length (2 bytes) - length of the TLV block in BIG ENDIAN
 - card data (variable, ends with 0x00), in format 0xF1 <track1> 0xF2 <track3> 0xF3 <track3> (some tracks might me missing, in this case indentifier is missing too)
 - crc (2 bytes) - CRC16 CCIT on all the bytes before it
 - padding (0-7 bytes) zeroes to pad the packet with
 */
#define ALG_PPAD_3DES_CBC   7
/**
 Encrypted Head Voltage encryption algorithm.
 The current voltage data encryption follows the format described in page 2-20 in voltage documentation, without checksum, i.e. the packet is formed as:
 _aFLAGS|[PAN]|[MID]|[TRACK1]| [TRACK2]| [TRACK3]|[EXP]|[APP]|ETB~
 
 Parameters must be supplied with this algorithm. The only mandatory parameter is @"encryption", which can be @"SPE" - structure preserving or @"FULL" - full track encryption.
 Optional ones are
 @"merchantID" - a number they will receive in the packet back encrypted
 @"appData" - custom string that will be attached to the packet untouched
 */
#define ALG_EH_VOLTAGE   8
/**
 Encrypted Head AES128 encryption algorithm. Encryption type is CBC.
 After decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Processed track data in the format: 0xF1 (track1 data), 0xF2 (track2 data) 0xF3 (track3 data). It is possible some of the tracks will be empty, then the identifier will not be present too, for example 0xF1 (track1 data) 0xF3 (track3 data)
 - End of track data (byte 0x00)
 - CRC16CCIT (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data (including the 0x00 byte).
 The data block is rounded to 16 bytes
 */
#define ALG_EH_AES128   9

/**
 Full track encryption, refer to Voltage documentation for more details
 */
#define VOLTAGE_ENCRYPTION_FULL 0
/**
 Structure preserving encryption (SPE), refer to Voltage documentation for more details
 */
#define VOLTAGE_ENCRYPTION_SPE 1


#define KEY_ENCRYPTION KEY_EH_AES256_ENCRYPTION1
#define KEY_EH_DUKPT_MASTER KEY_EH_DUKPT_MASTER1

/**
 Authentication key
 */
#define KEY_AUTHENTICATION 0x00

/**
 Encrypted head key loading(encryption) key (KEK), used to load other keys with
 */
#define KEY_EH_AES256_LOADING 0x02

/**
 Encrypted head AES256 Data encryption key 1
 */
#define KEY_EH_AES256_ENCRYPTION1 0x01
/**
 Encrypted head AES256 Data encryption key 2 (present on EMSR firmware version 2.30 and above)
 */
#define KEY_EH_AES256_ENCRYPTION2 0x03
/**
 Encrypted head AES256 Data encryption key 3 (present on EMSR firmware version 2.30 and above)
 */
#define KEY_EH_AES256_ENCRYPTION3 0x04


/**
 Encrypted head AES128 Data encryption key 1 (present on EMSR firmware version 2.30 and above)
 */
#define KEY_EH_AES128_ENCRYPTION1 0x09
/**
 Encrypted head AES128 Data encryption key 2 (present on EMSR firmware version 2.30 and above)
 */
#define KEY_EH_AES128_ENCRYPTION2 0x0B
/**
 Encrypted head AES128 Data encryption key 3 (present on EMSR firmware version 2.30 and above)
 */
#define KEY_EH_AES128_ENCRYPTION3 0x0C


/**
 Encrypted head TMK key
 */
#define KEY_EH_TMK_AES 0x10

/**
 Encrypted head 3DES DUKPT data encryption key 1
 */
#define KEY_EH_DUKPT_MASTER1 0x20
/**
 Encrypted head 3DES DUKPT data encryption key 2 (present on EMSR firmware version 2.30 and above)
 */
#define KEY_EH_DUKPT_MASTER2 0x21
/**
 Encrypted head 3DES DUKPT data encryption key 3 (present on EMSR firmware version 2.30 and above)
 */
#define KEY_EH_DUKPT_MASTER3 0x22

/**
 This flag locks barcode, magnetic card and bluetooth usage, so it will be possible to use them only after authenticating
 */
#define KEY_AUTH_FLAG_LOCK 1


/**
 In the case where the AES256 key can be disabled to return the devce to plain text (LP without encrypted head), loading this key will remove it
 */
extern const uint8_t KEY_AES256_EMPTY[32];

/**
 PIN encryption format
 */
typedef enum {
    /**
     PIN will be formatted, according to ISO 9564-0
     */
	PIN_FORMAT_ISO0=0x04,
    /**
     PIN will be formatted, according to ISO 9564-1
     */
	PIN_FORMAT_ISO1=0x05,
    /**
     PIN will be formatted, according to ISO 9564-3
     */
	PIN_FORMAT_ISO3=0x0D,
}PIN_ENCRYPTION_FORMATS;

typedef enum {
	TYPE_ICC=0,
	TYPE_PIN,
}ICC_TYPES;

typedef enum {
	KEY_ISSUER=0,
	KEY_ICC,
}RSA_VERIFY_KEY;

/**
 Smartcard slot types
 */
typedef enum
{
    /**
     Main slot, normal smartcard
     */
	SLOT_MAIN=0,
    /**
     SAM slot
     */
	SLOT_SAM,
}SC_SLOTS;

/**
 RF card types
 */
typedef enum
{
    /**
     Unknown card
     */
	CARD_UNKNOWN=0,
    /**
     Mifare Mini
     */
	CARD_MIFARE_MINI,
    /**
     Mifare Classic 1K
     */
	CARD_MIFARE_CLASSIC_1K,
    /**
     Mifare Classic 4K
     */
	CARD_MIFARE_CLASSIC_4K,
    /**
     Mifare Ultralight
     */
	CARD_MIFARE_ULTRALIGHT,
    /**
     Mifare Ultralight C
     */
	CARD_MIFARE_ULTRALIGHT_C,
    /**
     ISO 14443A
     */
	CARD_ISO14443A,
    /**
     Mifare Plus
     */
	CARD_MIFARE_PLUS,
    /**
     ISO 15693
     */
	CARD_ISO15693,
    /**
     Mifare Desfire
     */
	CARD_MIFARE_DESFIRE,
    /**
     ISO 14443B
     */
	CARD_ISO14443B,
    /**
     FeliCa
     */
	CARD_FELICA,
    /**
     ST SRI
     */
	CARD_ST_SRI,
    /**
     NFC Payment
     */
	CARD_PAYMENT,
    /**
     PicoPass 15693
     */
	CARD_PICOPASS_15693,
    /**
     PicoPass 14443-B
     */
	CARD_PICOPASS_14443B,
}RF_CARD_TYPES;

/**
 FeliCa SmartTag battery status
 */
typedef enum
{
    /**
     Normal, card can be used
     */
	FELICA_SMARTTAG_BATTERY_NORMAL1=0,
    /**
     Normal, card can be used
     */
	FELICA_SMARTTAG_BATTERY_NORMAL2,
    /**
     Low, consider replacing
     */
    FELICA_SMARTTAG_BATTERY_LOW1,
    /**
     Very Low, replace it
     */
    FELICA_SMARTTAG_BATTERY_LOW2,
}FELICA_SMARTTAG_BATERY_STATUSES;

/**
 FeliCa SmartTag draw mode
 */
typedef enum
{
    /**
     The area outside of the image will be emptied
     */
	FELICA_SMARTTAG_DRAW_WHITE_BACKGROUND=0,
    /**
     The area outside of the image will be shown black
     */
	FELICA_SMARTTAG_DRAW_BLACK_BACKGROUND,
    /**
     The area outside of the image will be kept to its current state
     */
    FELICA_SMARTTAG_DRAW_KEEP_BACKGROUND,
    /**
     The area outside of the image will be drawn using one of the previously stored layouts
     */
    FELICA_SMARTTAG_DRAW_USE_LAYOUT
}FELICA_SMARTTAG_DRAW_MODES;

/**
 RF card type, one of the CARD_* constants
 */
extern NSString * const RFCardInfoType;
/**
 RF card type as string, useful for display purposes
 */
extern NSString * const RFCardInfoTypeStr;
/**
 RF card unique identifier, if any
 */
extern NSString * const RFCardInfoUID;
/**
 Mifare card ATQA
 */
extern NSString * const RFCardInfoATQA;
/**
 Mifare card SAK
 */
extern NSString * const RFCardInfoSAK;
/**
 ISO15693 card AFI
 */
extern NSString * const RFCardInfoAFI;
/**
 ISO15693 card DSFID
 */
extern NSString * const RFCardInfoDSFID;
/**
 ISO15693 card block size
 */
extern NSString * const RFCardInfoBlockSize;
/**
 ISO15693 card number of blocks
 */
extern NSString * const RFCardInfoNBlocks;


/**
 Device name as string, for example "Linea"
 */
extern NSString * const InfoDeviceName;
/**
 Device model, if any, for example "XAMBL"
 */
extern NSString * const InfoDeviceModel;
/**
 Firmware revision as string, for example 2.41
 */
extern NSString * const InfoFirmwareRevision;
/**
 Firmware revision as number, useful for comparison, for example 241
 */
extern NSString * const InfoFirmwareRevisionNumber;

/**
 Different features supported by the device.
 */
typedef enum
{
    /**
     Magnetic stripe reader, one of MSR_* constants
     */
    FEAT_MSR,
    /**
     Barcode reader, one of the BARCODE_* constants
     */
    FEAT_BARCODE,
    /**
     Bluetooth module, one of the BLUETOOTH_* constants
     */
    FEAT_BLUETOOTH,
    /**
     Using device's internal battery to charge the host battery, an external battery of sorts
     */
    FEAT_BATTERY_CHARGING,
    /**
     External serial port, used to connect to external devices
     */
    FEAT_EXTERNAL_SERIAL_PORT,
    /**
     RF cards reader (Mifare, ISO15, NFC, etc)
     */
    FEAT_RF_READER,
    /**
     Printing support
     */
    FEAT_PRINTING,
    /**
     Smarcard module
     */
    FEAT_SMARTCARD,
    /**
     PIN entry capability
     */
    FEAT_PIN_ENTRY,
    /**
     EMV Level 2 Kernel
     */
    FEAT_EMVL2_KERNEL,
    /**
     Vibration supported
     */
    FEAT_VIBRATION,
    /**
     Program controllable LEDs
     */
    FEAT_LEDS,
    /**
     External speaker
     */
    FEAT_SPEAKER,
    /**
     iClass HID support
     */
    FEAT_HID,
    /**
     Last feature
     */
    FEAT_MAX
}FEATURES;

/**
 The feature is not present in the connected device(s)
 */
#define FEAT_UNSUPPORTED 0
/**
 The feature is present in the connected device(s)
 */
#define FEAT_SUPPORTED 1

/**
 Magnetic stripe reader types
 */
typedef enum
{
    /**
     Unencrypted magnetic card reader with no possible data encryption
     */
    MSR_PLAIN=1,
    /**
     Unencrypted magnetic card reader, but featuring in-device data encryption
     */
    MSR_PLAIN_WITH_ENCRYPTION=2,
    /**
     Encrypted magnetic head, no undencrypted data leaves the head
     */
    MSR_ENCRYPTED=4,
    /**
     Voltage support
     */
    MSR_VOLTAGE=8,
    /**
     Emulated encrypted magnetic head, no undencrypted data leaves the head
     */
    MSR_ENCRYPTED_EMUL=16,
}FEAT_MSRS;

/**
 Barcode module types
 */
typedef enum
{
    /**
     Opticon barcode engine
     */
    BARCODE_OPTICON=1,
    /**
     Code barcode engine
     */
    BARCODE_CODE=2,
    /**
     Newland barcode engine
     */
    BARCODE_NEWLAND=3,
    /**
     Intermec barcode engine
     */
    BARCODE_INTERMEC=4,
}FEAT_BARCODES;

/**
 Bluetooth module types
 */
typedef enum
{
    /**
     Bluetooth module can act as a client to connect to remote devices
     */
    BLUETOOTH_CLIENT=1,
    /**
     Bluetooth module can accept incoming connections
     */
    BLUETOOTH_HOST=2,
}FEAT_BLUETOOTHS;


/**
 Information about connected Pinpad
 */
@interface DTPinpadInfo : NSObject
/**
 Unique CPU serial number
 */
@property (copy) NSData *cpuSerial;
/**
 CPU version
 */
@property (assign) uint32_t cpuVersion;
/**
 CPU loader version
 */
@property (assign) uint32_t cpuLoaderVersion;
/**
 HAL version
 */
@property (assign) uint32_t cpuHALVersion;
/**
 PinPad serial number
 */
@property (copy) NSData *pinpadSerial;
/**
 Loader name
 */
@property (copy) NSString *loaderName;
/**
 Loader version
 */
@property (assign) uint32_t loaderVersion;
/**
 Firmware name
 */
@property (copy) NSString *fwName;
/**
 Firmware version
 */
@property (assign) uint32_t fwVersion;
@end

/**
 Information about RF card
 */
@interface DTRFCardInfo : NSObject
/**
 RF card type, one of the CARD_* constants
 */
@property (assign) int type;
/**
 RF card type as string, useful for display purposes
 */
@property (copy) NSString *typeStr;
/**
 RF card unique identifier, if any
 */
@property (copy) NSData *UID;
/**
 Mifare card ATQA
 */
@property (assign) int ATQA;
/**
 Mifare card SAK
 */
@property (assign) int SAK;
/**
 ISO15693 card AFI
 */
@property (assign) int AFI;
/**
 ISO15693 card DSFID
 */
@property (assign) int DSFID;
/**
 ISO15693 card block size
 */
@property (assign) int blockSize;
/**
 ISO15693 card number of blocks
 */
@property (assign) int nBlocks;
@end


// Barcode Printing Types
/**
 Prints UPC-A barcode
 */
#define BAR_PRN_UPCA		0
/**
 Prints UPC-E barcode
 */
#define BAR_PRN_UPCE		1
/**
 Prints EAN-13 barcode
 */
#define BAR_PRN_EAN13		2
/**
 Prints EAN-8 barcode
 */
#define BAR_PRN_EAN8		3
/**
 Prints CODE39 barcode
 */
#define BAR_PRN_CODE39		4
/**
 Prints ITF barcode
 */
#define BAR_PRN_ITF			5
/**
 Prints CODABAR barcode
 */
#define BAR_PRN_CODABAR		6
/**
 Prints CODE93 barcode
 */
#define BAR_PRN_CODE93		7
/**
 Prints CODE128 barcode
 */
#define BAR_PRN_CODE128		8
/**
 Prints 2D PDF-417 barcode
 */
#define BAR_PRN_PDF417		9
/**
 Prints CODE128 optimized barcode. Supported only on DPP-350 and DPP-250 printers, it makes the barcode lot smaller especially when numbers only are used
 */
#define BAR_PRN_CODE128AUTO	10
/**
 Prints EAN128 optimized barcode. Supported only on DPP-350 and DPP-250 printers, it makes the barcode lot smaller especially when numbers only are used
 */
#define BAR_PRN_EAN128AUTO	11

// Barcode Text Positopn
#define BAR_TEXT_NONE		0
#define BAR_TEXT_ABOVE		1
#define BAR_TEXT_BELOW		2
#define BAR_TEXT_BOTH		3

/* Align Flags */
#define ALIGN_LEFT				0
#define ALIGN_CENTER			1
#define ALIGN_RIGHT				2
#define ALIGN_JUSTIFY			3

#define TEXT_WORDWRAP			1

#define TEXT_ROTATE_0			0
#define TEXT_ROTATE_90			1
#define TEXT_ROTATE_180			2

#define LINESPACE_DEFAULT		0x22

#define BLACKMARK_TRESHOLD_DEFAULT	0x68

/* Table Flags */
#define TABLE_BORDERS_HORIZONTAL	1
#define TABLE_BORDERS_VERTICAL		2
#define TABLE_COLUMN_COMPACT		4

/**
 Horizontal printing, starting from the top-left, continuing to the right. Newline goes down
 */
#define PAGE_HORIZONTAL_TOPLEFT		0
/**
 Vertical printing, starting from bottom-left, going upwards, newline goes right
 */
#define PAGE_VERTICAL_BOTTOMLEFT	1
/**
 Horizontal printing, starting from the bottom-right, continuing to the left. Newline goes up
 */
#define PAGE_HORIZONTAL_BOTTOMRIGHT	2
/**
 Vertical printing, starting from top-right, going downwards, newline goes left
 */
#define PAGE_VERTICAL_TOPRIGHT		3


/*******************************************************************************
 printLogo function constants
 *******************************************************************************/
/**
 Prints the logo at 203x203 DPI
 */
#define LOGO_NORMAL			0
/**
 Prints the logo at 101x203 DPI
 */
#define LOGO_DOUBLEWIDTH	1
/**
 Prints the logo at 203x101 DPI
 */
#define LOGO_DOUBLEHEIGHT	2
/**
 Prints the logo at 101x101 DPI
 */
#define LOGO_DWDH			3

/**
 Animations, that the connected device can play
 */
typedef enum
{
    /**
     All animations, used only when stopping them
     */
    ANIM_ALL=-1,
    /**
     Insert card animation (MPED400)
     */
	ANIM_INSERT_CARD=0,
    /**
     Remove card animation (MPED400)
     */
	ANIM_REMOVE_CARD,
    /**
     Busy animation (MPED400,PPAD1)
     */
	ANIM_BUSY,
    /**
     Water drop animation (MPED400,PPAD1)
     */
	ANIM_DROP,
    /**
     Insert smartcard animation (PPAD1)
     */
	ANIM_INSERT_SMARTCARD,
    /*
     Inser magnetic card animation (PPAD1)
     */
	ANIM_INSERT_MAGNETIC_CARD,
}ANIMATIONS;

/**
 Languages to be used with some pinpad functions, like the manual magnetic card entry
 */
typedef enum {
    /**
     English
     */
	LANG_ENGLISH=0,
    /**
     Bulgarian
     */
	LANG_BULGARIAN,
    /**
     Spanish
     */
	LANG_ESPANIOL,
    /**
     Russian
     */
	LANG_RUSSIAN,
    /**
     Romanian
     */
	LANG_ROMANIAN,
    /**
     French
     */
	LANG_FRENCH,
    /**
     Finish
     */
	LANG_FINISH,
    /**
     Swedish
     */
	LANG_SWEDISH,
}LANGUAGES;

/**
 Specific codepages, that can be used with uiDrawText function
 */
typedef enum
{
    /**
     ISO 8859-1: Western Europe and Americas: Afrikaans, Basque, Catalan, Danish, Dutch, English, Faeroese, Finnish, French, Galician, German, Icelandic, Irish, Italian, Norwegian, Portuguese, Spanish and Swedish.
     */
	CP_ISO8859_1_LATIN1=0,
    /**
     ISO 8859-2: Latin-written Slavic and Central European languages: Czech, German, Hungarian, Polish, Romanian, Croatian, Slovak, Slovene.
     */
	CP_ISO8859_2_LATIN2,
    /**
     ISO 8859-3: Esperanto, Galician, Maltese, and Turkish.
     */
	CP_ISO8859_3_LATIN3,
    /**
     ISO 8859-4: Scandinavia/Baltic (mostly covered by 8859-1 also): Estonian, Latvian, and Lithuanian. It is an incomplete predecessor of Latin 6.
     */
	CP_ISO8859_4_LATIN4,
    /**
     ISO 8859-5: Bulgarian, Byelorussian, Macedonian, Russian, Serbian and Ukrainian.
     */
	CP_ISO8859_5_CYRILLIC,
    /**
     ISO 8859-6: Non-accented Arabic.
     */
	CP_ISO8859_6_ARABIC,
    /**
     ISO 8859-7: Greek.
     */
	CP_ISO8859_7_GREEK,
    /**
     ISO 8859-8: Non-accented Hebrew.
     */
	CP_ISO8859_8_HEBREW,
    /**
     ISO 8859-9: Same as 8859-1 except for Turkish instead of Icelandic
     */
	CP_ISO8859_9_LATIN5,
    /**
     ISO 8859-10: Latin6, for Lappish/Nordic/Eskimo languages: Adds the last Inuit (Greenlandic) and Sami (Lappish) letters that were missing in Latin 4 to cover the entire Nordic area.
     */
	CP_ISO8859_10_LATIN6,
}CODEPAGES;

/**
 Display fonts
 */
typedef enum
{
    /**
     6x8 pixels
     */
	FONT_6X8=0,
    /**
     8x16 pixels
     */
	FONT_8X16,
    /**
     4x6 pixels (not all symbols could be displayed using this font, best suited for numbers)
     */
	FONT_4X6,
}FONTS;

/**
 Special color that inverts the underlying colors
 */
#define COLOR_INVERT nil

/** @defgroup G_ERRORS Library Error Codes
 Library error codes returned in the NSError objects
 @{
 */

#ifndef Library_Errors_h
#define Library_Errors_h

/** Operation successful. */
#define DT_ENONE 0
/** General error / Unknown error. */
#define DT_EGENERAL -1
/** Create error. */
#define DT_ECREATE -2
/** Open error. */
#define DT_EOPEN -3
/** Close error. */
#define DT_ECLOSE -4
/** Device or resource busy. */
#define DT_EBUSY -5
/** Timeout expired. */
#define DT_ETIMEOUT -6
/** Unsupported method or operation. */
#define DT_ENOSUPPORTED -7
/** Memory allocation error. */
#define DT_EMEMORY -8
/** Invalid parameter. */
#define DT_EPARAM -9
/** Input/Output error. */
#define DT_EIO -10
/** CRC error. */
#define DT_ECRC -11
/** Flash error. */
#define DT_EFLASH -12
/** EEPROM error. */
#define DT_EEEPROM -13
/** Device error. */
#define DT_EDEVICE -14
/** The operation is not implemented. */
#define DT_ENOIMPLEMENTED -15
/** The device or resource does not exists. */
#define DT_ENOEXIST -16
/** Invalid command. */
#define DT_EINVALID_CMD -17
/** Not exist object. */
#define DT_ENOT_EXIST_OBJECT -18
/** No more items. */
#define DT_ENOMORE -19
/** Command Failed */
#define DT_EFAILED -20
/** Invalid command */
#define DT_EINVALID -21
/** Not registered */
#define DT_ENOT_REGISTERED -22
/** Permission denied */
#define DT_EPERMISSION_DENIED -23

/** Mifare operation successful. */
#define DT_MIFARE_EBASE -10000
/** Mifare timeout error. */
#define DT_MIFARE_ETIMEOUT DT_MIFARE_EBASE-1
/** Mifare collision error. */
#define DT_MIFARE_ECOLLISION DT_MIFARE_EBASE-2
/** Mifare parity error. */
#define DT_MIFARE_EPARITY DT_MIFARE_EBASE-3
/** Mifare frame error. */
#define DT_MIFARE_EFRAME DT_MIFARE_EBASE-4
/** Mifare CRC error. */
#define DT_MIFARE_ECRC DT_MIFARE_EBASE-5
/** Mifare FIFO overflow. */
#define DT_MIFARE_EFIFO DT_MIFARE_EBASE-6
/** Mifare EEPROM error. */
#define DT_MIFARE_EEEPROM DT_MIFARE_EBASE-7
/** Mifare invalid key. */
#define DT_MIFARE_EKEY DT_MIFARE_EBASE-8
/** Mifare generic error. */
#define DT_MIFARE_EGENERIC DT_MIFARE_EBASE-9
/** Mifare authentication error. */
#define DT_MIFARE_EAUTHENTICATION DT_MIFARE_EBASE-10
/** Mifare code error. */
#define DT_MIFARE_ECODE DT_MIFARE_EBASE-11
/** Mifare bit count error. */
#define DT_MIFARE_EBIT DT_MIFARE_EBASE-12
/** Mifare access error. */
#define DT_MIFARE_EACCESS DT_MIFARE_EBASE-13
/** Mifare value error. */
#define DT_MIFARE_EVALUE DT_MIFARE_EBASE-14


// Encrypted magnetic head codes
/** EMS base value */
#define DT_EMSR_EBASE -11000
/** Encrypted magnetic head invalid command sent. */
#define DT_EMSR_EINVALID_COMMAND DT_EMSR_EBASE-0x01
/** Encrypted magnetic head no permission error. */
#define DT_EMSR_ENO_PERMISSION DT_EMSR_EBASE-0x02
/** Encrypted magnetic head card error. */
#define DT_EMSR_ECARD DT_EMSR_EBASE-0x03
/** Encrypted magnetic head command syntax error. */
#define DT_EMSR_ESYNTAX DT_EMSR_EBASE-0x04
/** Encrypted magnetic head command no response from the magnetic chip. */
#define DT_EMSR_ENO_RESPONSE DT_EMSR_EBASE-0x05
/** Encrypted magnetic head no data available. */
#define DT_EMSR_ENO_DATA DT_EMSR_EBASE-0x06
/** Encrypted magnetic head invalid data length. */
#define DT_EMSR_EINVALID_LENGTH DT_EMSR_EBASE-0x14
/** Encrypted magnetic head is tampered. */
#define DT_EMSR_ETAMPERED DT_EMSR_EBASE-0x15
/** Encrypted magnetic head invalid signature. */
#define DT_EMSR_EINVALID_SIGNATURE DT_EMSR_EBASE-0x16
/** Encrypted magnetic head hardware failure. */
#define DT_EMSR_EHARDWARE DT_EMSR_EBASE-0x17

/**
 Pinpad base value
 */
#define DT_PPAD_EBASE -16500
/**
 Generic error
 */
#define DT_PPAD_EGENERAL DT_PPAD_EBASE-1
/**
 Invalid command or subcommand code
 */
#define DT_PPAD_EINVALID_COMMAND DT_PPAD_EBASE-2
/**
 Invalid paremeter
 */
#define DT_PPAD_EINVALID_PARAMETER DT_PPAD_EBASE-3
/**
 Address is outside limits
 */
#define DT_PPAD_EINVALID_ADDRESS DT_PPAD_EBASE-4
/**
 Value is outside limits
 */
#define DT_PPAD_EINVALID_VALUE DT_PPAD_EBASE-5
/**
 Length is outside limits
 */
#define DT_PPAD_EINVALID_LENGTH DT_PPAD_EBASE-6
/**
 The action is not permitted in current state
 */
#define DT_PPAD_ENO_PERMISSION DT_PPAD_EBASE-7
/**
 There is no data to be returned
 */
#define DT_PPAD_ENO_DATA DT_PPAD_EBASE-8
/**
 Timeout occured
 */
#define DT_PPAD_ETIMEOUT DT_PPAD_EBASE-9
/**
 Invalid key number
 */
#define DT_PPAD_EINVALID_KEY_NUMBER DT_PPAD_EBASE-10
/**
 Invalid key attributes (usage)
 */
#define DT_PPAD_EINVALID_KEY_ATTRIBUTES DT_PPAD_EBASE-11
/**
 Calling of non-existing device
 */
#define DT_PPAD_EINVALID_DEVICE DT_PPAD_EBASE-12
/**
 (not used in this FW version)
 */
#define DT_PPAD_ENOT_SUPPORTED DT_PPAD_EBASE-13
/**
 Pin entering limit exceed
 */
#define DT_PPAD_EPIN_LIMIT_EXCEEDED DT_PPAD_EBASE-14
/**
 Error in flash commands
 */
#define DT_PPAD_EFLASH DT_PPAD_EBASE-15
/**
 Hardware error
 */
#define DT_PPAD_EHARDWARE DT_PPAD_EBASE-16
/**
 (not used in this FW version)
 */
#define DT_PPAD_EINVALID_CRC DT_PPAD_EBASE-17
/**
 Operation cancelled
 */
#define DT_PPAD_ECANCELLED DT_PPAD_EBASE-18
/**
 Invalid signature
 */
#define DT_PPAD_EINVALID_SIGNATURE DT_PPAD_EBASE-19
/**
 Invalid data in header
 */
#define DT_PPAD_EINVALID_HEADER DT_PPAD_EBASE-20
/**
 Incorrent password
 */
#define DT_PPAD_EINVALID_PASSWORD DT_PPAD_EBASE-21
/**
 Invalid key format
 */
#define DT_PPAD_EINVALID_KEY_FORMAT DT_PPAD_EBASE-22
/**
 Error in smart card reader
 */
#define DT_PPAD_ESCR DT_PPAD_EBASE-23
/**
 Error code is returned from HAL functions
 */
#define DT_PPAD_EHAL DT_PPAD_EBASE-24
/**
 Invalid key (or missing)
 */
#define DT_PPAD_EINVALID_KEY DT_PPAD_EBASE-25
/**
 The PIN length is <4 or >12
 */
#define DT_PPAD_EINVALID_PIN DT_PPAD_EBASE-26
/**
 Issuer or ICC key invalid remainder length
 */
#define DT_PPAD_EINVALID_REMAINDER DT_PPAD_EBASE-27
/**
 (no used in this FW version)
 */
#define DT_PPAD_ENOT_INITIALIZED DT_PPAD_EBASE-28
/**
 (no used in this FW version)
 */
#define DT_PPAD_ELIMIT_REACHED DT_PPAD_EBASE-29
/**
 (no used in this FW version)
 */
#define DT_PPAD_EINVALID_SEQUENCE DT_PPAD_EBASE-30
/**
 The action is not permited
 */
#define DT_PPAD_ENOT_PERMITTED DT_PPAD_EBASE-31
/**
 TMK is not loaded. The action cannot be executed
 */
#define DT_PPAD_ENO_TMK DT_PPAD_EBASE-32
/**
 Wrong key format
 */
#define DT_PPAD_EWRONG_KEY DT_PPAD_EBASE-33
/**
 Duplicated key
 */
#define DT_PPAD_EDUPLICATE_KEY DT_PPAD_EBASE-34
/**
 General keyboard error
 */
#define DT_PPAD_EKEYBOARD_GENERAL DT_PPAD_EBASE-35
/**
 Keyboard not calibrated
 */
#define DT_PPAD_EKEYBOARD_NOT_CALIBRATED DT_PPAD_EBASE-36
/**
 Keyboard failure
 */
#define DT_PPAD_EKEYBOARD_FAILURE DT_PPAD_EBASE-37

#endif

/**@}*/

#endif

/**
 Information about Voltage
 */
@interface DTVoltageInfo : NSObject
/**
 Key is available, card can be read and encrypted
 */
@property (assign) BOOL keyGenerated;
/**
 Key generation in progress, wile the key is generated the old key will be used for encryption
 */
@property (assign) BOOL keyGenerationInProgress;
/**
 The date/time of the last key generated
 */
@property (copy) NSDate *keyGenerationDate;
/**
 Version of the voltage settings
 */
@property (assign) int settingsVersion;
@end


/**
 * The class that represents Encrypted Magnetic Head information
 */
@interface EMSRDeviceInfo : NSObject
/**
 * Identification string, for example "EMSR R"
 */
@property (copy) NSString *ident;
/**
 * Unique serial number (16 bytes)
 */
@property (copy) NSData *serialNumber;
/**
 * Unique serial number (16 bytes) in hexadeciamal string for display purposes
 */
@property (copy) NSString *serialNumberString;
/**
 * Firmware version number in format MAJOR*1000 + MINOR, i.e. version 1.123 will be presented as 1123
 */
@property (assign) int firmwareVersion;
/**
 * Firmware version number in string format, for display purposes
 */
@property (copy) NSString *firmwareVersionString;
/**
 * Security firmware version number in format MAJOR*1000 + MINOR, i.e. version 1.123 will be presented as 1123
 */
@property (assign) int securityVersion;
/**
 * Firmware version number in string format, for display purposes
 */
@property (copy) NSString *securityVersionString;

@end


/**
 * The class that represents Encrypted Magnetic Head key
 */
@interface EMSRKey : NSObject
/**
 * The ID of the key, one of the KEY_* constants
 */
@property (assign) int keyID;
/**
 * The version of the key
 */
@property (assign) int keyVersion;

/**
 * The name of the key (for display purposes)
 */
@property (copy) NSString *keyName;

@end


/**
 * The class that represents Encrypted Magnetic Head keys information
 */
@interface EMSRKeysInfo : NSObject

/**
 Returns the name of a key (for display purposes)
 @param keyID key ID, one of the KEY_* constants
 @return name string or nil if the ID was wrong
 */
+(NSString *)keyNameByID:(int)keyID;

/**
 * An array of EMSRKey objects representing the keys in the head
 */
@property (copy) NSArray *keys;
/**
 * Indicates if the head is tampered or not. Tampered head needs to be reactivated at secure facility after checking
 */
@property (assign) bool tampered;

/**
 Returns key version
 @param keyID key ID, one of the KEY_* constants
 @return key version or 0 if the key is missing
 */
-(int)getKeyVersion:(int)keyID;

@end

/**
 Provides information about EMV application
 */
@interface DTEMVApplication : NSObject
/**
 Application AID
 */
@property (copy) NSData *aid;
/**
 Application label
 */
@property (copy) NSString *label;
/**
 How the application is matched to the ones in the card:
 <table>
 <tr><td>MATCH_FULL</td><td>Complete match</td></tr>
 <tr><td>MATCH_PARTIAL_VISA</td><td>Partial Visa match</td></tr>
 <tr><td>MATCH_PARTIAL_EUROPAY</td><td>Partial Europay match</td></tr>
 </table>
 */
@property (assign) int matchCriteria;
@end



/**
 The way screen can display colors
 */
typedef enum
{
    /**
     2 color, black and white (or black and yellow on some screens)
     */
	COLOR_MODE_BW=0,
}SCREEN_COLOR_MODES;

/**
 Information about Certification Authority keys
 */
@interface DTCAKeyInfo : NSObject
/**
 Key index
 */
@property (assign) int keyIndex;
/**
 RIDI
 */
@property (copy) NSData *RIDI;
/**
 Length of the key module
 */
@property (assign) int moduleLength;
@end


/**
 Pinpad key information
 */
@interface DTKeyInfo : NSObject
/**
 Key check value
 */
@property (copy) NSData *checkValue;
/**
 Key type
 */
@property (assign) int type;
/**
 Key usage, according to TR31:
 Usage/Mode:
 
 'B0'	'N'	Base Derivation Key
 
 'P0'	'E'	pin key
 'M1'	'C'	key for ISO 9797-1 MAC Algorithm 1
 'M3'	'C'	key for ISO 9797-1 MAC Algorithm 3
 'M0'	'C'	key for ISO 16609 MAC algorithm 1
 'D0'	'E'	key for data encrypting
 'D0'	'D'	key for data decrypting
 
 Custom method usage vaules:
 
 '01'	transport key for pin key
 '02'	transport key for ISO 9797-1 MAC Algorithm 1 key
 '03'	transport key for ISO 9797-1 MAC Algorithm 3  key
 '04'	transport key for ISO 16609 MAC algorithm 1 key
 '05'	transport key for data encrypting key
 '06'	transport key for data decrypting key
 */
@property (copy) NSString *usage;
/**
 Key mode, according to TR31
 */
@property (assign) char mode;
/**
 Key version
 */
@property (assign) int version;
@end


/**
 Protocol describing various notifications that DTDevices SDK can send.
 */
@protocol DTDeviceDelegate
@optional
/** @defgroup G_DTDELEGATE Delegate Notifications
 Notifications sent by the sdk on various events - barcode scanned, magnetic card data, communication status, etc
 @{
 */

/**
 Notifies about the current connection state
 @param state - connection state, one of:
 <table>
 <tr><td>CONN_DISCONNECTED</td><td>there is no connection to any device and the sdk will not try to make one even if the device is attached</td></tr>
 <tr><td>CONN_CONNECTING</td><td>no device is currently connected, but the sdk is actively trying to</td></tr>
 <tr><td>CONN_CONNECTED</td><td>One or more devices are connected</td></tr>
 </table>
 **/
-(void)connectionState:(int)state;

/**
 Notification sent when some of the device's buttons is pressed
 @param which button identifier, one of:
 <table>
 <tr><td>0</td><td>right scan button</td></tr>
 </table>
 **/
-(void)deviceButtonPressed:(int)which;

/**
 Notification sent when some of the device's buttons is released
 @param which button identifier, one of:
 <table>
 <tr><td>0</td><td>right scan button</td></tr>
 </table>
 **/
-(void)deviceButtonReleased:(int)which;

/**
 Notification sent when barcode is successfuly read. This notification is used when barcode type is set to BARCODE_TYPE_DEFAULT or BARCODE_TYPE_EXTENDED.
 @param barcode - string containing barcode data
 @param type - barcode type, one of the BAR_* constants
 **/
-(void)barcodeData:(NSString *)barcode type:(int)type;

/**
 Notification sent when barcode is successfuly read. This notification is used when barcode type is set to BARCODE_TYPE_ISO15424
 @param barcode - string containing barcode data
 @param type - barcode type, according to ISO 15424
 **/
-(void)barcodeData:(NSString *)barcode isotype:(NSString *)isotype;

/**
 Notification sent when barcode is successfuly read. This notification is used when barcode type is set to BARCODE_TYPE_DEFAULT or BARCODE_TYPE_EXTENDED.
 @param barcode - NSData containing barcode data
 @param type - barcode type, one of the BAR_* constants
 **/
-(void)barcodeNSData:(NSData *)barcode type:(int)type;

/**
 Notification sent when barcode is successfuly read. This notification is used when barcode type is set to BARCODE_TYPE_ISO15424
 @param barcode - string containing barcode data
 @param type - barcode type, according to ISO 15424
 **/
-(void)barcodeNSData:(NSData *)barcode isotype:(NSString *)isotype;

/**
 Notification sent when magnetic card is successfuly read
 @param track1 - data contained in track 1 of the magnetic card or nil
 @param track2 - data contained in track 2 of the magnetic card or nil
 @param track3 - data contained in track 3 of the magnetic card or nil
 **/
-(void)magneticCardData:(NSString *)track1 track2:(NSString *)track2 track3:(NSString *)track3;

/**
 Notification sent when magnetic card is successfuly read. The data is being sent encrypted.
 @param encryption encryption algorithm used, one of ALG_* constants
 
 For AES256, after decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Processed track data in the format: 0xF1 (track1 data), 0xF2 (track2 data) 0xF3 (track3 data). It is possible some of the tracks will be empty, then the identifier will not be present too, for example 0xF1 (track1 data) 0xF3 (track3 data)
 - End of track data (byte 0x00)
 - CRC16 (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data (including the 0x00 byte).
 The data block is rounded to 16 bytes
 
 In the more secure way, where the decryption key resides in a server only, the card read process will look something like:
 - (User) swipes the card 
 - (iOS program) receives the data via magneticCardEncryptedData and sends to the server
 - (iOS program)[optional] sends current device serial number along with the data received from magneticCardEncryptedData. This can be used for data origin verification
 - (Server) decrypts the data, extracts all the information from the fields
 - (Server)[optional] if the ipod program have sent the device serial number before, the server compares the received serial number with the one that's inside the encrypted block 
 - (Server) checks if the card data is the correct one, i.e. all needed tracks are present, card is the same type as required, etc and sends back notification to the ipod program. 
 
 
 For IDTECH with DUKPT the data contains:
 - DATA[0]:	CARD TYPE: 0 - payment card
 - DATA[1]:	TRACK FLAGS
 - DATA[2]:	TRACK 1 LENGTH
 - DATA[3]:	TRACK 2 LENGTH
 - DATA[4]:	TRACK 3 LENGTH
 - DATA[??]:	TRACK 1 DATA MASKED
 - DATA[??]:	TRACK 2 DATA MASKED
 - DATA[??]:	TRACK 3 DATA
 - DATA[??]:	TRACK 1 AND TRACK 2 TDES ENCRYPTED
 - DATA[??]:	TRACK 1 SHA1 (0x14 BYTES)
 - DATA[??]:	TRACK 2 SHA1 (0x14 BYTES)
 - DATA[??]:	DUKPT SERIAL AND COUNTER (0x0A BYTES)
 
 @param tracks contain information which tracks are successfully read and inside the encrypted data as bit fields, bit 1 corresponds to track 1, etc, so value of 7 means all tracks are read
 @param data contains the encrypted card data
 **/
-(void)magneticCardEncryptedData:(int)encryption tracks:(int)tracks data:(NSData *)data;

/**
 Notification sent when magnetic card is successfuly read. The data is being sent encrypted.
 @param encryption encryption algorithm used, one of:
 <table>
 <tr><td>0</td><td>AES 256</td></tr>
 <tr><td>1</td><td>IDTECH with DUKPT</td></tr>
 </table>
 
 For AES256, after decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Processed track data in the format: 0xF1 (track1 data), 0xF2 (track2 data) 0xF3 (track3 data). It is possible some of the tracks will be empty, then the identifier will not be present too, for example 0xF1 (track1 data) 0xF3 (track3 data)
 - End of track data (byte 0x00)
 - CRC16 (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data (including the 0x00 byte).
 The data block is rounded to 16 bytes
 
 In the more secure way, where the decryption key resides in a server only, the card read process will look something like:
 - (User) swipes the card
 - (iOS program) receives the data via magneticCardEncryptedData and sends to the server
 - (iOS program)[optional] sends current Linea serial number along with the data received from magneticCardEncryptedData. This can be used for data origin verification
 - (Server) decrypts the data, extracts all the information from the fields
 - (Server)[optional] if the ipod program have sent the Linea serial number before, the server compares the received serial number with the one that's inside the encrypted block
 - (Server) checks if the card data is the correct one, i.e. all needed tracks are present, card is the same type as required, etc and sends back notification to the ipod program.
 
 For IDTECH with DUKPT the data contains:
 - DATA[0]:	CARD TYPE: 0 - payment card
 - DATA[1]:	TRACK FLAGS
 - DATA[2]:	TRACK 1 LENGTH
 - DATA[3]:	TRACK 2 LENGTH
 - DATA[4]:	TRACK 3 LENGTH
 - DATA[??]:	TRACK 1 DATA MASKED
 - DATA[??]:	TRACK 2 DATA MASKED
 - DATA[??]:	TRACK 3 DATA
 - DATA[??]:	TRACK 1 AND TRACK 2 TDES ENCRYPTED
 - DATA[??]:	TRACK 1 SHA1 (0x14 BYTES)
 - DATA[??]:	TRACK 2 SHA1 (0x14 BYTES)
 - DATA[??]:	DUKPT SERIAL AND COUNTER (0x0A BYTES)
 
 @param tracks contain information which tracks are successfully read and inside the encrypted data as bit fields, bit 1 corresponds to track 1, etc, so value of 7 means all tracks are read
 @param data contains the encrypted card data
 @param track1masked when possible, track1 data will be masked and returned here
 @param track2masked when possible, track2 data will be masked and returned here
 **/
-(void)magneticCardEncryptedData:(int)encryption tracks:(int)tracks data:(NSData *)data track1masked:(NSString *)track1masked track2masked:(NSString *)track2masked track3:(NSString *)track3;

/**
 Notification sent when magnetic card is successfuly read
 @param tracks contains the raw magnetic card data. These are the bits directly from the magnetic head.
 The maximum length of a single track is 704 bits (88 bytes), so the command returns the 3 tracks as 3x88 bytes block
 **/
-(void)magneticCardRawData:(NSData *)tracks;

/**
 Notification sent when magnetic card is successfuly read. The raw card data is encrypted via the selected encryption algorithm.
 After decryption, the result data will be as follows:
 - Random data (4 bytes)
 - Device identification text (16 ASCII characters, unused bytes are 0)
 - Track data: the maximum length of a single track is 704 bits (88 bytes), so track data contains 3x88 bytes
 - CRC16 (2 bytes) - the CRC is performed from the start of the encrypted block (the Random Data block) to the end of the track data.
 The data block is rounded to 16 bytes
 @param encryption encryption algorithm used, one of ALG_* constants
 @param data - Contains the encrypted raw card data
 **/
-(void)magneticCardEncryptedRawData:(int)encryption data:(NSData *)data;

/**
 Notification sent when firmware update process advances. Do not call any other functions until firmware update is complete! During the firmware update notifications will be posted.
 @param phase update phase, one of:
 <table>
 <tr><td>UPDATE_INIT</td><td>Initializing firmware update</td></tr>
 <tr><td>UPDATE_ERASE</td><td>Erasing flash memory</td></tr>
 <tr><td>UPDATE_WRITE</td><td>Writing data</td></tr>
 <tr><td>UPDATE_FINISH</td><td>Update complete</td></tr>
 </table>
 @param percent firmware update progress in percents
 **/
-(void)firmwareUpdateProgress:(int)phase percent:(int)percent;

/**
 Notification sent when bluetooth discovery finds new bluetooth device
 @param success true if the discovery complete successfully, even if it not resulted in any device found, false if there was an error communicating with the bluetooth module
 **/
-(void)bluetoothDiscoverComplete:(BOOL)success;

/**
 Notification sent when bluetooth discovery finds new bluetooth device
 @param address bluetooth address of the device
 @param name bluetooth name of the device
 **/
-(void)bluetoothDeviceDiscovered:(NSString *)address name:(NSString *)name;

/**
 Notification sent when bluetooth device is connected
 @param address bluetooth address of the device
 @param name bluetooth name of the device
 **/
-(void)bluetoothDeviceConnected:(NSString *)address;

/**
 Notification sent when bluetooth connection is lost
 @param address bluetooth address of the device
 */
-(void)bluetoothDeviceDisconnected:(NSString *)address;

/**
 Notification sent when a bluetooth device requests
 @param address bluetooth address of the device
 @param name bluetooth name of the device
 **/
-(BOOL)bluetoothDeviceRequestedConnection:(NSString *)address name:(NSString *)name;

/**
 Notification sent when a bluetooth device requests
 @param address bluetooth address of the device
 @param name bluetooth name of the device
 **/
-(NSString *)bluetoothDevicePINCodeRequired:(NSString *)address name:(NSString *)name;

/**
 Notification sent when JIS I & II magnetic card is successfuly read
 @param data - data contained in the magnetic card
 **/
-(void)magneticJISCardData:(NSString *)data;

/**
 Notification sent when a new supported RFID card enters the field
 @param cardIndex the index of the card, use this index with all subsequent commands to the card
 @param info information about the card
 **/
-(void)rfCardDetected:(int)cardIndex info:(DTRFCardInfo *)info;

/**
 Notification sent when the card leaves the field
 @param cardIndex the index of the card, use this index with all subsequent commands to the card
 */
-(void)rfCardRemoved:(int)cardIndex;

/**
 Notification sent when some of the features gets enabled or disabled
 @param feature feature type, one of the FEAT_* constants
 @param value FEAT_UNSUPPORTED if the feature is not supported on the connected device(s), FEAT_SUPPORTED or one of the specific constants for each feature otherwise
 */
-(void)deviceFeatureSupported:(int)feature value:(int)value;

/**
 Notification sent when smartcard was inserted
 @param slot smart card slot number
 **/
-(void)smartCardInserted:(SC_SLOTS)slot;

/**
 Notification sent when smartcard was removed
 @param slot smart card slot number
 **/
-(void)smartCardRemoved:(SC_SLOTS)slot;

/**
 Notification sent when PIN entry procedure have completed or was cancelled
 @param error nil if no error occured, or NSError object if the generation failed
 **/
-(void)PINEntryCompleteWithError:(NSError *)error;

/**
 Notification sent when printer's paper sensor changes
 @param present TRUE if paper is present, FALSE if printer is out of paper or cover is open
 **/
-(void)paperStatus:(BOOL)present;

/**
 Notification sent to display debug messages from the sdk or device
 @param logText debug message
 @param source source device type, 0 means the connected device, 1 is the sdk
 **/
-(void)sdkDebug:(NSString *)logText source:(int)source;

/**@}*/

@end


/**
 Provides universal access to all supported devices' functions.
 In order to use one of the supported accessories in your program, several steps have to be performed:
 - Include DTDevices.h and libdtdev.a in your project.
 - Go to Frameworks and add ExternalAccessory framework
 - Edit your program plist file, add new element and select "Supported external accessory protocols" from the list, then add the protocol names of the accessories you want to connect to:
 <br>For Linea series: com.datecs.linea.pro.msr and com.datecs.linea.pro.bar
 <br>For Pinpad: com.datecs.iserial.communication and com.datecs.ppad
 <br>For iSerial: com.datecs.iserial.communication
 <br>For ESC/POS printers: com.datecs.printer.escpos
 
 <br>Since this SDK is based on features, the specific device is not that important, for example, if your program relies on barcode scanning, then Linea, Pinpad or the ESC/POS printers can provide that functionality, so you can include all their protocols.
 */
@interface DTDevices : NSObject
/** @defgroup G_LNGENERAL General functions
 Functions to connect/disconnect, set delegate, make sounds, update firmware, control various device settings
 @{
 */

/**
 Creates and initializes new class instance or returns already initalized one. Use this function, if you want to access the class from different places
 @return shared class instance
 **/
+(id)sharedDevice;

/**
 Allows unlimited delegates to be added to a single class instance. This is useful in the case of global
 class and every view can use addDelegate when the view is shown and removeDelegate when no longer needs to monitor events
 @param newDelegate the delegate that will be notified of events
 **/
-(void)addDelegate:(id)newDelegate;

/**
 Removes delegate, previously added with addDelegate
 @param newDelegate the delegate that will be no longer be notified of events
 **/
-(void)removeDelegate:(id)newDelegate;

/**
 Tries to connect to supported devices in the background, connection status notifications will be passed through the delegate.
 Once connect is called, it will automatically try to reconnect until disconnect is called. Note that "connect" call works in background and will notify the caller of connection success via connectionState delegate. Do not assume the library has fully connected to the device after this call, but wait for the notification.
 **/
-(void)connect;

/**
 Stops the sdk from trying to connect to supported devices and breaks existing connections.
 **/
-(void)disconnect;

/*
 Checks if accessory is presnet - either already connected, or physically attached, even if not connected to
 @param type device type, one of DEVICE_TYPE_* constants
 @return true if the accessory is either connected or physically attached
 */
-(BOOL)isPresent:(int)type;

/**
 The sdk can work with many devices at the same time, but some functions can be executed on a single device at a time (for example barcodeStartScan), this function sets the prefered device to execute the function by type.
 @param type device type to be made active, one of the DEVICE_TYPE_* constants
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)setActiveDeviceType:(int)type error:(NSError **)error;

/**
 Sets the time in seconds, after which Linea will shut down to conserve battery. This works with lightning connector Lineas only (LP5, LPTab4, LPTabMini)
 @note When Linea is being used by a program, only the idle time is taken in effect, but when Linea is disconnected BOTH parameters have effect - if idle time is 10
 seconds and disconnected time is 30, then Linea will awlays disconnect in 10 seconds of inactivity! Thus idle time should always be bigger than disconnected time!
 @param timeIdle this is the idle time, connected or not, after which Linea will turn off. The default value is 5400 seconds (90 minutes)
 @param timeDisconnected this is the time with no active program connection, after which Linea will turn off. The default value is 30 seconds
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)setAutoOffWhenIdle:(NSTimeInterval)timeIdle whenDisconnected:(NSTimeInterval)timeDisconnected error:(NSError **)error;

/**
 Returns active device's battery capacity
 @note Reading battery voltages during charging is unreliable!
 @param capacity returns battery capacity in percents, ranging from 0 when battery is dead to 100 when fully charged. Pass nil if you don't want that information
 @param voltage returns battery voltage in Volts, pass nil if you don't want that information
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)getBatteryCapacity:(int *)capacity voltage:(float *)voltage error:(NSError **)error;

/**
 Plays a sound using the built-in speaker on the active device
 @note A sample beep containing of 2 tones, each with 400ms duration, first one 2000Hz and second - 5000Hz will look int beepData[]={2000,400,5000,400}
 @param volume controls the volume (0-100). Currently have no effect
 @param data an array of integer values specifying pairs of tone(Hz) and duration(ms).
 @param length length in bytes of beepData array
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)playSound:(int)volume beepData:(int *)data length:(int)length error:(NSError **)error;

/**
 Returns if the connected device is charging the iOS device from it's own battery. Linea firmware versions prior to 2.13 will return true if external charge is attached, 2.13 and later will return only if Linea's own battery is used for charging.
 @param charging returns TRUE if charging is enabled (from internal battery, external charging is omitted)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)getCharging:(BOOL *)charging error:(NSError **)error;

/**
 Enables or disables Lines's capability to charge the handheld from it's own battery. Charging can stop if connected device's battery goes too low.
 
 <br>While Linea can act as external battery for the iPod/iPhone, there are certain limitations if you decide to implement it. The internal battery is not big enough, so if the iPod/iPhone consumes a lot of power from it, it will go down very fast and force the firmware to cut the charge to prevent going down to dangerous levels. The proper use of this charging function depends on how the program, running on the iPod/iPhone, is used and how the iPod/iPhone is discharged
 
 <br>There are two possible ways to use Linea's charge:
 - Emergency mode - in the case iPod/iPhone usage is designed in a way it will last long enough between charging sessions and using Linea's charge is not generally needed, the charge can be used if the iPod/iPhone for some reason goes too low (like <50%), so it is given some power to continue working until next charging. An example will be store, where devices are being charged every night, but extreme usage on some iPod drains the battery before the end of the shift.
 This is the less efficient way to charge it, also, Linea will refuse to start the charge if it's own battery goes below 3.8v, so depending on the usage, barcode type and if the barcode engine is set to work all the time, it may not be possible to start the charge.
 
 - Max life mode - it is the case where both devices are required to operate as long as possible. Usually, the iPod/iPhone's battery will be drained way faster than Linea's, especially with wifi enabled programs and to keep both devices operating as long as possible, the charging should be desinged in a way so iPod/iPhone is able to use most of Linea's battery. This is possible, if you start charging when iPod/iPhone is almost full - at around 75-80% or higher. This way the iPod will consume small amount of energy, allowing our battery to slowly be used almost fully to charge it.
 
 <br>LibraryDemo application contains sample implementation of max life mode charging.
 
 @note Reading battery voltages during charging is unreliable!
 @note Enabling charge can fail if connected device's battery is low. Disabling charge will fail if there is external charger or usb cable attached.
 
 @param enabled TRUE to enable charging, FALSE to disable/stop it
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)setCharging:(BOOL)enabled error:(NSError **)error;

/**
 Returns the current state of the pass-through synchronization.
 @param enabled returns if the sync is enabled or disabled
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)getPassThroughSync:(BOOL *)enabled error:(NSError **)error;

/**
 Enables or disables pass-through synchronization when you plug usb cable. In lightning connector devices this is important, as you can no longer have both sync and communication at the same time.
 Disable the sync for stationary, always on charge systems. Sync mode is persistent, but there is no downside of setting the desired one upon connection.
 @param enabled TRUE to enable pass-through sync, FALSE to disable it
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)setPassThroughSync:(BOOL)enabled error:(NSError **)error;

/**
 Sets the charge current that lightning connector based Lineas will allow the iPod/iPhone/iPad to be charged with when connected via USB port. This setting persists.
 @note Note the combined consumption on both Linea (max 300mA) and the iPod/iPhone/iPad, some USB ports may not be strong enough and will turn off. Usually an usb port
 provides up to 1A, so setting the iOS charge to 500mA is always safe, but high powered usb ports can provide much more.
 @warning You can damage your adapter/port if you increase the charge current beyound its limits!!! Do not put 1A charge on 1A adapters, always use 2A adapter! Do not use 1A charge on PCs, unless it goes through high-power usb HUB!
 @param current the charge current in mA (normally it is 500). Currently linea accepts only 500 and 1000 as parameters
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)setUSBChargeCurrent:(int)current error:(NSError **)error;

/**
 Returns information about the specified firmware data. Based on it, and the connected device's name, model and firmware version you can chose to update or not the firmware
 @param data - firmware data
 <table>
 <tr><td>"deviceName"</td><td>Device name, for example "Linea"</td></tr>
 <tr><td>"deviceModel"</td><td>Device model, for example "XBAMBL</td></tr>
 <tr><td>"firmwareRevision"</td><td>Firmware revision as string, for example 2.41</td></tr>
 <tr><td>"firmwareRevisionNumber"</td><td>Firmware revision as number MAJOR*100+MINOR, i.e. 2.41 will be returned as 241</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return firmware information if function succeeded, nil otherwise
 **/
-(NSDictionary *)getFirmwareFileInformation:(NSData *)data error:(NSError **)error;

/**
 Updates connected device's firmware with specified firmware data. The firmware can only be upgraded or downgraded, if you send the same firmware version, then no update process will be started.
 @note Make sure the user does not interrupt the process or the device will be rendered unusable and can only be recovered via the special firmware update cable
 @param data the firmware data
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)updateFirmwareData:(NSData *)data error:(NSError **)error;

/**
 Returns if a feature is supported on connected device(s) and what type it is
 @param feature one of the FEAT_* constants
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return FEAT_UNSUPPORTED if feature is not supported, FEAT_SUPPORTED or one or more feature specific types otherwise
 */
-(int)getSupportedFeature:(int)feature error:(NSError **)error;
/**@}*/

/** @defgroup G_LNMSREADER Magnetic Stripe Reader Functions (Unencrypted)
 Functions to work with the unencrypted magenetic card reader
 @{
 */

/**
 Enables reading of magnetic cards. Current magnetic card heads used in Linea consume so little power, that there is no drawback in leaving it enabled all the time.
 By default magnetic card reading is enabled upon connect.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)msEnable:(NSError **)error;

/**
 Disables magnetic card reading
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)msDisable:(NSError **)error;

/**
 Helper function to parse financial card and extract the data - name, number, expiration date. The function will extract as much information as possible.
 @param track1 - track1 information or nil
 @param track2 - track2 information or nil
 @return dictionary containing extracted data or nil if the data is invalid. Keys contained are:
 <table>
 <tr><td>"accountNumber"</td><td>Account number</td></tr>
 <tr><td>"cardholderName"</td><td>Cardholder name, as stored in the card</td></tr>
 <tr><td>"expirationYear"</td><td>Expiration date - year</td></tr>
 <tr><td>"expirationMonth"</td><td>Expiration date - month</td></tr>
 <tr><td>"serviceCode"</td><td>Service code (if any)</td></tr>
 <tr><td>"discretionaryData"</td><td>Discretionary data (if any)</td></tr>
 <tr><td>"firstName"</td><td>Extracted cardholder's first name</td></tr>
 <tr><td>"lastName"</td><td>Extracted cardholder's last name</td></tr>
 </table>
 **/
-(NSDictionary *)msProcessFinancialCard:(NSString *)track1 track2:(NSString *)track2;

/**
 Sets Linea's magnetic card data mode. This setting is not persistent and is best to configure it upon connect.
 @param mode magnetic card data mode:
 <table>
 <tr><td>MS_PROCESSED_CARD_DATA</td><td>Card data will be processed and will be returned via call to magneticCardData</td></tr>
 <tr><td>MS_RAW_CARD_DATA</td><td>Card data will not be processed and will be returned via call to magneticCardRawData</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)msSetCardDataMode:(int)mode error:(NSError **)error;
/**@}*/

/** @defgroup G_LNBARCODEREADER Barcode Reader Functions
 Functions for scanning barcodes, various barcode settings and direct control of the barcode engine
 @{
 */

/**
 Helper function to return string name of barcode type
 @param barcodeType barcode type returned from scanBarcode
 @return barcode type name
 */
-(NSString *)barcodeType2Text:(int)barcodeType;

/**
 Starts barcode engine.
 In single scan mode the laser will be on until barcode is successfully read, the timeout elapses (set via call to setScanTimeout) or if stopScan is called.
 In multi scan mode the laser will stay on even if barcode is successfully read allowing series of barcodes to be scanned within a single read session. The scanning will stop if no barcode is scanned in the timeout interval (set via call to setScanTimeout) or if stopScan is called.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeStartScan:(NSError **)error;

/**
 Stops ongoing scan started with startScan
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeStopScan:(NSError **)error;

/**
 Returns the current scan button mode. See setScanButtonMode for more detailed description.
 This setting is not persistent and is best to configure it upon connect.
 @param mode returns scan button mode, one of the:
 <table>
 <tr><td>BUTTON_DISABLED</td><td>Scan button will become inactive</td></tr>
 <tr><td>BUTTON_ENABLED</td><td>Scan button will triger barcode scan when pressed</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeGetScanButtonMode:(int *)mode error:(NSError **)error;

/**
 Sets scan button mode.
 This setting is not persistent and is best to configure it upon connect.
 @param mode button mode, one of the:
 <table>
 <tr><td>BUTTON_DISABLED</td><td>Scan button will become inactive</td></tr>
 <tr><td>BUTTON_ENABLED</td><td>Scan button will triger barcode scan when pressed</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeSetScanButtonMode:(int)mode error:(NSError **)error;

/**
 Sets the sound, which is used upon successful barcode scan. This setting is not persistent and is best to configure it upon connect.
 @note  A sample beep containing of 2 tones, each with 400ms duration, first one 2000Hz and second - 5000Hz will look int beepData[]={2000,400,5000,400}
 @param enabled turns on or off beeping
 @param volume controls the volume (0-100). Currently have no effect
 @param data an array of integer values specifying pairs of tone(Hz) and duration(ms).
 @param length length in bytes of beepData array
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeSetScanBeep:(BOOL)enabled volume:(int)volume beepData:(int *)data length:(int)length error:(NSError **)error;

/**
 Returns the current scan mode.
 This setting is not persistent and is best to configure it upon connect.
 @param mode returns scanning mode, one of the MODE_* constants
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeGetScanMode:(int *)mode error:(NSError **)error;

/**
 Sets barcode engine scan mode.
 This setting is not persistent and is best to configure it upon connect.
 @param mode scanning mode, one of the MODE_* constants
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeSetScanMode:(int)mode error:(NSError **)error;

/**
 Returns the current barcode type mode. See setBarcodeTypeMode for more detailed description.
 This setting will not persists.
 @param mode returns barcode type mode, one of the:
 <table>
 <tr><td>BARCODE_TYPE_DEFAULT</td><td>default barcode types, listed in BARCODES enumeration</td></tr>
 <tr><td>BARCODE_TYPE_EXTENDED</td><td>extended barcode types, listed in BARCODES_EX enumeration</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeGetTypeMode:(int *)mode error:(NSError **)error;

/**
 Sets barcode type mode. Barcode type can be returned from the default list (listed in BARCODES), extended one (listed in BARCODES_EX) or ISO/AIM list. The extended one is superset to the default, so current programs will be mostly unaffected if they switch from default to extended (with the exception of barcodes like UPC-A and UPC-E, which will be returned as UPC in the default list, but proper types in the extended. This setting will not persists.
 @param mode barcode type mode, one of the:
 <table>
 <tr><td>BARCODE_TYPE_DEFAULT (default)</td><td>default barcode types, listed in BARCODES enumeration</td></tr>
 <tr><td>BARCODE_TYPE_EXTENDED</td><td>extended barcode types, listed in BARCODES_EX enumeration</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeSetTypeMode:(int)mode error:(NSError **)error;

/**
 Performs factory reset of the barcode module. This function is taxing, slow and should not be called often, emergency use only.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeEngineResetToDefaults:(NSError **)error;

/**
 Allows for a custom initialization string to be sent to the Opticon barcode engine. The string is sent directly, if the barcode is currently powered on, and every time it gets initialized. The setting does not persists, so it is best this command is called upon new connection.
 @param data barcode engine initialization data (consult barcode engine manual)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)barcodeOpticonSetInitString:(NSString *)data error:(NSError **)error;

/**
 Sends configuration parameters directly to the opticon barcode engine. Use this function with EXTREME care, you can easily render your barcode engine useless. Refer to the barcode engine documentation on supported commands.
 
 <br>The function encapsulates the data with the ESC and CR so you don't have to send them. It optionally sends Z2 after the command to ensure settings are stored in the flash.
 
 <br>You can send multiple parameters with a single call if you format them as follows:
 - commands that take 2 symbols can be sent without any delimiters, like: "C1C2C3"
 - commands that take 3 symbols should be prefixed by [, like: "C1[C2AC3" (in this case commands are C1, C2A and C3
 - commands that take 4 symbols should be prefixed by ], like: "C1C2]C3AB" (in this case commands are C1, C2 and C3AB
 @param data command string
 @param saveToFlash if TRUE, command also saves the settings to flash. Saving setting is slower, so should be in ideal case executed only once and the program to remember it. The scanner's power usually gets cut when device goes to sleep - 5 seconds of idle time, so any non-stored to flash settings are lost, but if barcodeEnginePowerControl:TRUE is used on 2D engine, then even non-saved to flash settings will persist until device disconnects (iOS goes to sleep, physical disconnect)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeOpticonSetParams:(NSString *)data saveToFlash:(BOOL)saveToFlash error:(NSError **)error;

/**
 Reads barcode engine's identification
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return opticon engine ident string if function succeeded, nil otherwise
 */
-(NSString *)barcodeOpticonGetIdent:(NSError **)error;

/**
 Performs firmware update on the optiocon 2D barcode engines. Barcode update can take very long time, it is best to call this function from a thread and update
 the user interface when firmwareUpdateProgress delegate is called
 @param firmwareData firmware file data to load
 @param bootLoader TRUE if you are going to update bootloader, FALSE if normal firmware
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeOpticonUpdateFirmware:(NSData *)firmwareData bootLoader:(BOOL)bootLoader error:(NSError **)error;

/**
 Sends configuration parameters directly to the code barcode engine. Use this function with EXTREME care,
 you can easily render your barcode engine useless. Refer to the barcode engine documentation for supported parameters.
 @param setting the setting number
 @param value the value to write to
 @return TRUE if operation was successful
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeCodeSetParam:(int)setting value:(uint64_t)value error:(NSError **)error;

/**
 Reads configuration parameters directly from the code barcode engine. Refer to the barcode engine documentation for supported parameters.
 @param setting the setting number
 @param value unpon success, the parameter value will be stored here
 @return TRUE if operation was successful
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeCodeGetParam:(int)setting value:(uint64_t *)value error:(NSError **)error;

/**
 Performs firmware update on the Code 2D barcode engines. Barcode update can take very long time, it is best to call this function from a thread and update
 the user interface when firmwareUpdateProgress delegate is called
 @param name the exact name of the firmware file
 @param data firmware file data to load
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)barcodeCodeUpdateFirmware:(NSString *)name data:(NSData *)data error:(NSError **)error;

-(NSDictionary *)barcodeCodeGetInformation:(NSError **)error;

/**
 Allows for a custom initialization string to be sent to the Intermec barcode engine. The data is sent directly, if the barcode is currently powered on, and every time it gets initialized. The setting does not persists, so it is best this command is called upon new connection.
 @param data barcode engine initialization data (consult barcode engine manual)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)barcodeIntermecSetInitData:(NSData *)data error:(NSError **)error;

/**
 Sends a custom command to the barcode engine and receives a reply
 @param command command data (consult barcode engine manual). You must only pass the data field, the header and checksum are automatically calculated
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return response data, if function succeeded, nil otherwise. Response is stripped of headers and checksum, only the real data is provided
 **/
-(NSData *)barcodeNewlandQuery:(NSData *)command error:(NSError **)error;

/**
 Allows for a custom initialization string to be sent to the Newland barcode engine. The string is sent directly, if the barcode is currently powered on, and every time it gets initialized.
 The settings does persists and are stored in barcode module's flash, but the is written only upon change, so it is safe to repeatedly call this function on every connect.
 @param data barcode engine initialization data (consult barcode engine manual)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)barcodeNewlandSetInitString:(NSString *)data error:(NSError **)error;

/**@}*/


/*******************************************************************************
 * BLUETOOTH COMMANDS
 *******************************************************************************/
/** @defgroup G_LNBLUETOOTH Bluetooth Functions
 Functions to work with the built-in bluetooth module
 @{
 */
/**
 Performs background discovery of nearby supported bluetooth devices. Supported devices are the ones some of the sdk has built-in support for - printers and pinpads. 
 The discovery status and devices found will be sent via delegate notifications
 @note this function cannot be called once connection to remote device was established
 @param maxDevices the maximum results to return
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @param filter filter of which devices to discover, a combination of one or more of BLUETOOT_FILTER_* constants or BLUETOOTH_FILTER_ALL to get all supported devices
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btDiscoverSupportedDevicesInBackground:(int)maxDevices maxTime:(double)maxTime filter:(int)filter error:(NSError **)error;

/**
 Performs background discovery of the nearby bluetooth devices. The discovery status and devices found will be sent via delegate notifications
 @note active connection with remote device will be broken
 @param maxDevices the maximum results to return
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @param codTypes bluetooth Class Of Device to look for or 0 to search for all bluetooth devices
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btDiscoverDevicesInBackground:(int)maxDevices maxTime:(double)maxTime codTypes:(int)codTypes error:(NSError **)error;

/**
 Performs background discovery of supported printers. These include PP-60, DPP-250, DPP-350, SM-112, DPP-450. The discovery status and devices found will be sent via delegate notifications
 @note active connection with remote device will be broken
 @param maxDevices the maximum results to return, default is 4
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btDiscoverPrintersInBackground:(int)maxDevices maxTime:(double)maxTime error:(NSError **)error;

/**
 Performs background discovery of supported printers. These include PP-60, DPP-250, DPP-350, SM-112, DPP-450. The discovery status and devices found will be sent via delegate notifications
 @note active connection with remote device will be broken
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btDiscoverPrintersInBackground:(NSError **)error;

/**
 Performs background discovery of supported printers. These include MPED-400 and PPAD1. The discovery status and devices found will be sent via delegate notifications
 @note active connection with remote device will be broken
 @param maxDevices the maximum results to return, default is 4
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btDiscoverPinpadsInBackground:(int)maxDevices maxTime:(double)maxTime error:(NSError **)error;

/**
 Performs background discovery of supported printers. These include MPED-400 and PPAD1. The discovery status and devices found will be sent via delegate notifications
 @note active connection with remote device will be broken
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btDiscoverPinpadsInBackground:(NSError **)error;

/**
 Tries to connect to remote device. Once connection is established, use bluetooth streams to read/write to the remote device.
 @note active connection with remote device will be broken
 @param address bluetooth address returned from btDiscoverDevices/btDiscoverPrinters
 @param pin PIN code if needed, or nil to try unencrypted connection
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btConnect:(NSString *)address pin:(NSString *)pin error:(NSError **)error;

/**
 Disconnects from remote device.
 @param address bluetooth address returned from btDiscoverDevices/btDiscoverPrinters
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btDisconnect:(NSString *)address error:(NSError **)error;

/**
 Tries to connect to supported bluetooth device. Supported devices are the ones the sdk has built-in support for - printers and pinpads.
 If successful, additional functions will become available and feature notifications will be sent
 @note active connection with remote device will be broken
 @param address bluetooth address returned from btDiscoverSupportedDevicesInBackground/btDiscoverPrintersInBackground
 @param pin PIN code if needed, or nil to try unencrypted connection
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btConnectSupportedDevice:(NSString *)address pin:(NSString *)pin error:(NSError **)error;

/**
 Sends data to the connected remote device.
 @note You can use bluethooth streams instead
 @param data data bytes to write
 @param length the length of the data in the buffer
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btWrite:(void *)data length:(int)length error:(NSError **)error;

/**
 Sends data to the connected remote device.
 @note You can use bluethooth streams instead
 @param data data string to write
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btWrite:(NSString *)data error:(NSError **)error;

/**
 Tries to read data from the connected remote device for specified timeout.
 @note You can use bluethooth streams instead
 @param data data buffer, where the result will be stored
 @param length maximum amount of bytes to wait for
 @param timeout maximim timeout in seconds to wait for data
 @return the
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return actual number of bytes stored in the data buffer if function succeeded, -1 otherwise
 */
-(int)btRead:(void *)data length:(int)length timeout:(double)timeout error:(NSError **)error;

/**
 Tries to read string data, ending with CR/LF up to specifed timeout
 @note You can use bluethooth streams instead
 @param timeout maximim timeout in seconds to wait for data
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return string with the line read (can be empty string too) if function succeeded, nil otherwise
 */
-(NSString *)btReadLine:(double)timeout error:(NSError **)error;

/**
 Enables or disables write caching on the bluetooth stream. When enabled the writes gets cached and send on bigger chunks, reducing substantially the time taken, if you are sending lot of data in small parts.
 Write caching has negative effect on the speed if your bluetooth communication is based on request/response format or packets, in this case every write operation will get delayed, resulting in very poor throughput.
 @param enabled enable or disable write caching, by default it is disabled
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btEnableWriteCaching:(BOOL)enabled error:(NSError **)error;

/**
 Performs synchronous discovery of the nearby bluetooth devices. Implemented for compatibility only!
 @deprecated This function is not recommended to be called on the main thread, use btDiscoverDevicesInBackground instead
 @note this function cannot be called once connection to remote device was established
 @param maxDevices the maximum results to return
 @param maxTime the max time to discover, in seconds. Actual time may vary.
 @param codTypes bluetooth Class Of Device to look for or 0 to search for all bluetooth devices
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return array of strings of bluetooth addresses if function succeeded, nil otherwise
 */
-(NSArray *)btDiscoverDevices:(int)maxDevices maxTime:(double)maxTime codTypes:(int)codTypes error:(NSError **)error;

/**
 Queries device name given the address. Implemented for compatibility only!
 @deprecated This function complements the btDiscoverDevices/btDiscoverPrinters and as such is not recommended, use btDiscoverDevicesInBackground instead
 @note this function cannot be called once connection to remote device was established
 @param address bluetooth address returned from btDiscoverDevices/btDiscoverPrinters
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return bluetooth device name if function succeeded, nil otherwise
 */
-(NSString *)btGetDeviceName:(NSString *)address error:(NSError **)error;

/**
 Sets the conditions to fire the NSStreamEventHasBytesAvailable event on bluetooth streams. If all special conditions are disabled, then the notification will be fired the moment data arrives.
 You can have multiple notifications active at the same time, for example maxBytes and maxTime.
 @param maxTime notification will be fired 'maxTime' seconds after the last byte arrives, passing 0 disables it. For example 0.1 means that 100ms after the last byte is received the notification will fire.
 @param maxLength notification will be fired after 'maxLength' data arrives, passing 0 disables it.
 @param sequenceData notification will be fired if the received data contains 'sequenceData', passing nil disables it.
 */
-(BOOL)btSetDataNotificationMaxTime:(double)maxTime maxLength:(int)maxLength sequenceData:(NSData *)sequenceData error:(NSError **)error;

/**
 Initiates/kills listen for incoming bluetooth connections. Incoming connecton requests will be sent as delegate notifications
 @note this function cannot be called once connection to remote device was established
 @param enabled if YES the bluetooth module will listen for incoming connections, NO disables this functionality
 @param discoverable if YES the module will be discoverable while waiting. Making the module non-discoverable means only devices, that know it's bluetooth address will be able to connect
 @param localName if discoverable, then this will be the name seen by the others
 @param cod Class Of Device, as per bluetooth documentation. Pass 0 if you don't want to set it
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)btListenForDevices:(BOOL)enabled discoverable:(bool)discoverable localName:(NSString *)localName cod:(uint32_t)cod error:(NSError **)error;

/**
 Bluetooth input stream, you can use it after connecting with btConnect. See NSInputStream documentation.
 **/
@property(assign, readonly) NSInputStream *btInputStream;

/**
 Bluetooth output stream, you can use it after connecting with btConnect. See NSOutputStream documentation.
 **/
@property(assign, readonly) NSOutputStream *btOutputStream;

/**
 Contains bluetooth addresses of the currently connected bluetooth devices or empty array if no connected devices are found
 **/
@property(readonly) NSArray *btConnectedDevices;
/**@}*/


/*******************************************************************************
 * EXTERNAL SERIAL PORT COMMANDS
 *******************************************************************************/
/** @defgroup G_ESERIAL External Serial Port Functions
 Functions to work with Linea Tab's external serial port
 @{
 */

/**
 No parity
 */
#define PARITY_NONE 0
/**
 Even parity
 */
#define PARITY_EVEN 1
/**
 Odd parity
 */
#define PARITY_ODD 2

/**
 7 data bits
 */
#define DATABITS_7 1
/**
 8 data bits
 */
#define DATABITS_8 0

/**
 1 stop bits
 */
#define STOPBITS_1 0
/**
 2 stop bits
 */
#define STOPBITS_2 1

/**
 No flow control
 */
#define FLOW_NONE 0
/**
 RTS/CTS hardware flow control
 */
#define FLOW_RTS_CTS 1
/**
 DSR/DTR hardware flow control
 */
#define FLOW_DTR_DSR 2
/**
 XON/XOFF software flow control
 */
#define FLOW_XON_XOFF 3


/**
 Opens the external serial port with specified settings
 @param port the port number, currently only 1 is used
 @param baudRate serial baud rate
 @param parity serial parity, one of the PARITY_* constants (currenty only PARITY_NONE is supported)
 @param dataBits serial data bits, one of the DATABITS_* constants (currently only DATABITS_8 is supported)
 @param stopBits serial stop bits, one of the STOPBITS_* constants (currently only STOPBITS_1 is supported)
 @param flowControl serial flow control, one of the FLOW_* constants (currently only FLOW_NONE is supported)
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)extOpenSerialPort:(int)port baudRate:(int)baudRate parity:(int)parity dataBits:(int)dataBits stopBits:(int)stopBits flowControl:(int)flowControl error:(NSError **)error;

/**
 Closes the external serial port opened with extOpenSerialPort
 @param port the port number, currently only 1 is used
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)extCloseSerialPort:(int)port error:(NSError **)error;

/**
 Sends data to the connected remote device via serial port.
 @param port the port number, currently only 1 is used
 @param data data bytes to write
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)extWriteSerialPort:(int)port data:(NSData *)data error:(NSError **)error;

/**
 Reads data from the connected remote device via serial port.
 @param port the port number, currently only 1 is used
 @param length the maximum amount of data to read
 @param timeout timeout in seconds, passing 0 reads and returns the bytes currently in the buffer
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData with bytes received if function succeeded, nil otherwise
 */
-(NSData *)extReadSerialPort:(int)port length:(int)length timeout:(double)timeout error:(NSError **)error;

/**@}*/


/*******************************************************************************
 * TCP/IP COMMANDS
 *******************************************************************************/
/** @defgroup G_TCPIP TCP/IP Functions
 Functions to work with the supported devices over the network.
 @{
 */
/**
 Tries to connect to supported device over the network. Supported devices are the ones the sdk has built-in support for - printers and pinpads.
 If successful, additional functions will become available and feature notifications will be sent
 @note active connection with remote device will be broken
 @param address network address, either dns or IP. Optionaly provide a port number separated by : i.e. address:port. Default port is 9100.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)tcpConnectSupportedDevice:(NSString *)address error:(NSError **)error;

/**
 Disconnects from remote device.
 @param address the address to disconnect from, the same one that was used to connect to tcpConnectConnectSupportedDevice
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)tcpDisconnect:(NSString *)address error:(NSError **)error;

/**
 Contains tcp addresses of the currently connected network devices or empty array if no connected devices are found
 **/
@property(readonly) NSArray *tcpConnectedDevices;

/**@}*/

/** @defgroup G_LNCRYPTO Cryptographic & Security Functions
 Starting from firmware 2.13, Linea provides strong cryptographic support for magnetic card data. The encryption is supported on all Linea devices, from software point of view they are all the same, but provide different levels of hardware/firmware security.
 
 <br>An overview of the security, provided by Linea (see each of the crypto functions for further detail):
 
 <br>Hardware/Firmware:
 
 <br>For magnetic card encryption Linea is using AES256, which is the current industry standard encryption algorithm. The encryption key resides in volatile, battery powered ram inside Linea's cpu (for Linea 1.5 onward) and is being lost if anyone tries to break in the Linea device in order to prevent the key from being stolen. Magnetic card data, along with device serial number and some random bytes (to ensure every packet will be different) are being sent to the iOS program in an encrypted way.
 
 
 <br>Software:
 
 <br>Currently there are 2 types of keys, that can be loaded into Linea:
 - AUTHENTICATION KEY - used for device authentication (for example the program can lock itself to work with very specific Linea device) and encryption of the firmware
 - ENCRYPTION KEY - used for magnetic card data encryption. To use msr encryption, you don't need to set the AUTHENTICATION KEY.
 
 <br>Keys: The keys can be set/changed in two ways:
 
 <br>1. Using plain key data - this method is easy to use, but less secure, as it relies on program running on iPod/iPhone to have the key inside, an attacker could compromise the system and extract the key from device's memory. Call cryptoSetKey to set the keys this way. If there is an existing key of the same type inside Linea, you have to pass it too.
 
 <br>2. Using encrypted key data - this method is harder to implement, but provides better security - the key data, encrypted with old key data is sent from a server in secure environment to the program, running on the iOS, then the program forwards it to the Linea. The program itself have no means to decrypt the data, so an attacker can't possibly extract the key. Refer to cryptoSetKey documentation for more detailed description of the loading process.
 
 <br>The initial loading of the keys should always be done in a secure environment.
 
 <br>Magnetic card encryption:
 
 <br>Once ENCRYPTION KEY is set, all magnetic card data gets encrypted, and is now sent via magneticCardEncryptedData instead. The LineaDemo program contains sample code to decrypt the data block and extract the contents - the serial number and track data.
 
 <br>As with keys, card data can be extracted on the iOS device itself (less secure, the application needs to have the key inside) or be sent to a secure server to be processed. Note, that the encrypted data contains Linea's serial number too, this can be used for Data Origin Verification, to be sure someone is not trying to mimic data, coming from another device.
 
 
 <br>Demo program: the sample program now have "Crypto" tab, where key management can be tested:
 
 - New AES 256 key - type in the key you want to set (or change to)
 - Old AES 256 key - type in the previous key, or leave blank if you set the key for the first time
 
 <br>[SET AUTHENTICATION KEY] and [SET ENCRYPTION KEY] buttons allow you to use the key info in the text fields above to set the key.
 
 - Decryption key - type in the key, which the demo program will use to try to decrypt card data. This field should contain the
 ENCRYPTION KEY, or something random, if you want to test failed card data decryption.
 @{
 */

/**
 Generates 16 byte block of random numbers, required for some of the other crypto functions.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return 16 bytes of random numbers if function succeeded, nil otherwise
 */
-(NSData *)cryptoRawGenerateRandomData:(NSError **)error;

/**
 @note RAW crypto functions are harder to use and require more code, but are created to allow no secret keys to reside on the device, but all the operations can be execuded with data, sent from a secure server. See cryptoSetKey if you plan to use the key in the mobile device.
 
 <br>Used to store AES256 keys into Linea internal memory. Valid keys that can be set:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateDevice
 or cryptoAuthenticateDevice. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or magneticCardEncryptedRawData
 
 <br>Generally the key loading process, using "Raw" commands, a program on the iOS device and a server which holds the keys will look similar to:
 
 - (iOS program) calls cryptoRawGenerateRandomData to get 16 bytes block of random data and send these to the server
 - (Server) creates byte array of 48 bytes consisting of: [RANDOM DATA: 16 bytes][KEY DATA: 32 bytes]
 - (Server) if there is current encryption key set on the Linea (if you want to change existing key) the server encrypts the 48 bytes block with the OLD key
 - (Server) sends the result data back to the program
 - (iOS program) calls cryptoRawSetKey with KEY_ENCRYPTION and the data it received from the server
 - (Linea) tries to decrypt the key data if there was already key present, then extracts the key, verifies the random data and if everything is okay, sets the key
 @param keyID the key type to set - KEY_AUTHENTICATION or KEY_ENCRYPTION
 @param encryptedData - 48 bytes that consists of 16 bytes random numbers received via call to cryptoRawGenerateRandomData and 32 byte AES256 key. If there has been previous key of the same type, then all 48 bytes should be encrypted with it.
 @param keyVersion - the version of the key. On firmware versions less than 2.43 this parameter is ignored and key version is considered to be 0x00000000. Key version is useful for the program to determine what key is inside the head.
 @param keyFlags - optional key flags, supported on ver 2.58 and onward
 - KEY_AUTHENTICATION:
 <table>
 <tr><td>BIT 1</td><td>If set to 1, scanning barcodes, reading magnetic card and using the bluetooth module are locked and have to be unlocked with cryptoAuthenticateHost/cryptoRawAuthenticateHost upon every reinsert of the device</td></tr>
 </table>
 - KEY_ENCRYPTION: No flags are supported
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)cryptoRawSetKey:(int)keyID encryptedData:(NSData *)encryptedData keyVersion:(uint32_t)keyVersion keyFlags:(uint32_t)keyFlags error:(NSError **)error;

/**
 Used to store AES256 keys into Linea internal memory. Valid keys that can be set:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateDevice
 or cryptoAuthenticateDevice. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or magneticCardEncryptedRawData
 @param keyID the key type to set - KEY_AUTHENTICATION or KEY_ENCRYPTION
 @param key 32 bytes AES256 key to set
 @param oldKey 32 bytes AES256 key that was previously used, or null if there was no previous key. The old key should match the new key, i.e. if you are setting KEY_ENCRYPTION, then you should pass the old KEY_ENCRYPTION.
 @param keyVersion - the version of the key. On firmware versions less than 2.43 this parameter is ignored and key version is considered to be 0x00000000. Key version is useful for the program to determine what key is inside the head.
 @param keyFlags - optional key flags, supported on ver 2.58 and onward
 - KEY_AUTHENTICATION:
 <table>
 <tr><td>BIT 1</td><td>If set to 1, scanning barcodes, reading magnetic card and using the bluetooth module are locked and have to be unlocked with cryptoAuthenticateHost/cryptoRawAuthenticateHost upon every reinsert of the device</td></tr>
 </table>
 - KEY_ENCRYPTION: No flags are supported
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)cryptoSetKey:(int)keyID key:(NSData *)key oldKey:(NSData *)oldKey keyVersion:(uint32_t)keyVersion keyFlags:(uint32_t)keyFlags error:(NSError **)error;

/**
 Returns key version. Valid key ID:
 - KEY_AUTHENTICATION - if set, you can use authentication functions - cryptoRawAuthenticateDevice
 or cryptoAuthenticateDevice. Firmware updates will require authentication too
 - KEY_ENCRYPTION - if set, magnetic card data will come encrypted via magneticCardEncryptedData or magneticCardEncryptedRawData
 @param keyVersion returns key version or 0 if the key is not present (key versions are available in firmware 2.43 or later)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)cryptoGetKeyVersion:(int)keyID keyVersion:(uint32_t *)keyVersion error:(NSError **)error;

/**
 @note RAW crypto functions are harder to use and require more code, but are created to allow no secret keys to reside on the device, but all the operations can be execuded with data, sent from a secure server. See cryptoAuthenticateDevice if you plan to use the key in the mobile device.
 
 <br>Encrypts a 16 bytes block of random data with the stored authentication key and returns the result.
 
 <br>The idea: if a program wants to work with specific Linea device, it sets AES256 authentication key once, then on every connect the program generates random 16 byte block of data, encrypts it internally with the said key, then encrypts it with linea too and compares the result. If that Linea contains no key, or the key is different, the resulting data will totally differ from the one generated. This does not block Linea from operation, what action will be taken if devices mismatch depends on the program.
 @param randomData 16 bytes block of data (presumably random bytes)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return random data, encrypted with the Linea authentication key if function succeeded, nil otherwise
 */
-(NSData *)cryptoRawAuthenticateDevice:(NSData *)randomData error:(NSError **)error;

/**
 @note Check out the cryptoRawAuthenticateDevice function, if you want to not use the key inside the mobile device.
 
 <br>Generates random data, uses the key to encrypt it, then encrypts the same data with the stored authentication key inside Linea and returns true if both data matches.
 
 <br>The idea: if a program wants to work with specific Linea device, it sets AES256 authentication key once, then on every connect the program uses cryptoAuthenticateDevice with that key. If Linea contains no key, or the key is different, the function will return FALSE. This does not block Linea from operation, what action will be taken if devices mismatch depends on the program.
 @param key 32 bytes AES256 key
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if if Linea contains the same authentication key, FALSE otherwise
 */
-(BOOL)cryptoAuthenticateDevice:(NSData *)key error:(NSError **)error;

/**
 @note RAW crypto functions are harder to use and require more code, but are created to allow no secret keys to reside on the device, but all the operations can be execuded with data, sent from a secure server. See cryptoAuthenticateHost if you plan to use the key in the mobile device.
 
 <br>Tries to decrypt random data, generated from cryptoRawGenerateRandomData with the stored internal authentication key and returns the result. This function is used so that Linea knows a "real" device is currently connected, before allowing some functionality. Currently firmware update is protected by this function, once authentication key is set, you have to use it or cryptoAuthenticateHost before you attempt firmware update, or it will error out.
 
 <br>The idea (considering the iOS device does not have the keys inside, but depends on server):
 - (iOS program) generates random data using cryptoRawGenerateRandomData and sends to the server
 - (Server) encrypts the random data with the same AES256 key that is in the Linea and sends back to the iOS program
 - (iOS program) uses cryptoRawAuthenticateHost to authenticate with the data, function will error out if authentication fails.
 @param encryptedRandomData 16 bytes block of encrypted data
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)cryptoRawAuthenticateHost:(NSData *)encryptedRandomData error:(NSError **)error;

/**
 @note Check out the cryptoRawAuthenticateHost function, if you want to not use the key inside the mobile device.
 
 Generates random data, uses the key to encrypt it, then sends to Linea to verify against it's internal authentication key. If both keys match, return value is TRUE. This function is used so that Linea knows a "real" device is currently connected, before allowing some functionality. Currently firmware update is protected by this function, once authentication key is set, you have to use it or cryptoRawAuthenticateHost before you attempt firmware update, or it will error out.
 @param key 32 bytes AES256 key
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if Linea contains the same authentication key, FALSE otherwise
 */
-(BOOL)cryptoAuthenticateHost:(NSData *)key error:(NSError **)error;
/**@}*/


/*******************************************************************************
 * ENCRYPTED MAGNETIC HEAD COMMANDS
 *******************************************************************************/
/** @defgroup G_LEMSR Encrypted Magnetic Head Functions
 Functions to work with encrypted magnetic head
 @{
 */

#define LN_EMSR_EBASE -11000
/** Encrypted magnetic head invalid command sent. */
#define LN_EMSR_EINVALID_COMMAND LN_EMSR_EBASE-0x01
/** Encrypted magnetic head no permission error. */
#define LN_EMSR_ENO_PERMISSION LN_EMSR_EBASE-0x02
/** Encrypted magnetic head card error. */
#define LN_EMSR_ECARD LN_EMSR_EBASE-0x03
/** Encrypted magnetic head command syntax error. */
#define LN_EMSR_ESYNTAX LN_EMSR_EBASE-0x04
/** Encrypted magnetic head command no response from the magnetic chip. */
#define LN_EMSR_ENO_RESPONSE LN_EMSR_EBASE-0x05
/** Encrypted magnetic head no data available. */
#define LN_EMSR_ENO_DATA LN_EMSR_EBASE-0x06
/** Encrypted magnetic head invalid data length. */
#define LN_EMSR_EINVALID_LENGTH LN_EMSR_EBASE-0x14
/** Encrypted magnetic head is tampered. */
#define LN_EMSR_ETAMPERED LN_EMSR_EBASE-0x15
/** Encrypted magnetic head invalid signature. */
#define LN_EMSR_EINVALID_SIGNATURE LN_EMSR_EBASE-0x16
/** Encrypted magnetic head hardware failure. */
#define LN_EMSR_EHARDWARE LN_EMSR_EBASE-0x17


/**
 Returns information about the specified head firmware data. Based on it, and the current head's name and firmware version you can chose to update or not the head's firmware
 @param data - firmware data
 @return dictionary containing extracted data or nil if the data is invalid. Keys contained are:
 <table>
 <tr><td>"deviceModel"</td><td>Head's model, for example "EMSR-DEA"</td></tr>
 <tr><td>"firmwareRevision"</td><td>Firmware revision as string, for example 1.07</td></tr>
 <tr><td>"firmwareRevisionNumber"</td><td>Firmware revision as number MAJOR*100+MINOR, i.e. 1.07 will be returned as 107</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(NSDictionary *)emsrGetFirmwareInformation:(NSData *)data error:(NSError **)error;

/**
 Checks if the head was tampered or not. If the head's tamper protection have activated, the device should be sent to service for checks
 @return true if the head was tampered and not operational
 */
-(BOOL)emsrIsTampered:(BOOL *)tampered error:(NSError **)error;

/**
 Retrieves the key version (if any) of a loaded key
 @param keyID the ID of the key to get the version, one of the KEY_* constants
 @param keyVersion - pointer to integer, where key version will be returned upon success. Key version can be 0.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrGetKeyVersion:(int)keyID keyVersion:(int *)keyVersion error:(NSError **)error;

/**
 Loads Terminal Master Key (TMK) or reenable after tampering. This command is enabled only if the device is in tamper mode or there is no TMK key yet. If the command is executed in normal mode an error will be returned. To reenable the device after tampering the old TMK key must be passed as an argument. If the keys do not match error will be returned.
 @param keyData an array, that consists of:
 - BLOCK IDENT - 1 byte, set to 0x29
 - KEY ID - the ID of the key to set, put KEY_TMK_AES (0x10)
 - KEY VERSION - the version of the key in high to low order, 4 bytes, cannot be 0
 - KEY - the key data, 16 bytes
 - HASH - SHA256 of the previous bytes (BLOCK IDENT, KEY ID, KEY VERSION and KEY)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrLoadInitialKey:(NSData *)keyData error:(NSError **)error;

/**
 Loads new key, in plain or encrypted with already loaded AES256 Key Encryption Key (KEK). Plain text loading works only the first time the specified key is loaded and is recommended only in secure environment. For normal usage the new key should be encrypted with the Key Encryption Key (KEK). The command is unavailable if the device is tampred.
 @param keyData an array, that consists of:
 - MAGIC NUMBER - (1 byte) 0x2b
 - ENCRYPTION KEY ID - (1 byte) the ID of the already existing key, used to encrypt the new key data. Set it to KEY_EH_AES256_LOADING (0x02) if you want to set the key in encrypted state or 0xFF for plain state.
 - KEY ID - (1 byte) the ID of the key to set, one of the KEY_ constants. The TMK cannot be changed with this command.
 - KEY VERSION - (4 bytes) the version of the key in high to low order, 4 bytes, cannot be 0
 - KEY - (variable) the key data, length depends on the key in question, AES256 keys are 32 bytes, DUKPT key is 16 bytes key, 10 bytes serial, 6 bytes for padding (zeroes)
 - HASH - SHA256 of the previous bytes (MAGIC NUMBER, ENCRYPTION KEY ID, KEY ID, KEY VERSION, KEY)
 
 <br>If using KEY_EH_AES256_LOADING, then KEY + HASH have to be put inside the packet encrypted with AES256 using key KEY_EH_AES256_LOADING. SHA256 is calculated on the unencrypted data. The head decrypts the data and then calculates and compares the hash. If the calculated SHA does not match the SHA sent with the command, the key excahnge is rejected and error is returned.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrLoadKey:(NSData *)keyData error:(NSError **)error;

/**
 Returns DUKPT serial number, if DUKPT key is set
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return serial number or nil if an error occured
 */
-(NSData *)emsrGetDUKPTSerial:(NSError **)error;

/**
 Returns head's model
 @return head's model as string
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(NSString *)emsrGetDeviceModel:(NSError **)error;

/**
 Returns head's firmware version as number MAJOR*100+MINOR, i.e. version 1.05 will be sent as 105
 @param version integer, where firmware version is stored upon success
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrGetFirmwareVersion:(int *)version error:(NSError **)error;

/**
 Returns head's security version as number MAJOR*100+MINOR, i.e. version 1.05 will be sent as 105. Security version is the version of the certificated security kernel.
 @param version integer, where firmware version is stored upon success
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrGetSecurityVersion:(int *)version error:(NSError **)error;

/**
 Return head's unique serial number as byte array
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return serial number or nil if an error occured
 */
-(NSData *)emsrGetSerialNumber:(NSError **)error;

/**
 Performs firmware update on the encrypted head.
 DO NOT INTERRUPT THE COMMUNICATION DURING THE FIRMWARE UPDATE!
 @param data firmware file data
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrUpdateFirmware:(NSData *)data error:(NSError **)error;

/**
 Returns supported encryption algorhtms by the encrypted head.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return an array of supported algorithms or nil if an error occured
 */
-(NSArray *)emsrGetSupportedEncryptions:(NSError **)error;

/**
 Selects the prefered encryption algorithm. When card is swiped, it will be encrypted by it and sent via magneticCardEncryptedData delegate
 @param encryption encryption algorhtm used, one o fthe ALG_* constants
 @param params optional algorithm parameters, currently no algorithm supports these
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrSetEncryption:(int)encryption params:(NSDictionary *)params error:(NSError **)error;

/**
 Fine-tunes which part of the card data will be masked, and which will be sent in clear text for display/print purposes
 @param showExpiration if set to TRUE, expiration date will be shown in clear text, otherwise will be masked
 @param unmaskedDigitsAtStart the number of digits to show in clear text at the start of the PAN, range from 0 to 6 (default is 4)
 @param unmaskedDigitsAtEnd the number of digits to show in clear text at the end of the PAN, range from 0, to 4 (default is 4)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)emsrConfigMaskedDataShowExpiration:(BOOL)showExpiration unmaskedDigitsAtStart:(int)unmaskedDigitsAtStart unmaskedDigitsAtEnd:(int)unmaskedDigitsAtEnd error:(NSError **)error;

-(BOOL)emsrLoadRSAKeyPEM:(NSString *)pem version:(int)version error:(NSError **)error;

/**
 Returns general information about the encrypted head - firmware version, ident, serial number
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return EMSRDeviceInfo object if function succeeded, nil otherwise
 **/
-(EMSRDeviceInfo *)emsrGetDeviceInfo:(NSError **)error;

/**
 Returns information about the loaded keys in the encrypted head and tampered status
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return EMSRKeysInfo object if function succeeded, nil otherwise
 **/
-(EMSRKeysInfo *)emsrGetKeysInfo:(NSError **)error;

/**@}*/

/*******************************************************************************
 * VOLTAGE COMMANDS
 *******************************************************************************/
/** @defgroup G_LNVOLTAGE Voltage Functions
 Functions to work with voltage card endcryption
 @{
 */

/**
 Returns various information about Voltage state
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return DTVoltageInfo class if function succeeded, nil otherwise
 */
-(DTVoltageInfo *)voltageGetInfo:(NSError **)error;

/**
 Sets public parameters to be used with ETB genration. After changing public parameters, be sure to call voltageGenerateNewKey function
 @param publicParameters public parameters block or nil to use the built-in test ones
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)voltageSetPublicParameters:(NSData *)publicParameters error:(NSError **)error;

/**
 Sets identity string to be used with ETB genration. After changing identity string, be sure to call voltageGenerateNewKey function
 @param identityString identity string to be used, pass nil if you want to use the test one
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)voltageSetIdentityString:(NSString *)identityString error:(NSError **)error;

/**
 Sets merchant ID.
 @param merchantID merchant ID number
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)voltageSetMerchantID:(NSString *)merchantID error:(NSError **)error;

/**
 Sets encryption type
 @param type encryption type - VOLTAGE_ENCRYPTION_FULL or VOLTAGE_ENCRYPTION_SPE
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)voltageSetEncryptionType:(int)type error:(NSError **)error;

/**
 Sets settings version
 @param version settings version
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)voltageSetSettingsVersion:(int)version error:(NSError **)error;

/**
 Sets how often a new key will be generated. Generating key is a long process. Currently this function has no effect!
 @param days keys will be regenerated after that number of days, pass 0 to disable that
 @param numberOfTransactions keys will be regenerated after the specified number of transactions, pass 0 to disable that
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)voltageSetKeyRolloverDays:(int)days numberOfTransactions:(int)numberOfTransactions error:(NSError **)error;

/**
 Forces generation of a new key. This is asynchronous process, you can query the current state of key generation via voltageGetInfo
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)voltageGenerateNewKey:(NSError **)error;

/**@}*/

/*******************************************************************************
 * RF READER COMMANDS
 *******************************************************************************/
/** @defgroup G_LNRFREADER RF Reader Functions
 Functions to work with the RF cards reader
 @{
 */

/**
 ISO14443 Type A (Mifare) cards will be detected
 */
#define CARD_SUPPORT_TYPE_A 0x0001
/**
 ISO14443 Type B cards will be detected. Currently unsupported.
 */
#define CARD_SUPPORT_TYPE_B 0x0002
/**
 Felica cards will be detected.
 */
#define CARD_SUPPORT_FELICA 0x0004
/**
 NFC cards will be detected. Currently unsupported.
 */
#define CARD_SUPPORT_NFC 0x0008
/**
 Jewel cards will be detected. Currently unsupported.
 */
#define CARD_SUPPORT_JEWEL 0x0010
/**
 ISO15693 cards will be detected
 */
#define CARD_SUPPORT_ISO15 0x0020
/**
 ST SRI cards will be detected
 */
#define CARD_SUPPORT_STSRI 0x0040
/**
 PicoPass ISO14443-A
 */
#define CARD_SUPPORT_PICOPASS_ISO14 0x0080
/**
 PicoPass ISO15693
 */
#define CARD_SUPPORT_PICOPASS_ISO15 0x0100

/**
 Initializes and powers on the RF card reader module. Call this function before any other RF card functions. The module power consumption is highly optimized, so it can be left on for extended periods of time.
 @param supportedCards any combination of CARD_SUPPORT_* flags to mark which card types to be active. Enable only cards you actually plan to work with, this has high implication on power usage and detection speed.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)rfInit:(int)supportedCards error:(NSError **)error;
/**
 Powers down RF card reader module. Call this function after you are done with the reader.
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)rfClose:(NSError **)error;
/**
 Call this function once you are done with the card, a delegate call rfCardRemoved will be called when the card leaves the RF field and new card is ready to be detected
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)rfRemoveCard:(int)cardIndex error:(NSError **)error;
/**
 Authenticate mifare card block with direct key data. This is less secure method, as it requires the key to be present in the program, the prefered way is to store a key once in a secure environment and then authenticate using the stored key.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param type key type, either 'A' or 'B'
 @param address the address of the block to authenticate
 @param key 6 bytes key
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)mfAuthByKey:(int)cardIndex type:(char)type address:(int)address key:(NSData *)key error:(NSError **)error;
/**
 Store key in the internal module memory for later use
 @param keyIndex the index of the key, you can have up to 8 keys stored (0-7)
 @param type key type, either 'A' or 'B'
 @param key 6 bytes key
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)mfStoreKeyIndex:(int)keyIndex type:(char)type key:(NSData *)key error:(NSError **)error;
/**
 Authenticate mifare card block with previously stored key. This the prefered method, as no key needs to reside in application.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param type key type, either 'A' or 'B'
 @param address the address of the block to authenticate
 @param keyIndex the index of the stored key, you can have up to 8 keys stored (0-7)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)mfAuthByStoredKey:(int)cardIndex type:(char)type address:(int)address keyIndex:(int)keyIndex error:(NSError **)error;
/**
 Reads one more more blocks of data from Mifare Classic/Ultralight cards. A single read operation gets 16 bytes of data, so you can pass 32 on length to read 2 blocks, etc
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param address the address of the block to read
 @param length the number of bytes to read, this must be multiple of block size (16 bytes)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData object containing the data received or nil if an error occured
 */
-(NSData *)mfRead:(int)cardIndex address:(int)address length:(int)length error:(NSError **)error;
/**
 Writes one more more blocks of data to Mifare Classic/Ultralight cards. A single write operation stores 16 bytes of data, so you can pass 32 on length to write 2 blocks, etc
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param address the address of the block to write
 @param data the data to write, must be multiple of the block size (16 bytes)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return number of bytes actually written or 0 if an error occured
 */
-(int)mfWrite:(int)cardIndex address:(int)address data:(NSData *)data error:(NSError **)error;
/**
 Sets the 3DES key of Mifare Ultralight C cards
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param key 16 bytes 3DES key to set
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)mfUlcSetKey:(int)cardIndex key:(NSData *)key error:(NSError **)error;
/**
 Performs 3DES authentication of Mifare Ultralight C card using the given key
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param key 16 bytes 3DES key to authenticate with
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)mfUlcAuthByKey:(int)cardIndex key:(NSData *)key error:(NSError **)error;
/**
 Reads one more more blocks of data from ISO 15693 card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param startBlock the starting block to read from
 @param length the number of bytes to read, this must be multiple of block size (can be taken from the card info that is coming with rfCardDetected call)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData object containing the data received or nil if an error occured
 */
-(NSData *)iso15693Read:(int)cardIndex startBlock:(int)startBlock length:(int)length error:(NSError **)error;
/**
 Writes one more more blocks of data to ISO 15693 card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param startBlock the starting block to write to
 @param data the data to write, it must be multiple of block size (can be taken from the card info that is coming with rfCardDetected call)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return number of bytes actually written or 0 if an error occured
 */
-(int)iso15693Write:(int)cardIndex startBlock:(int)startBlock data:(NSData *)data error:(NSError **)error;
/**
 Reads the security status of one more more blocks from ISO 15693 card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param startBlock the starting block to read from
 @param nBlocks the number of blocks to get the security status
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData object containing the data received or nil if an error occured
 */
-(NSData *)iso15693GetBlocksSecurityStatus:(int)cardIndex startBlock:(int)startBlock nBlocks:(int)nBlocks error:(NSError **)error;
/**
 Locks a single ISO 15693 card block. Locked blocks cannot be written upon anymore.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param block the block index to lock
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)iso15693LockBlock:(int)cardIndex block:(int)block error:(NSError **)error;
/**
 Changes ISO 15693 card AFI.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param afi new AFI value
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)iso15693WriteAFI:(int)cardIndex afi:(uint8_t)afi error:(NSError **)error;
/**
 Locks ISO 15693 AFI preventing further changes.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)iso15693LockAFI:(int)cardIndex error:(NSError **)error;
/**
 Changes ISO 15693 card DSFID.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param dsfid new DSFID value
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)iso15693WriteDSFID:(int)cardIndex dsfid:(uint8_t)dsfid error:(NSError **)error;
/**
 Locks ISO 15693 card DSFID preventing further changes.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)iso15693LockDSFID:(int)cardIndex error:(NSError **)error;

/**
 Initializes ISO1443B card and returns Answer To Select. Call this function before further communication with the card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return Answer To Select data, or nil if command failed
 */
-(NSData *)iso14GetATS:(int)cardIndex error:(NSError **)error;
/**
 Executes APDU command on ISO1443B compatible card. The card must be initialized with iso14GetATS first
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param cla CLA parameter, refer to card documentation
 @param ins INS parameter, refer to card documentation
 @param p1 P1 parameter, refer to card documentation
 @param p2 P2 parameter, refer to card documentation
 @param data optional data with the command
 @param apduResult every APDU command sends 2 bytes result code, refer to card documentation
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return APDU response data or empty object, or nil if command failed
 */
-(NSData *)iso14APDU:(int)cardIndex cla:(uint8_t)cla ins:(uint8_t)ins p1:(uint8_t)p1 p2:(uint8_t)p2 data:(NSData *)data apduResult:(uint16_t *)apduResult error:(NSError **)error;

/**
 Sets polling parameters of FeliCa card. Call this function before rfInit!
 @param requestCode request code, refer to FeliCa documentation, default is 1
 @param systemCode system code, refer to FeliCa documentation, default is 0xFFFF
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)felicaSetPollingParamsRequestCode:(int)requestCode systemCode:(int)systemCode error:(NSError **)error;

/**
 Executes a raw command on FeliCa card. The IDm(UUID) parameter is automatically added and needs to be skipped.
 @example To read block 0 with service code 0x0900, then you need to send command 06 with data 01 09 00 01 80 00
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param command command code, refer to FeliCa documentation
 @param data optional data to the command
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData object containing the data received or nil if an error occured. Received data contains command code (1 byte) and command data, IDm(UUID) is skipped
 */
-(NSData *)felicaSendCommand:(int)cardIndex command:(int)command data:(NSData *)data error:(NSError **)error;

/**
 Reads one more more blocks of data from FeliCa card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param serviceCode the service code, default is 0x0900
 @param startBlock the starting block to read from
 @param length the number of bytes to read, this must be multiple of block size (can be taken from the card info that is coming with rfCardDetected call)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData object containing the data received or nil if an error occured
 */
-(NSData *)felicaRead:(int)cardIndex serviceCode:(int)serviceCode startBlock:(int)startBlock length:(int)length error:(NSError **)error;
/**
 Writes one more more blocks of data to FeliCa card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param serviceCode the service code, default is 0x0900
 @param startBlock the starting block to write to
 @param data the data to write, it must be multiple of block size (can be taken from the card info that is coming with rfCardDetected call)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return number of bytes actually written or 0 if an error occured
 */
-(int)felicaWrite:(int)cardIndex serviceCode:(int)serviceCode startBlock:(int)startBlock data:(NSData *)data error:(NSError **)error;

/**
 Returns FeliCa SmartTag battery status
 @note Call this function before any other SmartTag
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param status upon successful execution, battery status will be returned here, one of FELICA_SMARTTAG_BATTERY_* constants
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)felicaSmartTagGetBatteryStatus:(int)cardIndex status:(int *)status error:(NSError **)error;
/**
 Clears the screen of FeliCa SmartTag
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param status upon successful execution, battery status will be returned here, one of FELICA_SMARTTAG_BATTERY_* constants
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)felicaSmartTagClearScreen:(int)cardIndex error:(NSError **)error;
/**
 Draws image on FeliCa SmartTag's screen. The screen is 200x96 pixels.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param image image to draw
 @param topLeftX - topleft X coordinate in pixels
 @param topLeftY - topleft Y coordinate in pixels
 @param drawMode draw mode, one of the FELICA_SMARTTAG_DRAW_* constants
 @param layout only used when drawMode is FELICA_SMARTTAG_DRAW_USE_LAYOUT, it specifies the index of the layout (1-12) of the previously stored image
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)felicaSmartTagDrawImage:(int)cardIndex image:(UIImage *)image topLeftX:(int)topLeftX topLeftY:(int)topLeftY drawMode:(int)drawMode layout:(int)layout error:(NSError **)error;
/**
 Saves the current display as layout number
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param layout layout index (1-12) to which the currently displayed image will be saved
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)felicaSmartTagSaveLayout:(int)cardIndex layout:(int)layout error:(NSError **)error;
/**
 Displays previously stored layout
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param layout layout index (1-12) of the previously stored image
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)felicaSmartTagDisplayLayout:(int)cardIndex layout:(int)layout error:(NSError **)error;
/**
 Writes data in FeliCa SmartTag.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param address the address of the card to write to, refer to SmartTag documentation
 @param data data to write, note that the data does not need to be aligned to block size
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return number of bytes actually written or 0 if an error occured
 */
-(int)felicaSmartTagWrite:(int)cardIndex address:(int)address data:(NSData *)data error:(NSError **)error;
/**
 Writes data in FeliCa SmartTag.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param address the address of the card to read from, refer to SmartTag documentation
 @param length of the data to read, note that the data does not need to be aligned to block size
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData object containing the data received or nil if an error occured
 */
-(NSData *)felicaSmartTagRead:(int)cardIndex address:(int)address length:(int)length error:(NSError **)error;
/**
 Waits for FeliCa SmartTag to complete current operation. Waiting is generally not needed, but needed in case for example drawing an image and then saving the layout, you need to wait for the image to be drawn.
 Write operation forces waiting internally.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)felicaSmartTagWaitCompletion:(int)cardIndex error:(NSError **)error;

/**
 Reads one more more blocks of data from ST SRI card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param address the starting block to read from
 @param length the number of bytes to read, this must be multiple of block size (can be taken from the card info that is coming with rfCardDetected call)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return NSData object containing the data received or nil if an error occured
 */
-(NSData *)stSRIRead:(int)cardIndex address:(int)address length:(int)length error:(NSError **)error;
/**
 Writes one more more blocks of data to ST SRI card.
 @param cardIndex the index of the card as sent by rfCardDetected delegate call
 @param address the starting block to write to
 @param data the data to write, it must be multiple of block size (can be taken from the card info that is coming with rfCardDetected call)
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return number of bytes actually written or 0 if an error occured
 */
-(int)stSRIWrite:(int)cardIndex address:(int)address data:(NSData *)data error:(NSError **)error;


-(NSData *)hidGetVersionInfo:(NSError **)error;
-(NSData *)hidGetSerialNumber:(NSError **)error;
-(NSData *)hidGetContentElement:(int)contentTag pin:(NSData *)pin rootSoOID:(NSData *)rootSoOID error:(NSError **)error;
/**@}*/

/** @defgroup G_PPSMARTCARD SmartCard Functions
 This section includes functions to access SmartCard module and operate with SmartCards
 @{
 */

/**
 Initializes SmartCard module. Call this function before any other SmartCard related one. Without
 initialization, no SmartCard events will be fired.
 @param slot - which slot you want to operate with, one of:
 <table>
 <tr><td>SLOT_MAIN</td><td>main SmartCard slot</td></tr>
 <tr><td>SLOT_SAM</td><td>SAM module slot</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)scInit:(SC_SLOTS)slot error:(NSError **)error;

/**
 Powers on the SmartCard, resets it and returns ATR (Answer To Reset). Call this function before you perform any APDU commands
 @param slot - which slot you want to operate with, one of:
 <table>
 <tr><td>SLOT_MAIN</td><td>main SmartCard slot</td></tr>
 <tr><td>SLOT_SAM</td><td>SAM module slot</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return ATR response data if function succeeded or nil otherwise
 **/
-(NSData *)scCardPowerOn:(SC_SLOTS)slot error:(NSError **)error;

/**
 Powers off SmartCard, call this function when you are done with the card.
 @param slot - which slot you want to operate with, one of:
 <table>
 <tr><td>SLOT_MAIN</td><td>main SmartCard slot</td></tr>
 <tr><td>SLOT_SAM</td><td>SAM module slot</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)scCardPowerOff:(SC_SLOTS)slot error:(NSError **)error;

/**
 Manually checks if there is a card in the reader
 @param slot - which slot you want to operate with, one of:
 <table>
 <tr><td>SLOT_MAIN</td><td>main SmartCard slot</td></tr>
 <tr><td>SLOT_SAM</td><td>SAM module slot</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if card is present, FALSE otherwise
 **/
-(BOOL)scIsCardPresent:(SC_SLOTS)slot error:(NSError **)error;

/**
 Performs APDU command in the card
 @param slot - which slot you want to operate with, one of:
 <table>
 <tr><td>SLOT_MAIN</td><td>main SmartCard slot</td></tr>
 <tr><td>SLOT_SAM</td><td>SAM module slot</td></tr>
 </table>
 @param apdu - the APDU command
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return APDU response data if function succeeded, nil otherwise
 **/
-(NSData *)scCAPDU:(SC_SLOTS)slot apdu:(NSData *)apdu error:(NSError **)error;

/**
 Shuts down SmartCard module
 @param slot - which slot you want to operate with, one of:
 <table>
 <tr><td>SLOT_MAIN</td><td>main SmartCard slot</td></tr>
 <tr><td>SLOT_SAM</td><td>SAM module slot</td></tr>
 </table>
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)scClose:(SC_SLOTS)slot error:(NSError **)error;

/**@}*/

/** @defgroup G_PINPAD Pinpad functions
 Specific functions to work with the pinpad - entering and getting pin data, managing keys
 @{
 */
/**
 Initiates asynchronous PIN entry procedure. The PIN is stored encrypted and protected inside the pinpad.
 This function is not blocking, it passes the answer via delegate. Currently this function calls internal synchronous function from a thread
 and notifies about the result, but future firmware versions will have native support where you can cancel pin entry too.
 @param startX - X coordinate in characters from the left end of the defined window where the PIN entry prompt will be drawn
 @param startY - Y coordinate in characters from the top of the defined window where the PIN entry prompt will be drawn
 @param timeout - timeout in seconds waiting for the user to enter the pin (10-180)
 @param echoChar - symbol used to mark the pin digits, allowed are '*', '+' or '-'
 @param message - text to be displayed to the user. You can use <CR> to move the cursor to the next line.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)ppadStartPINEntry:(int)startX startY:(int)startY timeout:(int)timeout echoChar:(char)echoChar message:(NSString *)message error:(NSError **)error;

/**
 Tries to cancel asynchronous PIN entry procedure. Current pinpad versions do not have native support for async PIN, so this
 function always returns an error, but it will be implemented in the future.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)ppadCancelPINEntry:(NSError **)error;

/**
 Initiates synchronous magnetic card entry procedure. The magnetic card data is stored encrypted and protected inside the pinpad.
 After successful operation card data is sent like any other card read operation - via magneticCardEncryptedData with the encryption selected via emsrSetEncryption. This function is blocking and can take up to timeout seconds, so make sure to call it on a thread or dispatch_async
 @param language - the language to display promt on, one of the LANG_* constants
 @param startY - Y coordinate in characters from the top of the defined window where the PIN entry prompt will be drawn
 @param timeout - timeout in seconds waiting for the user to enter the card data (10-180)
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)ppadMagneticCardEntry:(int)language timeout:(int)timeout error:(NSError **)error;

/**
 Gets encrypted pin data using pre-loaded 3DES key
 The returned data consists of:
 - 3DES Encrypted PIN code, according to the selected format (8 bytes)
 @param fixedKeyID - key ID (1-49)
 @param keyVariant 16 bytes of data, that is XOR-ed with the key before encrypting. Pass nil if you don't want that.
 @param pinFormat PIN format, one of the PIN_FORMAT_* constants, according to ISO 9564
 @param error returns error information, you can pass nil if you don't want it
 @return key information object upon success, nil otherwise
 **/
-(NSData *)ppadGetPINBlockUsingFixedKey:(int)fixedKeyID keyVariant:(NSData *)keyVariant pinFormat:(int)pinFormat error:(NSError **)error;

/**
 Gets encrypted pin data using DUKPT.
 The returned data consists of:
 - DUKPT/3DES Encrypted PIN code, according to the selected format (8 bytes)
 - Current Key Serial Number (10 bytes)
 @param dukptKeyID - DUKPT key ID (0-1)
 @param keyVariant 16 bytes of data, that is XOR-ed with the key before encrypting. Pass nil if you don't want that.
 @param pinFormat PIN format, one of the PIN_FORMAT_* constants, according to ISO 9564
 @param error returns error information, you can pass nil if you don't want it
 @return key information object upon success, nil otherwise
 **/
-(NSData *)pinGetPINBlockUsingDUKPT:(int)dukptKeyID keyVariant:(NSData *)keyVariant pinFormat:(int)pinFormat error:(NSError **)error;

/**
 Gets information about some of the keys loaded in the pinpad.
 @param keyID - key ID (1-49)
 @param error returns error information, you can pass nil if you don't want it
 @return key information object upon success, nil otherwise
 **/
-(DTKeyInfo *)ppadGetKeyInfo:(int)keyID error:(NSError **)error;

/**
 Loads/changes 3DES key into the pinpad. The key is encrypted via 3DES (ECB or CBC) by a Key Encryption Key already loaded.
 If KBPK type is used as KEK, then only other KEK (data encrypt, decrypt, pin) can be loadead, not the data key itself.
 @param keyID - key the index of key, used to decrypt the encrypted key data when loading. The value can be between 0 and 49, where on index 0 resides the HMK key
 @param kekID - key the index where key shall be saved. For DUKPT keys this value can be between 0 and 1. For other keys the value can be between 1 and 49
 @param usage the key usage (type of key) attributes. See the KEY_USAGE_* constant field values.
 @param version the key version. Not used if key usage is KEY_USAGE_DUKPT
 @param data the 16 or 26 byte of input data to be processed. The first 16 bytes must contains encrypted key and next 10 bytes (if presents) are key serial number.
 @param error returns error information, you can pass nil if you don't want it
 @return key check value upon success, nil otherwise
 **/
-(NSData *)ppadCryptoExchangeKeyID:(int)keyID kekID:(int)kekID usage:(int)usage version:(int)version data:(NSData *)data cbc:(BOOL)cbc error:(NSError **)error;

/**
 Loads/changes 3DES key into the pinpad. The key is encrypted with TR31 by an already loaded KEK, KBPK or HMK
 If KBPK type is used as KEK, then all key types can be loaded.
 @param keyID - key the index of key, used to decrypt the encrypted key data when loading. The value can be between 0 and 49, where on index 0 resides the HMK key
 @param kekID - key the index where key shall be saved. For DUKPT keys this value can be between 0 and 1. For other keys the value can be between 1 and 49
 @param tr31 the TR31 data block
 @param error returns error information, you can pass nil if you don't want it
 @return key check value upon success, nil otherwise
 **/
-(NSData *)ppadCryptoTR31ExchangeKeyID:(int)keyID kekID:(int)kekID tr31:(NSString *)tr31 error:(NSError **)error;

/**
 Sets the text that is drawn above functional buttons in MPED400.
 @param buttonIndex - functional button index (1-3) 
 @param caption - text to display
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)ppadSetButtonCaption:(int)buttonIndex caption:(NSString *)caption error:(NSError **)error;

/**
 Returns pinpad specific information
 @param error returns error information, you can pass nil if you don't want it
 @return class containing pinpad information or nil if function failed
 **/
-(DTPinpadInfo *)ppadGetSystemInfo:(NSError **)error;

/**
 Captures or releases keyboard.
 <br>PinPad internally reads the keyboard to operate menus and such, if you want to be able to read keys, then you have to capture
 it before that, and release after.
 @param capture - capture the keyboard if TRUE, release if FALSE
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)ppadKeyboardControl:(BOOL)capture error:(NSError **)error;

/**
 Reads key from the pinpad. Кеy codes are:
 <table>
 <tr><td>0x00</td><td>No key have been pressed</td></tr>
 <tr><td>0x01/0x03</td><td>Numeric key have been pressed, but no numeric mode is enabled</td></tr>
 <tr><td>'0'-'9'</td><td>Number keys 0-9, available only in numeric mode</td></tr>
 <tr><td>'A'</td><td>Accept button have been pressed</td></tr>
 <tr><td>'C'</td><td>Cancel button have been pressed</td></tr>
 <tr><td>'a','b','c'</td><td>Functional buttons 1-3</td></tr>
 </table>
 @param key - stores key upon return
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)ppadReadKey:(char *)key error:(NSError **)error;
/**@}*/


/** @defgroup G_PPCA Certification Authority Functions
 This section includes functions for managing CA keys
 @{
 */

/**
 Import CA key.
 @param keyNumber - key number (0-29)
 @param RIDI - DIR+index (6 bytes)
 @param module - key module (32-248 bytes)
 @param exponent - key exponent (1-3 bytes typical)
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)caImportKeyNumber:(int)keyNumber RIDI:(NSData *)RIDI module:(NSData *)module exponent:(NSData *)exponent error:(NSError **)error;

/**
 Writes CA keys to flash. It is important to call this function after changing the keys if you don't want to lose them after device is turned off.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)caWriteKeysToFlash:(NSError **)error;

/**
 Returns keys data.
 @param error returns error information, you can pass nil if you don't want it
 @return array of RFCAKeyData objects or nil if function failed
 **/
-(NSArray *)caGetKeysData:(NSError **)error;

/**
 Import issuer key.
 @param keyNumber - key number to decrypt issuer key (0-29)
 @param exponent - exponent
 @param remainder - remainder
 @param certificate - certificate
 @param error returns error information, you can pass nil if you don't want it
 @return decrypted certificate or nil if function failed
 **/
-(NSData *)caImportIssuerKeyNumber:(int)keyNumber exponent:(NSData *)exponent remainder:(NSData *)remainder certificate:(NSData *)certificate error:(NSError **)error;

/**
 Import ICC key.
 @param keyType - key type, one of:
 <table>
 <tr><td>TYPE_ICC</td><td>ICC</td></tr>
 <tr><td>TYPE_PIN</td><td>PIN</td></tr>
 </table>
 @param exponent - exponent
 @param remainder - remainder
 @param certificate - certificate
 @param error returns error information, you can pass nil if you don't want it
 @return decrypted certificate or nil if function failed
 **/
-(NSData *)caImportICCKeyType:(ICC_TYPES)keyType exponent:(NSData *)exponent remainder:(NSData *)remainder certificate:(NSData *)certificate error:(NSError **)error;

/**
 RSA verify.
 @param keyType - key type, one of:
 <table>
 <tr><td>KEY_ISSUER</td><td>Issuer key</td></tr>
 <tr><td>KEY_ICC</td><td>ICC key</td></tr>
 </table>
 @param inData - input data
 @param error returns error information, you can pass nil if you don't want it
 @return output data or nil if function failed
 **/
-(NSData *)caRSAVerify:(RSA_VERIFY_KEY)keyType inData:(NSData *)inData error:(NSError **)error;

/**@}*/


/** @defgroup G_PPEMV EMV Kernel
 EMV Level 2 kernel functions, structures and defnitions.
 
 <p><b>Kernel initialisation and version verification</b>
 <br>Firstly the application will have to initialise the library, this will only have to be done once at the unit power up.
 At the same time it will be convenient also to check the version info provided by the kernel to make sure that is the expected one.
 <br>After the initialisation, the first thing to do will be to set all the data items needed to start the transaction, mainly these items
 correspond to configuration issues:
 @image html diagram_a.png
 @image latex diagram_a.eps "Kernel initialisation and version verification" width=15cm
 
 <p><b>Card recognition and ATR validation</b>
 <p>The application will be in charge of detecting the presence of the smart card in the reader using the corresponding firmware function call,
 the application must power on the card also, the kernel is used in this phase to validate the ATR got from the card.
 @image html diagram_b.png
 @image latex diagram_b.eps "Card recognition and ATR validation" width=15cm
 
 <p><b>Application selection & initiation</b>
 <p>Once the card has been powered on and the ATR validated to ensure that is a valid EMV card, the next step is to proceed
 with the application selection and initiation.
 @image html diagram_c.png
 @image latex diagram_c.eps "Application selection & initiation" width=15cm
 
 <p><b>Transaction data processing</b>
 <p>Next the rest of the EMV transaction phases will be completed prior to the transaction decision, this includes:
 
 <br>Card data authentication.
 <br>Restrictions processing.
 <br>Risk control.
 <br>Cardholder verification.
 
 <p>For the card data authentication process the function shEMVAuthentication is called with the amount detection flag set to FALSE
 because it's assumed that the amount was already entered and is available for the application, if that’s not the case if the application
 wants to use the actual value for the amount can enable this flag and provide the amount if requested during the dynamic authentication.
 
 <p>If the application is not offline enabled the call to the function shEMVTerminalRisk can be made without setting the data previously
 as shown in the diagam.
 @image html diagram_d.png
 @image latex diagram_d.eps "Data authentication process" width=15cm
 
 <p><b>Application transaction decision</b>
 <br>At this point of the transaction, it's where the first decision is made. All the previous procedures results have been reflected
 on the TVR & TSI, and in this case the former is used to determine what type of transaction will be carried out from here.
 
 <br>Additionally for offline applications it will be necessary to check if the card is in the host list, if so the appropiate TVR bit must be updated.
 
 <br>The “offline possible” verification normally consists of a validation of the transactions log to ensure that the application can store
 the transaction data properly as well as any additional validation such as BIN control.
 
 <br>If the application has online only capabilities the result TRANSACTION_APPROVED should never be received as the response to the
 shEMVMakeTransDecision call, anyhow if this happens the transaction should be considered denied.
 
 <br>Once the cryptogram has been generated, it's necessary to check its type according to the original requested type. So, it's not acceptable
 to get a TC when requesting an AAC or ARQC, for that reason the verification types “AC Requested < XX” appear on the flow diagram.
 @image html diagram_e.png
 @image latex diagram_e.eps "Diagram" width=15cm
 
 <p><b>Transaction card decision</b>
 <br>When the issuer decision is known, it must be informed to the card requesting the appropiate cryptogram type, so that it's the card the one
 who has the final decision regarding the transaction. The refund/reversal procedure is out of the scope of the kernel, anyway all the data items
 needed can be accessed through the shEMVGetDatAsXXXX functions.
 
 <br>Additionally the storage of the scripts results, second cryptogram for further report to the issuer is also out of the scope of this
 specification and will have to be determined by the particular payment system.
 @image html diagram_g.png
 @image latex diagram_g.eps "Diagram" width=15cm
 
 <p><b>Default processing</b>
 <br>If the transaction cannot be completed online due to problems with the communication channel the default processing must be applied.
 In this case, if the application has no offline capabilities the transaction must be declined inmediately without any further processing.
 @image html diagram_h.png
 @image latex diagram_h.eps "Default processing" width=15cm
 
 @{
 */

/** @defgroup G_PPEMV_FLOW EMV Operation Workflow
 @ingroup G_PPEMV
 Description and block diagrams of various operations with the pinpad.
 
 <p><b>Kernel initialisation and version verification</b>
 <br>Firstly the application will have to initialise the library, this will only have to be done once at the unit power up.
 At the same time it will be convenient also to check the version info provided by the kernel to make sure that is the expected one.
 <br>After the initialisation, the first thing to do will be to set all the data items needed to start the transaction, mainly these items
 correspond to configuration issues:
 @image html diagram_a.png
 @image latex diagram_a.eps "Kernel initialisation and version verification" width=15cm

 <p><b>Card recognition and ATR validation</b>
 <p>The application will be in charge of detecting the presence of the smart card in the reader using the corresponding firmware function call,
 the application must power on the card also, the kernel is used in this phase to validate the ATR got from the card.
 @image html diagram_b.png
 @image latex diagram_b.eps "Card recognition and ATR validation" width=15cm
 
 <p><b>Application selection & initiation</b>
 <p>Once the card has been powered on and the ATR validated to ensure that is a valid EMV card, the next step is to proceed
 with the application selection and initiation.
 @image html diagram_c.png
 @image latex diagram_c.eps "Application selection & initiation" width=15cm
 
 <p><b>Transaction data processing</b>
 <p>Next the rest of the EMV transaction phases will be completed prior to the transaction decision, this includes:
 
 <br>Card data authentication.
 <br>Restrictions processing.
 <br>Risk control.
 <br>Cardholder verification.
 
 <p>For the card data authentication process the function shEMVAuthentication is called with the amount detection flag set to FALSE
 because it's assumed that the amount was already entered and is available for the application, if that’s not the case if the application
 wants to use the actual value for the amount can enable this flag and provide the amount if requested during the dynamic authentication.
 
 <p>If the application is not offline enabled the call to the function shEMVTerminalRisk can be made without setting the data previously
 as shown in the diagam.
 @image html diagram_d.png
 @image latex diagram_d.eps "Data authentication process" width=15cm
 
 <p><b>Application transaction decision</b>
 <br>At this point of the transaction, it's where the first decision is made. All the previous procedures results have been reflected
 on the TVR & TSI, and in this case the former is used to determine what type of transaction will be carried out from here.
 
 <br>Additionally for offline applications it will be necessary to check if the card is in the host list, if so the appropiate TVR bit must be updated.
 
 <br>The “offline possible” verification normally consists of a validation of the transactions log to ensure that the application can store
 the transaction data properly as well as any additional validation such as BIN control.
 
 <br>If the application has online only capabilities the result TRANSACTION_APPROVED should never be received as the response to the
 shEMVMakeTransDecision call, anyhow if this happens the transaction should be considered denied.
 
 <br>Once the cryptogram has been generated, it's necessary to check its type according to the original requested type. So, it's not acceptable
 to get a TC when requesting an AAC or ARQC, for that reason the verification types “AC Requested < XX” appear on the flow diagram.
 @image html diagram_e.png
 @image latex diagram_e.eps "Diagram" width=15cm
 
 <p><b>Transaction card decision</b>
 <br>When the issuer decision is known, it must be informed to the card requesting the appropiate cryptogram type, so that it's the card the one
 who has the final decision regarding the transaction. The refund/reversal procedure is out of the scope of the kernel, anyway all the data items
 needed can be accessed through the shEMVGetDatAsXXXX functions.
 
 <br>Additionally the storage of the scripts results, second cryptogram for further report to the issuer is also out of the scope of this
 specification and will have to be determined by the particular payment system.
 @image html diagram_g.png
 @image latex diagram_g.eps "Diagram" width=15cm
 
 <p><b>Default processing</b>
 <br>If the transaction cannot be completed online due to problems with the communication channel the default processing must be applied.
 In this case, if the application has no offline capabilities the transaction must be declined inmediately without any further processing.
 @image html diagram_h.png
 @image latex diagram_h.eps "Default processing" width=15cm
 */

#ifndef EMV_STRUCTURES_DEFINED
#define EMV_STRUCTURES_DEFINED

/**
 This is the list of the bits of the TVR that can be checked or updated
 */
#define TVR_DEFAULT_TDOL_USED 					 0x0508
#define TVR_ISSUER_AUTH_FAILED                   0x0507
#define TVR_SCRIPT_FAIL_BEFORE_AC                0x0506
#define TVR_SCRIPT_FAIL_AFTER_AC                 0x0505
#define TVR_TERMINAL_LIMIT_EXCEEDED              0x0408
#define TVR_LOWER_OFF_LIMIT_EXCEEDED             0x0407
#define TVR_UPPER_OFF_LIMIT_EXCEEDED             0x0406
#define TVR_RANDOM_SELECTION_ONLINE              0x0405
#define TVR_MERCHANT_FORCE_ONLINE                0x0404
#define TVR_CARDHOLDER_VERIF_FAILURE             0x0308
#define TVR_VERIF_METHOD_UNKNOWN                 0x0307
#define TVR_PIN_LIMIT_EXCEEDED                   0x0306
#define TVR_PIN_ASKED_PINPAD_FAILURE             0x0305
#define TVR_PIN_ASKED_BUT_NOT_ENTERED            0x0304
#define TVR_ONLINE_PIN_ENTERED                   0x0303
#define TVR_SOFTWARE_VERSIONS                    0x0208
#define TVR_APPLICATION_EXPIRED                  0x0207
#define TVR_APPLICATION_NOT_EFFECTIVE            0x0206
#define TVR_REQ_SERVICE_NOT_ALLOWED              0x0205
#define TVR_NEW_CARD                             0x0204
#define TVR_OFFDATA_AUTH_NOT_DONE                0x0108
#define TVR_STATIC_AUTH_FAILED                   0x0107
#define TVR_DATA_NOT_FOUND                       0x0106
#define TVR_CARD_IN_HOT_LIST                     0x0105
#define TVR_DYNAMIC_AUTH_FAILED                  0x0104
#define TVR_COMBINED_DDA_FAILED                  0x0103

/**
 This is the list of the bits of the TSI that can be checked or updated
 */
#define TSI_OFFDATA_AUTH_DONE 0x0108
#define TSI_CARDHOLDER_VERIF_DONE 0x0107
#define TSI_CARD_RISK_DONE 0x0106
#define TSI_ISSUER_AUTH_DONE 0x0105
#define TSI_TERMINAL_RISK_DONE 0x0104
#define TSI_SCRIPT_PROCESS_DONE 0x0103

typedef enum {
	SELECTION_PSE=0,
	SELECTION_AIDLIST,
}APP_SELECTION_METHODS;

typedef enum {
	MATCH_FULL=1,
	MATCH_PARTIAL_VISA,
	MATCH_PARTIAL_EUROPAY,
}APP_MATCH_CRITERIAS;

typedef enum {
    AUTH_RESULT_SUCCESS=1,
    AUTH_RESULT_FAILURE,
    AUTH_FAIL_PIN_ENTRY_NOT_DONE,
    AUTH_FAIL_USER_CANCELLATION,
}AUTH_RESULTS;

typedef enum {
    BYPASS_CURRENT_METHOD_MODE=0,
    BYPASS_ALL_METHODS_MODE,
}BYPASS_MODES;

typedef enum {
    CERTIFICATE_AAC=0,
    CERTIFICATE_TC,
    CERTIFICATE_ARQC,
}CERTIFICATE_AC_TYPES;

typedef enum {
    CDOL_1=1,
    CDOL_2,
}CARD_RISK_TYPES;

typedef enum {
    TAG_TYPE_BINARY=0,
    TAG_TYPE_BCD,
    TAG_TYPE_STRING,
}TAG_TYPES;

/** @defgroup G_PPEMV_TAGS EMV TAGs
 @ingroup G_PPEMV
 EMV TAGs you can use with their properties
 @{
 */

/**
 <br>Source: ICC
 <br>Length: ..10
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_PAN 0x5A
/**
 <br>Source: ICC
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CDOL_1 0x8C
/**
 <br>Source: ICC
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CDOL_2 0x8D
/**
 <br>Source: ICC
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CVM_LIST 0x8E
/**
 <br>Source: ICC
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_TDOL 0x97
/**
 <br>Source: ICC
 <br>Length: ..248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_PK_CERTIFICATE 0x90
/**
 <br>Source: ICC
 <br>Length: ..248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_SIGNED_STA_APP_DAT 0x93
/**
 <br>Source: ICC
 <br>Length: ..248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_PK_REMAINDER 0x92
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CA_PK_INDEX 0x8F
/**
 <br>Source: ICC
 <br>Length: 2-26
 <br>Format: A
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CARDHOLDER_NAME 0x5F20
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_SERVICE_CODE 0x5F30
/**
 <br>Source: ICC
 <br>Length: 27-45
 <br>Format: A
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CARDHOLDER_NAME_EXTEN 0x9F0B
/**
 <br>Source: ICC
 <br>Length: 3
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_EXPIRY_DATE 0x5F24
/**
 <br>Source: ICC
 <br>Length: 3
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_EFFECTIVE_DATE 0x5F25
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_COUNTRY_CODE 0x5F28
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: A
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_COUNTRY_CODE_A2 0x5F55
/**
 <br>Source: ICC
 <br>Length: 3
 <br>Format: A
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_COUNTRY_CODE_A3 0x5F56
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_PAN_SEQUENCE_NUMBER 0x5F34
/**
 <br>Source: ICC
 <br>Length: 1-32
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APP_DISCRETION_DAT 0x9F05
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APP_USAGE_CONTROL 0x9F07
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_APP_VERSION_NUMBER 0x9F08
/**
 <br>Source: ICC
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_ACTION_DEFAULT 0x9F0D
/**
 <br>Source: ICC
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_ACTION_DENIAL 0x9F0E
/**
 <br>Source: ICC
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_ACTION_ONLINE 0x9F0F
/**
 <br>Source: ICC
 <br>Length: 2-8
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APPL_REF_CURRENCY 0x9F3B
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APPL_CURRENCY_CODE 0x9F42
/**
 <br>Source: ICC
 <br>Length: 1-4
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APPL_REF_CURRENCY_EXP 0x9F43
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APPL_CURRENCY_EXP 0x9F44
/**
 <br>Source: ICC
 <br>Length: 248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_PK_CERTIFICATE 0x9F46
/**
 <br>Source: ICC
 <br>Length: 248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_PIN_PK_CERTIFICATE 0x9F2D
/**
 <br>Source: ICC
 <br>Length: 1-3
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_PK_EXP 0x9F47
/**
 <br>Source: ICC
 <br>Length: 1-3
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_PIN_PK_EXP 0x9F2E
/**
 <br>Source: ICC
 <br>Length: 248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_PK_REMAINDER 0x9F48
/**
 <br>Source: ICC
 <br>Length: 248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_PIN_PK_REMAINDER 0x9F2F
/**
 <br>Source: ICC
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_STA_DAT_AUTH_TAG_LIST 0x9F4A
/**
 <br>Source: ICC
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_DDOL 0x9F49
/**
 <br>Source: ICC
 <br>Length: 1-3
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_PK_EXP 0x9F32
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_LOW_CONSEC_OFFLINE_LIMIT 0x9F14
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_UPP_CONSEC_OFFLINE_LIMIT 0x9F23
/**
 <br>Source: ICC
 <br>Length: ..22
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_TRACK2_DISCRETION_DAT 0x9F20
/**
 <br>Source: ICC
 <br>Length: ..52
 <br>Format: A
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_TRACK1_DISCRETION_DAT 0x9F1F
/**
 <br>Source: ICC
 <br>Length: ..19
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_TRACK2_EQUIVALENT_DATA 0x57
/**
 <br>Source: KER
 <br>Length: 4
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_UNPREDICTABLE_NUMBER 0x9F37
/**
 <br>Source: APP
 <br>Length: 6
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_ACQUIRER_IDENTIFIER 0x9F01
/**
 <br>Source: APP
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_ADD_TERM_CAPABILITIES 0x9F40
/**
 <br>Source: APP
 <br>Length: 4
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_AMOUNT_AUTHORISED_BINARY 0x81
/**
 <br>Source: APP
 <br>Length: 6
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_AMOUNT_AUTHORISED_NUM 0x9F02
/**
 <br>Source: APP
 <br>Length: 4
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_AMOUNT_OTHER_BINARY 0x9F04
/**
 <br>Source: APP
 <br>Length: 6
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_AMOUNT_OTHER_NUM 0x9F03
/**
 <br>Source: APP
 <br>Length: 4
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_AMOUNT_REF_CURR 0x9F3A
/**
 <br>Source: ICC
 <br>Length: 8
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APP_CRYPTOGRAM 0x9F26
/**
 <br>Source: ICC
 <br>Length: ...252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_AFL 0x94
/**
 <br>Source: ICC
 <br>Length: 5-16
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_AID 0x4F
/**
 <br>Source: APP
 <br>Length: 5-16
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERM_AID 0x9F06
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_AIP 0x82
/**
 <br>Source: ICC
 <br>Length: 1-16
 <br>Format: AN
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APP_LABEL 0x50
/**
 <br>Source: ICC
 <br>Length: 1-16
 <br>Format: AN
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APP_PREFERRED_NAME 0x9F12
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_APP_PRIORITY_INDICATOR 0x87
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ATC 0x9F36
/**
 <br>Source: APP
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_APP_VERSION_NUMBER 0x9F09
/**
 <br>Source: APP
 <br>Length: 6
 <br>Format: AN
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_AUTH_CODE 0x89
/**
 <br>Source: APP
 <br>Length: 2
 <br>Format: AN
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_AUTH_RESP_CODE 0x8A
/**
 <br>Source: KER
 <br>Length: 3
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CH_VERIF_METHOD_RESULT 0x9F34
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_CA_PUBLIC_KEY_INDEX 0x9F22
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_CRYPT_INFO_DATA 0x9F27
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_DAT_AUTH_CODE 0x9F45
/**
 <br>Source: ICC
 <br>Length: 2-8
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ICC_DYN_NUMBER 0x9F4C
/**
 <br>Source: APP
 <br>Length: 8
 <br>Format: AN
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_SERIAL_NUMBER 0x9F1E
/**
 <br>Source: ICC
 <br>Length: ..32
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_APP_DAT 0x9F10
/**
 <br>Source: APP
 <br>Length: 8-16
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_ISSUER_AUTH_DAT 0x91
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_CODE_INDEX 0x9F11
/**
 <br>Source: ICC
 <br>Length: 2-8
 <br>Format: AN
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_LANGUAGE_PREFERENCE 0x5F2D
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_LATC 0x9F13
/**
 <br>Source: APP
 <br>Length: 2
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_MERCHANT_CATEGORY_CODE 0x9F15
/**
 <br>Source: APP
 <br>Length: 15
 <br>Format: AN
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_MERCHANT_IDENTIFIER 0x9F16
/**
 <br>Source: ICC
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_PIN_TRY_COUNTER 0x9F17
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_POS_ENTRY_MODE 0x9F39
/**
 <br>Source: ICC
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_PDOL 0x9F38
/**
 <br>Source: APP
 <br>Length: 3
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERMINAL_CAPABILITIES 0x9F33
/**
 <br>Source: APP
 <br>Length: 2
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERMINAL_COUNTRY_CODE 0x9F1A
/**
 <br>Source: APP
 <br>Length: 4
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERMINAL_FLOOR_LIMIT 0x9F1B
/**
 <br>Source: APP
 <br>Length: 8
 <br>Format: AN
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERMINAL_ID 0x9F1C
/**
 <br>Source: APP
 <br>Length: 1-8
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERMINAL_RISK_DAT 0x9F1D
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERMINAL_TYPE 0x9F35
/**
 <br>Source: KER
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_TVR 0x95
/**
 <br>Source: APP
 <br>Length: 2
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_CURR_CODE 0x5F2A
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_CURR_EXP 0x5F36
/**
 <br>Source: APP
 <br>Length: 3
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_DATE 0x9A
/**
 <br>Source: APP
 <br>Length: 2
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_REF_CURR_CODE 0x9F3C
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_REF_CURR_EXP 0x9F3D
/**
 <br>Source: APP
 <br>Length: 2-4
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_SEQ_COUNTER 0x9F41
/**
 <br>Source: KER
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_TSI 0x9B
/**
 <br>Source: APP
 <br>Length: 3
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_TIME 0x9F21
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_TYPE 0x9C
/**
 <br>Source: ICC
 <br>Length: ..248
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_SIGNED_DYN_APP_DAT 0x9F4B
/**
 <br>Source: APP
 <br>Length: 20
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TC_HASH_VALUE 0x98
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: N
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_ACCOUNT_TYPE 0x5F37
/**
 <br>Source: ICC
 <br>Length: 8-11
 <br>Format: AN
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_BANK_IDENTIFIER_CODE 0x5F54
/**
 <br>Source: ICC
 <br>Length: ..34
 <br>Format: AN
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_IBAN 0x5F53
/**
 <br>Source: ICC
 <br>Length: 3
 <br>Format: N
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_IDENTIFICATION_NUMBER 0x42
/**
 <br>Source: ICC
 <br>Length: ..255
 <br>Format: AN
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_URL 0x5F50
/**
 <br>Source: ICC
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_LOG_ENTRY 0x9F4D

/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TRANSACTION_CATEGORY_CODE 0x9F53

/**
 <br>Source: APP
 <br>Length: 4
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_RISK_AMOUNT 0xDF02
/**
 <br>Source: APP
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERM_ACTION_DEFAULT 0xDF03
/**
 <br>Source: APP
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERM_ACTION_DENIAL 0xDF04
/**
 <br>Source: APP
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TERM_ACTION_ONLINE 0xDF05
/**
 <br>Source: APP
 <br>Length: 5
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_THRESHOLD_VALUE 0xDF07
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_TARGET_PERCENTAGE 0xDF08
/**
 <br>Source: APP
 <br>Length: 1
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_MAX_TARGET_PERCENTAGE 0xDF09
/**
 <br>Source: APP
 <br>Length: ...252
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_DEFAULT_DDOL 0xDF15
/**
 <br>Source: APP
 <br>Length: ..252
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_DEFAULT_TDOL 0xDF18
/**
 <br>Source: APP
 <br>Length: 2
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_FLOOR_LIMIT_CURRENCY 0xDF19
/**
 <br>Source: APP
 <br>Length: ..2048
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_OFF_AUTH_DAT 0xDF23
/**
 <br>Source: APP
 <br>Length: ..256
 <br>Format: B
 <br>Read: YES
 <br>Write: YES
 */
#define TAG_ISSUER_SCRIPTS 0xDF24
/**
 <br>Source: APP
 <br>Length: ..256
 <br>Format: B
 <br>Read: YES
 <br>Write: NO
 */
#define TAG_ISSUER_SCRIPTS_RESULT 0xDF25

/**@}*/


/** @defgroup G_PPEMV_STATUSES EMV Status Codes
 @ingroup G_PPEMV
 These status codes are returned from every EMV function to indicate the result of it
 @{
 */

/**
 Operation successful
 */
#define EMV_SUCCESS 0
/**
 More than one matching applications found
 */
#define EMV_LIST_AVAILABLE 1
/**
 Only one matching application found
 */
#define EMV_APPLICATION_AVAILABLE 2
/**
 No matching applications found
 */
#define EMV_NO_COMMON_APPLICATION 3
/**
 Easy Entry application
 */
#define EMV_EASY_ENTRY_APP 4
/**
 Amount is requested by the dynamic data authentication
 */
#define EMV_AMOUNT_NEEDED 5
/**
 Result needed
 */
#define EMV_RESULT_NEEDED 6
/**
 Authentication is completed
 */
#define EMV_AUTH_COMPLETED 7
/**
 Authentication was not performed
 */
#define EMV_AUTH_NOT_DONE 8
/**
 OFFLINE plain text pin is required
 */
#define EMV_OFFLINE_PIN_PLAIN 9
/**
 ONLINE pin is required
 */
#define EMV_ONLINE_PIN 10
/**
 OFFLINE ciphered pin is required
 */
#define EMV_OFFLINE_PIN_CIPHERED 11
/**
 Explicit selection was done and blocked AIDs were found
 */
#define EMV_BLOCKED_APPLICATION 12
/**
 An online request should be done
 */
#define EMV_TRANSACTION_ONLINE 13
/**
 Transaction can be accepted offline
 */
#define EMV_TRANSACTION_APPROVED 14
/**
 Transaction must be declined
 */
#define EMV_TRANSACTION_DENIED 15
/**
 CDA failed and the cryptogram got is not an AAC or the data handed for DDA was not found
 */
#define EMV_CDA_FAILED 16
/**
 Incorrect PIN
 */
#define EMV_INVALID_PIN 17
/**
 Incorrect PIN, last attempt available only
 */
#define EMV_INVALID_PIN_LAST_ATTEMPT 18
/**
 Command failed, possibly due wrong imput parameters - wrong ATR, bit values, etc
 */
#define EMV_FAILURE 50
/**
 Incoming data pointer is null or empty.
 */
#define EMV_NO_DATA_FOUND 51
/**
 Internal system error occurred.
 */
#define EMV_SYSTEM_ERROR 52
/**
 Incorrect format found in the input parameters.
 */
#define EMV_DATA_FORMAT_ERROR 53
/**
 Invalid ATR sequence, not according to specs
 */
#define EMV_INVALID_ATR 54
/**
 Severe error occurred transaction must be aborted.
 */
#define EMV_ABORT_TRANSACTION 55
/**
 AID not found in the card
 */
#define EMV_APPLICATION_NOT_FOUND 56
/**
 Application is not correct
 */
#define EMV_INVALID_APPLICATION 57
/**
 Some error during read process
 */
#define EMV_ERROR_IN_APPLICATION 58
/**
 Status word got from the PSE selection indicates that the card is blocked
 */
#define EMV_CARD_BLOCKED 59
/**
 No script loaded
 */
#define EMV_NO_SCRIPT_LOADED 61
/**
 Tag cannot be read
 */
#define EMV_INVALID_TAG 62
/**
 Length of the buffer is incorrect
 */
#define EMV_INVALID_LENGTH 63
/**
 Error in the HASH verification
 */
#define EMV_INVALID_HASH 64
/**
 No key was found to do the verification
 */
#define EMV_INVALID_KEY 65
/**
 No more available locations for keys
 */
#define EMV_NO_MORE_KEYS 66
/**
 Error processing the AC generation.
 */
#define EMV_ERROR_AC_PROCESS 67
/**
 Status word got from the card is 6985
 */
#define EMV_ERROR_AC_DENIED 68
/**
 No method is currently applicable
 */
#define EMV_NO_CURRENT_METHOD 69
/**
 Result already loaded for the current method
 */
#define EMV_RESULT_ALREADY_LOADED 70
/**
 
 */
#define EMV_LAST_EMVKERNEL_ERR_CODE 70
/**
 
 */
#define EMV_INVALID_REMAINDER 80
/**
 Invalid header
 */
#define EMV_INVALID_HEADER 81
/**
 Invalid footer
 */
#define EMV_INVALID_FOOTER 82
/**
 Invalid format
 */
#define EMV_INVALID_FORMAT 83
/**
 Invalid certificate
 */
#define EMV_INVALID_CERTIFICATE 84
/**
 Invalid signature
 */
#define EMV_INVALID_SIGNATURE 85

/**@}*/

#endif

/** @defgroup G_PPEMV_TRANS_START Transaction Start
 @ingroup G_PPEMV
 This section includes the command used to start the transaction: ATR validation and application selection.
 @{
 */

/**
 This command initializes the emv kernel, call it before calling any other EMV function
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvInitialise:(NSError **)error;

/**
 This command deinitializes the emv kernel and frees the allocated resources, call it after you are done with the EMV transaction
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvDeinitialise:(NSError **)error;


/**
 The command is in charge of validating the ATR sequence got from the card to ensure that is fully EMV compliant
 and that obeys the rules stated in the specification.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param warmReset - holds the type of power up applied if cold or warm power up.
 @param ATR - ATR sequence received form the card: TS+T0+TB1+TC1+TS+T0+TB1+TC1+TD1+TD2+TA3+TB3+TCK
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvATRValidation:(NSData *)ATR warmReset:(BOOL)warmReset error:(NSError **)error;

/**
 The command initiates the application selection process, loading the application list supported by the terminal.
 The maximum number of application that can be loaded into the kernel is up to 75. This number is only constrained
 by the max packet size that can be exchanged on the port (2Kb).
 <p>
 Initially the command will inspect the incoming data to make sure that if data are provided and that all the data
 related to terminal applications is valid. If no data has been provided (the list is empty) the status EMV_NO_DATA_FOUND
 will be returned, in the event of a format failure of the applications data the result got will be EMV_DATA_FORMAT_ERROR.
 If during the internal procedure of the commands a system error occurs the command will return with the status EMV_SYSTEM_ERROR,
 on the other hand if the error occurs dealing with the card or with the data got and the transaction must be aborted
 according to EMV specs, the result will be EMV_ABORT_TRANSACTION. If the process can be completed correctly and the list
 is properly parsed and managed the status SUCCESS will be returned.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param appList - an array of application DTEMVApplication
 @param selectionMethod - defines the selection preferred method:
 <table>
 <tr><td>SELECTION_PSE</td><td>Selection by PSE</td></tr>
 <tr><td>SELECTION_AIDLIST</td><td>Selection by AID list</td></tr>
 </table>
 @param includeBlockedAIDs - indicates if blocked AIDs should be included
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvLoadAppList:(NSArray *)appList selectionMethod:(APP_SELECTION_METHODS)selectionMethod includeBlockedAIDs:(BOOL)includeBlockedAIDs error:(NSError **)error;

/**
 The command gets back the list of common applications supported by the terminal and the card, actually this commands will end
 or resume the selection procedure.
 <p>
 Initially the command will check the provided data, if it's empty string, the status NO_DATA_FOUND will be returned,
 if during the procedure any internal error occurs the status will be EMV_SYSTEM_ERROR. On the other hand, if the process
 and be completed correctly the possible status returned will be: EMV_LIST_AVAILABLE, EMV_APPLICATION_AVAILABLE, EMV_NO_COMMON_APPLICATION
 according to the number of common applications found.
 @note The application may know beforehand the number of common applications by retrieving the value of the data item TAG_COMMON_APP_NUMBER.
 @note In the event of an application error that doesn’t force to abort the transaction, this command will be called again as many times
 as necessary while the list won’t be empty. Internally the Kernel will remove the wrong application so that the selection could be resumed.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param confirmationRequired - defines if USER Confirmation is required
 @param error returns error information, you can pass nil if you don't want it
 @return Array of DTEMVApplication upon success, nil otherwise
 **/
-(NSArray *)emvGetCommonAppList:(BOOL *)confirmationRequired error:(NSError **)error;

/**@}*/

/** @defgroup G_PPEMV_TRANS_PROCESSING Transaction Processing
 @ingroup G_PPEMV
 This section covers the different phases of the transaction:
 <br>Initial process
 <br>Data reading
 <br>Card data authentication
 <br>Restrictions processing
 <br>Risk Control
 <br>Cardholder authentication
 <br>Certificate generation
 <br>Make Transaction decision
 <br>Make default decision
 @{
 */

/**
 Once an application has been selected, the next phase is to start the transaction with it by issuing the GET PROCESSING
 ommand and analyzing the information got.
 <p>
 First the input data are checked, if empty the status EMV_NO_DATA_FOUND is returned, if the length of the AID is incorrect
 (greater than AID max length or less than TAG min length) the status got will be EMV_DATA_FORMAT_ERROR. If any internal error
 occurs during the processing the status returned will be EMV_SYSTEM_ERROR. Depending on the application type or status the codes
 EMV_EASY_ENTRY_APP, EMV_INVALID_APPLICATION or EMV_BLOCKED_APPLICATION could be returned. If the transaction must be aborted
 due to a processing error with the card or with the data got from it the status returned will be EMV_ABORT_TRANSACTION.
 EMV_APPLICATION_NOT_FOUND will be the status got if the AID provided cannot be found in the card. If everything is correct and the
 application can be initiated properly the status will be EMV_SUCCESS.
 @note At this point of the transaction it could be possible to resume the application selection by calling the ppEmvGetCommonAppList
 command again, this will depend on the status got, normally for EMV_EASY_ENTRY_APP, EMV_INVALID_APPLICATION or EMV_BLOCKED_APPLICATION
 the selection should be resumed.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param aid - indicates the selected application AID
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvInitialAppProcessing:(NSData *)aid error:(NSError **)error;

/**
 The command reads and validates the data informed in the AFL and that will be used along the transaction.
 <p>
 If during the AFL data reading and validating an error occurs that commits the transaction to be terminated, the status EMV_ABORT_TRANSACTION
 will be returned. If the error allows the application selection to be resumed, the status returned will be EMV_ERROR_IN_APPLICATION.
 If psrEMVManTagList is not NULL, the presence of the tags provided here will be checked. If during the procedure any internal error occurs,
 EMV_SYSTEM_ERROR will be returned. On the other hand, if everything is correct and the data can be extracted and validated, the status
 EMV_SUCCESS will be the value returned.
 @note At this point of the transaction it could be possible to resume the application selection by calling the ppEmvGetCommonAppList command
 again, this will depend on the status got, normally for EMV_ERROR_IN_APPLICATION the selection should be resumed.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tags - an array of tags to return
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvReadAppData:(NSArray *)tags error:(NSError **)error;

/**
 Through this command the card data is authenticated depending on the capabilities of the card and the kernel. The method could be
 static or dynamic, in this case is completed here, or combined that will be carried out later at the application cryptogram generation stage.
 <p>
 If the authentication can be performed (successfully or not) the command will return EMV_SUCCESS. If an internal error occurs the status
 got will be EMV_SYSTEM_ERROR. EMV_ABORT_TRANSACTION will be returned if the transaction must be immediately terminated due to a severe error
 in the processing. If the check amount flag was enabled and the amount is one of the data items requested by the dynamic data authentication
 the status EMV_AMOUNT_NEEDED will be returned. If the authentication cannot be completed due to a missing CA public key, the status returned
 will be EMV_INVALID_KEY.
 @note EMV_INVALID_KEY status code will let the application to detect and invalid configuration concerning the CA RSA public keys.
 @note If the selected authentication method is the CDA, the verification of the CA public key presence and the recovery of the issuer public key
 is done here prior to the actual CDA verification to be done at the AC generation.
 @note The reason for setting the checkAmount parameter to TRUE is to allow the application to know if the amount is required as part of the
 dynamic data used for the authentication. This can be useful if the application plans to be sure that the actual amount will be used in the
 process rather than a default value set to zero.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param checkAmount - determine whether the amount is checked for the dynamic authentication
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvAuthentication:(BOOL)checkAmount error:(NSError **)error;

/**
 The command performs the restrictions processing related to application version, application usage control and effective and expiry dates.
 <p>
 If the process can be completed correctly the returned status will be SUCCESS, if any internal error occurs the status will be
 EMV_SYSTEM_ERROR instead.
 @note To complete this process the kernel needs from the application the following data items to have been provided prior to this command:
 • TAG_APP_VERSION_NUMBER • TAG_TERMINAL_TYPE • TAG_ADD_TERM_CAPABILITIES • TAG_TERMINAL_COUNTRY_CODE • TAG_TRANSAC_DATE • TAG_TRANSAC_TYPE
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvProcessRestrictions:(NSError **)error;

/**
 The application risk control is done by this command, including Floorlimit checking, Random selection (only if offline is enabled) and Velocity checking.
 <p>
 If the process can be completed correctly the returned status will be SUCCESS, if any internal error occurs the status will be
 EMV_SYSTEM_ERROR instead.
 @note To complete this process the kernel needs from the application the following data items to have been provided previously:
 •	TAG_RISK_AMOUNT (if offline enabled) •	TAG_AMOUNT_AUTHORISED_BINARY (if online only) •	TAG_FLOOR_LIMIT_CURRENCY (optional) • TAG_TERMINAL_FLOOR_LIMIT •	TAG_THRESHOLD_VALUE (if offline) •	TAG_TARGET_PERCENTAGE (if offline) •	TAG_MAX_TARGET_PERCENTAGE (if offline) •	TAG_TRANSAC_CURR_CODE (optional)
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param forceProcessing - determine whether the process should be carried out despite of the AIP configuration
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvTerminalRisk:(BOOL)forceProcessing error:(NSError **)error;

/**
 The command starts or resumes the cardholder authentication procedure, the current verification method is communicated to the application.
 <p>
 The lists of methods and conditions is parsed and processed to identify what are the valid ones according to the kernel capabilities the
 possible methods available are: EMV_OFF_LINE_PIN_PLAIN, EMV_ONLINE_PIN, EMV_OFFLINE_PIN_CIPHERED.
 <br>If during the process an internal error occurs the status EMV_SYSTEM_ERROR is returned, if the transaction has to be terminated the
 status EMV_ABORT_TRANSACTION will be returned. If there are not more valid methods to be applied the status EMV_AUTH_COMPLETED is set.
 @note If a combination of methods is required by the card, pin verification plus signature, the kernel directly checks if the latter is
 possible according to the capabilities, if so the former is informed otherwise the next entry in the list will be processed.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvGetAuthenticationMethod:(NSError **)error;

/**
 Using this command the kernel gets the result of the previously informed verification method.
 <p>
 Firstly the value of the result informed must be checked, if its value is not a valid one the status EMV_DATA_FORMAT_ERROR will be returned.
 If the authentication process was not started and no method is currently active the status EMV_NO_CURRENT_METHOD will be got by the application,
 if the result for the current method was already provided the status will be EMV_RESULT_ALREADY_LOADED. EMV_SYSTEM_ERROR will be get by the
 application if any internal error occurs during the processing. When everything is ok and the result can be stored correctly the status
 sent back is EMV_SUCCESS.
 @note The actual verification method result according to EMV specs can be recovered by the application at later stage by accessing the data
 item TAG_CH_VERIF_METHOD_RESUL.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param result - result of the verification method previously informed:
 <table>
 <tr><td>AUTH_RESULT_SUCCESS</td><td>The method result was successful</td></tr>
 <tr><td>AUTH_RESULT_FAILURE</td><td>The method failed</td></tr>
 <tr><td>AUTH_FAIL_PIN_ENTRY_NOT_DONE</td><td>PIN entry was bypassed</td></tr>
 <tr><td>AUTH_FAIL_USER_CANCELLATION</td><td>PIN entry was cancelled</td></tr>
 </table>
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvSetAuthenticationResult:(AUTH_RESULTS)result error:(NSError **)error;

/**
 The command allows the application to apply the offline PIN verification (plaintext or encrypted) method.
 <p>
 Depending on the current PIN entry type (plaintext or encrypted) is verified against the card, if the PIN is no valid and is rejected
 the status EMV_INVALID_PIN will be returned if more than one attempt is still available otherwise the status will be EMV_INVALID_PIN_LAST_ATTEMPT.
 If a severe error occurs so that the transaction should be terminated immediately, the status EMV_ABORT_TRANSACTION will be set.
 If any kind of internal error occurs during the processing, the status EMV_SYSTEM_ERROR will be returned. If the verification cannot be completed
 due to a missing CA public key, the status returned will be EMV_INVALID_KEY. Finally if the PIN is entered and verified correctly the status
 got will be EMV_SUCCESS.
 @note EMV_INVALID_KEY status code will let the application to detect and invalid configuration concerning the CA RSA public keys.
 @note The PIN entry process will have to be accomplished by the application calling to the proper commands provided for that aim.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvVerifyPinOffline:(NSError **)error;

/**
 Using this command the application will be able to generate an application cryptogram, the first or the second one, as required by the transaction.
 <p>
 If the incoming pointer to the structure with the parameters is NULL, the result set will be EMV_NO_DATA_FOUND. If any of the incoming parameters
 value is incorrect the status EMV_DATA_FORMAT_ERROR will be returned. EMV_SYSTEM_ERROR will be get by the application if any internal error
 occurs during the processing. If during the cryptogram generation an error occurs that requires the transaction termination,
 the status EMV_ABORT_TRANSACTION will be informed. If other kind of error occurs during the generation the status EMV_ERROR_AC_PROCESS
 will be got. If the combined authentication is enabled, EMV_CDA_FAILED will be returned to indicate that it failed. Finally if the certificate
 can be obtained with no error the status will be EMV_SUCCESS.
 @note If the CDA is the card data authentication mode the CDA will be always requested on the first cryptogram generation if the cryptogram
 type to be requested is a TC. It will be always disabled for AAC and for an ARQC depends on the CDA mode active.
 @note If the CDA is the card data authentication mode the CDA will be disabled on the second cryptogram generation if the cryptogram type
 to be requested is an AAC, otherwise if the cryptogram type is a TC it will depend on the CDA mode active.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param type - specifies AC type AAC:
 <table>
 <tr><td>CERTIFICATE_AAC</td><td>AAC</td></tr>
 <tr><td>CERTIFICATE_TC</td><td>TC</td></tr>
 <tr><td>CERTIFICATE_ARQC</td><td>ARQC</td></tr>
 </table>
 @param risk - card risk:
 <table>
 <tr><td>CDOL_1</td><td>CDOL_1</td></tr>
 <tr><td>CDOL_2</td><td>CDOL_2</td></tr>
 </table>
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvGenerateCertificate:(CERTIFICATE_AC_TYPES)type risk:(CARD_RISK_TYPES)risk error:(NSError **)error;

/**
 The command checks the action codes (provided by the application and read from the card), the TVR and will determine how the transaction is resolved.
 <p>
 EMV_SYSTEM_ERROR will be got by the application if any internal error occurs during the processing. First the denial action codes are checked,
 if any of the bits in the TVR match the status EMV_TRANSACTION_DENIED will be returned, otherwise if the terminal is both offline & online,
 the online action codes will be checked in the same way and if any of the bits match with the TVR data the status EMV_TRANSACTION_ONLINE
 will be set, if there’s no match at all the status will be EMV_TRANSACTION_APPROVED instead. If the terminal is offline only the default action
 code is checked, if any of the bits in the TVR match the status EMV_TRANSACTION_DENIED will be returned, otherwise the status got will be
 EMV_TRANSACTION_APPROVED. If the terminal is online only the status EMV_TRANSACTION_ONLINE will be returned.
 @note According to the latest EMV recommendations concerning the CDA processing (Specification update bulletin No. 44) if the CDA is the
 card data authentication mechanism to be performed, the previous key recovery process will be accomplished prior to the transaction decision
 so that CDA errors could be detected in advance and reflected on the TVR.
 @note The online/offline capability of the terminal is determined by the value of the tag TAG_TERMINAL_TYPE.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvMakeTransactionDecision:(NSError **)error;

/**
 The command checks the default action code (provided by the application and read from the card), the TVR and will determine how the transaction
 is resolved by default.
 <p>
 EMV_SYSTEM_ERROR will be returned if any internal error occurs during the processing. If any of the bits in the TVR match with the default action
 codes the status EMV_TRANSACTION_DENIED will be returned, otherwise the status will be EMV_TRANSACTION_APPROVED instead.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvMakeDefaultDecision:(NSError **)error;

/**@}*/

/** @defgroup G_PPEMV_ISSUER_AUTH Issuer Authentication
 @ingroup G_PPEMV
 The commands listed here are intended to process the data coming from the issuer as part of the response to the online authorization request.
 @{
 */

/**
 The command is used to validate the cryptogram got from the issuer.
 <p>
 If the issuer cryptogram was not set previously, the status EMV_NO_DATA_FOUND will be returned. If during the processing any internal error
 occurs, the status EMV_SYSTEM_ERROR will be set. If everything is ok and the cryptogram is verified, the result will be EMV_SUCCESS.
 @note The data item that the application has to provide to the kernel so that this command could be executed is: TAG_ISSUER_AUTH_DATA
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvAuthenticateIssuer:(NSError **)error;

/**
 The script processing retrieved in the online authorization is handled by this command.
 <p>
 First the presence of the script in the data repository is checked, if it's not present the status EMV_NO_SCRIPT_LOADED is returned.
 If during the processing any internal error occurs the status EMV_SYSTEM_ERROR will be set. Once the script has been conveniently processed
 and issued to the card the status EMV_SUCCESS will be set.
 @note The script data should be provided to the kernel through the data item TAG_ISSUER_SCRIPTS, and after the processing is over the results
 can be recovered by accessing the data item TAG_ISSUER_SCRIPTS_RESULT. The maximum length of the scripts supported is 256 bytes.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param type - script type to be processed:
 <table>
 <tr><td>0x71</td><td>SCRIPT_71</td></tr>
 <tr><td>0x72</td><td>SCRIPT_72</td></tr>
 </table>
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvScriptProcessing:(int)type error:(NSError **)error;

/**@}*/

/** @defgroup G_PPEMV_GENERAL General Commands
 @ingroup G_PPEMV
 These commands are not part of the basic transaction management but provide the kernel with more flexibility, and can be used by the application
 for its own particular requirements.
 @{
 */

/**
 The command allows modifying the TVR directly, setting or unsetting the desired bits.
 <p>
 Initially the incoming parameters are validated to ensure that are pointing to a valid location within the TVR structure. If that’s not the case,
 the status EMV_DATA_FORMAT_ERROR will be returned. If during the processing any internal error occurs, the status EMV_SYSTEM_ERROR will be set.
 EMV_SUCCESS will be returned if everything is correct and the TVR could be updated.
 @note The aim of this command is to let the application to achieve any additional procedure that could need as a particular requirement.
 Consult section List of TVR and TSI bits below for the complete list of the bits.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param byte - defines the byte number to update. Accepted values are in the range [1..5]
 @param bit - defines the bit number to update. Accepted values are in the range [1..8]
 @param value - holds the new bit value [0..1]
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvUpdateTVRByte:(int)byte bit:(int)bit value:(int)value error:(NSError **)error;

/**
 The command allows modifying the TSI directly, setting or unsetting the desired bits.
 <p>
 Initially the incoming parameters are validated to ensure that are pointing to a valid location within the TSI structure, if that’s not the case
 the status EMV_DATA_FORMAT_ERROR will be returned. If during the processing any internal error occurs the status EMV_SYSTEM_ERROR will be set.
 EMV_SUCCESS will be returned if everything is correct and the TVR could be updated.
 @note The aim of this command is to let the application to achieve any additional procedure that could need as a particular requirement.
 Consult section List of TVR and TSI bits for a list of the bits.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param byte - defines the byte number to update. Accepted values are in the range [1..5]
 @param bit - defines the bit number to update. Accepted values are in the range [1..8]
 @param value - holds the new bit value [0..1]
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvUpdateTSIByte:(int)byte bit:(int)bit value:(int)value error:(NSError **)error;

/**
 The command is intended to verify an individual bit within the TVR.
 <p>
 Initially the incoming parameters are validated to ensure that are pointing to a valid location within the TVR structure, if that’s not the case
 the status EMV_DATA_FORMAT_ERROR will be returned. If during the processing any internal error occurs the status EMV_SYSTEM_ERROR will be set.
 EMV_SUCCESS will be returned if the given bit is set otherwise it will be EMV_FAILURE.
 @note The aim of this command is to let the application to achieve any additional procedure that could need as a particular requirement.
 Consult section List of TVR and TSI bits for a list of the bits.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param byte - defines the byte number. Accepted values are in the range [1..5]
 @param bit - defines the bit number. Accepted values are in the range [1..8]
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvCheckTVRByte:(int)byte bit:(int)bit error:(NSError **)error;

/**
 The command is intended to verify an individual bit within the TSI.
 <p>
 Initially the incoming parameters are validated to ensure that are pointing to a valid location within the TSI structure, if that’s not the case
 the status EMV_DATA_FORMAT_ERROR will be returned. If during the processing any internal error occurs the status EMV_SYSTEM_ERROR will be set.
 EMV_SUCCESS will be returned if the given bit is set otherwise it will be EMV_FAILURE.
 @note The aim of this command is to let the application to achieve any additional procedure that could need as a particular requirement.
 Consult section List of TVR and TSI bits for a list of the bits.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param byte - defines the byte number. Accepted values are in the range [1..5]
 @param bit - defines the bit number. Accepted values are in the range [1..8]
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvCheckTSIByte:(int)byte bit:(int)bit error:(NSError **)error;

/**
 The command is intended to delete a given CA public key.
 <p>
 If the input pointer is NULL the status returned will be EMV_NO_DATA_FOUND, if the key cannot be found the EMV_INVALID_KEY status will be got.
 If during the processing any internal error occurs the returned status will be EMV_SYSTEM_ERROR. Finally if the key can be deleted the status
 will be EMV_SUCCESS.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param RID - holds the RID data (5 bytes)
 @param caIndex - certification authority public key index
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvRemovePublicKey:(int)caIndex RID:(NSData *)RID error:(NSError **)error;

/**@}*/

/** @defgroup G_PPEMV_DATA_ACCESS Data Access
 @ingroup G_PPEMV
 The commands described below are used to access the data items used by the kernel.
 @{
 */

/**
 The command sets a data item with data in binary format (raw data).
 <p>
 Initially the input data is validated, if the buffer is NULL the status EMV_NO_DATA_FOUND will be returned, in case of not locating the tag
 EMV_TAG_NOT_FOUND will be set, if the length of the incoming data is not in the range accepted by the data item the status EMV_INVALID_LENGTH
 will be returned. The data item attributes are checked to determine whether the item can be written or not, if it's not the case the status
 returned will be EMV_INVALID_TAG. If during the processing any internal error occurs the returned status will be EMV_SYSTEM_ERROR.
 Once the data has been saved properly the status EMV_SUCCESS will be set.
 @note Using this method there’s no applicable conversion, so the data provided should be in the format that corresponds to the data item
 to be set. So, in fact, it's like setting a given data item with raw data. Consult section List of EMV tags for a list of the data items.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagID - holds the Tag Id of the data item
 @param data - holds the Tag Data
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvSetDataAsBinary:(uint32_t)tagID data:(NSData *)data error:(NSError **)error;

/**
 The command sets a data item with data in string format.
 <p>
 Initially the input data is validated, if the buffer is NULL the status EMV_NO_DATA_FOUND will be returned, in case of not locating the tag
 EMV_TAG_NOT_FOUND will be set, if the length of the incoming data is not in the range accepted by the data item the status EMV_INVALID_LENGTH
 will be returned. The data item attributes are checked to determine whether the item can be written or not, if it's not the case the status
 returned will be EMV_INVALID_TAG. If during the processing any internal error occurs the returned status will be EMV_SYSTEM_ERROR.
 Once the data has been saved properly the status EMV_SUCCESS will be set.
 @note Using this method there’s no applicable conversion, so the data provided should be in the format that corresponds to the data item
 to be set. So, in fact, it's like setting a given data item with raw data. Consult section List of EMV tags for a list of the data items.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagID - holds the Tag Id of the data item
 @param data - holds the Tag Data
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvSetDataAsString:(uint32_t)tagID data:(NSString *)data error:(NSError **)error;

/**
 The command gets a data item in binary format (raw data).
 <p>
 If the length of the data item is greater than the length of the buffer requested the status EMV_INVALID_LENGTH will be set, in the case
 of not finding the requested item the status EMV_TAG_NOT_FOUND will be returned. After checking the item attributes, if the item cannot
 be read the returned status will be EMV_INVALID_TAG. If during the processing any internal error occurs the returned status will be
 EMV_SYSTEM_ERROR. Finally if everything is OK and the data can be extracted the status will be EMV_SUCCESS.
 @note Using this method there’s no applicable conversion, so the data retrieved is in the format that corresponds to the data item.
 Consult section List of EMV tags for a list of the data items.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagID - holds the Tag Id of the data item
 @param error returns error information, you can pass nil if you don't want it
 @return Tag value as data upon success, nil otherwise
 **/
-(NSData *)emvGetDataAsBinary:(uint32_t)tagID error:(NSError **)error;

/**
 The command gets a data item in string format.
 <p>
 If the length of the data item is greater than the length of the buffer requested the status EMV_INVALID_LENGTH will be set, in the case
 of not finding the requested item the status EMV_TAG_NOT_FOUND will be returned. After checking the item attributes, if the item cannot
 be read the returned status will be EMV_INVALID_TAG. If during the processing any internal error occurs the returned status will be
 EMV_SYSTEM_ERROR. Finally if everything is OK and the data can be extracted the status will be EMV_SUCCESS.
 @note Using this method there’s no applicable conversion, so the data retrieved is in the format that corresponds to the data item.
 Consult section List of EMV tags for a list of the data items.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagID - holds the Tag Id of the data item
 @param error returns error information, you can pass nil if you don't want it
 @return Tag value as string upon success, nil otherwise
 **/
-(NSString *)emvGetDataAsString:(uint32_t)tagID error:(NSError **)error;

/**
 The command allows the application direct access to the data of a given item.
 <p>
 In the case of not finding the requested item the status EMV_TAG_NOT_FOUND will be returned. If during the processing any internal error occurs,
 the returned status will be EMV_SYSTEM_ERROR. Finally, if everything is OK and the attributes can be extracted, the status will be EMV_SUCCESS.
 @warning The aim of this command is to let the application a direct access to the already assigned buffers of the data items.
 This could be useful to save and to optimize memory usage. It can be also used to determine the presence of an item or to know its current length.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagID - holds the Tag Id of the data item
 @param tagType - returns the type of the tag:
 <table>
 <tr><td>TAG_TYPE_BINARY</td><td>Binary data</td></tr>
 <tr><td>TAG_TYPE_BCD</td><td>Numeric data (BCD)</td></tr>
 <tr><td>TAG_TYPE_STRING</td><td>String data</td></tr>
 </table>
 @param maxLen - returns maximum length of the item
 @param currentLen - returns current length of the item
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvGetDataDetails:(uint32_t)tagID tagType:(int *)tagType maxLen:(int *)maxLen currentLen:(int *)currentLen error:(NSError **)error;

/**
 With this command is possible to setup the behavior of the KERNEL regarding the PIN based method bypass, so that only the current method
 will be bypassed or any other found later in the CVM list will be considered so as well.
 <p>
 If any kind of internal error occurs during the processing or the kernel was not initialized before the status EMV_SYSTEM_ERROR will be returned.
 On the other hand if the value can be set correctly the status got will be EMV_SUCCESS.
 @note If this command is not used along the transaction the default value applied by the kernel will be BYPASS_CURRENT_METHOD_MODE.
 If the expected behavior is other than the default one the call to this command will have to be done prior to the cardholder authentication
 procedure and after application selection.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param mode - bypass mode, one of:
 <table>
 <tr><td>BYPASS_CURRENT_METHOD_MODE</td><td>Bypass current method</td></tr>
 <tr><td>BYPASS_ALL_METHODS_MODE</td><td>Bypass all methods</td></tr>
 </table>
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvSetBypassMode:(BYPASS_MODES)mode error:(NSError **)error;

/**
 Loads multiple tags at the same time, this is much faster than calling them 1 by 1
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tlv BER-TLV lists ot tag-length-value, as described in EMV books
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 **/
-(BOOL)emvSetTags:(NSData *)tlv error:(NSError **)error;

/**
 Reads multiple tags at the same time, this is much faster than calling them 1 by 1. Some sensitive tags can only be read encrypted.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagList list of tags to read, the list follows the BER_TLV structure without having length and value, tags can be single or 2bytes
 @param error returns error information, you can pass nil if you don't want it
 @return BER-TLV data containing tag-length-value or nil if function failed
 **/
-(NSData *)emvGetTags:(NSData *)tagList error:(NSError **)error;

/**
 Reads multiple tags at the same time and sends them encrypted, this is much faster than calling them 1 by 1. Some sensitive tags can only be read encrypted.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagList list of tags to read, the list follows the BER_TLV structure without having length and value, tags can be single or 2bytes
 @param keyID index of the key to use (1-49)
 @param error returns error information, you can pass nil if you don't want it
 @return encrypted packet or nil if function failed. After decryption the data contains:
 - random data (4 bytes)
 - unique ID (4 bytes) - same ID you have sent to the function
 - payload length (2 bytes) - length of the TLV block in BIG ENDIAN
 - data (variable) - BER-TLV data, as per EMV books
 - crc (2 bytes) - CRC16 CCIT on all the bytes before it
 - padding (0-7 bytes) zeroes to pad the packet with
 **/
-(NSData *)emvGetTagsEncrypted3DES:(NSData *)tagList keyID:(int)keyID uniqueID:(uint32_t)uniqueID error:(NSError **)error;

/**
 Reads multiple tags at the same time and sends them encrypted, this is much faster than calling them 1 by 1. Some sensitive tags can only be read encrypted.
 @note Upon successful execution, EMV kernel status is stored in emvLastStatus property.
 @param tagList list of tags to read, the list follows the BER_TLV structure without having length and value, tags can be single or 2bytes
 @param keyID index of the DUKPT key to use (0-1)
 @param error returns error information, you can pass nil if you don't want it
 @return encrypted packet + DUKPT KSN (10 bytes) or nil if function failed. After decryption the data contains:
 - random data (4 bytes)
 - unique ID (4 bytes) - same ID you have sent to the function
 - payload length (2 bytes) - length of the TLV block in BIG ENDIAN
 - data (variable) - BER-TLV data, as per EMV books
 - crc (2 bytes) - CRC16 CCIT on all the bytes before it
 - padding (0-7 bytes) zeroes to pad the packet with
 **/
-(NSData *)emvGetTagsEncryptedDUKPT:(NSData *)tagList keyID:(int)keyID uniqueID:(uint32_t)uniqueID error:(NSError **)error;

/**@}*/

/**@}*/


/** @defgroup G_PPUI User Interface Functions
 This section includes functions for managing the display, reading PIN and keyboard
 @{
 */

/**
 Returns screen properties
 @param width screen width in pixels will be returned here
 @param height screen height in pixels will be returned here
 @param color screen capability to display colors will be returned here, one of the COLOR_MODE_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiGetScreenInfoWidth:(int *)width height:(int *)height colorMode:(SCREEN_COLOR_MODES *)colorMode error:(NSError **)error;

/**
 Disaplay some text, starting at a specified position. The text can contain control symbols that alter cursor position, colors or whole window.
 Characters going outside the screen will not be drawn.
 @param text - text string to write. Special codes that can be used are:
 <table>
 <tr><td>0x0A</td><td>newline (moves cursor at the beginning of the next line)</td></tr>
 <tr><td>0x0B</td><td>turns on character inversion</td></tr>
 <tr><td>0x0C</td><td>turns of character inversion</td></tr>
 </table>
 @param topLeftX - topleft X coordinate in pixels
 @param topLeftY - topleft Y coordinate in pixels
 @param font font size, one of the FONT_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiDrawText:(NSString *)text topLeftX:(int)topLeftX topLeftY:(int)topLeftY font:(FONTS)font error:(NSError **)error;

/**
 Fills rectangle on the screen with specified color.
 @param topLeftX - topleft X coordinate of the rectangle in pixels
 @param topLeftY - topleft Y coordinate of the rectangle in pixels
 @param width - rectangle width in pixels or 0 for automatic calculation
 @param height - rectangle height in pixels or 0 for automatic calculation
 @param color - the color to use, either COLOR_INVERT or custom UIColor
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiFillRectangle:(int)topLeftX topLeftY:(int)topLeftY width:(int)width height:(int)height color:(UIColor *)color error:(NSError **)error;

/**
 Set display contrast.
 @param contrast - display contrast
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiSetContrast:(int)contrast error:(NSError **)error;

/**
 Draws pixel on the screen with specified color.
 @param x - X coordinate in pixels
 @param y - Y coordinate in pixels
 @param color - the color to use, either COLOR_INVERT or custom UIColor
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiPutPixel:(int)x y:(int)y color:(UIColor *)color error:(NSError **)error;

/**
 Displays image on the screen. The image is dithered down to black and white before sending.
 @param topLeftX - topleft X coordinate of the image in pixels
 @param topLeftY - topleft Y coordinate of the image in pixels
 @param image - image to draw
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiDisplayImage:(int)topLeftX topLeftY:(int)topLeftY image:(UIImage *)image error:(NSError **)error;

/**
 Draws predefined animation on the screen. You can have multiple animations active. Not all animations are present in every pinpad.
 @param animationIndex - animation index, one of the ANIM_* constants
 @param topLeftX - topleft X coordinate of the animation in pixels
 @param topLeftY - topleft Y coordinate of the animation in pixels
 @param animated - if TRUE, the animation will play continuous until stopped with ppUiStopAnimation
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiStartAnimation:(ANIMATIONS)animationIndex topLeftX:(int)topLeftX topLeftY:(int)topLeftY animated:(BOOL)animated error:(NSError **)error;

/**
 Stops animation playback started with ppUiStartAnimation.
 @param animationIndex - animation index, one of the ANIM_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 **/
-(BOOL)uiStopAnimation:(ANIMATIONS)animationIndex error:(NSError **)error;

/**
 Enables or disables controllable LEDs on the device based on bit mask
 @param mask bit mask of the enabled LEDs, 1 means the bit will be lit, 0 - disabled
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)uiControlLEDsWithBitMask:(uint32_t)mask error:(NSError **)error;

/**
 Activates vibration motor (if available) for a specific time
 @param time the maximum amount of time the vibration will be active
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)uiEnableVibrationForTime:(float)time error:(NSError **)error;

/**
 Enables or disables external speaker. The speaker is active as long as the device controlling it is connected/awake, so if you want the speaker
 to be used in background, you have to set external accessory background mode in your application or use setAutoOffWhenIdle to set long standby time
 @note enabling external speaker consumes power for the amplifier, so in order to conserve battery, enable it only when needed
 @param enabled TRUE if you want to enable the external speaker
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)uiEnableSpeaker:(BOOL)enabled error:(NSError **)error;

/**
 Returns the state of external speaker.
 @param enabled stores the current state of the external speaker, TRUE means it is enabled, FALSE - internal speaker is used
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)uiIsSpeakerEnabled:(BOOL *)enabled error:(NSError **)error;


/**
 Contains display width in pixels
 **/
@property(readonly) int uiDisplayWidth;

/**
 Contains display height in pixels
 **/
@property(readonly) int uiDisplayHeight;

/**
 Contains display height in pixels
 **/
@property(readonly) BOOL uiDisplayAtBottom;

/**@}*/


/** @defgroup G_PRNGENERAL Printing functions
 Functions to print graphic, text and barcodes on supported printers
 @{
 */
/*******************************************************************************
 Data channels
 *******************************************************************************/
#define CHANNEL_PRN			1
#define CHANNEL_SMARTCARD	2
#define CHANNEL_GPRS		5
#define CHANNEL_ENCMSR		14
#define CHANNEL_MIFARE		16

/**
 Forces data still in the sdk buffers to be sent directly to the printer
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnFlushCache:(NSError **)error;
/**
 Sends data to the connected printer no matter the connection type. This also handles the internal packet mode, so only the payload needs to be send.
 @param channel one of the CHANNEL_* constants. Use CHANNEL_PRN for generic access to the printer. This parameter has only meaning in protocol mode.
 @param data data bytes to write
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return TRUE if function succeeded, FALSE otherwise
 */
-(BOOL)prnWriteDataToChannel:(int)channel data:(NSData *)data error:(NSError **)error;
/**
 Tries to read data from the connected remote device for specified timeout.
 @param channel one of the CHANNEL_* constants. Use CHANNEL_PRN for generic access to the printer. This parameter has only meaning in protocol mode.
 @param length maximum amount of bytes to wait for
 @param timeout maximim timeout in seconds to wait for data
 @param error pointer to NSError object, where error information is stored in case function fails. You can pass nil if you don't want that information
 @return actual data being read or nil if error occured
 */
-(NSData *)prnReadDataFromChannel:(int)channel length:(int)length timeout:(double)timeout error:(NSError **)error;
/**
 Waits specified timeout for the printout to complete. It is best to call this function with the complete timeout you are willing
 to wait, rather than calling it in a loop
 @param timeout the timeout to wait for the job to finish
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE if printer have successfully finished printing and ready to accept new data, FALSE if communication problem or the printer
 is still busy
 */
-(BOOL)prnWaitPrintJob:(NSTimeInterval)timeout error:(NSError **)error;
/**
 Retrieves current printer status. This function is useful on printers having no automatic status notifications like DPP-250 and DPP-350.
 @param status upon successful execution, printer status (one or more of the PRN_STAT_* constants) will be stored here
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnGetPrinterStatus:(int *)status error:(NSError **)error;
/**
 Prints selftest
 @param longtest TRUE if you want complete test with fonts and codepage, FALSE for short one
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnSelfTest:(BOOL)longtest error:(NSError **)error;
/**
 Forces printer to turn off
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnTurnOff:(NSError **)error;
/**
 Feeds the paper X lines (1/203 of the inch) or as needed (different length based on the printer model) so it allows paper to be teared.
 @note If blackmark mode is active, this function searches for blackmark. If the paper is not blackmark one
 or the mark can not be found in 360mm, the printer will put itself into out of paper state and will need LF button to be pushed to continue.
 @param lines the number of lines (1/203 of the inch) to feed or 0 to automatically feed the paper as much as needed to tear the paper.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnFeedPaper:(int)lines error:(NSError **)error;
/**
 Prints barcode
 @param bartype Barcode type, one of the BAR_PRN_* constants
 @param barcode barcode data to be printed
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnPrintBarcode:(int)bartype barcode:(NSData *)barcode error:(NSError **)error;
/**
 Prints the stored logo. You can upload log with {@link #loadLogo:(NSData *)logo} function
 @param mode logo mode, one of the LOGO_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnPrintLogo:(int)mode error:(NSError **)error;
/**
 Set various barcode parameters.
 @param scale width of each barcode column in pixels (1/203 of the inch) between 2 and 4, default is 3
 @param height barcode height in pixels between 1 and 255. Default is 77
 @param hriPosition barcode hri code position, one of the BAR_TEXT_* constants
 @param align barcode aligning, one of the ALIGN_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnSetBarcodeSettings:(int)scale height:(int)height hriPosition:(int)hriPosition align:(int)align error:(NSError **)error;
/**
 Sets printer density level
 @param percent density level in percents (50%-200%)
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnSetDensity:(int)percent error:(NSError **)error;
/**
 Sets the line "height" in pixels
 If the characters are 16 pixelx high for example, setting the linespace to 20 will make the printer leave 4 blank lines before next line of text starts.
 You cannot make text lines overlap.
 @param lineSpace linespace in pixels, or 0 for automatic calculation. Default is 0
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnSetLineSpace:(int)lineSpace error:(NSError **)error;
/**
 Sets left margin
 @param leftMargin left margin in pixels. Default is 0
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnSetLeftMargin:(int)leftMargin error:(NSError **)error;
/**
 Prints text with specified font/styles.
 This function can act as both simple plain text printing and quite complex printing using internal tags to format the text.
 The function uses the currently font size and style (or default ones) as well as the aligning, however it allows modifications of them inside the text. Any modification of the settings using the tags will be reverted when function completes execution. For example if you have default font selected before using printText and set bold font inside, it will be reverted to plain when function completes.
 The tags are control commands used to modify the text printing parameters. They are surrounded by {} brackets. A list of all control tags follows:
 <ul>
 <li>{==} - reverts all settings to their defaults. It includes font size, style, aligning
 <li>{=Fx} - selects font size. x ranges from 0 to 1 as follows:
 <li>     0: FONT_9X16 (hieroglyph characters are using the same width as height, i.e. 16x16)
 <li>     1: FONT_12X24 (hieroglyph characters are using the same width as height, i.e. 24x24)
 <li>{=L} - left text aligning
 <li>{=C} - center text aligning
 <li>{=R} - right text aligning
 <li>{=Rx} - text rotation as follows:
 <li>     0: not rotated
 <li>     1: rotated 90 degrees
 <li>     2: rotated 180 degrees
 <li>{+/-B} - sets or unsets bold font style
 <li>{+/-I} - sets or unsets italic font style
 <li>{+/-U} - sets or unsets underline font style
 <li>{+/-V} - sets or unsets inverse font style
 <li>{+/-W} - sets or unsets text word-wrapping
 <li>{+/-DW} - sets or unsets doubled font width
 <li>{+/-DH} - sets or unsets doubled font height
 </ul><p>
 An example of using tags "{=C}Plain centered text\n{=L}Left centered\n{+B}...bold...{-B}{+I}or ITALIC"
 @param textString the text to print
 @param encoding the encoding to use when converting the string to format suitable to the printer. Default encoding should be NSWindowsCP1252StringEncoding. Currently double-byte encodings like JIS are not supported.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnPrintText:(NSString *)textString usingEncoding:(NSStringEncoding)encoding error:(NSError **)error;
/**
 Prints text with specified font/styles.
 This function can act as both simple plain text printing and quite complex printing using internal tags to format the text.
 The function uses the currently font size and style (or default ones) as well as the aligning, however it allows modifications of them inside the text. Any modification of the settings using the tags will be reverted when function completes execution. For example if you have default font selected before using printText and set bold font inside, it will be reverted to plain when function completes.
 The tags are control commands used to modify the text printing parameters. They are surrounded by {} brackets. A list of all control tags follows:
 <ul>
 <li>{==} - reverts all settings to their defaults. It includes font size, style, aligning
 <li>{=Fx} - selects font size. x ranges from 0 to 1 as follows:
 <li>     0: FONT_9X16 (hieroglyph characters are using the same width as height, i.e. 16x16)
 <li>     1: FONT_12X24 (hieroglyph characters are using the same width as height, i.e. 24x24)
 <li>{=L} - left text aligning
 <li>{=C} - center text aligning
 <li>{=R} - right text aligning
 <li>{=Rx} - text rotation as follows:
 <li>     0: not rotated
 <li>     1: rotated 90 degrees
 <li>     2: rotated 180 degrees
 <li>{+/-B} - sets or unsets bold font style
 <li>{+/-I} - sets or unsets italic font style
 <li>{+/-U} - sets or unsets underline font style
 <li>{+/-V} - sets or unsets inverse font style
 <li>{+/-W} - sets or unsets text word-wrapping
 <li>{+/-DW} - sets or unsets doubled font width
 <li>{+/-DH} - sets or unsets doubled font height
 </ul><p>
 An example of using tags "{=C}Plain centered text\n{=L}Left centered\n{+B}...bold...{-B}{+I}or ITALIC"
 @param textString the text to print
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnPrintText:(NSString *)textString error:(NSError **)error;
/**
 Prints the delimiter character at the whole width of the paper, adjusting itself to the paper width. The character is printed with font 12x24
 @param delimchar character to print
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnPrintDelimiter:(char)delimchar error:(NSError **)error;
/**
 Returns blackmark sensor treshold or UnsupportedOperationException if printer is not in blackmark mode.
 This value tells the printer how dark a spot on the paper needs to be in order to be considered as blackmark.
 @param treshold upon success stores the current blackmark treshold
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnGetBlackMarkTreshold:(int *)treshold error:(NSError **)error;
/**
 Sets blackmark sensor treshold or UnsupportedOperationException if printer is not in blackmark mode.
 This value tells the printer how dark a spot on the paper needs to be in order to be considered as blackmark.
 @param treshold value between 0x20 and 0xc0, default is 0x68
 @throw NSPortTimeoutException if there is no connection to the printer
 */
-(BOOL)prnSetBlackMarkTreshold:(int)treshold error:(NSError **)error;
/**
 Provides blackmark sensor calibration by scaning 200mm of paper for possible black marks and adjust the sensor treshold.
 Make sure you have put the right paper before calling this function.
 @return returns new trashold value for the scanned paper. The trashold is already stored in printer's flash memory so no
 additional set is needed.
 @param treshold upon sucess, the black mark treshold will be returned here
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnCalibrateBlackMark:(int *)treshold error:(NSError **)error;
/**
 Loads logo into printer's memory. The logo is persistent and can be deleted only if battery is removed
 @param logo logo bitmap data
 @param align logo alignment, one of the ALIGN_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnLoadLogo:(UIImage *)logo align:(int)align error:(NSError **)error;
/**
 Prints Bitmap object using specified alignment. You can print color bitmaps, as they will be converted to black and white using error diffusion and dithering to achieve best results. On older devices this can take some time
 @param image UIImage object
 @param align image alighment, one of the ALIGN_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)prnPrintImage:(UIImage *)image align:(int)align error:(NSError **)error;
/**@}*/

/** @defgroup G_PRNPAGEMODE Printing Page Mode Functions
 Functions to work with the printer's page mode. Page mode is a special operation mode, that allows you to define a virtual page
 and then draw inside text, graphics, barcodes and print it all at once. Page mode allows for extended positioning of the elements,
 rotation, inversion and basic graphics elements.
 @ingroup G_PRINTER
 @{
 */
/**
 Returns TRUE if page mode is supported on the connected device
 */
-(BOOL)pageIsSupported;
/**
 Creates a new virtual page using the maximum supported page height.
 Use {@link #getInfo:(int)infocmd} to get the maximum page height supported.
 See {@link #pageStart} for more detailed information
 The page mode allows constructing a virtual page inside the printer, draw text, graphics,
 and performs some basic graphics operations (draw rectangles, frames, invert parts of the page)
 at any place, rotated or not, then print the result.
 Page mode is useful if you want to create some non-standart printout, or print vertically.
 Tables functions also work in page mode allowing a huge tables to be created and printed vertically.
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pageStart:(NSError **)error;
/**
 Prints the content of the virtual page.
 @note The white space from the top and bottom is not printed so the print ends at the last black dot.
 If you want to feed the paper use the {@link #prnFeedPaper:(int)lines error:(NSError **)error} function
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pagePrint:(NSError **)error;
/**
 Exits page mode
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pageEnd:(NSError **)error;
/**
 Sets a working area and orientation inside the virtual page. No drawing can ever occur outside the said area
 @param left, top, width, height working area rectangle in absolute pixels (i.e. does not depend on the page orientation)
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pageSetWorkingArea:(int)left top:(int)top width:(int)width height:(int)height error:(NSError **)error;
/**
 Sets a working area and orientation inside the virtual page. No drawing can ever occur outside the said area
 @param left, top, width, height working area rectangle in absolute pixels (i.e. does not depend on the page orientation)
 @param orientation one of the PAGE_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pageSetWorkingArea:(int)left top:(int)top width:(int)width heigth:(int)height orientation:(int)orientation error:(NSError **)error;
/**
 Fills the current working area (or whole page if none is set) with the specified color
 @param color - the color to use, either COLOR_INVERT or custom UIColor
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pageFillRectangle:(UIColor *)color error:(NSError **)error;
/**
 Fills a rectangle inside the current working area with specified color
 @param left, top, width, height rectangle coordinates
 @param color - the color to use, either COLOR_INVERT or custom UIColor
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pageFillRectangle:(int)left top:(int)top width:(int)width height:(int)height color:(UIColor *)color error:(NSError **)error;
/**
 Draws a rectangle frame inside the current working area with specified color
 @param left, top, width, height rectangle coordinates
 @param framewidth width of the frame (1-64)
 @param color - the color to use, either COLOR_INVERT or custom UIColor
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)pageRectangleFrame:(int)left top:(int)top width:(int)width height:(int)height framewidth:(int)framewidth color:(UIColor *)color error:(NSError **)error;
/**@}*/

/** @defgroup G_PRNTABLES Printing Table Functions
 Functions to create, fill and print tables
 @ingroup G_PRINTER
 @{
 */
/**
 Checks if the currently connected printer supports tables
 @return TRUE if tables are supported
 */
-(BOOL)tableIsSupported;
/**
 Create a new table using custom flags
 @param flags one or more of the TABLE_BORDERS_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableCreate:(int)flags error:(NSError **)error;
/**
 Create a new table using default settings - both horizontal and vertical borders around it
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableCreate:(NSError **)error;
/**
 Adds a new column using default settings - 12x24 font, plain, vertical border between the cells, left aligning
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddColumn:(NSError **)error;
/**
 Adds a new column using default settings - plain text, vertical border between the cells, left aligning
 @param font one of the FONT_size constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddColumn:(int)font error:(NSError **)error;
/**
 Adds a new column using custom font and vertical border between the cells
 @param font one of the FONT_size constants
 @param style one or more of the font style constants (FONT_BOLD, FONT_ITALIC, etc)
 @param alignment text alignment inside the cell, one of the ALIGN_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddColumn:(int)font style:(int)style alignment:(int)alignment error:(NSError **)error;
/**
 Adds a new column
 @param font one of the FONT_size constants
 @param style one or more of the font style constants (FONT_BOLD, FONT_ITALIC, etc)
 @param alignment text alignment inside the cell, one of the ALIGN_* constants
 @param flags one or more of the TABLE_BORDERS_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddColumn:(int)font style:(int)style alignment:(int)alignment flags:(int)flags error:(NSError **)error;
/**
 Adds a new cell using the font size and style and aligning of the column that cell belongs to
 @param data string data
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddCell:(NSString *)data error:(NSError **)error;
/**
 Adds a new cell using the font style and aligning of the column that cell belongs to
 @param data string data
 @param font font size, one of the FONT_size constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddCell:(NSString *)data font:(int)font error:(NSError **)error;
/**
 Adds a new cell using custom font size and style and aligning of the column that cell belongs to
 @param data string data
 @param font font size, one of the FONT_size constants
 @param style one or more of the font style constants (FONT_BOLD, FONT_ITALIC, etc)
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddCell:(NSString *)data font:(int)font style:(int)style error:(NSError **)error;
/**
 Adds a new cell using custom font size and style and aligning
 @param data string data
 @param font font size, one of the FONT_size constants
 @param style one or more of the font style constants (FONT_BOLD, FONT_ITALIC, etc)
 @param alignment date aligning, one of the ALIGN_* constants
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddCell:(NSString *)data font:(int)font style:(int)style alignment:(int)alignment error:(NSError **)error;
/**
 Adds aa horizontal black line to the entire row that separates it from the next
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableAddDelimiter:(NSError **)error;
/**
 Sets the row height that will be used by default for new cells added
 @param height row height, any value less than the characters height will be auto fixed. Default is LINESPACE_DEFAULT
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tableSetRowHeight:(int)height error:(NSError **)error;
/**
 Prints current table or throws IllegalArgumentException if cell data cannot be fit into paper
 @param error returns error information, you can pass nil if you don't want it
 @return TRUE upon success, FALSE otherwise
 */
-(BOOL)tablePrint:(NSError **)error;
/**@}*/

/**
 Adds delegate to the class
 **/
@property(assign) id delegate;

/**
 Provides a list of currently registered delegates
 */
@property(readonly) NSMutableArray *delegates;

/**
 Returns current connection state
 **/
@property(readonly) int connstate;
/**
 Returns connected device name
 **/
@property(readonly) NSString *deviceName;
/**
 Returns connected device model
 **/
@property(readonly) NSString *deviceModel;
/**
 Returns connected device firmware version
 **/
@property(readonly) NSString *firmwareRevision;
/**
 Returns connected device hardware version
 **/
@property(readonly) NSString *hardwareRevision;
/**
 Returns connected device serial number
 **/
@property(readonly) NSString *serialNumber;

/**
 SDK version number in format MAJOR*100+MINOR, i.e. version 1.15 will be returned as 115
 */
@property(readonly) int sdkVersion;

/**
 SDK build date
 */
@property(readonly) NSDate *sdkBuildDate;

/**
 EMV last status, one of the EMV_* constants
 */
@property(readonly) short emvLastStatus;

/**@}*/

@end











