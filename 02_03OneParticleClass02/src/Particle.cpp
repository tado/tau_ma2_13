#include "Particle.h"

void Particle::setup(ofVec2f _position){
    position = _position;
}

void Particle::draw(){
    ofSetHexColor(0x3399cc);
    ofCircle(position, 10);
}