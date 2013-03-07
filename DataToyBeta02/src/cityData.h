//
//  cityData.h
//  DataToyBeta02
//
//  Created by PengCheng on 3/7/13.
//
//

#ifndef __DataToyBeta02__cityData__
#define __DataToyBeta02__cityData__

#include "ofMain.h"
#include "MpiData.h"
class cityData{
public:
    void setup(string &name,int &year);
    void update();
    void draw();
    void touchDown(int id, int number, float x, float y);
    void touchMove(int id, int number, float x, float y);
    void touchUp(int id, int number, float x, float y);
    
    
    MpiData                         dBase;
    string*                         cityName;
    int*                            cityYear;
    string                          preName;
    string                          pop;
    string                          imm_pct;
    string                          imm_pct_job;
    
    int                             preYear;
    float                           alpha;
    float                           size;
    float                           shape;
                        
};

#endif /* defined(__DataToyBeta02__cityData__) */
