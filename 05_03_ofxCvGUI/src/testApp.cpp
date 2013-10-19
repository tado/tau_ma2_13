#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
    // CV初期設定
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(200);
    background.setLearningTime(900);
	background.setThresholdValue(20);
    
    // GUI
    resetBackgroundButton.addListener(this, &testApp::resetBackgroundPressed);
    gui.setup();
    gui.add(bgThresh.setup("background thresh", 50, 0, 100));
    gui.add(contourThresh.setup("contour finder thresh", 127, 0, 255));
    gui.add(resetBackgroundButton.setup("reset background"));
}

void testApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        // 背景差分画像を生成
        background.setThresholdValue(bgThresh);
        background.update(cam, thresholded);
		thresholded.update();
        
        // 背景差分画像の輪郭抽出
        contourFinder.setThreshold(contourThresh);
        contourFinder.findContours(thresholded);
    }
}

void testApp::draw() {
    // 差分画像を描画
    ofSetColor(255);
    thresholded.draw(0, 0);
    
    // 輪郭抽出結果を描画
    ofSetColor(255, 0, 0);
    contourFinder.draw();
    
    // GUI
    gui.draw();
}

void testApp::resetBackgroundPressed(){
    background.reset();
}