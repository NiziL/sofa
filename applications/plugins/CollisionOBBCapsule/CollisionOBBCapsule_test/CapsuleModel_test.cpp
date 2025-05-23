﻿/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <gtest/gtest.h>
#include <CollisionOBBCapsule/geometry/CapsuleModel.h>
#include <sofa/core/ObjectFactory.h>
#include <sofa/helper/system/PluginManager.h>

TEST(CapsuleModel, creationFromFactory)
{
    sofa::helper::system::PluginManager& pm = sofa::helper::system::PluginManager::getInstance();
    pm.loadPluginByName("CollisionOBBCapsule");

    sofa::core::ObjectFactory* objectFactory = sofa::core::ObjectFactory::getInstance();
    objectFactory->registerObjectsFromPlugin("CollisionOBBCapsule");

    const auto entry = objectFactory->getEntry("CapsuleCollisionModel");
    const auto creatorRigid = entry.creatorMap.at("Rigid3d");

    sofa::core::objectmodel::BaseObjectDescription desc;
    const auto object = creatorRigid->createInstance(nullptr, &desc);
}
