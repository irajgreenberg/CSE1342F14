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
START_SCREEN(0), GAME_SCREEN(1), INST_SCREEN(2), END_SCREEN(3), WIN_SCREEN(4) {
	_init();
}

ClickClickEngine::~ClickClickEngine() {
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < columns; i++) {
			delete shapes[i][j];
		}
	}
	delete startCube;
}

void ClickClickEngine::_init() {
	ofSetVerticalSync(true);
    lt = Light(ofVec3f(0, -20, 50), 1.0,  ofColor(255, 255, 255));
	timeFont.loadFont("verdana.ttf", 30);
	titleFont.loadFont("orange juice 2.0.ttf",48);
	instFont.loadFont("orange juice 2.0.ttf",34);
	gameOverFont.loadFont("youmurderer.ttf", 100);
	restartFont.loadFont("youmurderer.ttf", 50);
	mediumFont.loadFont("True Lies.ttf",30);
	arrow.loadImage("back.png");
	instShape.loadImage("shapes.png");
	startCube = new Cube(ofVec3f(ofGetWidth()/2,ofGetHeight()/2), ofVec3f(230, 230, 230), ofColor(249,249,249), lt);
	screen = START_SCREEN;
	rows = 4;
	columns = 6;
	score = 0;
	level = 0;
	shapeType = 'c';
	readTimes = 0;
	EASY = true;
	MEDIUM = false;
	HARD = false;
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
	} else if (screen == WIN_SCREEN) {
		drawWinScreen();
	}
	drawCursor();
}

void ClickClickEngine::drawStartScreen() {
	if(EASY == true) {
		ofBackground(91,163,255);
		ofSetHexColor(0x2980b9);
		ofNoFill();
		ofRect(233,505,107,53);
	}
	if(MEDIUM == true) {
		ofBackgroundHex(0x2ecc71);
		ofSetHexColor(0x27ae60);
		ofNoFill();
		ofRect(492,505,150,53);
	}
	if(HARD == true) {
		ofBackgroundHex(0xe74c3c);
		ofSetHexColor(0xc0392b);
		ofNoFill();
		ofRect(833,505,109,53);
	}
	ofSetColor(240,240,240);
	titleFont.drawString("Welcome to Click Click Madness!",ofGetWidth()/10,ofGetHeight()/4);
	timeFont.drawString("Instructions",ofGetWidth()/10,ofGetHeight()/2);
	timeFont.drawString("Play Now",7.6*ofGetWidth()/10,ofGetHeight()/2);
	timeFont.drawString("Easy",2*ofGetWidth()/10,2.9*ofGetHeight()/4);
	mediumFont.drawString("Medium",4.2*ofGetWidth()/10,2.9*ofGetHeight()/4);
	restartFont.drawString("Hard",7*ofGetWidth()/10,2.9*ofGetHeight()/4);
	timeFont.drawString("Created by: CSE 1342 Fall 2014",2.1*ofGetWidth()/10,3.5*ofGetHeight()/4);
	startCube->display(Base3D::SOLID);
}


void ClickClickEngine::drawGameScreen() {
	ofBackground(39, 40, 34);
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < columns; i++) {
			shapes[i][j]->display(Base3D::SOLID);
		}
	}
	displayTime();
	displayScore();
	displayInstructions(shapeType);
	if(timeLeft <= 0) {
		screen = END_SCREEN;
	}
}

void ClickClickEngine::displayInstructions(char shape) {
	std::string doThis = "Click the ";
	ofSetColor(255);
	if (shapeType == 'c') {
		doThis = doThis + "cubes!";
	} else if (shapeType == 'd') {
		doThis = doThis + "diamonds!";
	}  else if (shapeType == 't') {
		doThis = doThis + "triangle-base pyramids!";
	}  else if (shapeType == 's') {
		doThis = doThis + "square-base pyramids!";
	}  else if (shapeType == 'o') {
		doThis = doThis + "dodecahedrons!";
	}  else if (shapeType == 'a') {
		doThis = doThis + "stars!";
	}  else if (shapeType == 'e') {
		doThis = doThis + "celeries!";
	}
	timeFont.drawString(doThis, ofGetWidth()/2 - timeFont.stringWidth(doThis)/2, timeFont.stringHeight(doThis) * 1.5);
}

