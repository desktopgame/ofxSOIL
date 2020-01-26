#include "ofApp.h"
#include "ofxSOIL.h"

//--------------------------------------------------------------
void ofApp::setup(){
	this->status = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (this->status == 10) {
		ofxSOIL::saveScreenshot("ss.bmp", ofxSOIL::TYPE_BMP, 0, 0, ofGetWidth(), ofGetHeight());
		this->status = 11;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	int w = ofGetWidth();
	int h = ofGetHeight();
	ofSetColor(ofColor::red);
	ofDrawRectangle(0, 0, 100, 100);

	ofSetColor(ofColor::green);
	ofDrawRectangle(w-100, h-100, 100, 100);
	if (this->status < 10) {
		this->status++;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
