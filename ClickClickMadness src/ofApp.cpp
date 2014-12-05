#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    lt = Light(ofVec3f(-50, 0, 10), 1.0,  ofColor(255, 255, 255) );
    c = new Cube(ofVec3f(ofGetWidth()/4, ofGetHeight()/4, -50), ofVec3f(230, 230, 230), ofColor(0, 0, 255), lt);
	d = new Dodecahedron(ofVec3f(3 * ofGetWidth()/4.0, 3 * ofGetHeight()/4.0, -50), ofVec3f(230, 230, 230), ofColor(255, 0, 0), lt);
	t = new TrianglePyramid(ofVec3f(3 * ofGetWidth()/4.0, ofGetHeight()/4.0, -50), ofVec3f(230, 230, 230), ofColor(255, 0, 0), lt);
	s = new SquarePyramid(ofVec3f(ofGetWidth()/4.0, 3 * ofGetHeight()/4.0, -50), ofVec3f(230, 230, 230), ofColor(0, 255, 0), lt);
	cel = new Celery(ofVec3f(ofGetWidth()/2, ofGetHeight()/2, -50), ofVec3f(230, 230, 230), ofColor(0, 255, 255), lt);
	dia = new Diamond(ofVec3f(ofGetWidth()/4, ofGetHeight()/2, -50), ofVec3f(230, 230, 230), ofColor(255, 255, 0), lt);
	st = new Star(ofVec3f(3 * ofGetWidth()/4, ofGetHeight()/2, -50), ofVec3f(230, 230, 230), ofColor(255, 0, 255), lt);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
    c->display(Base3D::SOLID);
	
	d->display(Base3D::SOLID);
	
	t->display(Base3D::SOLID);
	
	s->display(Base3D::SOLID);
	
	cel->display(Base3D::SOLID);
	
	dia->display(Base3D::SOLID);
	
	st->display(Base3D::SOLID);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		input.open("/Developer/Applications/of_v0.8.3_osx_release/apps/myApps/ClickClickMadness/bin/data/input.txt");
		while (input.is_open() && input.good()) {
			f = input.get();
			if (f == '!') {
				std::cout << "cube" << std::endl;
			} else if (f == '@') {
				std::cout << "dodecahedron" << std::endl;	
			} else if (f == '#') {
				std::cout << "triangular pyramid" << std::endl;	
			} else if (f == '$') {
				std::cout << "square pyramid" << std::endl;	
			} else if (f == '%') {
				std::cout << "celery" << std::endl;	
			} else if (f == '^') {
				std::cout << "diamond" << std::endl;	
			} else if (f == '&') {
				std::cout << "star" << std::endl;	
			}
		}
		input.close();
	}

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
