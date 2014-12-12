/*
 *  Dodecahedron.cpp
 *  threeD_example
 *
 *  Created by Brittni Watkins on 11/20/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "Dodecahedron.h"

int Dodecahedron::dodecCount = 0;

Dodecahedron::Dodecahedron():
Base3D() {
	
}

Dodecahedron::Dodecahedron(const ofVec3f& loc, const ofVec3f& size, const ofColor& color, const Light& lt):
Base3D(loc, size, color, lt) {
	_init();
}

void Dodecahedron::_init() {
	float gold = (1.00 + sqrt(5.00))/2.00;
	
	vecs.push_back(ofVec3f(1, -1, 1));
	vecs.push_back(ofVec3f(0, -1/gold, gold));
	vecs.push_back(ofVec3f(0, 1/gold, gold));
	vecs.push_back(ofVec3f(1, 1, 1));
	vecs.push_back(ofVec3f(gold, 0, 1/gold));
	vecs.push_back(ofVec3f(1/gold, -gold, 0));
	vecs.push_back(ofVec3f(-1/gold, -gold, 0));
	vecs.push_back(ofVec3f(-1, -1, 1));
	vecs.push_back(ofVec3f(-gold, 0, 1/gold));
	vecs.push_back(ofVec3f(-1, 1, 1));
	vecs.push_back(ofVec3f(-1/gold, gold, 0));
	vecs.push_back(ofVec3f(1/gold, gold, 0));
	vecs.push_back(ofVec3f(1, 1, -1));
	vecs.push_back(ofVec3f(gold, 0, -1/gold));
	vecs.push_back(ofVec3f(1, -1, -1));
	vecs.push_back(ofVec3f(-1, -1, -1));
	vecs.push_back(ofVec3f(0, -1/gold, -gold));
	vecs.push_back(ofVec3f(0, 1/gold, -gold));
	vecs.push_back(ofVec3f(-1, 1, -1));
	vecs.push_back(ofVec3f(-gold, 0, -1/gold));
	
	indices.push_back(Index<int>(0, 1, 2));
	indices.push_back(Index<int>(3, 0, 2));
	indices.push_back(Index<int>(3, 4, 0));
	indices.push_back(Index<int>(0, 5, 6));
	indices.push_back(Index<int>(1, 0, 6));
	indices.push_back(Index<int>(1, 6, 7));
	indices.push_back(Index<int>(8, 1, 7));
	indices.push_back(Index<int>(8, 2, 1));
	indices.push_back(Index<int>(2, 8, 9));
	indices.push_back(Index<int>(2, 9, 10));
	indices.push_back(Index<int>(3, 2, 10));
	indices.push_back(Index<int>(11, 3, 10));
	indices.push_back(Index<int>(11, 12, 3));
	indices.push_back(Index<int>(12, 4, 3));
	indices.push_back(Index<int>(4, 12, 13));
	indices.push_back(Index<int>(14, 4, 13));
	indices.push_back(Index<int>(14, 0, 4));
	indices.push_back(Index<int>(14, 5, 0));
	indices.push_back(Index<int>(14, 16, 5));
	indices.push_back(Index<int>(5, 16, 15));
	indices.push_back(Index<int>(5, 15, 6));
	indices.push_back(Index<int>(6, 15, 7));
	indices.push_back(Index<int>(7, 15, 19));
	indices.push_back(Index<int>(7, 19, 8));
	indices.push_back(Index<int>(8, 19, 9));
	indices.push_back(Index<int>(18, 9, 19));
	indices.push_back(Index<int>(10, 9, 18));
	indices.push_back(Index<int>(10, 18, 11));
	indices.push_back(Index<int>(11, 18, 17));
	indices.push_back(Index<int>(11, 17, 12));
	indices.push_back(Index<int>(12, 17, 13));
	indices.push_back(Index<int>(13, 17, 16));
	indices.push_back(Index<int>(13, 16, 14));
	indices.push_back(Index<int>(16, 17, 18));
	indices.push_back(Index<int>(15, 16, 18));
	indices.push_back(Index<int>(19, 15, 18));
	
	
	for (int i = 0; i < indices.size(); i++) {
		faces.push_back(Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]));
	}
	
	setScale(ofVec3f(35.0, 35.0, 35.0));
	
}

char Dodecahedron::getType() const {
	return 'o';
}