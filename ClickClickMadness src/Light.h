//
//  Light.h
//  threeD_example
//
//  Created by Ira on 11/13/14.
//
//

#ifndef __threeD_example__Light__
#define __threeD_example__Light__

#include <stdio.h>
#include "ofMain.h"

class Light{
public:
    
    ofVec3f pos;
    float intensity;
    ofColor col;
    
    Light();
    
    Light(const ofVec3f& pos, float intensity, const ofColor& col);
    
    
};

#endif /* defined(__threeD_example__Light__) */
