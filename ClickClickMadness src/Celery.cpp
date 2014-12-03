//
//  Celery.cpp
//  3D_example
//
//  Created by Kaitlyn on 12/3/14.
//
//

#include "Celery.h"


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
    indices.push_back(Index<int>(0, 2, 1 ));
    indices.push_back(Index<int>(0, 3, 2 ));
    indices.push_back(Index<int>(0, 4, 3 ));
    indices.push_back(Index<int>(0, 5, 4));
    indices.push_back(Index<int>(0, 6, 5));
    indices.push_back(Index<int>(0, 7, 6));
    indices.push_back(Index<int>(0, 8, 7));
    indices.push_back(Index<int>(0, 1, 8));
    
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
    indices.push_back(Index<int>(13, 12, 4));
    indices.push_back(Index<int>(12, 11, 3));
    indices.push_back(Index<int>(11, 10, 2));
    indices.push_back(Index<int>(10, 9, 1));
    indices.push_back(Index<int>(9, 16, 8));
    indices.push_back(Index<int>(16, 15, 7));
    indices.push_back(Index<int>(15, 14, 6));
    indices.push_back(Index<int>(14, 13, 5));
    
    //sides with two top one bottom
    indices.push_back(Index<int>(4, 5, 13));
    indices.push_back(Index<int>(3, 4, 12));
    indices.push_back(Index<int>(2, 3, 11));
    indices.push_back(Index<int>(1, 2, 10));
    indices.push_back(Index<int>(8, 1, 9));
    indices.push_back(Index<int>(7, 8, 16));
    indices.push_back(Index<int>(6, 7, 15));
    indices.push_back(Index<int>(5, 6, 14));

    
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
    
}
























