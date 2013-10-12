#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    box2d.init(); // Box2Dの世界の初期化
    box2d.setGravity(0, 3.0); // 重力を設定
    box2d.createBounds(); // 地面を生成
    box2d.setFPS(15.0); // Box2Dの世界でのFPS
    box2d.registerGrabbing(); // 物体に接触可能に
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update(); // Box2Dの更新
}

//--------------------------------------------------------------
void testApp::draw(){
    // バネを描く
    for(int i=0; i<joints.size(); i++) {
        ofNoFill();
        ofSetHexColor(0x666666);
        joints[i].draw();
    }
    
    // rectsを描く
    for(int i=0; i<rects.size(); i++) {
        ofFill();
        ofSetHexColor(0x3366ff);
        rects[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    // r キーで四角を追加
    if (key == 'r') {
        // 四角を追加
        ofxBox2dRect rect;
        rect.setPhysics(1.0, 0.5, 0.1);
        
        // Box2dの世界に生成した円を追加
        rect.setup(box2d.getWorld(), mouseX, mouseY, 4, 4);
        rects.push_back(rect);
        
        // 動的配列に追加
        // パーティクル同士をばねで結ぶ
        if (rects.size() > 1) {
            for (int i = 0; i < rects.size()-1; i++) {
                ofxBox2dJoint j;
                j.setup(box2d.getWorld(), rects[rects.size()-1].body, rects[i].body);
                j.setFrequency(0.4);
                j.setDamping(0.1);
                j.setLength(200);
                joints.push_back(j);
            }
        }
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
    // マウスをドラッグすると、最初に配置した四角をつかむ
    rects[0].setPosition(x, y);
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
