//
//  Toroid.h
//  Base3D
//
//  Created by Eric Smith on 12/7/14.
//
//

#ifndef __Base3D__Toroid__
#define __Base3D__Toroid__

#include <stdio.h>
#include "Base3D.h"

class Toroid : public Base3D {
    
public:
    Toroid();
    Toroid (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    
private:
    void _init();
    
};

#endif /* defined(__Base3D__Toroid__) */