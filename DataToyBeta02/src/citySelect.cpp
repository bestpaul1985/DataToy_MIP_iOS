//
//  citySelect.cpp
//  DataToyBeta02
//
//  Created by PengCheng on 3/6/13.
//
//

#include "citySelect.h"

citySelect::citySelect(){
    
    
    height = 0;
    width = 0;
    speed = 0.03f;
    pct = 0;
    W = 200;
    H = 768;
    space = 10;
    pos.set(0, 0);
    prePos.set(0, 0);
    offSet = 25;
    boxPos.set(220, 0);
    temPos.set(0, 0);
    bSelect1 = false;
}

//--------------------------------------------------------------
void citySelect::setup(string &name,bool &select){
    
    bSelect = &select;
    cityName =&name;
    font.loadFont("fonts/Futura-CondensedMedium.ttf",20);
    dBase.loadCities("cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2005, "2005.csv");
    dBase.loadYear(2010, "2010.csv");
    pos.set(0, 0);
    for (int i=0; i<25; i++) {
        ofColor c;
        c.set(255, 255, 255,100);
        colors.push_back(c);
        ofRectangle temp;
        temp.set(0,space*i+35*i,W,35);
        rects.push_back(temp);
    }
    
}

//--------------------------------------------------------------
void citySelect::update(){

  
    pct += speed;
    if (pct>1) {
        pct = 1;
    }
    width = (1-pct) * width + pct * W;
    height = (1-pct) * height + pct * H;
}

//--------------------------------------------------------------
void citySelect::draw(){
    
    ofSetColor(51, 60, 65);
    
    ofPushMatrix();
    
        ofSetColor(51, 60, 64);
        ofRect(0, 0, width, height);
        ofTranslate(0, offSet);
        for (int i =0; i<25; i++) {
            ofSetColor(colors[i]);
            ofRect(rects[i]);
        }
        for (int i = 0; i<25; i++) {
            ofRectangle rect;
            rect = font.getStringBoundingBox(dBase.getCity(i), 0, 0);
            ofSetColor(255, 255, 255);
            font.drawString(dBase.getCity(i),W/2 -int(rect.getWidth()/2), space*i+35*i+28);
        }
    
    ofPopMatrix();
    

    
}

//--------------------------------------------------------------
void citySelect::mouseDown(int id, int number, float x, float y){

    if (id ==0) {
        pos.set(x, y);
        for (int i=0; i<25; i++) {
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x,rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y)){
                colors[i].set(255, 255, 255,50);
            }else{
                colors[i].set(255, 255, 255,0);
            }
        }
        
        prePos = pos;
        prePos1 = pos;
    }
    
}

//--------------------------------------------------------------
void citySelect::mouseMove(int id, int number, float x, float y){
    
    if (id ==0) {
        pos.set(x, y);

        float diff;
        diff = pos.y - prePos.y;
        offSet += diff;
        
        if (offSet< -(space*8+35*8+14)) {
            offSet= -(space*8+35*8+14);
        }else if(offSet>28){
            offSet=28;
        }
        
        for (int i=0; i<25; i++) {
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x, rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y)){
                colors[i].set(255, 255, 255,50);
            }else{
                colors[i].set(255, 255, 255,0);
            }
        }
        prePos = pos;
    }
}

//--------------------------------------------------------------
void citySelect::mouseUp(int id, int number, float x, float y){
   
    if (id == 0) {
    
        for (int i=0; i<25; i++) {
            colors[i].set(255, 255, 255,0);
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x,rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y) && prePos1.y == pos.y){
                colors[i].set(255, 255, 255,0);
                *cityName = dBase.getCity(i);
                *bSelect = false;
            }
            
        }
    }

}