#include "testApp.h"

void testApp::setup(){
    //イベントリスナーの追加
    ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
    
    //画面の基本設定
    ofBackground(0,0,0);
    ofSetFrameRate(60);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    //サウンドファイルの読み込み
    for (int i = 0; i < NUM; i++) {
        mySounds[i].loadSound("sounds/rainstick.aif");
        mySounds[i].setLoop(true);
        mySounds[i].setVolume(0);
        mySounds[i].play();
    }
    
    //TUIO通信開始、ポート3333
    tuio.start(3333);
}

void testApp::update(){
    //TUIOメッセージの受信
    tuio.getMessage();
    
    //オブジェクトのリストを取得
    list<ofxTuioObject*> objectList = tuio.getTuioObjects();
    //イテレータの準備
    list<ofxTuioObject*>::iterator it;
    //表示されている物体の数だけくりかえし
    for (it = objectList.begin(); it != objectList.end(); it++) {
        int i = 0;
        //個別の物体を取り出し
        ofxTuioObject *blob = (*it);
        //IDを抽出
        int id = blob->getFiducialId();
        //サウンドが設定されたIDの範囲
        if (id >= 0) {
            //X座標を左右の定位に適用
            mySounds[i].setPan(blob->getX());
            //Y座標を再生スピードの適用
            mySounds[i].setSpeed((1.0f - blob->getY()) * 2.0);
            //角度をサウンドのボリュームに適用
            mySounds[i].setVolume(blob->getAngleDegrees()/360.0);
        }
        i++;
    }
}

void testApp::draw(){
    //オリジナルの図形を描画
    //半径を20に
    float radius = 20;
    //オブジェクトのリストを取得
    list<ofxTuioObject*> objectList = tuio.getTuioObjects();
    //イテレータの準備
    list<ofxTuioObject*>::iterator tobj;
    //表示されている物体の数だけくりかえし
    for (tobj=objectList.begin(); tobj != objectList.end(); tobj++) {
        //個別の物体を取り出し
        ofxTuioObject *blob = (*tobj);
        //オリジナルの物体を描画
        glPushMatrix();
        glTranslatef(blob->getX()*ofGetWidth(), blob->getY()*ofGetHeight(), 0.0);
        glRotatef(blob->getAngleDegrees(), 0.0, 0.0, 1.0);
        ofFill();
        ofSetColor(0, 0, 255, 127);
        //サウンドのレベルによって半径を変化させて青い円を描く
        float* spectrum;
        spectrum = ofSoundGetSpectrum(1);
        ofCircle(0, 0, spectrum[0] * radius * 100.0);
        ofSetColor(255, 255, 255);
        ofNoFill();
        ofCircle(0, 0, radius);
        ofLine(0, -radius, 0, 0);
        glPopMatrix();
    }
    
    //ログを表示
    ofSetColor(0xffffff);
    ofDrawBitmapString(log, 20, 20);
}

void testApp::objectAdded(ofxTuioObject & tuioObject){
    int id = tuioObject.getFiducialId();
    if (id >= 0 && id < NUM) {
        mySounds[tuioObject.getFiducialId()].play();
    }
    //マーカー追加
    log = " new object: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void testApp::objectRemoved(ofxTuioObject & tuioObject){
    int id = tuioObject.getFiducialId();
    if (id >= 0 && id < NUM) {
        mySounds[tuioObject.getFiducialId()].stop();
    }
    //マーカー削除
    log = " object removed: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void testApp::objectUpdated(ofxTuioObject & tuioObject){
    //マーカーの状態更新
    log = " object updated: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void testApp::tuioAdded(ofxTuioCursor & tuioCursor){
    //カーソル追加
    log = " new cursor: " + ofToString(tuioCursor.getFingerId())+
    " X: "+ofToString(tuioCursor.getX())+
    " Y: "+ofToString(tuioCursor.getY());
}
void testApp::tuioRemoved(ofxTuioCursor & tuioCursor){
    //カーソル削除
    log =  " cursor removed: " + ofToString(tuioCursor.getFingerId())+
    " X: "+ofToString(tuioCursor.getX())+
    " Y: "+ofToString(tuioCursor.getY());
}
void testApp::tuioUpdated(ofxTuioCursor & tuioCursor){
    //カーソル状態更新
    log =  " cursor updated: " + ofToString(tuioCursor.getFingerId())+
    " X: "+ofToString(tuioCursor.getX())+
    " Y: "+ofToString(tuioCursor.getY());
}
