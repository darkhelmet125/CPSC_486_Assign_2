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
    Entity* _entity;
    
public:
    Vector3 origin[3];
    Vector3 direction[3];
    Vector3 position[3];
    Ray3D();
    ~Ray3D();
};

#endif /* defined(__CPSC_486_Assign_2__Ray3D__) */
