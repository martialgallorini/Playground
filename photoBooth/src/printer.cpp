//
//  printer.cpp
//  photoBooth
//
//  Created by Martial on 15/09/2016.
//
//

#include "printer.h"
#include "thermalPrinter.h"
#include "cupsPrinter.h"
#include "instaxPrinter.h"

Printer * Printer::create(int type) {
    switch (type) {
        case PRINTER_THERMAL:
            return new ThermalPrinter();
            break;
        case PRINTER_INSTAX:
            return new InstaxPrinter();
            break;
        case PRINTER_CUPS:
            return new CupsPrinter();
            break;
        default:
            break;
    }
}

Printer::Printer() {
    cout << "Base printer constructor()" << endl;
}

Printer::~Printer() {
    cout << "Base printer destructor()" << endl;
}

void Printer::print(ofImage &img) {
    cout << "Base printer print()" << endl;
}