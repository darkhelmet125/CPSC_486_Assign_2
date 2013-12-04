//
//  main.cpp
//  CPSC_486_Assign_2
//
//  Created by William Short on 12/2/13.
//  Copyright (c) 2013 William Short. All rights reserved.
//

#include <iostream>
#include "ProjectManager.h"

int main(int argc, const char * argv[])
{
    ProjectManager *projectManager = &ProjectManager::getProjectManager();
    projectManager->runGameLoop();
    ProjectManager::destroyProjectManager();
}

