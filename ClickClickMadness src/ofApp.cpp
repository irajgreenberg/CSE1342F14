#include "ofApp.h"

int counter = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    lt = Light(ofVec3f(-50, 0, 10), 1.0,  ofColor(255, 255, 255) );
    c = new Cube(ofVec3f(0, 0, 0), ofVec3f(230, 230, 230), ofColor(0, 0, 255), lt);
	d = new Dodecahedron(ofVec3f(0, 0, 0), ofVec3f(230, 230, 230), ofColor(255, 131, 29), lt);
	t = new TrianglePyramid(ofVec3f(0, 0, 0), ofVec3f(230, 230, 230), ofColor(255, 0, 0), lt);
	s = new SquarePyramid(ofVec3f(0, 0, 0), ofVec3f(230, 230, 230), ofColor(0, 255, 0), lt);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushMatrix();
    ofTranslate(ofGetWidth()/4.0, ofGetHeight()/4.0, -50);
    ofScale(50.0, 50.0, 50.0);
	c->rotate(1.5, 0.5, 0.5, 0.0);
    c->display(Base3D::SOLID);
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(3 * ofGetWidth()/4.0, 3 * ofGetHeight()/4.0, -50);
	ofScale(50.0, 50.0, 50.0);
	d->rotate(1.5, 0.5, 0.5, 0.0);
    d->display(Base3D::SOLID);
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(3 * ofGetWidth()/4.0, ofGetHeight()/4.0, -50);
	ofScale(50.0, 50.0, 50.0);
	t->rotate(1.5, 0.5, 0.5, 0.0);
    t->display(Base3D::SOLID);
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/4.0, 3 * ofGetHeight()/4.0, -50);
	ofScale(50.0, 50.0, 50.0);
	s->rotate(1.5, 0.5, 0.5, 0.0);
    s->display(Base3D::SOLID);
	ofPopMatrix();
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
