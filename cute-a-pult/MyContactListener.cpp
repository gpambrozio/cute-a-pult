//
//  MyContactListener.cpp
//  cute-a-pult
//
//  Created by Gustavo Ambrozio on 28/8/11.
//  Copyright 2011 CodeCrop Software. All rights reserved.
//

#include "MyContactListener.h"

MyContactListener::MyContactListener() : contacts()
{
}

MyContactListener::~MyContactListener()
{
}

void MyContactListener::BeginContact(b2Contact* contact)
{
}

void MyContactListener::EndContact(b2Contact* contact)
{
}

void MyContactListener::PreSolve(b2Contact* contact, 
                                 const b2Manifold* oldManifold)
{
}

void MyContactListener::PostSolve(b2Contact* contact, 
                                  const b2ContactImpulse* impulse)
{
    bool isAEnemy = contact->GetFixtureA()->GetUserData() != NULL;
    bool isBEnemy = contact->GetFixtureB()->GetUserData() != NULL;
    if (isAEnemy || isBEnemy)
    {
        // Should the body break?
        int32 count = contact->GetManifold()->pointCount;
        
        float32 maxImpulse = 0.0f;
        for (int32 i = 0; i < count; ++i)
        {
            maxImpulse = b2Max(maxImpulse, impulse->normalImpulses[i]);
        }
        
        if (maxImpulse > 1.0f)
        {
            // Flag the enemy(ies) for breaking.
            if (isAEnemy)
                contacts.insert(contact->GetFixtureA()->GetBody());
            if (isBEnemy)
                contacts.insert(contact->GetFixtureB()->GetBody());
        }
    }
}
