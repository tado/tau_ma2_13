#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
	ofxBox2d box2d;	// Box2Dの世界を構築
	vector <ofxBox2dCircle> circles;	// Circleを格納する動的配列
	vector <ofxBox2dRect> rects;	// Rectを格納する動的配列
	ofPolyline drawing; // 画面に描く線
	ofxBox2dPolygon polyLine; // 描いた線から、多角形の物体を生成
    
};
