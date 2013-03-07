//
//  scene02.h
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#ifndef __DataToyPrototype002__scene02__
#define __DataToyPrototype002__scene02__

#include "ofMain.h"

#include "Box2D.h"
#include "citySelect.h"
#include "cityData.h"
#include "superBall.h"

class scene02{
public:
    scene02();
    void    setup(int &level);
    void    update();
    void    draw();
    void    touchDown(int id, int number, float x, float y);
    void    touchMove(int id, int number, float x, float y);
    void    touchUp(int id, int number, float x, float y);
    
    
    bool                    mouseOver;
    bool                    bPressed;
    bool                    bCitySeclect;
    bool                    bBalls;
    
    float                   startTime;
    float                   ButtonSize;
        
   
    string                  cityName;
    string                  preCityName;
    int                     cityYear;
    int                     preCityYear;
    
    ofTrueTypeFont          font2;
    ofImage                 platForm[3];
    ofImage                 character01;
    ofImage                 selectLayout01;
    ofImage                 selectLayout02;
    ofImage                 info01;
    ofImage                 icons[25];
    ofTrueTypeFont          font;
    ofRectangle             selectRect;
    ofRectangle             selectRect2;
    citySelect              select;
    cityData                myCity;
    vector<superBall>       mySuperBall;
    ofxBox2d                box2d;

    
    
};

#endif /* defined(__DataToyPrototype002__scene02__) */
