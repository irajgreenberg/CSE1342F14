#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	v[0] = CSE1342::VerletOrg(5, 6);
	
	for (int i = 0; i < 2; i++) {
		v[i].position();
		v[i].connect();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < 2; i++) {
		v[i].move();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < 2; i++) {
		v[i].display();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
