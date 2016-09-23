//
//  thermalPrinter.cpp
//  photoBooth
//
//  Created by Martial on 15/09/2016.
//
//


#include <thermalPrinter.h>

ThermalPrinter::ThermalPrinter() {
    this->open("/dev/tty.usbserial");
    cout << "Thermal Printer : constructor()" << endl;
}


ThermalPrinter::~ThermalPrinter() {
    this->close();
    cout << "Thermal Printer : destructor()" << endl;
}


void ThermalPrinter::print(ofImage &img) {
    cout << "Thermal Printer : print()" << endl;
    this->reset();
    this->ofxThermalPrinter::print(img, 105);
}