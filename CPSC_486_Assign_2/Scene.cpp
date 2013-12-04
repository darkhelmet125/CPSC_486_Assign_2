//
//  Scene.cpp
//  CPSC_486_Assign_1_initWithData_tut
//
//  Created by William Short 11/25/13.
//  Copyright (c) 2013 William Short. All rights reserved.
//

#include "Scene.h"
#include "CameraSystem.h"
#include "ResourceManager.h"

//public
std::vector<Entity *>* Scene::getChildren()
{
    return _children;
}

Scene::Scene()
{
    _children = new std::vector<Entity *>();
    
    ResourceManager *resourceManager = &ResourceManager::getResourceManager();
    
    Entity *square1 = new Entity(resourceManager->getVertexBufferArray()->at(0), makeVector3(0.0f, 0.0f, 0.0f));
    square1->setRotation(makeVector3(0.0f, 0.0f, 0.0f));
    square1->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    square1->setVelocity(makeVector3(0.1f, 0.0f, 0.0f));
    square1->setRotationVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square1->setScaleVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    _children->push_back(square1);
    
    Entity *camera = new Entity(NULL, makeVector3(0.0f, 0.0f, 10.0f));
    camera->setEyeVector(makeVector3(0.0f, 0.0f, -1000.0f));
    camera->setVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    _children->push_back(camera);
    
    CameraSystem *cameraSystem = &CameraSystem::getCameraSystem();
    cameraSystem->setCurrentCamera(camera);
}

Scene::~Scene()
{
    for (std::vector<Entity *>::iterator iterator = _children->begin(); iterator != _children->end(); ++iterator) {
        delete *iterator;
    }
    
    delete _children;
}