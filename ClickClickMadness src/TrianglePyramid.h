//
//  TrianglePyramid.h
//  3D_example
//
//  Created by Kaitlyn on 12/3/14.
//
//

#ifndef ___D_example__TrianglePyramid__
#define ___D_example__TrianglePyramid__

#include <stdio.h>
#include "Base3D.h"

class TrianglePyramid : public Base3D {
    
public:
    TrianglePyramid();
    TrianglePyramid (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    
private:
    void _init();
    
};
#endif /* defined(___D_example__TrianglePyramid__) */
