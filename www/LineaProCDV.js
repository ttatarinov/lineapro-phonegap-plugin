var argscheck = require('cordova/argscheck'),
    channel = require('cordova/channel'),
    utils = require('cordova/utils'),
    exec = require('cordova/exec'),
    cordova = require('cordova');
              
 function LineaProCDV() {
    this.results = [];
    this.connCallback = null;
    this.errorCallback = null;
    this.cancelCallback = null;
    
}


LineaProCDV.prototype.initDT = function(connectionCallback, cancelCallback, errorCallback) {
    this.results = [];
    this.connCallback = connectionCallback;
    exec(null, errorCallback, "LineaProCDV", "initDT", []);
};
               
LineaProCDV.prototype.barcodeStart = function() {
    exec(null, null, "LineaProCDV", "barcodeStart", []);
};

LineaProCDV.prototype.barcodeStop = function() {
    exec(null, null, "LineaProCDV", "barcodeStop", []);
};
               
LineaProCDV.prototype.connectionChanged = function(state) {
    this.connCallback(state);
};
               
              
module.exports = new LineaProCDV();
