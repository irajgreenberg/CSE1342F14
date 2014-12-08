/*
 *  ClickClickEngine.cpp
 *  ClickClickMadness
 *
 *  Created by Brittni Watkins on 12/7/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "ClickClickEngine.h"

ClickClickEngine::ClickClickEngine():
START_SCREEN(0), GAME_SCREEN(1), INST_SCREEN(2), END_SCREEN(3),
rawPath(__FILE__), path(rawPath, 0, rawPath.length() - 24), filePath(path + "bin/data/input.txt") {
	_init();
}

ClickClickEngine::~ClickClickEngine() {
	delete c;
	delete d;
	delete t;
	delete s;
	delete dia;
	delete st;
	delete cel;
	delete tor;
}

void ClickClickEngine::_init() {
	ofSetVerticalSync(true);
    lt = Light(ofVec3f(0, -20, 50), 1.0,  ofColor(255, 255, 255));
	timeFont.loadFont("verdana.ttf", 30);
	screen = START_SCREEN;
}

void ClickClickEngine::drawScreen() {
	if (screen == START_SCREEN) {
		drawStartScreen();
	} else if (screen == GAME_SCREEN) {
		drawGameScreen();
	} else if (screen == INST_SCREEN) {
		drawInstScreen();
	} else if (screen == END_SCREEN) {
		drawEndScreen();
	}
}

void ClickClickEngine::drawStartScreen() {
	ofBackground(255, 0, 0);
}


void ClickClickEngine::drawGameScreen() {
	ofBackground(39, 40, 34);
	c->display(Base3D::SOLID);
	
	d->display(Base3D::SOLID);
	
	t->display(Base3D::SOLID);
	
	s->display(Base3D::SOLID);
	
	cel->display(Base3D::SOLID);
	
	dia->display(Base3D::SOLID);
	
	st->display(Base3D::SOLID);
	
	//tor->display(Base3D::SOLID);
	
	displayTime();
	
	if(timeLeft <= 0) {
		screen = END_SCREEN;
	}
}

void ClickClickEngine::drawInstScreen() {
	ofBackground(0, 255, 0);
}

void ClickClickEngine::drawEndScreen() {
	ofBackground(0, 0, 255);
}

void ClickClickEngine::startGame() {
	if (screen == START_SCREEN) {
		readFile();
		playStart = clock();
		screen = GAME_SCREEN;
	}
}

void ClickClickEngine::readFile() {
	input.open(filePath.c_str());
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
	c = new Cube(ofVec3f(ofGetWidth()/4, ofGetHeight()/4, -50), ofVec3f(230, 230, 230), ofColor(0, 0, 255), lt);
	d = new Dodecahedron(ofVec3f(3 * ofGetWidth()/4.0, 3 * ofGetHeight()/4.0, -50), ofVec3f(230, 230, 230), ofColor(255, 0, 0), lt);
	t = new TrianglePyramid(ofVec3f(3 * ofGetWidth()/4.0, ofGetHeight()/4.0, -50), ofVec3f(230, 230, 230), ofColor(255, 0, 0), lt);
	s = new SquarePyramid(ofVec3f(ofGetWidth()/4.0, 3 * ofGetHeight()/4.0, -50), ofVec3f(230, 230, 230), ofColor(0, 255, 0), lt);
	cel = new Celery(ofVec3f(ofGetWidth()/2, ofGetHeight()/2, -50), ofVec3f(230, 230, 230), ofColor(0, 255, 255), lt);
	dia = new Diamond(ofVec3f(ofGetWidth()/4, ofGetHeight()/2, -50), ofVec3f(230, 230, 230), ofColor(255, 255, 0), lt);
	st = new Star(ofVec3f(3 * ofGetWidth()/4, ofGetHeight()/2, -50), ofVec3f(230, 230, 230), ofColor(255, 0, 255), lt);
	tor = new Toroid(ofVec3f(ofGetWidth()/2, ofGetHeight()/4, -50), ofVec3f(230, 230, 230), ofColor(255), lt);
}

void ClickClickEngine::convertTime() {
	stringstream convert;
	convert << timeLeft;
	timeLeftString = convert.str();
}

void ClickClickEngine::displayTime() {
	playTime = (clock() - playStart) /(double) CLOCKS_PER_SEC;
	timeLeft = 31 - playTime;
	convertTime();
	ofSetColor(255);
	timeFont.drawString(timeLeftString, timeFont.stringWidth(timeLeftString)/2, timeFont.stringHeight(timeLeftString) * 1.5);
}