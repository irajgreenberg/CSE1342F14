#include "Pyramid.h"


Pyramid::Pyramid(){
}

Pyramid::Pyramid (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
Base3D(loc, sz, col, lt){
    _init();
}

void Pyramid::_init(){
    vecs.push_back(ofVec3f(-1, -1, -1));   
    vecs.push_back(ofVec3f(-1, -1, 1));		
    vecs.push_back(ofVec3f(1, -1, 1));		
	vecs.push_back(ofVec3f(1,-1, -1));		
    vecs.push_back(ofVec3f(0, 1, 0));		
	
    
    indices.push_back(Index<int>(1, 4, 2));
    indices.push_back(Index<int>(2, 0, 1));
    indices.push_back(Index<int>(2, 3, 0));
	indices.push_back(Index<int>(0, 4, 1)); 
	indices.push_back(Index<int>(3, 2, 4));
	indices.push_back(Index<int>(0, 3, 4));

	
    
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
    
}
