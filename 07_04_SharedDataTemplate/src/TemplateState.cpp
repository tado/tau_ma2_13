#include "TemplateState.h"

void TemplateState::setup(){
}

void TemplateState::update(){
}

void TemplateState::draw(){
    ofBackground(64);
    ofSetColor(255);
    ofDrawBitmapString("Template State", 20, 20);
    ofDrawBitmapString("ShreadData = " + getSharedData().sharedMsg, 20, 40);
}

string TemplateState::getName(){
    return "template";
}
