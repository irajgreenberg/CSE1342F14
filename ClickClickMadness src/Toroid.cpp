//
//  Toroid.cpp
//  Base3D
//
//  Created by Eric Smith on 12/7/14.
//
//

#include "Toroid.h"


Toroid::Toroid(){
}

Toroid::Toroid (const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
Base3D(loc, sz, col, lt){
    _init();
}

void Toroid::_init(){
    float x=0;
    float y=0;
    float z=0;
    float phi = 0;
    int toroidDetail = 36;
    int ringDetail = 12;
    
    
    for(int i=0;i<toroidDetail;i++){
        float theta = 0;
        
        for(int j=0;j<ringDetail;j++){
            x = (toroidDetail + ringDetail*cos(theta))*cos(phi);
            y = ringDetail*sin(theta);
            z = (toroidDetail + ringDetail*cos(theta))*sin(phi);
            vecs.push_back(ofVec3f(x,y,z));
            theta += TWO_PI/ringDetail;
        }
        phi += TWO_PI/toroidDetail;
    }
    
    for(int i=0;i<toroidDetail;i++){
        for(int j=0;j<ringDetail;j++){
            int i0 = i*ringDetail + j;
            int i1 = (i+1)*ringDetail + j;
            int i2 = i*ringDetail + (j+1);
            int i3 = (i+1)*ringDetail + (j+1);
            int i4 = j;
            int i5 = i*ringDetail;
            int i7 = (i+1) * ringDetail;
            int i8 = j + 1;
            
            if(i < toroidDetail-1){
                if(j<ringDetail-1){
                    indices.push_back(Index<int>(i0,i2,i3));
                    indices.push_back(Index<int>(i0,i3,i1));
                }
                
                else{
                    indices.push_back(Index<int>(i0,i5,i7));
                    indices.push_back(Index<int>(i0,i7,i1));
                }
            }
            
            else{
                if(j<ringDetail-1){
                    indices.push_back(Index<int>(i0,i2,i8));
                    indices.push_back(Index<int>(i0,i8,i4));
                }
                
                else{
                    indices.push_back(Index<int>(i0,i5,0));
                    indices.push_back(Index<int>(i0,0,i4));
                }
            }
            
        }
    }
    
    
    for (int i=0; i<indices.size(); ++i){
        // to do
        //cout << indices[i].elem0 << ", " << indices[i].elem1 << ", " << indices[i].elem2 << endl;
        faces.push_back( Face(&vecs[indices[i].elem0], &vecs[indices[i].elem1], &vecs[indices[i].elem2]) );
    }
	
	setScale(ofVec3f(1.5, 1.5, 1.5));
    
}
