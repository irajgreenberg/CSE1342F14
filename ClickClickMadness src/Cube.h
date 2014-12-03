//
//  Cube.h
//  3D_example
//
//  Created by Ira on 11/6/14.
//
//

#ifndef ___D_example__Cube__
#define ___D_example__Cube__

#include <stdio.h>
#include "Base3D.h"

class Cube : public Base3D {
    
public:
    Cube();
    Cube (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    
private:
    void _init();
    
};
#endif /* defined(___D_example__Cube__) */
