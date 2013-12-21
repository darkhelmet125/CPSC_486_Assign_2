//
//  Vector3.cpp
//  CPSC_486_Assign_1_initWithData_tut
//
//  Created by William Short 11/24/13.
//  Copyright (c) 2013 William Short. All rights reserved.
//

#include "Vector3.h"

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z)
{
    Vector3 newVector;
    newVector.x = x;
    newVector.y = y;
    newVector.z = z;
    
    return newVector;
}

Vector3 addVector3(const Vector3& vectorA, const Vector3& vectorB)
{
    Vector3 newVector;
    newVector.x = vectorA.x + vectorB.x;
    newVector.y = vectorA.y + vectorB.y;
    newVector.z = vectorA.z + vectorB.z;

    return newVector;
}

float dot(Vector3 vectorA, Vector3 vectorB)
{
    return ((vectorA.x*vectorB.x)+(vectorA.y*vectorB.y)+(vectorA.z*vectorB.z));
}