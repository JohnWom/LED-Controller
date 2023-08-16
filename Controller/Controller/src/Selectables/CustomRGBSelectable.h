//
// Created by johnw on 7/12/2023.
//

#ifndef CustomRGBSELECTABLE_H
#define CustomRGBSELECTABLE_H

#include "SelectableInterface.h"
#include <Arduino.h>

/*
 * Selectable to set a custom RGB Number
 * It comes in 3 types, R, G, and B
 * Builds custom code for each type
*/

class CustomRGBSelectable: public Selectable
{
public:
    enum types {R, G, B};
    CustomRGBSelectable(char*, int, int, int);
    // min, max, type

    void execute() override;
    void rightScroll() override;
    void leftScroll() override;

private:
    void refresh();
    int val;
    int minV;
    int maxV;
    int type;
};


#endif //CustomRGBSELECTABLE_H
