#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//画面基本設定
	ofSetFrameRate(60);
	
	//シーンを新規の生成し、配列に追加
	baseScene * sa = new SceneA();
	scenes.push_back(sa);	
	
	//現在のシーンを0に
	currentScene = 0;
	scenes[currentScene]->setup();	
	
}

//--------------------------------------------------------------
void testApp::update(){

	scenes[currentScene]->update();
}


//--------------------------------------------------------------
void testApp::draw(){

	scenes[currentScene]->draw();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	//シーンの切り替え
	currentScene++;
	currentScene %= scenes.size();
	scenes[currentScene]->setup();
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
