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
    ofBackground(0,0,0);
    
    //ポート番号3333で、TUIOの通信開始
    tuio.start(3333);
    //ログのテキストを空に
    log="";
    //画像ファイルを読み込み
    myImage.loadImage("images/photo.png");
}

void testApp::update(){
    //TUIOのメッセージを受信
    tuio.getMessage();
}

void testApp::draw(){
    //オブジェクトのリストを取得
    list<ofxTuioObject*> objectList = tuio.getTuioObjects();

    //リスト操作のためのイテレータを準備
    list<ofxTuioObject*>::iterator it;
    //全てのオブジェクトをイテレータで操作
    for (it=objectList.begin(); it != objectList.end(); it++) {
        //物体を取得
        ofxTuioObject *blob = (*it);
        //座標を記録
        glPushMatrix();
        //座標を移動
        glTranslatef(blob->getX()*ofGetWidth(), blob->getY()*ofGetHeight(), 0.0);
        //ID番号を表示
        ofDrawBitmapString("id = " + ofToString(blob->getFiducialId(), 0), -64, 80);
        //回転
        glRotatef(blob->getAngleDegrees(), 0.0, 0.0, 1.0);
        ofSetColor(255, 255, 255);
        //画像を描画
        myImage.draw(-64, -64);
        //座標を復帰
        glPopMatrix();
    }
    
    //ログを表示
    ofSetColor(0xffffff);
    ofDrawBitmapString(log, 20, 20);
}

void testApp::objectAdded(ofxTuioObject & tuioObject){
    //マーカー追加
    log = " new object: " + ofToString(tuioObject.getFiducialId())+
    " X: "+ofToString(tuioObject.getX())+
    " Y: "+ofToString(tuioObject.getY())+
    " angle: "+ofToString(tuioObject.getAngleDegrees());
}
void testApp::objectRemoved(ofxTuioObject & tuioObject){
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