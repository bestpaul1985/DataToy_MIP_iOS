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


#include "citySelect.h"
#include "cityData.h"
#include "balls.h"

class scene02{
public:
    scene02();
    void    setup(int &level);
    void    update();
    void    draw();
    void    touchDown(int id, int number, float x, float y);
    void    touchMove(int id, int number, float x, float y);
    void    touchUp(int id, int number, float x, float y);
    
    int                     * myLevel;
    int                     year;
    int                     preYear;
    int                     myCase;
    int                     count;
    bool                    bAddOutwardCircle;
    bool                    timeUp;
    bool                    mouseOver;
    bool                    bPressed;
    float                   startTime;
    float                   ButtonSize;
        
    //------new
    bool                    bCitySeclect;
    string                  cityName;
    int                     cityYear;
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
    balls                   myBalls;
    //--------old



    
    
};

#endif /* defined(__DataToyPrototype002__scene02__) */
