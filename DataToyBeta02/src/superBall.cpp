//
//  superBall.cpp
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#include "superBall.h"

superBall::superBall(){
    color.set(30, 0, 255);
    cs =30;
    duration = 3000;
    startTime = ofGetElapsedTimeMicros();
    bDead = false;
    bTimer  = false;
    alpha = 179;
}

void superBall::draw(){
    
   
    float radius = getRadius();
    glPushMatrix();
    glTranslatef(getPosition().x, getPosition().y, 0);
    ofSetCircleResolution(cs);
    ofSetColor(color.r, color.g, color.b, alpha);
    if (bTimer) {
        if (ofGetElapsedTimeMicros()-startTime>duration) {
            bDead = true;
        }
    }
    if (bTimer){
        if (alpha>=0) {
            alpha -= 1;
        }
    }
    ofFill();
    ofCircle(0, 0, radius);
    glPopMatrix();
    

}
