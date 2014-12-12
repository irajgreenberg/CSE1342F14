//
//  Diamond.cpp
//  Cube
//
//  Created by Eric  Smith on 12/4/14.
//
//

#include "Diamond.h"

int Diamond::diamondCount = 0;

Diamond::Diamond(){
}

Diamond::Diamond (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
Base3D(loc, sz, col, lt) {
    _init();
}

void Diamond::_init(){
	
	vecs.push_back(ofVec3f(0, -1.2, 0));
	vecs.push_back(ofVec3f(-.6, 0, .6));
	vecs.push_back(ofVec3f(.6, 0, .6));
	vecs.push_back(ofVec3f(1.2, 0, 0));
	vecs.push_back(ofVec3f(.6, 0, -.6));
	vecs.push_back(ofVec3f(-.6, 0, -.6));
	vecs.push_back(ofVec3f(-1.2, 0, 0));
	vecs.push_back(ofVec3f(0, 1.2, 0));
	
	indices.push_back(Index<int>(0, 1, 2));
	indices.push_back(Index<int>(0, 2, 3));
	indices.push_back(Index<int>(0, 3, 4));
	indices.push_back(Index<int>(0, 4, 5));
	indices.push_back(Index<int>(0, 5, 6));
	indices.push_back(Index<int>(0, 6, 1));
	
	indices.push_back(Index<int>(1, 7, 2));
	indices.push_back(Index<int>(2, 7, 3));
	indices.push_back(Index<int>(3, 7, 4));
	indices.push_back(Index<int>(4, 7, 5));
	indices.push_back(Index<int>(5, 7, 6));
	indices.push_back(Index<int>(6, 7, 1));
	
	
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
	
	setScale(ofVec3f(55.0, 55.0, 55.0));
    
}

char Diamond::getType() const {
	return 'd';
}
