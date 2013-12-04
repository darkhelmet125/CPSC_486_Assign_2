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
    square1->setVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square1->setRotationVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square1->setScaleVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    _children->push_back(square1);
    
    Entity *square2 = new Entity(resourceManager->getVertexBufferArray()->at(1), makeVector3(12.64f, -3.0f, 0.0f));
    square2->setRotation(makeVector3(0.0f, 0.0f, 0.0f));
    square2->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    square2->setVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square2->setRotationVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square2->setScaleVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    _children->push_back(square2);
    
    Entity *square3 = new Entity(resourceManager->getVertexBufferArray()->at(2), makeVector3(-12.64f, 3.0f, 0.0f));
    square3->setRotation(makeVector3(0.0f, 0.0f, 0.0f));
    square3->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    square3->setVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square3->setRotationVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square3->setScaleVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    _children->push_back(square3);
    
    Entity *square4 = new Entity(resourceManager->getVertexBufferArray()->at(3), makeVector3(-1.0f, 6.68f, 0.0f));
    square4->setRotation(makeVector3(0.0f, 0.0f, 0.0f));
    square4->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    square4->setVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square4->setRotationVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square4->setScaleVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    _children->push_back(square4);
    
    Entity *square5 = new Entity(resourceManager->getVertexBufferArray()->at(4), makeVector3(1.0f, -6.68f, 0.0f));
    square5->setRotation(makeVector3(0.0f, 0.0f, 0.0f));
    square5->setScale(makeVector3(1.0f, 1.0f, 1.0f));
    square5->setVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square5->setRotationVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    square5->setScaleVelocity(makeVector3(0.0f, 0.0f, 0.0f));
    _children->push_back(square5);
    
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