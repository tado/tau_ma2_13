#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "vectorField.h"
#include "ofxGui.h"

class testApp : public ofSimpleApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased (int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	vector <Particle> particles;
	vectorField VF;
	
	float prevMouseX;
	float prevMouseY;
    
    // GUI
    ofxPanel gui;
    ofxFloatSlider friction;
    ofxFloatSlider radius;
    ofxColorSlider color;
    ofxButton resetButton;
    ofxButton clearButton;
    ofxButton randomVF;
    
    // GUIイベントリスナー
    void frictionChanged(float & friction);
    void radiusChanged(float & radius);
    void resetButtonPressed();
    void clearButtonPressed();
    void randomButtonPressed();
};
