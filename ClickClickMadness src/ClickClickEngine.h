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

	int level;
	
	int mouseX;
	int mouseY;
	
	bool EASY, MEDIUM, HARD;
	ofImage arrow, instShape;
	
	char shapeType;
	
	ofTrueTypeFont timeFont, gameOverFont, restartFont;
	ofTrueTypeFont titleFont, instFont, mediumFont;
	
	char symbols[6][4];
	Base3D* shapes[6][4], * startCube;
	
	int columns;
	int rows;

    Light lt;
	ifstream input;
	char f;
	
	int screen;
	int timeLeft;
	string timeLeftString;
	
	int score;
	std::string scoreString;
	
	clock_t wholeStart, playStart;
	double playTime;
	
	int readTimes;
	
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
	void convertScore();
	void displayScore();
	void displayInstructions(char shape);
	void drawCursor();
	
public:
	ClickClickEngine();
	~ClickClickEngine();
	void drawScreen();
	void startGame();
	void restartGame();
	void setMousePosition(int newMx,int newMy);
	void clickingShapes();
	void clickBoxes();

};

inline void ClickClickEngine::setMousePosition(int newMx, int newMy) {
	mouseX = newMx;
	mouseY = newMy;	
}

#endif