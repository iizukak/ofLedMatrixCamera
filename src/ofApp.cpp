#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    screenShotOnce = true;
    
    camWidth = 320;  // try to grab at this size.
    camHeight = 240;

    // LED マトリクスライブラリを初期化
    led.setup();

    // ledPixels.resize(64, 32, OF_INTERPOLATE_NEAREST_NEIGHBOR);
    ledPixels.allocate(64, 32, OF_IMAGE_COLOR);
    ledImage.allocate(64, 32, OF_IMAGE_COLOR);
    
    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - available";
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);

    // vidGrabber.setup(camWidth, camHeight);

    ofSetVerticalSync(true);
    
    // WebCam のセットアップを待つ
    ofSleepMillis(20000);
}

//--------------------------------------------------------------
void ofApp::update(){
    // ofBackground(100, 100, 100);
    ofBackground(0);
    vidGrabber.update();
    if(vidGrabber.isFrameNew()){
	// ofLog(OF_LOG_NOTICE, "IIZUKAK: NEW FRAME");
        pixels = vidGrabber.getPixels();
	pixels.resizeTo(ledPixels, OF_INTERPOLATE_NEAREST_NEIGHBOR);
	ledImage.setFromPixels(ledPixels);
    }

    ofSleepMillis(100);
}

//--------------------------------------------------------------
void ofApp::draw(){
    /*
    for (int i = 0; i < 64; i++){
        for (int j = 0; j < 64; j++) {
            ofSetColor(pixels.getColor(i * 10, j * 10));
            ofDrawCircle(i * 10 + 5, j * 10 + 5, 4);
        }
    }
    */

    // テスト用に初回だけスクリーンショットを取得する
    if (screenShotOnce) {
	// WebCam のテスト用画像を生成
	ofLog(OF_LOG_NOTICE, "IIZUKAK: CAMERA IMAGE SAVE");
	cameraImage.setFromPixels(pixels);
        cameraImage.save("cameraimage.png");

	ofLog(OF_LOG_NOTICE, "IIZUKAK: LED IMAGE SAVE");
        ledImage.save("ledimage.png");

	ofLog(OF_LOG_NOTICE, "IIZUKAK: SCREEN SHOT TAKE");
        screenImage.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        screenImage.save("screenshot.png");
        screenShotOnce = false;

	ofLog(OF_LOG_NOTICE, "IIZUKAK: w:%f, h:%f", ledImage.getWidth(), ledImage.getHeight());
    	// led.draw(ledImage);
    }

    led.draw(ledImage);
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
