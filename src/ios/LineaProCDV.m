//
//  LineaProCDV.m
//
//  Created by Timofey Tatarinov on 27.01.14.
//  Citronium
//  http://citronium.com
//

#import "LineaProCDV.h"

@interface LineaProCDV()

+ (NSString*) getPDF417ValueByCode: (NSArray*) codesArr code:(NSString*)code;

@end

@implementation LineaProCDV

-(void) scannerConect:(NSString*)num {
    
    NSString *jsStatement = [NSString stringWithFormat:@"reportConnectionStatus('%@');", num];
    [self.webView stringByEvaluatingJavaScriptFromString:jsStatement];
    
}

-(void) scannerBattery:(NSString*)num {
    
    int percent;
    float voltage;
    
	if([dtdev getBatteryCapacity:&percent voltage:&voltage error:nil])
    {
        NSString *status = [NSString stringWithFormat:@"Bat: %.2fv, %d%%",voltage,percent];
        
        // send to web view
        NSString *jsStatement = [NSString stringWithFormat:@"reportBatteryStatus('%@');", status];
        [self.webView stringByEvaluatingJavaScriptFromString:jsStatement];
        
    }
}

-(void) scanPaymentCard:(NSString*)num {
    
    NSString *jsStatement = [NSString stringWithFormat:@"onSuccessScanPaymentCard('%@');", num];
    [self.webView stringByEvaluatingJavaScriptFromString:jsStatement];
	[self.viewController dismissViewControllerAnimated:YES completion:nil];
    
}

- (void)initDT:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    if (!dtdev) {
        dtdev = [DTDevices sharedDevice];
        [dtdev addDelegate:self];
        [dtdev connect];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getConnectionStatus:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:[dtdev connstate]];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)startBarcode:(CDVInvokedUrlCommand *)command
{
    [dtdev barcodeStartScan:nil];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:[dtdev connstate]];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)stopBarcode:(CDVInvokedUrlCommand *)command
{
    [dtdev barcodeStopScan:nil];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:[dtdev connstate]];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)connectionState: (int)state {
    NSLog(@"connectionState: %d", state);
    
    switch (state) {
		case CONN_DISCONNECTED:
		case CONN_CONNECTING:
                break;
		case CONN_CONNECTED:
		{
			NSLog(@"PPad connected!\nSDK version: %d.%d\nHardware revision: %@\nFirmware revision: %@\nSerial number: %@", dtdev.sdkVersion/100,dtdev.sdkVersion%100,dtdev.hardwareRevision,dtdev.firmwareRevision,dtdev.serialNumber);
			break;
		}
	}
    
    NSString* retStr = [ NSString stringWithFormat:@"LineaProCDV.connectionChanged(%d);", state];
    [[super webView] stringByEvaluatingJavaScriptFromString:retStr];
}

- (void) deviceButtonPressed: (int) which {
    NSLog(@"deviceButtonPressed: %d", which);
}

- (void) deviceButtonReleased: (int) which {
    NSLog(@"deviceButtonReleased: %d", which);
}

- (void) deviceFeatureSupported: (int) feature value:(int) value {
    NSLog(@"deviceFeatureSupported: feature - %d, value - %d", feature, value);
}

- (void) firmwareUpdateProgress: (int) phase percent:(int) percent {
    NSLog(@"firmwareUpdateProgress: phase - %d, percent - %d", phase, percent);
}

- (void) magneticCardData: (NSString *) track1 track2:(NSString *) track2 track3:(NSString *) track3 {
    NSLog(@"magneticCardData: track1 - %@, track2 - %@, track3 - %@", track1, track2, track3);
    NSDictionary *card = [dtdev msProcessFinancialCard:track1 track2:track2];
    if(card && [card objectForKey:@"accountNumber"]!=nil && [[card objectForKey:@"expirationYear"] intValue]!=0)
    {
        NSLog(@"magneticCardData (full info): accountNumber - %@, cardholderName - %@, expirationYear - %@, expirationMonth - %@, serviceCode - %@, discretionaryData - %@, firstName - %@, lastName - %@", [card objectForKey:@"accountNumber"], [card objectForKey:@"cardholderName"], [card objectForKey:@"expirationYear"], [card objectForKey:@"expirationMonth"], [card objectForKey:@"serviceCode"], [card objectForKey:@"discretionaryData"], [card objectForKey:@"firstName"], [card objectForKey:@"lastName"]);
    }
    NSString* retStr = [ NSString stringWithFormat:@"LineaProCDV.onMagneticCardData('%@', '%@', '%@');", track1, track2, track3];
    [[super webView] stringByEvaluatingJavaScriptFromString:retStr];
}

