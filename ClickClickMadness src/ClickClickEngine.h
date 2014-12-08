/*
 *  ClickClickEngine.h
 *  ClickClickMadness
 *
 *  Created by Brittni Watkins on 12/7/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ClickClickMadness__ClickClickEngine__
#define __ClickClickMadness__ClickClickEngine__

#include "ofMain.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "Cube.h"
#include "Dodecahedron.h"
#include "TrianglePyramid.h"
#include "SquarePyramid.h"
#include "Celery.h"
#include "Diamond.h"
#include "Star.h"
#include "Toroid.h"
#include "Light.h"


class ClickClickEngine {
private:
	const int START_SCREEN;
	const int GAME_SCREEN;
	const int END_SCREEN;
	const int INST_SCREEN;
	
	ofTrueTypeFont timeFont;
	
	Base3D* c, * d, * t, * s, * dia, * st, * cel, * tor;
    Light lt;
	ifstream input;
	char f;
	
	int screen;
	int timeLeft;
	string timeLeftString;
	
	clock_t wholeStart, playStart;
	double playTime;
	
	std::string rawPath;
	std::string path;
	std::string filePath;
	
	void _init();
	
	void drawStartScreen();
	void drawGameScreen();
	void drawInstScreen();
	void drawEndScreen();
	void readFile();
	void convertTime();
	void displayTime();
	
public:
	ClickClickEngine();
	~ClickClickEngine();
	void drawScreen();
	void startGame();

};
#endif