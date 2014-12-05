#pragma once

#include "ofMain.h"
#include "Cube.h"
#include "Dodecahedron.h"
#include "TrianglePyramid.h"
#include "SquarePyramid.h"
#include "Celery.h"
#include "Diamond.h"
#include "Star.h"
#include "Light.h"
#include <fstream>

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
    Base3D* c, * d, * t, * s, * dia, * st, * cel;
    Light lt;
	ifstream input;
	char f;
	
};