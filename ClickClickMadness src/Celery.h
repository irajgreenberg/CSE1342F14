//
//  Celery.h
//  3D_example
//
//  Created by Kaitlyn on 12/3/14.
//
//

#ifndef ___D_example__Celery__
#define ___D_example__Celery__

#include <stdio.h>
#include "Base3D.h"

class Celery : public Base3D {
    
public:
    Celery();
    Celery (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    static int celeryCount;
    
private:
	char getType() const;
    void _init();
    
};


#endif /* defined(___D_example__Celery__) */

