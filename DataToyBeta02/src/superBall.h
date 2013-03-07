//
//  superBall.h
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#ifndef __DataToyBeta02__superBall__
#define __DataToyBeta02__superBall__

#include "ofMain.h"
#include "ofxBox2d.h"
#include "MpiData.h"

class superBall : public ofxBox2dCircle{
public:
    void setup(MpiData &data);
    void update();
    void draw();

    int all_pop;
    int no_pop;
    int hs_pop;
    int ba_pop;
    MpiData* dbase;
};

#endif /* defined(__DataToyBeta02__superBall__) */
