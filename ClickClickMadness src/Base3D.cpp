//
//  Base3D.cpp
//  3D_example
//
//  Created by Ira on 11/6/14.
//
//

#include "Base3D.h"


Base3D::Base3D(){
    
}

Base3D::Base3D(const ofVec3f& loc, const ofVec3f& sz, const ofColor& col, const Light& lt):
loc(loc), sz(sz), col(col), lt(lt) {
    
}


// slow bubble sort:
// http://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
void Base3D::_sort(){
    Face temp;
    for(int i=0; i<faces.size()-1; ++i){
        for(int j=0; j<faces.size()-i-1; ++j){
            if (faces.at(j).getNormal().z > faces.at(j+1).getNormal().z){
                temp = faces.at(j);
                faces.at(j) = faces.at(j+1);
                faces.at(j+1) = temp;
            }
        }
        
    }
}


void Base3D::rotate(float angle, float xAxis, float yAxis, float zAxis) {
    ofVec3f temp;
    float theta = angle*PI/180;
    for(int i=0; i<vecs.size(); ++i){
        // x-axis
        temp.y = vecs.at(i).y*cos(theta*xAxis) - vecs.at(i).z*sin(theta*xAxis);
        temp.z = vecs.at(i).y*sin(theta*xAxis) + vecs.at(i).z*cos(theta*xAxis);
        vecs.at(i).y = temp.y;
        vecs.at(i).z = temp.z;
        
        // y-axis
        temp.z = vecs.at(i).z*cos(theta*yAxis) - vecs.at(i).x*sin(theta*yAxis);
        temp.x = vecs.at(i).z*sin(theta*yAxis) + vecs.at(i).x*cos(theta*yAxis);
        vecs.at(i).z = temp.z;
        vecs.at(i).x = temp.x;
        
        // z-axis
        temp.x = vecs.at(i).x*cos(theta*zAxis) - vecs.at(i).y*sin(theta*zAxis);
        temp.y = vecs.at(i).x*sin(theta*zAxis) + vecs.at(i).y*cos(theta*zAxis);
        vecs.at(i).x = temp.x;
        vecs.at(i).y = temp.y;
    }
}


void Base3D::display(RenderStyle style){
	ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    ofScale(scaleX, scaleY, scaleZ);
	rotate(1.5, 0.5, 0.5, 0.0);
    _sort();
	ofSetLineWidth(1);
    for(int i=0; i<faces.size(); ++i){
        // solid
        if (style == Base3D::SOLID) {
            
            // do light calculations
            ofVec3f A = lt.pos - faces.at(i).getNormal();
            ofVec3f B = faces.at(i).getNormal();
            A.normalize();
            B.normalize();
            float d = B.dot(A);
            
            int r = 0;
            int g = 0;
            int b = 0;
			r = col.r*d + 80;
			g = col.g*d + 80;
			b = col.b*d + 80;
			ofSetColor(r, g, b);
            ofFill();
            ofBeginShape();
            ofVertex(faces.at(i).getV0().x, faces.at(i).getV0().y, faces.at(i).getV0().z);
            ofVertex(faces.at(i).getV1().x, faces.at(i).getV1().y, faces.at(i).getV1().z);
            ofVertex(faces.at(i).getV2().x, faces.at(i).getV2().y, faces.at(i).getV2().z);
            ofEndShape(true);
        } else if (style == Base3D::WIRE) {
            // wireframe
            ofSetColor(ofColor(255, 0, 0));
            ofNoFill();
            ofBeginShape();
            ofVertex(faces.at(i).getV0().x, faces.at(i).getV0().y, faces.at(i).getV0().z);
            ofVertex(faces.at(i).getV1().x, faces.at(i).getV1().y, faces.at(i).getV1().z);
            ofVertex(faces.at(i).getV2().x, faces.at(i).getV2().y, faces.at(i).getV2().z);
            ofEndShape(true);
        }
    }
	ofPopMatrix();
}

void Base3D::displayNormals(float m, const ofColor& col){
	ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    ofScale(50.0, 50.0, 50.0);
	rotate(1.5, 0.5, 0.5, 0.0);
    for(int i=0; i<faces.size(); ++i){
        ofSetColor(ofColor(col));
        ofNoFill();
        ofBeginShape();
        ofVertex(faces.at(i).getCentroid().x, faces.at(i).getCentroid().y, faces.at(i).getCentroid().z);
        ofVertex(faces.at(i).getCentroid().x+faces.at(i).getNormal().x*m,
                 faces.at(i).getCentroid().y+faces.at(i).getNormal().y*m,
                 faces.at(i).getCentroid().z+faces.at(i).getNormal().z*m);
        ofEndShape(true);
    }
	ofPopMatrix();
    
}

void Base3D::setScale(const ofVec3f& newScale) {
	scaleX = newScale.x;
	scaleY = newScale.y;
	scaleZ = newScale.z;
}
