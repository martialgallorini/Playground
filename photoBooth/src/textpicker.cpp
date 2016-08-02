#include "textpicker.h"

void TextPicker::init()
{
    ofBuffer buffer = ofBufferFromFile("list.txt");
    for (auto line : buffer.getLines()){
        list.push_back(line);
    }
}

string TextPicker::getRandomText()
{
    int index = ofRandom(0, list.size());
    return list.at(index);
}
