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
            processColor(code, &command);
        else if (code.charAt(0) == 'M')
            processMusic(code, &command);
        else if (code.charAt(0) == 'S')
            processStatic(code, &command);
        else
            noCommand(&command);

    }
    else {
        noCommand(&command);
    }

    return command;
}

void SerialReader::processColor(String code, Command_t *command) {
    command->type = Command::COLOR;

    // decode code into RGB values
    String red = code.substring(1,4);

    String green = code.substring(4,7);

    String blue = code.substring(7,10);

    command->r = red.toInt();
    command->g = green.toInt();
    command->b = blue.toInt();
}

void SerialReader::processMusic(String code, Command_t *command) {
    command->type = Command::MUSIC_P;
    command->value = code.substring(2,10).toInt();
}

void SerialReader::processStatic(String code, Command_t *command) {
    command->type = Command::STATIC_P;
    command->value = code.substring(2,10).toInt();
}

void SerialReader::noCommand(Command *command) {
    command->type = Command::NONE;
    command->value = Command::NONE;
}