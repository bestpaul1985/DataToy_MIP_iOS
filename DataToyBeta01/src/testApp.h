#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "Ball.h"
#include "particle.h"
#include "vectorField.h"
#include "ofxBox2d.h"
#include "scene01.h"
#include "scene02.h"
#include "identity.h"
class testApp : public ofxiPhoneApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);
        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
        void gotMessage(ofMessage msg);
    
        int                     level;
        int                     eductionID;// 0 = NO, 1 = HS, 2 = BA
        ofImage                 arrow;
        ofImage                 bg3;
        vector<Ball>            balls;
        scene01                 myScene01;
        scene02                 myScene02;
        identity                myidentity;
    
        
};