- (void) magneticCardEncryptedData: (int) encryption tracks:(int) tracks data:(NSData *) data {
    NSLog(@"magneticCardEncryptedData: encryption - %d, tracks - %d, data - %@", encryption, tracks, [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]);
}

- (void) magneticCardEncryptedData: (int) encryption tracks:(int) tracks data:(NSData *) data track1masked:(NSString *) track1masked track2masked:(NSString *) track2masked track3:(NSString *) track3 {
    NSLog(@"magneticCardEncryptedData: encryption - %d, tracks - %d, track3 - %@, track1masked - %@, track2masked - %@, track3 - %@", encryption, tracks, [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding], track1masked, track2masked, track3);
}

- (void) magneticCardEncryptedRawData: (int) encryption data:(NSData *) data {
    NSLog(@"magneticCardEncryptedRawData: encryption - %d, data - %@", encryption, [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]);
}

- (void) magneticCardRawData: (NSData *) tracks {
    NSLog(@"magneticCardRawData: data - %@", [[NSString alloc] initWithData:tracks encoding:NSUTF8StringEncoding]);
}

- (void) magneticJISCardData: (NSString *) data {
    NSLog(@"magneticJISCardData: data - %@", data);
}

- (void) paperStatus: (BOOL) present {
    NSLog(@"paperStatus: present - %d", present);
}

- (void) PINEntryCompleteWithError: (NSError *) error {
    NSLog(@"PINEntryCompleteWithError: error - %@", [error localizedDescription]);
}

- (void) rfCardDetected: (int) cardIndex info:(DTRFCardInfo *) info {
    NSLog(@"rfCardDetected (debug): cardIndex - %d, info - %@", cardIndex, [info description]);
    NSLog(@"rfCardDetected (debug): cardIndex - %d, info - %@", cardIndex, [info debugDescription]);
}

- (void) rfCardRemoved: (int) cardIndex {
    NSLog(@"rfCardRemoved: cardIndex - %d", cardIndex);
}

- (void) sdkDebug: (NSString *) logText source:(int) source {
    NSLog(@"sdkDebug: logText - %@, source - %d", logText, source);
}

- (void) smartCardInserted: (SC_SLOTS) slot {
    NSLog(@"smartCardInserted: slot - %d", slot);
}

- (void) smartCardRemoved: (SC_SLOTS) slot {
    NSLog(@"smartCardRemoved: slot - %d", slot);
}

- (void) barcodeData: (NSString *) barcode type:(int) type {
    NSLog(@"barcodeData: barcode - %@, type - %@", barcode, [dtdev barcodeType2Text:type]);
    NSString* retStr = [ NSString stringWithFormat:@"LineaProCDV.onBarcodeData('%@', '%@');", barcode, [dtdev barcodeType2Text:type]];
    [[super webView] stringByEvaluatingJavaScriptFromString:retStr];
}

- (void) barcodeNSData: (NSData *) barcode isotype:(NSString *) isotype {
    NSLog(@"barcodeNSData: barcode - %@, type - %@", [[NSString alloc] initWithData:barcode encoding:NSUTF8StringEncoding], isotype);
    NSString* retStr = [ NSString stringWithFormat:@"LineaProCDV.onBarcodeData('%@', '%@');", [[NSString alloc] initWithData:barcode encoding:NSUTF8StringEncoding], isotype];
    [[super webView] stringByEvaluatingJavaScriptFromString:retStr];
}