void ClickClickEngine::drawInstScreen() {
	ofBackgroundHex(0xd35400);
	ofSetColor(255,255,255,255);
	arrow.draw(10, 15);
	instShape.draw(ofGetWidth()/4, 180);
	ofSetHexColor(0xf9f9f9);
	instFont.drawString("1. Select a difficulty.",ofGetWidth()/3.5,ofGetHeight()/6);
	instFont.drawString("2. You have 30 seconds to click all the instances \n              of your shape.",ofGetWidth()/10 - 30,5*ofGetHeight()/6);
}

void ClickClickEngine::drawEndScreen() {	
	ofBackground(0);
	ofSetColor(169, 11, 11);
	gameOverFont.drawString("GAME OVER!",.6*ofGetWidth()/2,ofGetHeight()/2);
	restartFont.drawString("Press SPACEBAR to restart",.5*ofGetWidth()/2,1.2*ofGetHeight()/2);
}

void ClickClickEngine::startGame() {
	if (screen == START_SCREEN) {
		playStart = clock();
		screen = GAME_SCREEN;
	}
}

void ClickClickEngine::readFile() {
	if (readTimes == 0) {
		rawPath = __FILE__;
		path = std::string(rawPath, 0, rawPath.length() - 24);
		filePath = path + "bin/data/";
		if (EASY && !(MEDIUM) && !(HARD)) {
			filePath = filePath + "easy.txt";
		} else if (!(EASY) && MEDIUM && !(HARD)) {
			filePath = filePath + "medium.txt";
		} else if (!(EASY) && !(MEDIUM) && HARD) {
			filePath = filePath + "hard.txt";
		}
		input.open(filePath.c_str());
		if (input.is_open() && input.good()) {
			for (int j = 0; j < rows; j++) {
				for (int i = 0; i < columns; i++) {
					f = input.get();
					if (f == '!') {
						symbols[i][j] = f;
					} else if (f == '@') {
						symbols[i][j] = f;
					} else if (f == '#') {
						symbols[i][j] = f;
					} else if (f == '$') {
						symbols[i][j] = f;
					} else if (f == '%') {
						symbols[i][j] = f;
					} else if (f == '^') {
						symbols[i][j] = f;
					} else if (f == '&') {
						symbols[i][j] = f;
					}
				}
			}
		}
		input.close();
		int w = ofGetWidth();
		int h = ofGetHeight();
		for (int j = 0; j < rows; j++) {
			for (int i = 0; i < columns; i++) {
				shapeColor = setShapeColor();
				if (symbols[i][j] == '!') {
					shapes[i][j] = new Cube(ofVec3f(w/6 + (i * w/6) - 60, h/4 + (j * h/4) - 75, -50),
											ofVec3f(230, 230, 230), ofColor(shapeColor), lt);
					Cube::cubeCount ++;
				} else if (symbols[i][j] == '@') {
					shapes[i][j] = new Dodecahedron(ofVec3f(w/6 + (i * w/6) - 60, h/4 + (j * h/4) - 75, -50),
													ofVec3f(230, 230, 230), ofColor(shapeColor), lt);
					Dodecahedron::dodecCount ++;
				} else if (symbols[i][j] == '#') {
					shapes[i][j] = new TrianglePyramid(ofVec3f(w/6 + (i * w/6) - 60, h/4 + (j * h/4) - 75, -50),
													   ofVec3f(230, 230, 230), ofColor(shapeColor), lt);
					TrianglePyramid::triPyrCount ++;
				} else if (symbols[i][j] == '$') {
					shapes[i][j] = new SquarePyramid(ofVec3f(w/6 + (i * w/6) - 60, h/4 + (j * h/4) - 75, -50),
													 ofVec3f(230, 230, 230), ofColor(shapeColor), lt);
					SquarePyramid::sqrPyrCount ++; 
				} else if (symbols[i][j] == '%') {
					shapes[i][j] = new Celery(ofVec3f(w/6 + (i * w/6) - 60, h/4 + (j * h/4) - 75, -50),
											  ofVec3f(230, 230, 230), ofColor(shapeColor), lt);
					Celery::celeryCount ++;
				} else if (symbols[i][j] == '^') {
					shapes[i][j] = new Diamond(ofVec3f(w/6 + (i * w/6) - 60, h/4 + (j * h/4) - 75, -50),
											   ofVec3f(230, 230, 230), ofColor(shapeColor), lt);
					Diamond::diamondCount ++;
				} else if (symbols[i][j] == '&') {
					shapes[i][j] = new Star(ofVec3f(w/6 + (i * w/6) - 60, h/4 + (j * h/4) - 75, -50),
											ofVec3f(230, 230, 230), ofColor(shapeColor), lt);
					Star::starCount ++;
				}
			}
		}
		readTimes ++;
	}
}

