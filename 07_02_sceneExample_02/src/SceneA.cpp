#include "SceneA.h"

void SceneA::setup(){
	ofBackgroundHex(0x000000);
	cam.setDistance(600);
	glEnable(GL_DEPTH_TEST);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	light.enable();
	
	rot = 0.0f;
}

void SceneA::update(){
	rot += 0.3f;
}

void SceneA::draw(){
	ofPushStyle();
	glPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

	cam.begin();
	
	ofSetHexColor(0x3399cc);
	ofRotateX(rot * 1.2);
	ofRotateY(rot);
	ofBox(0, 0, 0, 200);
	
	cam.end();

	glPopMatrix();
	ofPopStyle();
}