+ (NSString*) getPDF417ValueByCode: (NSArray*) codesArr code:(NSString*)code {
    for (NSString* currStr in codesArr) {
        // do something with object
        NSRange range = [currStr rangeOfString:code];
        if (range.length == 0) continue;
        NSString *substring = [[currStr substringFromIndex:NSMaxRange(range)] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
        return substring;
    }
    return NULL;
}

+ (NSString*) generateStringForArrayEvaluationInJS: (NSArray*) stringsArray {
    NSString* arrayJSString = [NSString stringWithFormat:@"["];
    BOOL isFirst = TRUE;
    for (int i = 0; i < stringsArray.count; ++i) {
        NSString* currString = [stringsArray objectAtIndex:i];
        if (currString.length <= 1) continue;
        arrayJSString = [NSString stringWithFormat:@"%@%@\"%@\"", arrayJSString, isFirst ? @"" : @",", currString];
        isFirst = FALSE;
    }
    arrayJSString = [NSString stringWithFormat:@"%@]", arrayJSString];
    return arrayJSString;
}

- (void) barcodeNSData: (NSData *) barcode type:(int) type {
    NSLog(@"barcodeNSData: barcode - %@, type - %@", [[NSString alloc] initWithData:barcode encoding:NSUTF8StringEncoding], [dtdev barcodeType2Text:type]);
    NSArray *codesArr = [[[NSString alloc] initWithData:barcode encoding:NSUTF8StringEncoding] componentsSeparatedByCharactersInSet:
                        [NSCharacterSet characterSetWithCharactersInString:@"\n\r"]];
    NSString* substrDateBirth = @"DBB";
    NSString* dateBirth = [LineaProCDV getPDF417ValueByCode:codesArr code: substrDateBirth];
    NSString* substrName = @"DAC";
    NSString* name = [LineaProCDV getPDF417ValueByCode:codesArr code: substrName];
    NSString* substrLastName = @"DCS";
    NSString* lastName = [LineaProCDV getPDF417ValueByCode:codesArr code: substrLastName];
    NSString* substrEye = @"DAY";
    NSString* eye = [LineaProCDV getPDF417ValueByCode:codesArr code: substrEye];
    NSString* substrState = @"DAJ";
    NSString* state = [LineaProCDV getPDF417ValueByCode:codesArr code: substrState];
    NSString* substrCity = @"DAI";
    NSString* city = [LineaProCDV getPDF417ValueByCode:codesArr code: substrCity];
    NSString* substrHeight = @"DAU";
    NSString* height = [LineaProCDV getPDF417ValueByCode:codesArr code: substrHeight];
    NSString* substrWeight = @"DAW";
    NSString* weight = [LineaProCDV getPDF417ValueByCode:codesArr code: substrWeight];
    NSString* substrGender = @"DBC";
    NSString* gender = [LineaProCDV getPDF417ValueByCode:codesArr code: substrGender];
    NSString* substrHair = @"DAZ";
    NSString* hair = [LineaProCDV getPDF417ValueByCode:codesArr code: substrHair];
    NSString* substrExpires = @"DBA";
    NSString* expires = [LineaProCDV getPDF417ValueByCode:codesArr code: substrExpires];
    NSString* substrLicense = @"DAQ";
    NSString* license = [LineaProCDV getPDF417ValueByCode:codesArr code: substrLicense];
    NSLog(@"%@ %@ %@ %@ %@ %@ %@ %@ %@ %@ %@ %@", dateBirth, name, lastName, eye, state, city, height, weight, gender, hair, expires, license);
    
    NSString* rawCodesArrJSString = [LineaProCDV generateStringForArrayEvaluationInJS:codesArr];
    //LineaProCDV.onBarcodeData(scanId, dob, state, city, expires, gender, height, weight, hair, eye)
    NSString* retStr = [ NSString stringWithFormat:@"var rawCodesArr = %@; LineaProCDV.onBarcodeData(rawCodesArr, '%@', '%@', '%@', '%@', '%@', '%@', '%@', '%@', '%@', '%@', '%@', '%@');", rawCodesArrJSString, license, dateBirth, state, city, expires, gender, height, weight, hair, eye, name, lastName];
    [[super webView] stringByEvaluatingJavaScriptFromString:retStr];
}

- (void) bluetoothDeviceConnected: (NSString *) address {
    NSLog(@"bluetoothDeviceConnected: address - %@", address);
}

- (void) bluetoothDeviceDisconnected: (NSString *) address {
    NSLog(@"bluetoothDeviceDisconnected: address - %@", address);
}

- (void) bluetoothDeviceDiscovered: (NSString *) address name:(NSString *) name {
    NSLog(@"bluetoothDeviceDiscovered: address - %@, name - @name", name);
}
- (NSString *) bluetoothDevicePINCodeRequired: (NSString *) address name:(NSString *) name {
    NSLog(@"bluetoothDevicePINCodeRequired: address - %@, name - @name", name);
    return address;
}

- (BOOL) bluetoothDeviceRequestedConnection: (NSString *) address name:(NSString *) name {
    NSLog(@"bluetoothDeviceRequestedConnection: address - %@, name - @name", name);
    return TRUE;
}

- (void) bluetoothDiscoverComplete: (BOOL) success {
    NSLog(@"bluetoothDiscoverComplete: success - %d", success);
}



@end
