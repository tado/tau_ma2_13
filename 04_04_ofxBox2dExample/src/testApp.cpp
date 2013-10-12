#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    
    box2d.init(); // Box2Dの世界の初期化
    box2d.setGravity(0, 10); // 重力を下向きに10
    box2d.setFPS(30.0); // Box2Dの世界でのFPS
    box2d.registerGrabbing(); // 物体に接触可能に
    
    polyLine.setPhysics(0.0, 0.5, 0.5);
    polyLine.create(box2d.getWorld());
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update(); // Box2Dの更新
}

//--------------------------------------------------------------
void testApp::draw(){
    // 円を描く
    ofFill();
    for(int i=0; i<circles.size(); i++) {
        ofSetHexColor(0x3366ff);
        circles[i].draw();
    }
    
    // 四角形を描く
    for(int i=0; i<rects.size(); i++) {
        ofSetHexColor(0xff6633);
        rects[i].draw();
    }
    
    // 多角形(描画した線分)を描く
    ofNoFill();
    ofSetHexColor(0xffffff);
    if(drawing.size()==0) {
        polyLine.draw();
    }	else {
        drawing.draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    // [c]キーを押すと、ofxBox2DCircleを追加
    if(key == 'c') {
        float r = ofRandom(4, 20); //半径をランダムに
        ofxBox2dCircle circle; //円
        circle.setPhysics(3.0, 0.53, 0.1); //物理法則を追加
        // Box2dの世界に生成した円を追加
        circle.setup(box2d.getWorld(), mouseX, mouseY, r);
        circles.push_back(circle); // 動的配列に追加
    }
    // [r]キーを押すと、ofxBox2DRectを追加
    if(key == 'r') {
        float w = ofRandom(4, 20); // 幅をランダムに
        float h = ofRandom(4, 20); // 高さをランダムに
        ofxBox2dRect rect; // 四角形
        rect.setPhysics(3.0, 0.53, 0.1); // 物理法則を追加
        // Box2dの世界に生成した四角形を追加
        rect.setup(box2d.getWorld(), mouseX, mouseY, w, h);
        rects.push_back(rect); // 動的配列に追加
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    drawing.addVertex(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    // もしも既に多角形が存在していたら、消去する
    if(polyLine.isBody()) {
        drawing.clear();
        polyLine.destroy();
    }
    // 描画中の線分に辺を追加
    drawing.addVertex(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    // 描画していた多角形を確定
    //drawing.setClosed(false);
    drawing.simplify();
    
    // ofxBox2dPlyLineとして生成
    polyLine.addVertexes(drawing);
    polyLine.simplify();
    polyLine.setPhysics(0.0, 0.5, 0.5);
    polyLine.create(box2d.getWorld());
    drawing.clear();
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
