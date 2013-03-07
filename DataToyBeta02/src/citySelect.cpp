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
    W = 160;
    H = 600;
    space = 10;
    pos.set(0, 0);
    prePos.set(0, 0);
    offSet =0;
}

//--------------------------------------------------------------
void citySelect::setup(){
    
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
        ofRect(0, 0, width, height);
        ofTranslate(0, offSet);
        for (int i =0; i<25; i++) {
            ofSetColor(colors[i]);
            ofRect(rects[i]);
        }
        for (int i = 0; i<25; i++) {
            ofSetColor(255, 255, 255);
            font.drawString(dBase.getCity(i), 0, space*i+35*i+25);
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
                colors[i].set(255, 255, 255,179);
            }else{
                colors[i].set(255, 255, 255,100);
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
        float dis = pos.distance(prePos);
        if (dis>0) {
            float diff;
            diff = pos.y - prePos.y;
            offSet += diff;
        }
        if (offSet< -(space*11+35*11+25)) {
            offSet= -(space*11+35*11+25);
        }else if(offSet>0){
            offSet=0;
        }
        
        for (int i=0; i<25; i++) {
            
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x,rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y)){
                colors[i].set(255, 255, 255,179);
            }else{
                colors[i].set(255, 255, 255,100);
            }
        }
        prePos = pos;
    }
}


void citySelect::mouseUp(int id, int number, float x, float y){
   
    if (id == 0) {
        for (int i=0; i<25; i++) {
            colors[i].set(255, 255, 255,100);
            ofRectangle tempRect;
            tempRect.set(rects[i].getPosition().x,rects[i].getPosition().y + offSet, rects[i].getWidth(), rects[i].getHeight());
            if(tempRect.inside(x, y)&& prePos1.y == pos.y){
                cout<<dBase.getCity(i)<<endl;
            }
        }
    }

}