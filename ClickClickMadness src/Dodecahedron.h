/*
 *  Dodecahedron.h
 *  threeD_example
 *
 *  Created by Brittni Watkins on 11/20/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __Watkins_Dodecahedron__
#define __Watkins_Dodecahedron__


#include "ofMain.h"
#include <iostream>
#include "Base3D.h"

class Dodecahedron: public Base3D {
	
private:
	void _init();
	char getType() const;
	
public:
	Dodecahedron();
	Dodecahedron(const ofVec3f& loc, const ofVec3f& size, const ofColor& color, const Light& lt);
	static int dodecCount;
};


#endif
