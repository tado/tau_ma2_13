#pragma once

#include "ofxState.h"

class TemplateState : public itg::ofxState<> {
    void setup();
    void update();
    void draw();
    string getName();
};