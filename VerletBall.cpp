#include "VerletBall.h"

using namespace CSE1342;

namespace CSE1342 {
	ofVec2f operator-(const VerletBall& b1, const VerletBall& b2) {
		return b2.pos - b1.pos;	
	}
	
	float dist(const VerletBall& vb1, const VerletBall vb2) {
		float l = sqrt(((vb2.pos.x - vb1.pos.x)*(vb2.pos.x - vb1.pos.x)) + ((vb2.pos.y - vb1.pos.y)*(vb2.pos.y - vb1.pos.y)));
		return l;
	}
	
	ofVec2f absVal(const VerletBall& b1, const VerletBall& b2) {
		ofVec2f vec = b2 - b1;
		vec.x = vec.x<-1 ? vec.x*=-1 : vec.x;
		vec.y = vec.y<-1 ? vec.y*=-1 : vec.y;
		return vec;
	}
}

VerletBall::VerletBall():
radius(1.0), pos(ofVec2f(0, 0)) {
	posOld = this -> pos;
}


VerletBall::VerletBall(float radius, const ofVec2f& pos):
radius(radius), pos(pos) {
	posOld = this -> pos;
}

void VerletBall::display() {
	ofSetCircleResolution(100);
	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	ofCircle(0, 0, radius);
	ofPopMatrix();
}

void VerletBall::verlet() {
	ofVec2f posTemp = pos;
	pos += (pos - posOld);
	posOld = posTemp;
}

void VerletBall::push(const ofVec2f& v){
	pos += v;
}

float VerletBall::dist(const VerletBall& vb) {
	float l = sqrt(((vb.pos.x - pos.x)*(vb.pos.x - pos.x)) + ((vb.pos.y - pos.y)*(vb.pos.y - pos.y)));
	return l;	
}

void VerletBall::operator+=(const ofVec2f& v) {
	pos += v;
}

void VerletBall::operator-=(const ofVec2f& v) {
	pos -= v;
}
