//
//  Ray3D.h
//  CPSC_486_Assign_2
//
//  Created by William Short on 12/4/13.
//  Copyright (c) 2013 William Short. All rights reserved.
//

#ifndef __CPSC_486_Assign_2__Ray3D__
#define __CPSC_486_Assign_2__Ray3D__

#include <iostream>
#include "Vector3.h"
#include "Entity.h"

class Ray3D
{
private:
    Vector3 origin[3];
    Vector3 direction[3];
    Entity* _entity;
    
public:
    bool rayIntersection();
};

#endif /* defined(__CPSC_486_Assign_2__Ray3D__) */
