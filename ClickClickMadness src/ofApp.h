#pragma once

#include "ofMain.h"
#include "Cube.h"
#include "Dodecahedron.h"
#include "TrianglePyramid.h"
#include "SquarePyramid.h"
#include "Light.h"

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
    
    Cube* c;
	Dodecahedron* d;
	TrianglePyramid* t;
	SquarePyramid* s;
    Light lt;
	
};