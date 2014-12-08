//
//  Light.cpp
//  threeD_example
//
//  Created by Ira on 11/13/14.
//
//

#include "Light.h"


Light::Light(){
}

Light::Light(const ofVec3f& pos, float intensity, const ofColor& col):
pos(pos), intensity(intensity), col(col) {
}


