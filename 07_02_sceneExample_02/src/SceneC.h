#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "Particle.h"

class SceneC : public baseScene {
	
	void setup();
	void update();
	void draw();
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	
    vector <Particle> particles;
	ofImage img;
};
