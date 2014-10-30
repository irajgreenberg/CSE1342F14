#include "VerletOrg.h"
using namespace CSE1342;

VerletOrg::VerletOrg():
stickNum(1), ballNum(2) {
	_init();
}

VerletOrg::VerletOrg(int stickNum, int ballNum):
stickNum(stickNum), ballNum(ballNum) {
	_init();	
}

VerletOrg::VerletOrg(const VerletOrg& v) {
	this->stickNum = v.stickNum;
	this->ballNum = v.ballNum;
	sticks = new VerletStick[stickNum];
	balls = new VerletBall[ballNum];
	for (int i = 0; i < stickNum; i++) {
		sticks[i] = v.sticks[i];
	}
	for (int i = 0; i < ballNum; i++) {
		balls[i] = v.balls[i];
	}
}

VerletOrg::~VerletOrg() {
	delete [] sticks;
	delete [] balls;
}

VerletOrg& VerletOrg::operator=(const VerletOrg& v) {
	if (this != &v) {
		this->stickNum = v.stickNum;
		this->ballNum = v.ballNum;
		delete [] sticks;
		delete [] balls;
		sticks = new VerletStick[stickNum];
		balls = new VerletBall[ballNum];
		for (int i = 0; i < stickNum; i++) {
			sticks[i] = v.sticks[i];
		}
		for (int i = 0; i < ballNum; i++) {
			balls[i] = v.balls[i];
		}
	}
	return *this;
}

void VerletOrg::_init() {
	sticks = new VerletStick[stickNum];
	balls = new VerletBall[ballNum];
}

void VerletOrg::move() {
	for (int i = 0; i < stickNum; i++) {
		sticks[i].constrain();
		sticks[i].verlet();
	}
}

void VerletOrg::display() {
	ofSetColor(stickColor);
	for (int i = 0; i < stickNum; i++) {
		sticks[i].displayStick();
	}
	ofSetColor(ballColor);
	for (int i = 0; i < stickNum; i++) {
		sticks[i].displayBalls();
	}
}

void VerletOrg::push() {
	for (int i = 0; i < stickNum; i++) {
		(*sticks[i].b1).push(ofVec2f(sticks[i].pushX, sticks[i].pushY));
	}
}