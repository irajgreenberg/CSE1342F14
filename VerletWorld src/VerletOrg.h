#ifndef __Verlet_Organisms__VerletOrg__
#define __Verlet_Organisms__VerletOrg__

#include "ofMain.h"
#include "VerletStick.h"
#include "VerletBall.h"

namespace CSE1342 {
	class VerletOrg {
		private:
			CSE1342::VerletStick* sticks;
			CSE1342::VerletBall* balls;
			int stickNum;
			int ballNum;
			ofColor stickColor;
			ofColor ballColor;
			void _init();
	
		public:
			VerletOrg();
			VerletOrg(int stickNum, int ballNum);
			VerletOrg(const VerletOrg& v);
			~VerletOrg();
			VerletOrg& operator=(const VerletOrg& v);
	
			virtual void position() = 0;
			virtual void connect() = 0;
			virtual void push();
			void display();
			void move();
		
			void setStickColor(int r, int g, int b);
			void setBallColor(int r, int g, int b);
	};
	
	inline void VerletOrg::setStickColor(int r, int g, int b) {
		stickColor.r = r;
		stickColor.g = g;
		stickColor.b = b;
	}
	
	inline void VerletOrg::setBallColor(int r, int g, int b) {
		ballColor.r = r;
		ballColor.g = g;
		ballColor.b = b;
	}
}

#endif