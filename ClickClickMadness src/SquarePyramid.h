#include <stdio.h>
#include "Base3D.h"

class Pyramid : public Base3D {
    
public:
    Pyramid();
    Pyramid (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    
private:
    void _init();
    
};
