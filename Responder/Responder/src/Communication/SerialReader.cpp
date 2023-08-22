//
// Created by johnw on 7/8/2023.
//

#include "SerialReader.h"

Command_t SerialReader::getCommand() {
    String code;
    Command_t command;

    if (Serial1.available()) {
        code = Serial1.readString();
        code.trim();

        // display the code
        Serial.println(code);

        // make the change
        if (code.charAt(0) == 'C')
            processColor(code, command);
        else if (code.charAt(0) == 'K')
            processCustomColor(code, command);
        else if (code.charAt(0) == 'M')
            processMusic(code, command);
        else if (code.charAt(0) == 'S')
            processStatic(code, command);
        else
            noCommand(command);
    }
    else {
        noCommand(command);
    }
    return command;
}

void SerialReader::processColor(const String& code, Command &command) {
    command.type = Command::COLOR;
    command.value = code.substring(1,1).toInt();    // Set Primary, Secondary, or Tertiary

    // decode code into RGB values
    String red = code.substring(2,5);

    String green = code.substring(5,8);

    String blue = code.substring(8,11);

    command.r = dynamic_cast<uint8_t>(red.toInt());
    command.g = dynamic_cast<uint8_t>(green.toInt());
    command.b = dynamic_cast<uint8_t>(blue.toInt());
}

void SerialReader::processCustomColor(const String &code, Command &command) {
    command.type = Command::COLOR;
    command.value = code.substring(1,1).toInt(); // Set Primary, Secondary, or Tertiary

    String red = code.substring(2,5);

    String green = code.substring(5,8);

    String blue = code.substring(8,11);

    if (!red.equals("---")) {
        command.r = dynamic_cast<uint8_t>(red.toInt());
        command.g = 999;
        command.b = 999;
    }
    else if (!green.equals("---")) {
        command.g = dynamic_cast<uint8_t>(green.toInt());
        command.r = 999;
        command.b = 999;
    }
    else if (!blue.equals("---")) {
        command.b = dynamic_cast<uint8_t>(blue.toInt());
        command.r = 999;
        command.g = 999;
    }
}

void SerialReader::processMusic(const String& code, Command &command) {
    command.type = Command::MUSIC_P;
    command.value = code.substring(2,10).toInt();
}

void SerialReader::processStatic(const String& code, Command &command) {
    command.type = Command::STATIC_P;
    command.value = code.substring(2,10).toInt();
}

void SerialReader::noCommand(Command &command) {
    command.type = Command::NONE;
    command.value = Command::NONE;
}