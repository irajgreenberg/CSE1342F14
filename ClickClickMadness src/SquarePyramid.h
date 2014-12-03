#ifndef __ClickClickMadness__SquarePyramid__
#define __ClickClickMadness__SquarePyramid__

#include <stdio.h>
#include "Base3D.h"

class SquarePyramid : public Base3D {
    
public:
    SquarePyramid();
    SquarePyramid (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    
private:
    void _init();
    
};

#endif