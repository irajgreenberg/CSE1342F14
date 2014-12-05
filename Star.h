
#include <stdio.h>
#include "Base3D.h"

class Star : public Base3D {
    
public:
    Star();
    Star(const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    
private:
    void _init();
    
};
