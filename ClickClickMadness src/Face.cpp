//
//  Face.cpp
//  3D_example
//
//  Created by Ira on 11/6/14.
//
//

#include "Face.h"


Face::Face(){
    
}

Face::Face(ofVec3f* v0, ofVec3f* v1, ofVec3f* v2):
v0(v0), v1(v1), v2(v2){
    
}

ofVec3f Face::getCentroid(){
    ofVec3f c(*v0);
    c += *v1;
    c += *v2;
    return c/3;
}

    
    ofVec3f Face::getNormal(){
    ofVec3f _v0(*v0);
    ofVec3f _v1(*v1);
    ofVec3f _v2(*v2);
    _v1 -= _v0;
    _v2 -= _v0;
    
    ofVec3f n;
    n.x = _v2.y * _v1.z - _v2.z * _v1.y;
    n.y = _v2.z * _v1.x - _v2.x * _v1.z;
    n.z = _v2.x * _v1.y - _v2.y * _v1.x;
    
    return n/n.length();
}

ofVec3f Face::getV0() const{
    return *v0;
}

ofVec3f Face::getV1() const{
    return *v1;
}

ofVec3f Face::getV2() const{
    return *v2;
}
