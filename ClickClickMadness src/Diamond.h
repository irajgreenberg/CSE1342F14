//
//  Diamond.h
//  Cube
//
//  Created by Eric  Smith on 12/4/14.
//
//

#ifndef __Cube__Diamond__
#define __Cube__Diamond__

#include <stdio.h>

#include "Base3D.h"

class Diamond : public Base3D {
    
public:
    Diamond();
    Diamond(const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    
private:
    void _init();
    
};


#endif /* defined(__Cube__Diamond__) */
