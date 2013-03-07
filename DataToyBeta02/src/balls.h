//
//  balls.h
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#ifndef __DataToyBeta02__balls__
#define __DataToyBeta02__balls__

#include "ofMain.h"
#include "ofxBox2d.h"
// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
	
	void draw() {
        
       
		glPushMatrix();
		glTranslatef(getPosition().x- getRadius(), getPosition().y- getRadius(), 0);
		ofSetColor(255,255,255,150);
		ofFill();
		ofCircle(0, 0, 10);
		glPopMatrix();
		
	}
    
};

class balls{

public:
    void setup();
    void update();
    void draw();

ofxBox2d world;
vector<CustomParticle>  myballs;

};

#endif /* defined(__DataToyBeta02__balls__) */
