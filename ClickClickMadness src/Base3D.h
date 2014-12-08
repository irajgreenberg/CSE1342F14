//
//  Base3D.h
//  3D_example
//
//  Created by Ira on 11/6/14.
//
//

#ifndef ___D_example__Base3D__
#define ___D_example__Base3D__

#include <stdio.h>
#include "ofMain.h"
#include "Face.h"
#include "Light.h"
#include "Index.h"

class Base3D {
    
public:
    
    
    enum RenderStyle {
        WIRE,
        SOLID
    };
	
    
    Base3D();
    Base3D(const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt);
    
    void rotate(float angle, float xAxis, float yAxis, float zAxis);
    void display(RenderStyle style = SOLID);
    void displayNormals(float m, const ofColor& col);
    
	//protected:
    std::vector<ofVec3f> vecs;
    std::vector<Face> faces;
    std::vector< Index<int> > indices;
    
    Light lt;
	
	void setScale(const ofVec3f& newScale);
    
private:
    ofVec3f loc;
    ofVec3f sz;
    ofColor col;
    
    virtual void _init() = 0;
    void _sort();
	
	float scaleX, scaleY, scaleZ;
    
    
};

#endif /* defined(___D_example__Base3D__) */
