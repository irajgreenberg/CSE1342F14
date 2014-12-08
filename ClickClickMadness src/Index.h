//
//  Index.h
//  3D_example
//
//  Created by Ira on 11/6/14.
//
//

#ifndef ___D_example__Index__
#define ___D_example__Index__

#include <stdio.h>

template <class T>
class Index {
public:
    T elem0, elem1, elem2;
    
    Index(T elem0 = 0, T elem1 = 0, T elem2 = 0) :
    elem0(elem0), elem1(elem1), elem2(elem2) {
    }
};

#endif /* defined(___D_example__Index__) */

