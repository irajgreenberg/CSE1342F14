#ifndef __Verlet_System__VerletStick__
#define __Verlet_System__VerletStick__

#include <iostream>
#include "ofMain.h"
#include "VerletBall.h"

namespace CSE1342 {
	
	class VerletStick {
		
	private:
		VerletBall * b1, * b2;
		float length;
		float tension;
		float pushX;
		float pushY;
		
	public:
		friend class VerletOrg;
		VerletStick();
		VerletStick(VerletBall* b1, VerletBall* b2, float tension);
		VerletStick(VerletBall* b1, VerletBall* b2, float tension, float pushX, float pushY);
		void constrain();
		void displayStick();
		void displayBalls();
		void verlet();
	};

	
}

#endif
