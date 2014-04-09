lineapro-phonegap-plugin
========================

## Quick start
To start plugin need to execute 'LineaProCDV.initDT()' method. 
Recommended to add this into 'deviceready' handler.

###
!!! You must add section "SupportedExternalAccessoryProtocols" into "[Project Name].plist" file. 
This section should include the following items:

* com.datecs.linea.pro.msr
* com.datecs.iserial.communication
* com.datecs.pinpad
* com.datecs.linea.pro.bar

### Sample cordova project
The sample project which is using this plugin available here https://github.com/ttatarinov/lineapro-phonegap-plugin-example

## Device support
Universal plugin for following devices:

* PPAD 1.0
* MPED-400
* BluePad-500
* BluePad-50
* Infinea TAB mini
* Infinea TAB 4
* Infinea TAB
* Linea Pro 5
* Linea Pro 4
* PP-60
* iSerial
* Linea-Pro

## Supported features:

* Automatically device connection
* Log all events
* Start/Stop Barcode methods

## Additional info

Using iOS SDK from http://www.datecs.bg/en/products/Universal-iOS-SDK/8/121

Tested on Cordova ver.3.3

(c) Citronium, 2014
http://citronium.com
