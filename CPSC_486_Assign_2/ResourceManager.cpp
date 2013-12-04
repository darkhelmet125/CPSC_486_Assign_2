//
//  ResourceManager.cpp
//  CPSC_486_Assign_1_initWithData_tut
//
//  Created by William Short 11/24/13.
//  Copyright (c) 2013 William Short. All rights reserved.
//

#include "ResourceManager.h"
#include "SquareVertices.h"

//private
ResourceManager::ResourceManager()
{
    _shaderArray = new std::vector<ShaderInterface *>();
    ShaderInterface *shader = new ShaderInterface("ColorShader.vsh", "ColorShader.fsh");
    _shaderArray->push_back(shader);
    ShaderInterface *lightShader = new ShaderInterface("SimpleLightShader.vsh", "SimpleLightShader.fsh");
    _shaderArray->push_back(lightShader);
    
    _shaderData = new std::vector<ShaderData *>();
    ShaderData *skyColor = new ShaderData(makeVector4(0.5f, 0.7f, 1.0f, 1.0f), makeVector3(0.0f, 20.0f, 0.0f));
    _shaderData->push_back(skyColor);
    ShaderData *redishColor = new ShaderData(makeVector4(1.0f, 0.3f, 0.25f, 1.0f), makeVector3(0.0f, 0.0f, 10.0f));
    _shaderData->push_back(redishColor);
    ShaderData *greenishColor = new ShaderData(makeVector4(0.3f, 1.0f, 0.65f, 1.0f), makeVector3(0.0f, 0.0f, 0.1f));
    _shaderData->push_back(greenishColor);
    
    _vertexBufferArray = new std::vector<VertexBuffer *>();
    VertexBuffer *square1 = new VertexBuffer(squareVertices,
                                             sizeof(squareVertices),
                                             GL_QUADS,
                                             4,
                                             sizeof(VertexDataP),
                                             _shaderArray->at(0),
                                             _shaderData->at(1),
                                             NULL,
                                             NULL);
    _vertexBufferArray->push_back(square1);
    
}

ResourceManager::~ResourceManager()
{
    
    for (std::vector<ShaderInterface *>::iterator iterator = _shaderArray->begin(); iterator != _shaderArray->end(); ++iterator)
    {
        delete *iterator;
    }
    
    delete _shaderArray;
    
    for (std::vector<VertexBuffer *>::iterator iterator = _vertexBufferArray->begin(); iterator != _vertexBufferArray->end(); ++iterator)
    {
        delete *iterator;
    }
    
    delete _vertexBufferArray;
    
    for (std::vector<ShaderData *>::iterator iterator = _shaderData->begin(); iterator != _shaderData->end(); ++iterator)
    {
        delete *iterator;
    }
    
    delete _shaderData;
}

//public
std::vector<ShaderInterface *>* ResourceManager::getShaderArray()
{
    return _shaderArray;
}

std::vector<VertexBuffer *>* ResourceManager::getVertexBufferArray()
{
    return _vertexBufferArray;
}

ResourceManager& ResourceManager::getResourceManager()
{
    static ResourceManager *resourceManager = NULL;
    
    if (resourceManager == NULL)
    {
        resourceManager = new ResourceManager();
    }
    
    return *resourceManager;
}

void ResourceManager::destroyResourceManager()
{
    ResourceManager *resourceManager = &getResourceManager();
    delete resourceManager;
}