#pragma once

#include "ofMain.h"
#include "baseScene.h"

#define WIDTH 200
#define HEIGHT 200
#define NUM_PARTICLES WIDTH * HEIGHT

class SceneB : public baseScene {
	
	void setup();
	void update();
	void draw();
	
	ofEasyCam cam; // カメラ
	ofVbo myVbo; // VBO
	ofVec3f myVerts[NUM_PARTICLES]; // 頂点の座標
	ofFloatColor myColor[NUM_PARTICLES]; // 頂点の色情報	
};
