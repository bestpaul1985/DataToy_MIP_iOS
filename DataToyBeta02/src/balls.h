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
#include "MpiData.h"
// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
	
	void draw() {
        
        switch (education) {
            case 0:
                glPushMatrix();
                glTranslatef(getPosition().x- getRadius(), getPosition().y- getRadius(), 0);
                ofSetColor(247,151,121,200);
                ofFill();
                ofCircle(0, 0, getRadius());
                glPopMatrix();
                break;
             case 1:
                glPushMatrix();
                glTranslatef(getPosition().x- getRadius(), getPosition().y- getRadius(), 0);
                ofSetColor(151,205,171,200);
                ofFill();
                ofCircle(0, 0, getRadius());
                glPopMatrix();
                 break;
            case 2:
                glPushMatrix();
                glTranslatef(getPosition().x- getRadius(), getPosition().y- getRadius(), 0);
                ofSetColor(135,129,190,200);
                ofFill();
                ofCircle(0, 0, getRadius());
                glPopMatrix();
                break;
        }
       
		
		
    }
    
    int education; // 0 = no high school , 1 = HS, 2 = BA
                

};

class balls{

public:
    void setup(string &name, int &year);
    void update();
    void draw();

    ofxBox2d                        world;
    vector<CustomParticle>          myballs;
    MpiData                         dBase;
    string*                         cityName;
    int*                            cityYear;
    int                             imm_num_HS;
    int                             imm_num_No;
    int                             imm_num_BA;
    int                             native_num_No;
    int                             native_num_BA;
    int                             native_num_HS;
    int                             imm_all;
    int                             Native_all;
    int                             no_balls;
    int                             hs_balls;
    int                             ba_balls;
    int                             Pop_Per_Ball;
    int                             pre_imm_all;
};

#endif /* defined(__DataToyBeta02__balls__) */
