//
// Created by johnw on 7/11/2023.
//

#include "CenterPulseSplit.h"

CenterPulseSplit::CenterPulseSplit(CRGB *np, int nleds, colors_t c):
        Pattern(np, nleds, c),
        num_groups(nleds / 40),
        state(1),
        prev_state(0),
        max_state(20)
        {}

void CenterPulseSplit::firstStep() {
    // Clear the string
    Pattern::firstStep();

    state = 1;
    prev_state = 0;
}

void CenterPulseSplit::nextStep() {
    int s;
    int type;
    for (s=0; s<num_groups; s++){
        if (s % 2 == 0)
            type = PRIMARY;
        else
            type = SECONDARY;

        for (int i=prev_state; i < state and i <= max_state; i++){
            leds[(40*s) + i] = colors->get(type);
            leds[(40*s) + 40 - i] = colors->get(type);
        }
    }
    FastLED.show();
    delay(300);

    if (state > max_state)
        firstStep();
    else {
        prev_state = state;
        state += state;
    }


}
