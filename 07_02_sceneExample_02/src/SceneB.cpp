#include "SceneB.h"

void SceneB::setup(){
	// 画面設定
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	cam.setDistance(100);
	
	// 頂点情報を初期化
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			myVerts[j * WIDTH + i].set(i - WIDTH/2, j - HEIGHT/2, 0);
			myColor[j * WIDTH + i].set(0.6, 0.8, 1.0, 1.0);
		}
	}
	
	// 頂点バッファに位置と色の情報を設定
	myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

void SceneB::update(){
	
	// 頂点の座標を更新
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			float x = sin(i * 0.1 + ofGetElapsedTimef()) * 10.0;
			float y = sin(j * 0.15 + ofGetElapsedTimef()) * 10.0;
			float z = x + y;
			myVerts[j * WIDTH + i] = ofVec3f(i - WIDTH/2, j - HEIGHT/2, z);
		}
	}
	
	// 頂点バッファの頂点の座標情報を更新
	myVbo.updateVertexData(myVerts, NUM_PARTICLES);
}

void SceneB::draw(){
	ofBackgroundHex(0x000000);
	
	// VBOの頂点を描画
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	cam.begin();
	glPointSize(2);
	myVbo.draw(GL_POINTS, 0, NUM_PARTICLES);
	cam.end();
	ofPopMatrix();
}