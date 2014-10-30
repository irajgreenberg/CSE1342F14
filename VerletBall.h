#ifndef __Verlet_System__VerletBall__
#define __Verlet_System__VerletBall__

#include <iostream>
#include "ofMain.h"

namespace CSE1342 {
	
	class VerletBall {
		
	public:
		friend class VerletStick;
		friend class VerletOrg;
		
		friend ofVec2f operator-(const VerletBall& b1, const VerletBall& b2);
		friend ofVec2f absVal(const VerletBall& b1, const VerletBall& b2);
		friend float dist(const VerletBall& vb1, const VerletBall vb2); 

		VerletBall();
		VerletBall(float radius, const ofVec2f& pos);
		
		void setRadius(float radius);
		float getRadius() const;
		void setPos(const ofVec2f& pos);
		ofVec2f getPos() const;
		
		void display();
		void verlet();
		void push(const ofVec2f& v);
		float dist(const VerletBall& vb);
		void operator+=(const ofVec2f& v);
		void operator-=(const ofVec2f& v);
		
	private:
		float radius;
		ofVec2f pos, posOld;
	};
	
	inline void VerletBall::setRadius(float radius) {
		this -> radius = radius;
	}
	
	inline float VerletBall::getRadius() const {
		return radius;
	}
	
	inline void VerletBall::setPos(const ofVec2f& pos) {
		this -> pos = pos;
	}
	
	inline ofVec2f VerletBall::getPos() const {
		return pos;
	}
}

#endif
