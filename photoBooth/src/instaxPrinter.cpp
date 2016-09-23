//
//  instaxPrinter.cpp
//  photoBooth
//
//  Created by Martial on 18/09/2016.
//
//

#include "instaxPrinter.h"

InstaxPrinter::InstaxPrinter() {
    cout << "Instax Printer : constructor()" << endl;
}


InstaxPrinter::~InstaxPrinter() {
    cout << "Instax Printer : destructor()" << endl;
}


void InstaxPrinter::print(ofImage &img) {
    cout << "Instax Printer : print()" << endl;
}