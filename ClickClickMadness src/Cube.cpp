//
//  Cube.cpp
//  3D_example
//
//  Created by Ira on 11/6/14.
//
//

#include "Cube.h"

int Cube::cubeCount = 0;

Cube::Cube(){
}

Cube::Cube (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
Base3D(loc, sz, col, lt) {
    _init();
}

void Cube::_init(){
    vecs.push_back(ofVec3f(-.5, -.5, .5));
    vecs.push_back(ofVec3f(.5, -.5, .5));
    vecs.push_back(ofVec3f(.5, -.5, -.5));
    vecs.push_back(ofVec3f(-.5, -.5, -.5));
    vecs.push_back(ofVec3f(-.5, .5, .5));
    vecs.push_back(ofVec3f(.5, .5, .5));
    vecs.push_back(ofVec3f(.5, .5, -.5));
    vecs.push_back(ofVec3f(-.5, .5, -.5));
    
    indices.push_back(Index<int>(0, 1, 3));
    indices.push_back(Index<int>(1, 2, 3));
    indices.push_back(Index<int>(4, 7, 5));
    indices.push_back(Index<int>(5, 7, 6));
    indices.push_back(Index<int>(1, 5, 6));
    indices.push_back(Index<int>(1, 6, 2));
    indices.push_back(Index<int>(0, 7, 4));
    indices.push_back(Index<int>(0, 3, 7));
    indices.push_back(Index<int>(0, 4, 5));
    indices.push_back(Index<int>(0, 5, 1));
    indices.push_back(Index<int>(2, 6, 3));
    indices.push_back(Index<int>(3, 6, 7));
    
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
	
	setScale(ofVec3f(75.0, 75.0, 75.0));
    
}

char Cube::getType() const {
	return 'c';
}

