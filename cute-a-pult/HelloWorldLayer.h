//
//  HelloWorldLayer.h
//  cute-a-pult
//
//  Created by Gustavo Ambrozio on 23/8/11.
//  Copyright CodeCrop Software 2011. All rights reserved.
//


// When you import this file, you import all the cocos2d classes
#import "cocos2d.h"
#import "Box2D.h"
#import "GLES-Render.h"

// HelloWorldLayer
@interface HelloWorldLayer : CCLayer
{
	b2World* world;
	GLESDebugDraw *m_debugDraw;

    b2Fixture *armFixture;
    b2Body *armBody;
    b2RevoluteJoint *armJoint;
    b2MouseJoint *mouseJoint;
    b2Body *groundBody;

    NSMutableArray *bullets;
    int currentBullet;

    b2Body *bulletBody;
    b2WeldJoint *bulletJoint;
    
    BOOL releasingArm;
}

// returns a CCScene that contains the HelloWorldLayer as the only child
+(CCScene *) scene;

@end
