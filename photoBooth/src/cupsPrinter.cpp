//
//  cupsPrinter.cpp
//  photoBooth
//
//  Created by Martial on 18/09/2016.
//
//

#include "cupsPrinter.h"

CupsPrinter::CupsPrinter() {
    cout << "CUPS Printer : constructor()" << endl;
}


CupsPrinter::~CupsPrinter() {
    cout << "CUPS Printer : destructor()" << endl;
}


void CupsPrinter::print(ofImage &img) {
    cout << "CUPS Printer : print()" << endl;
    
    //PRINT VIA CUPS COMMANDLINE ON USB OR WIFI
    //system("lp -o Media=860x1070 -o ColorModel=Gray /Users/Martial/Desktop/DEV/oF093/apps/playground/photoBooth/bin/data/test.jpg");
    string cmd;
    cmd += "lp";
    cmd += " -o ColorModel=Gray";
    //    cmd += " -o MediaSize=Custom." + ofToString(comp.getWidth()) + "x" + ofToString(comp.getHeight());
    //    cmd += " -o media=3.5x5";
    cmd += " /Users/Martial/Desktop/DEV/oF093/apps/playground/photoBooth/bin/data/test_300dpi.jpg";
    system(cmd.c_str());
    
    // PRINT VIA BLUETOOTH
    //    ofSerial printer;
    //    printer.setup(0, 9600);
    //    if(printer.isInitialized() && printer.available()) {
    //        //unsigned char *buffer = bat.getPixels();
    //        unsigned char *buffer = bat.getData();
    //        printer.writeBytes(buffer, sizeof(buffer));
    //        printer.flush();
    //    }

}