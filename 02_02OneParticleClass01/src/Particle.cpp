#include "Particle.h"

void Particle::draw(){
    ofSetHexColor(0x3399cc);
    ofCircle(position, 10);
}