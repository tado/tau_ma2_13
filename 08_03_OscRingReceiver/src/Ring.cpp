#include "Ring.h"

Ring::Ring(ofPoint _pos){
    pos = _pos;
    radius = 0;
    radiusSpeed = 0.5;
    dead = false;
}

void Ring::update(){
    radius += radiusSpeed;
    if (radius > ofGetWidth()) {
        dead = true;
    }
}

void Ring::draw(){
    ofSetCircleResolution(64);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    ofEnableSmoothing();
    ofSetLineWidth(1);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofNoFill();
    ofSetColor(63, 127, 255, 127 - radius * 127 / ofGetHeight());
    ofCircle(0, 0, radius);
    ofFill();
    ofSetColor(63, 127, 255, 31 - radius * 31 / ofGetHeight());
    ofCircle(0, 0, radius);
    ofPopMatrix();
}