ofColor ClickClickEngine::setShapeColor() {
	int num = ofRandom(100);
	ofColor tempCol;
	if (num % 10 == 0) {
		tempCol = ofColor(166, 226, 45);
	} else if (num % 10 == 1) {
		tempCol = ofColor(241, 39, 114);
	} else if (num % 10 == 2) {
		tempCol = ofColor(230, 219, 116);
	} else if (num % 10 == 3) {
		tempCol = ofColor(80, 196, 239);
	} else if (num % 10 == 4) {
		tempCol = ofColor(155, 89, 182);
	} else if (num % 10 == 5) {
		tempCol = ofColor(211, 84, 0);
	} else if (num % 10 == 6) {
		tempCol = ofColor(236, 240, 241);
	} else if (num % 10 == 7) {
		tempCol = ofColor(127, 140, 141);
	} else if (num % 10 == 8) {
		tempCol = ofColor(22, 160, 133);
	} else if (num % 10 == 9) {
		tempCol = ofColor(169, 39, 38);
	}
	return tempCol;
}

void ClickClickEngine::convertTime() {
	stringstream convert;
	convert << timeLeft;
	timeLeftString = convert.str();
}

void ClickClickEngine::convertScore() {
	stringstream convert;
	convert << score;
	scoreString = convert.str();	
}

void ClickClickEngine::displayTime() {
	playTime = (clock() - playStart) /(double) CLOCKS_PER_SEC;
	if (EASY && !(MEDIUM) && !(HARD)) {
		timeLeft = 10 - playTime;
	} else if (!(EASY) && MEDIUM && !(HARD)) {
		timeLeft = 15 - playTime;
	} else if (!(EASY) && !(MEDIUM) && HARD) {
		timeLeft = 20 - playTime;
	}
	convertTime();
	ofSetColor(255);
	timeFont.drawString(timeLeftString, timeFont.stringWidth(timeLeftString)/2, timeFont.stringHeight(timeLeftString) * 1.5);
}

void ClickClickEngine::displayScore() {
	convertScore();
	ofSetColor(255);
	timeFont.drawString(scoreString, timeFont.stringWidth(scoreString)/2 + 5, ofGetHeight()/2 - timeFont.stringHeight(scoreString) * 1.5);
}


