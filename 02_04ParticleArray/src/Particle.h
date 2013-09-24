#pragma once
#include "ofMain.h"

class Particle {

public:

    ofVec2f position;
    void setup(ofVec2f position);
    void draw();
};