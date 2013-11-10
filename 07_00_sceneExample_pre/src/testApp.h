#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "SceneA.h"

class testApp : public ofBaseApp {
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	//複数のシーンを格納する動的配列
	vector <baseScene *> scenes;
	//現在のシーン番号
	int currentScene;
};
