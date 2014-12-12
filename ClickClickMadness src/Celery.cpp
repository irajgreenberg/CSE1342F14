//
//  Celery.cpp
//  3D_example
//
//  Created by Kaitlyn on 12/3/14.
//
//

#include "Celery.h"

int Celery::celeryCount = 0;

Celery::Celery(){
}

Celery::Celery (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
Base3D(loc, sz, col, lt){
    _init();
}

void Celery::_init(){
    
    //top of donut
    
    vecs.push_back(ofVec3f(0, -.5, 0));
    vecs.push_back(ofVec3f(-.25, -.5, -.75));
    vecs.push_back(ofVec3f(-.75, -.5, -.25));
    vecs.push_back(ofVec3f(-.75, -.5, .25));
    vecs.push_back(ofVec3f(-.25, -.5, .75));
    vecs.push_back(ofVec3f(.25, -.5, .75));
    vecs.push_back(ofVec3f(.75, -.5, .25));
    vecs.push_back(ofVec3f(.75, -.5, -.25));
    vecs.push_back(ofVec3f(.25, -.5, -.75));
    
    //bottom of donut
    
    vecs.push_back(ofVec3f(-.25, .5, -.75));
    vecs.push_back(ofVec3f(-.75, .5, -.25));
    vecs.push_back(ofVec3f(-.75, .5, .25));
    vecs.push_back(ofVec3f(-.25, .5, .75));
    vecs.push_back(ofVec3f(.25, .5, .75));
    vecs.push_back(ofVec3f(.75, .5, .25));
    vecs.push_back(ofVec3f(.75, .5, -.25));
    vecs.push_back(ofVec3f(.25, .5, -.75));
    vecs.push_back(ofVec3f(0, .5, 0));
    
    
    //top
    
    indices.push_back(Index<int>(0, 1, 2 ));
    indices.push_back(Index<int>(0, 2, 3 ));
    indices.push_back(Index<int>(0, 3, 4 ));
    indices.push_back(Index<int>(0, 4, 5));
    indices.push_back(Index<int>(0, 5, 6));
    indices.push_back(Index<int>(0, 6, 7));
    indices.push_back(Index<int>(0, 7, 8));
    indices.push_back(Index<int>(0, 8, 1));
    
    //bottom
    
    indices.push_back(Index<int>(17, 9, 16));
    indices.push_back(Index<int>(17, 16, 15));
    indices.push_back(Index<int>(17, 15, 14));
    indices.push_back(Index<int>(17, 14, 13));
    indices.push_back(Index<int>(17, 13, 12));
    indices.push_back(Index<int>(17, 12, 11));
    indices.push_back(Index<int>(17, 11, 10));
    indices.push_back(Index<int>(17, 10, 9));
    
    
    //sides with two bottom one top
    
    indices.push_back(Index<int>(13, 4, 12));
    indices.push_back(Index<int>(12, 3, 11));
    indices.push_back(Index<int>(11, 2, 10));
    indices.push_back(Index<int>(10, 1, 9));
    indices.push_back(Index<int>(9, 8, 16));
    indices.push_back(Index<int>(16, 7, 15));
    indices.push_back(Index<int>(15, 6, 14));
    indices.push_back(Index<int>(14, 5, 13));
    
    //sides with two top one bottom
    
    indices.push_back(Index<int>(4, 13, 5));
    indices.push_back(Index<int>(3, 12, 4));
    indices.push_back(Index<int>(2, 11, 3));
    indices.push_back(Index<int>(1, 10, 2));
    indices.push_back(Index<int>(8, 9, 1));
    indices.push_back(Index<int>(7, 16, 8));
    indices.push_back(Index<int>(6, 15, 7));
    indices.push_back(Index<int>(5, 14, 6));
	
    
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
	
	setScale(ofVec3f(65.0, 65.0, 65.0));
}

char Celery::getType() const {
	return 'e';
}

