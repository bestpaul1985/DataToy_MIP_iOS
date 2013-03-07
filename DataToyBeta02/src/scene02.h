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
#include "particle.h"
#include "vectorField.h"
#include "cities.h"
#include "stopClock.h"
#include "dataBall.h"
#include "citySelect.h"

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
    ofImage                 platForm[3];
    ofImage                 character01;
    ofImage                 info01;
    ofImage                 icons[25];
    ofTrueTypeFont          font;
    
    citySelect              seclet01;
    //--------old
    ofPoint                 AddOutwardCirclePos;
    ofImage                 formula;
    ofImage                 charactor01;
    ofImage                 selectLayout01;
    ofImage                 selectLayout02;
    ofImage                 halo[6];
    ofImage                 cityIcon;
    ofImage                 chooseCity;
    vector<particle>        particles;
    vectorField             VF;
    cities                  myCities;
    stopClork               myClork;
    ofTrueTypeFont          city;
    ofTrueTypeFont          city2;
    string                  name;
    dataBall                myBall;
    
    
};

#endif /* defined(__DataToyPrototype002__scene02__) */
