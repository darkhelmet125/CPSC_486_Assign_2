//
//  RenderSystem.cpp
//  CPSC_486_Assign_1_initWithData_tut
//
//  Created by William Short 11/24/13.
//  Copyright (c) 2013 William Short. All rights reserved.
//

#include "RenderSystem.h"
#include "ShaderInterface.h"
#include "Ray3D.h"

//other
void perp(float* in, float* out);
int whichSide(Entity& s, Ray3D& r);
bool testIntersection(Entity& a, Entity& b);

//private
RenderSystem::RenderSystem(): _window(glfwGetCurrentContext()),
_cameraSystem(&CameraSystem::getCameraSystem())
{
    _currentCamera = _cameraSystem->getCurrentCamera();
}

RenderSystem::~RenderSystem()
{
    
}

//public
Entity* RenderSystem::getCurrentCamera()
{
    return _currentCamera;
}

void RenderSystem::setCurrentCamera(Entity *newCamera)
{
    _currentCamera = newCamera;
}

void RenderSystem::render(std::vector<Entity *> *entityArray)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (std::vector<Entity *>::iterator iterator = entityArray->begin(); iterator != entityArray->end(); ++iterator)
    {
        Entity *entity = *iterator;
        
        if (entity->getVertexBuffer() != NULL)
        {
            glUseProgram(entity->getVertexBuffer()->getShader()->getProgramHandle());
            glBindBuffer(GL_ARRAY_BUFFER, entity->getVertexBuffer()->getVertexBufferID());
            
            glLoadIdentity();
            gluLookAt(_currentCamera->getPosition().x,
                      _currentCamera->getPosition().y,
                      _currentCamera->getPosition().z,
                      _currentCamera->getEyeVector().x,
                      _currentCamera->getEyeVector().y,
                      _currentCamera->getEyeVector().z,
                      _currentCamera->getUpVector().x,
                      _currentCamera->getUpVector().y,
                      _currentCamera->getUpVector().z);
            
            glTranslatef(entity->getPosition().x, entity->getPosition().y, entity->getPosition().z);
            
            //bounce off of left/right
            if((entity->getPosition().x >= 0.9f) || (entity->getPosition().x <=-0.9f))
            {
                entity->setVelocity(makeVector3(-(entity->getVelocity().x), entity->getVelocity().y, entity->getVelocity().z));
            }
            
            //bounce off of top/bottom
            if((entity->getPosition().y >= 0.9f) || (entity->getPosition().y <=-0.9f))
            {
                entity->setVelocity(makeVector3(entity->getVelocity().x, -(entity->getVelocity().y), entity->getVelocity().z));
            }
            
            glRotatef(entity->getRotation().x, 0.0f, 0.0f, 1.0f);
            glRotatef(entity->getRotation().y, 0.0f, 1.0f, 0.0f);
            glRotatef(entity->getRotation().z, 1.0f, 0.0f, 0.0f);
            
            glScalef(entity->getScale().x, entity->getScale().y, entity->getScale().z);
            
            glUniform4f(entity->getVertexBuffer()->getShader()->get_uColor(),
                        entity->getVertexBuffer()->getShaderData()->get_uColorValue().x,
                        entity->getVertexBuffer()->getShaderData()->get_uColorValue().y,
                        entity->getVertexBuffer()->getShaderData()->get_uColorValue().z,
                        entity->getVertexBuffer()->getShaderData()->get_uColorValue().w);
            
            glUniform3f(entity->getVertexBuffer()->getShader()->get_uLightPosition(),
                        entity->getVertexBuffer()->getShaderData()->get_uLightPosition().x,
                        entity->getVertexBuffer()->getShaderData()->get_uLightPosition().y,
                        entity->getVertexBuffer()->getShaderData()->get_uLightPosition().z);
            
            
            entity->getVertexBuffer()->configureVertexAttributes();
            entity->getVertexBuffer()->renderVertexBuffer();
        }
    }
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

RenderSystem& RenderSystem::getRenderSystem()
{
    static RenderSystem *renderSystem = NULL;
    
    if (renderSystem == NULL) {
        renderSystem = new RenderSystem();
        
        glClearColor(0.0f, 0.7f, 1.0f, 1.0f);
        
        glMatrixMode(GL_PROJECTION);
        glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 2, -2);
        //gluPerspective(75.0f, 850.0f/850.0f, 2, -2);
        glViewport(0.0f, 0.0f, 850.0f, 850.0f);
        glMatrixMode(GL_MODELVIEW);
        
        glEnable(GL_CULL_FACE);
    }
    
    return *renderSystem;
}

void RenderSystem::destroyRenderSystem()
{
    RenderSystem *renderSystem = &getRenderSystem();
    delete renderSystem;
}

/*
void perp(float* in, float* out)
{
    float temp = in[0];
    out[0] = -in[1];
    out[1] = temp;
}

int whichSide(Entity& s, Ray3D& r)
{
    int positive, negative;
    positive = negative = 0;
    float t;
    for(int i = 0; i<4; ++i)
    {
        t = dot(r.direction, (s.getVertexBuffer()->at(i) - r.position));
        if(t>0)
            ++positive;
        else if(t<0)
            ++negative;
        if(positive && negative)
            return 0;
    }
    return (positive?1:-1);
}

bool testIntersection(Entity& a, Entity& b)
{
    for (int i=0, j=3; i<4; ++i)
    {
        if(whichSide(b, a.ray[i]) > 0)
            return false;
    }
    for (int i=0; i<4; ++i)
    {
        if(whichSide(a, b.ray[i]) > 0)
            return false;
    }
    return true;
}
*/