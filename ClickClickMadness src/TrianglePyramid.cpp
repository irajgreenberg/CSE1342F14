//
//  TrianglePyramid.cpp
//  3D_example
//
//  Created by Kaitlyn on 12/3/14.
//
//

#include "TrianglePyramid.h"

int TrianglePyramid::triPyrCount = 0;


TrianglePyramid::TrianglePyramid(){
}

TrianglePyramid::TrianglePyramid (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
Base3D(loc, sz, col, lt){
    _init();
}

void TrianglePyramid::_init(){
    
    
    //0
    vecs.push_back(ofVec3f( 0, 1, 0));
    //1
    vecs.push_back(ofVec3f( -.5, 0, -.4));
    //2
    vecs.push_back(ofVec3f( .5, 0, -.4));
    //3
    vecs.push_back(ofVec3f( 0, 0, .6));
    
    //zero
    indices.push_back(Index<int>(0, 1, 2));
    //first
    indices.push_back(Index<int>(1, 3, 2));
    //second
    indices.push_back(Index<int>(0, 2, 3));
    //third
    indices.push_back(Index<int>(1, 0, 3));
    
    
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
    
	setScale(ofVec3f(100.0, 100.0, 100.0));
}

char TrianglePyramid::getType() const {
	return 't';
}
