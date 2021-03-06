//
//  CameraSystem.cpp
//  CPSC_486_Assign_1_initWithData_tut
//
//  Created by William Short 11/25/13.
//  Copyright (c) 2013 William Short. All rights reserved.
//

#include "CameraSystem.h"
#include "RenderSystem.h"

Entity* CameraSystem::getCurrentCamera()
{
    return _currentCamera;
}

void CameraSystem::setCurrentCamera(Entity *newCamera)
{
    _currentCamera = newCamera;
    
    RenderSystem *renderSystem = &RenderSystem::getRenderSystem();
    renderSystem->setCurrentCamera(_currentCamera);
}

CameraSystem::CameraSystem()
{
    
}

CameraSystem::~CameraSystem()
{
    
}

CameraSystem& CameraSystem::getCameraSystem()
{
    static CameraSystem *cameraSystem = NULL;
    
    if (cameraSystem == NULL) {
        
        cameraSystem = new CameraSystem();
    }
    
    return *cameraSystem;
}

void CameraSystem::destroyCameraSystem()
{
    CameraSystem *cameraSystem = &getCameraSystem();
    delete cameraSystem;
}