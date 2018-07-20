#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 1280;  // try to grab at this size.
    camHeight = 720;
    
    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(camWidth, camHeight);

    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    // ofBackground(100, 100, 100);
    ofBackground(0);
    vidGrabber.update();
    if(vidGrabber.isFrameNew()){
        pixels = vidGrabber.getPixels();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 64; i++){
        for (int j = 0; j < 64; j++) {
            ofSetColor(pixels.getColor(i * 10 + 500, j * 10));
            ofDrawCircle(i * 10 + 5, j * 10 + 5, 4);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
