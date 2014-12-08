/*
 *  Face.h
 *  ClickClickMadness
 *
 *  Created by Brittni Watkins on 12/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

//
//  Face.h
//  3D_example
//
//  Created by Ira on 11/6/14.
//
//

#ifndef ___D_example__Face__
#define ___D_example__Face__

#include <stdio.h>
#include "ofMain.h"

class Face {
    
public:
    
    Face();
    Face(ofVec3f* v0, ofVec3f* v1, ofVec3f* v2);
    
    ofVec3f getNormal();
    ofVec3f getCentroid();
    
    ofVec3f getV0() const;
    ofVec3f getV1() const;
    ofVec3f getV2() const;
    
private:
    ofVec3f* v0;
    ofVec3f* v1;
    ofVec3f* v2;
    
    
};

#endif /* defined(___D_example__Face__) */