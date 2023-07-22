//
// Created by johnw on 7/8/2023.
//

#ifndef SERIAL_READER_H
#define SERIAL_READER_H

#include "CommunicatorInterface.h"
#include <Arduino.h>
#include <string.h>

class SerialReader: public Communicator
{
public:
    Command getCommand();

private:
    void processColor(const String& code, Command* command);
    void processStatic(const String& code, Command* command);
    void processMusic(const String& code, Command* command);
    void processCustomColor(const String& code, Command* command);
    void noCommand(Command* command);
};


#endif //SERIAL_READER_H
