#pragma once

#include "ofMain.h"
#include "baseScene.h"

class SceneA : public baseScene {
	
	void setup();
	void update();
	void draw();
	
	ofEasyCam cam;
	ofLight light;
	float rot;
};
