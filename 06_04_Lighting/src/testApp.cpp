#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofEnableDepthTest(); // 深度テストを有効に
    ofEnableSmoothing(); // 表示をスムースに
    
    // ライティングを有効に
    light.enable();
	// スポットライトを配置
	light.setSpotlight();
	// 照明の位置
	light.setPosition(-100, 100, 100);
	// 環境反射光の色
	light.setAmbientColor(ofFloatColor(0.5, 0.2, 0.2, 1.0));
	// 拡散反射光の色
	light.setDiffuseColor(ofFloatColor(0.5, 0.5, 1.0));
	// 鏡面反射光の色
	light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    cam.begin(); // カメラ開始
    
    ofSetColor(255);
    
    // 立方体
    box.set(200); // サイズ設定
    box.setPosition(-150, 0, 0); // 位置
    box.draw(); // 塗りつぶしで描画
    
    // 球
    sphere.set(100, 16); // 半径と面の細かさ
    sphere.setPosition(150, 0, 0); // 位置
    sphere.draw(); // 塗りつぶしで描画
    
    cam.end(); // カメラ終了
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}