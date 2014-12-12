#include "Star.h"

int Star::starCount = 0;

Star::Star(){
}

Star::Star (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
Base3D(loc, sz, col, lt){
    _init();
} 

void Star::_init(){
    vecs.push_back(ofVec3f(-.5, -.5, .5));//0
    vecs.push_back(ofVec3f(.5, -.5, .5));//1
    vecs.push_back(ofVec3f(.5, -.5, -.5));//2
    vecs.push_back(ofVec3f(-.5, -.5, -.5));//3
    vecs.push_back(ofVec3f(-.5, .5, .5));//4
    vecs.push_back(ofVec3f(.5, .5, .5));//5
    vecs.push_back(ofVec3f(.5, .5, -.5));//6
    vecs.push_back(ofVec3f(-.5, .5, -.5));//7
	vecs.push_back(ofVec3f(0, 0, 2));//front 8
	vecs.push_back(ofVec3f(-2, 0, 0));//left 9
	vecs.push_back(ofVec3f(0, 0, -2));//back 10
	vecs.push_back(ofVec3f(2, 0, 0));//right 11
	vecs.push_back(ofVec3f(0, -2, 0));//top triangle 12
	vecs.push_back(ofVec3f(0, 2, 0));//bottom triangle 13
	
	
    
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
	
	indices.push_back(Index<int>(12,0,1));
	indices.push_back(Index<int>(12,1,2));
	indices.push_back(Index<int>(12,2,3));
	indices.push_back(Index<int>(12,3,0));
	
	indices.push_back(Index<int>(11,1,5));
	indices.push_back(Index<int>(11,2,1));
	indices.push_back(Index<int>(11,6,2));
	indices.push_back(Index<int>(11,5,6));
	
	indices.push_back(Index<int>(9,4,0));
	indices.push_back(Index<int>(9,0,3));
	indices.push_back(Index<int>(9,3,7));
	indices.push_back(Index<int>(9,7,4));
	
	indices.push_back(Index<int>(13,5,4));
	indices.push_back(Index<int>(13,6,5));
	indices.push_back(Index<int>(13,7,6));
	indices.push_back(Index<int>(13,4,7));
	
	indices.push_back(Index<int>(10,6,7));
	indices.push_back(Index<int>(10,7,3));
	indices.push_back(Index<int>(10,2,6));
	indices.push_back(Index<int>(10,3,2));
	
	indices.push_back(Index<int>(8,0,4));
	indices.push_back(Index<int>(8,4,5));
	indices.push_back(Index<int>(8,5,1));
	indices.push_back(Index<int>(8,1,0));
    
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
	
	setScale(ofVec3f(40.0, 40.0, 40.0));
    
}


char Star::getType() const {
	return 'a';
}
