#include "VerletStick.h"

using namespace CSE1342;

VerletStick::VerletStick() {
}

VerletStick::VerletStick(VerletBall* b1, VerletBall* b2, float tension):
b1(b1), b2(b2), tension(tension), pushX(1), pushY(2) {
	length = dist(*b1, *b2);
}

VerletStick::VerletStick(VerletBall* b1, VerletBall* b2, float tension, float pushX, float pushY):
b1(b1), b2(b2), tension(tension), pushX(pushX), pushY(pushY) {
	length = dist(*b1, *b2);
}


void VerletStick::constrain() {
	ofVec2f delta = (*b1) - (*b2);
	float deltaLength = delta.length();
	float difference = ((deltaLength - length) / deltaLength);
	(*b1).pos += delta * (0.5 * tension * difference);
	(*b2).pos -= delta * (0.5 * tension * difference);
	if ((*b1).pos.y >= ofGetHeight() - (*b1).radius) { 
		(*b1).push(ofVec2f(0, -pushY));
	}
	if ((*b1).pos.y <= (*b1).radius) { 
		(*b1).push(ofVec2f(0, pushY));
	}
	if ((*b1).pos.x >= ofGetWidth() - (*b1).radius) { 
		(*b1).push(ofVec2f(-pushX, 0));
	}
	if ((*b1).pos.x <= (*b1).radius) { 
		(*b1).push(ofVec2f(pushX, 0));
	}
	if ((*b2).pos.y >= ofGetHeight() - (*b2).radius) { 
		(*b2).push(ofVec2f(0, -pushY));
	}
	if ((*b2).pos.y <= (*b2).radius) { 
		(*b2).push(ofVec2f(0, pushY));
	}
	if ((*b2).pos.x >= ofGetWidth() - (*b2).radius) { 
		(*b2).push(ofVec2f(-pushX, 0));
	}
	if ((*b2).pos.x <= (*b2).radius) { 
		(*b2).push(ofVec2f(pushX, 0));
	}
	
}

void VerletStick::displayStick() {
	ofLine((*b1).pos.x, (*b1).pos.y, (*b2).pos.x, (*b2).pos.y);
}

void VerletStick::displayBalls() {
	(*b1).display();
	(*b2).display();
}

void VerletStick::verlet() {
	(*b1).verlet();
	(*b2).verlet();
}
