#include "testApp.h"

void testApp::setup(){
    //TUIOに関連するイベントリスナーの追加
    ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
    
    //フレームレート設定
    ofSetFrameRate(60);
    //背景を黒に
    ofBackground(0);
    
    //ポート番号3333で、TUIOの通信開始
    tuio.start(3333);
    
    //ログのテキストを空に
    log="";
}

void testApp::update(){
    //TUIOのメッセージを受信
    tuio.getMessage();
}

void testApp::draw(){
    //カーソルの状態を表示
    //tuio.drawCursors();
    //オブジェクトの状態を表示
    tuio.drawObjects();
    //ログを表示
    ofSetColor(255);
    ofDrawBitmapString(log, 20, 20);
}

//TUIOに関するイベントが発生した時に、ログを出力

void testApp::objectAdded(ofxTuioObject & tuioObject){
    // マーカー追加
    log = " new object: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void testApp::objectRemoved(ofxTuioObject & tuioObject){
    // マーカー削除
    log = " object removed: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void testApp::objectUpdated(ofxTuioObject & tuioObject){
    // マーカーの状態更新
    log = " object updated: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void testApp::tuioAdded(ofxTuioCursor & tuioCursor){
    // カーソル追加
    log = " new cursor: " + ofToString(tuioCursor.getFingerId())+
    " X: "+ofToString(tuioCursor.getX())+
    " Y: "+ofToString(tuioCursor.getY());
}
void testApp::tuioRemoved(ofxTuioCursor & tuioCursor){
    // カーソル削除
    log =  " cursor removed: " + ofToString(tuioCursor.getFingerId())+
    " X: "+ofToString(tuioCursor.getX())+
    " Y: "+ofToString(tuioCursor.getY());
}
void testApp::tuioUpdated(ofxTuioCursor & tuioCursor){
    // カーソル状態更新
    log =  " cursor updated: " + ofToString(tuioCursor.getFingerId())+
    " X: "+ofToString(tuioCursor.getX())+
    " Y: "+ofToString(tuioCursor.getY());
}