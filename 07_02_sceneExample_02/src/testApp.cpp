#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	
	//シーンを新規の生成し、配列に追加
	baseScene * sa = new SceneA();
	scenes.push_back(sa);
	
	baseScene * sb = new SceneB();
	scenes.push_back(sb);
	
	baseScene * sc = new SceneC();
	scenes.push_back(sc);	
	
	//現在のシーンを0に
	currentScene = 0;
	scenes[currentScene]->setup();
}

//--------------------------------------------------------------
void testApp::update(){
	
	//現在表示しているシーンを更新
	scenes[currentScene]->update();
}


//--------------------------------------------------------------
void testApp::draw(){
	
	//現在表示しているシーンを描画
	scenes[currentScene]->draw();
	
	//メッセージ表示
	ofSetHexColor(0xFFFFFF);
	ofDrawBitmapString("Press [SPACE] : Change scene", 20, 20);
	ofDrawBitmapString("Press [f] : Toggle fullscreen", 20, 40);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key) {
		case ' ':

			//シーンの切り替え
			currentScene++;
			currentScene %= scenes.size();
			scenes[currentScene]->setup();
			break;
			
		case 'f':
			ofToggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	scenes[currentScene]->keyReleased(key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	scenes[currentScene]->mouseMoved(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	scenes[currentScene]->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	scenes[currentScene]->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	scenes[currentScene]->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	scenes[currentScene]->windowResized(w, h);
}
