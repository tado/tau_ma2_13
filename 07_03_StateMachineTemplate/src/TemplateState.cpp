#include "TemplateState.h"

void TemplateState::setup(){
}

void TemplateState::update(){
}

void TemplateState::draw(){
    ofBackground(64);
    ofSetColor(255);
    ofDrawBitmapString("Template State", 20, 20);
}

string TemplateState::getName(){
    return "template";
}