void ClickClickEngine::clickingShapes() {
	if (screen == GAME_SCREEN) {
		for (int j = 0; j < rows; j++) {
			for (int i = 0; i < columns; i++) {
				if (mouseX <= shapes[i][j]->loc.x + 50 && mouseX >= shapes[i][j]->loc.x - 50) {
					if (mouseY <= shapes[i][j]->loc.y + 50 && mouseY >= shapes[i][j]->loc.y - 50) {
						if (shapeType == shapes[i][j]->getType() && shapes[i][j]->getInteract()) {
							shapes[i][j]->setInteract(false);
							score ++;
							if (shapes[i][j]->getType() == 'c') {
								Cube::cubeCount --;
							} else if (shapes[i][j]->getType() == 'd') {
								Diamond::diamondCount --;
							}  else if (shapes[i][j]->getType() == 't') {
								TrianglePyramid::triPyrCount --;
							}  else if (shapes[i][j]->getType() == 's') {
								SquarePyramid::sqrPyrCount --;
							}  else if (shapes[i][j]->getType() == 'o') {
								Dodecahedron::dodecCount --;
							}  else if (shapes[i][j]->getType() == 'a') {
								Star::starCount --;
							}  else if (shapes[i][j]->getType() == 'e') {
								Celery::celeryCount --;
							}
						} else if (shapeType != shapes[i][j]->getType() && shapes[i][j]->getInteract()) {
							score --;
						}
					}
				}
			}
		}
		if (EASY && !(MEDIUM) && !(HARD)) {
			if (Diamond::diamondCount <= 0) {
				screen = WIN_SCREEN;
			} else if (TrianglePyramid::triPyrCount <= 0) {
				shapeType = 'd';
			} else if (Cube::cubeCount <= 0) {
				shapeType = 't';
			}
		} else if (!(EASY) && MEDIUM && !(HARD)) {
			if (Star::starCount <= 0) {
				screen = WIN_SCREEN;
			} else if (Dodecahedron::dodecCount <= 0) {
				shapeType = 'a';
			} else if (Diamond::diamondCount <= 0) {
				shapeType = 'o';
			} else if (TrianglePyramid::triPyrCount <= 0) {
				shapeType = 'd';
			} else if (Cube::cubeCount <= 0) {
				shapeType = 't';
			}
		} else if (!(EASY) && !(MEDIUM) && HARD) {
			if (SquarePyramid::sqrPyrCount <= 0) {
				screen = WIN_SCREEN;
			} else if (Celery::celeryCount <= 0) {
				shapeType = 's';
			} else if (Star::starCount <= 0) {
				shapeType = 'e';
			} else if (Dodecahedron::dodecCount <= 0) {
				shapeType = 'a';
			} else if (Diamond::diamondCount <= 0) {
				shapeType = 'o';
			} else if (TrianglePyramid::triPyrCount <= 0) {
				shapeType = 'd';
			} else if (Cube::cubeCount <= 0) {
				shapeType = 't';
			}
		}
	}
}

void ClickClickEngine::clickBoxes() {
	if(screen == GAME_SCREEN) {
		clickingShapes();
	} else if(screen == INST_SCREEN) {
		if(mouseX >= 10 && mouseX <= 145 && mouseY >= 15 && mouseY <= 68) {
			screen = START_SCREEN;
		}
	} else if(screen == START_SCREEN) {
		if (mouseX >= 233 && mouseX <= 341 && mouseY >= 505 && mouseY <= 558) {
			EASY = true;
			MEDIUM = false;
			HARD = false;
		} else if (mouseX >= 492 && mouseX <= 642 && mouseY >= 505 && mouseY < 558) {
			EASY = false;
			MEDIUM = true;
			HARD = false;
		} else if (mouseX >= 833 && mouseX <= 942 && mouseY >= 505 && mouseY <= 558) {
			EASY = false;
			MEDIUM = false;
			HARD = true;
		} else if (mouseX >= 112 && mouseX <= 362 && mouseY >= 336 && mouseY <= 389) {
			screen = INST_SCREEN;
		} else if ( mouseX >= 906 && mouseX <= 1113 && mouseY >= 336 && mouseY <= 389) {
			readFile();
			startGame();
		}
	}
}

void ClickClickEngine::restartGame() {
	if (screen == END_SCREEN || screen == WIN_SCREEN) {
		for (int j = 0; j < rows; j++) {
			for (int i = 0; i < columns; i++) {
				delete shapes[i][j];
			}
		}
		shapeType = 'c';
		readTimes = 0;
		score = 0;
		EASY = true;
		MEDIUM = false;
		HARD = false;
		screen = START_SCREEN;
	}
}

void ClickClickEngine::drawCursor() {
	ofRectMode(OF_RECTMODE_CENTER);
	ofSetColor(240, 240, 240);
	ofFill();
	ofRect(mouseX, mouseY, 5, 5);
}

void ClickClickEngine::drawWinScreen() {
	ofBackground(39, 40, 34);
	titleFont.drawString("You Win!", 470,ofGetHeight()/4);
	startCube->display(Base3D::SOLID);
}