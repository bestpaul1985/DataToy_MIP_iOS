//
//  scene02.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#include "scene03.h"

scene03::scene03(){
    
}
//-------------------------------
void scene03::setup(int &level){
    //images
    info01.loadImage("image/info01.png");
    character.loadImage("image/dad.png");
    selectLayout01.loadImage("image/SelectingLayout01.png");
    selectLayout02.loadImage("image/SelectingLayout02.png");
    font.loadFont("fonts/Futura-CondensedMedium.ttf",30);
    font2.loadFont("fonts/Futura.ttc",18);
    
    for (int i =0; i<3; i++) {
        platForm[i].loadImage("image/c0" + ofToString(i+1)+".png");
    }
    
    //others
    
    startTime = ofGetElapsedTimeMillis();
    
    mouseOver = false;
    bPressed = false;
    bCitySeclect = false;
    bBalls = false;
    
    ButtonSize = 70;
    
    //select
    cityName = "0";
    preCityName = cityName;
    cityYear = 2005;
    preCityYear = cityYear;
    
    selectRect.set(228, 443, 190, 97);
    selectRect2.set(632, 443, 170, 97);
    select.setup(cityName,cityYear,bCitySeclect, bBalls);
    myCity.setup(cityName, cityYear);
    
    box2d.init();
	box2d.setGravity(0, 15);
	box2d.createBounds();
	box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.setIterations(1, 1);
    
}
//-------------------------------
void scene03::update(){
    
    box2d.update();
    
    if (bCitySeclect) select.update();
    myCity.update();
    
    if (cityName != preCityName || cityYear != preCityYear) {
        
        cout<<myCity.no_num<<" "<<myCity.hs_num<<" "<<myCity.ba_num<<endl;
        
        
        for (int i =0; i<myCity.no_num; i++) {
            superBall b;
            b.setPhysics(3.0, 0, 0.1);
            b.setup(box2d.getWorld(), ofRandom(ofGetWidth()), ofRandom(0,ofGetHeight()/3), 10);
            b.setVelocity(0, 0);
            b.cs = myCity.shape;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.hs_num; i++) {
            superBall b;
            b.setPhysics(3.0, 0, 0.1);
            b.setup(box2d.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()/3), 10);
            b.setVelocity(0, 0);
            b.cs = myCity.shape;
            mySuperBall.push_back(b);
        }
        
        for (int i =0; i<myCity.ba_num; i++) {
            superBall b;
            b.setPhysics(3.0, 0, 0.1);
            b.setup(box2d.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()/3), 10);
            b.setVelocity(0, 0);
            b.cs = myCity.shape;
            mySuperBall.push_back(b);
        }
        
        preCityName = cityName;
        preCityYear = cityYear;
    }
}
//-------------------------------
void scene03::draw(){
    
    ofColor myColor;
    mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
    ofSetColor(myColor);
    
    ofSetColor(255, 255, 255,179);
    platForm[1].draw(177,270);
    ofSetColor(255, 255, 255,179);
    platForm[2].draw(573,270);
    ofSetColor(255, 255, 255,179);
    platForm[0].draw(376,166);
    ofSetColor(255, 255, 255,255);
    character.draw(430, 337);
    ofSetColor(255, 255, 255,255);
    info01.draw(396, 211);
    selectLayout01.draw(236, 439);
    selectLayout02.draw(660, 439);
    
    if (cityName == "0") {
        font.drawString("SELECT A CITY", 231, 505);
    }else{
        ofRectangle rect;
        rect = font.getStringBoundingBox(cityName, 0, 0);
        font.drawString(cityName, int(317-rect.getWidth()/2), 503);
        myCity.draw();
        
        rect = font2.getStringBoundingBox("Population: " + myCity.pop, 0, 0);
        font2.drawString("Population: " + myCity.pop, int(317-rect.getWidth()/2), 567+30);
        rect = font2.getStringBoundingBox("Imm Pop Pct: "+ myCity.imm_pct, 0, 0);
        font2.drawString("Imm Pop Pct: " + myCity.imm_pct, int(317-rect.getWidth()/2), 567+60);
        rect = font2.getStringBoundingBox("Imm Job Pct: "+ myCity.imm_pct_job, 0, 0);
        font2.drawString("Imm Job Pct: " + myCity.imm_pct_job, int(317-rect.getWidth()/2), 567+90);
        rect = font2.getStringBoundingBox("Recent Arrived Imm +/-: "+ myCity.imm_change, 0, 0);
        font2.drawString("Recent Arrived Imm +/-: " + myCity.imm_change, int(317-rect.getWidth()/2), 567+120);
        
        
    }
    
    font.drawString(ofToString(cityYear), 685, 505);
    
    
    
    if (mySuperBall.size()>0) {
        for (int i=0; i<mySuperBall.size(); i++) {
            mySuperBall[i].draw();
        }
    }
    
    
    if (bCitySeclect) {
        select.draw();
    }
    
    
}
//-------------------------------
void scene03::touchDown(int id, int number, float x, float y){
    
    if (selectRect.inside(x, y)&& bCitySeclect == false) {
        select.width = 0;
        select.height = 0;
        select.pct = 0;
        bCitySeclect = true;
        
    }
    
    if (bCitySeclect) select.mouseDown(id, number, x, y);
}
//-------------------------------
void scene03::touchMove(int id, int number, float x, float y){

    if (bCitySeclect) select.mouseMove(id, number, x, y);
    
}

//-------------------------------
void scene03::touchUp(int id, int number, float x, float y){
    
    
    if (bCitySeclect) {
        select.mouseUp(id, number, x, y);
    }
    
    
}

void scene03::reset(){
    
    mouseOver = false;
    bPressed = false;
    bCitySeclect = false;
    bBalls = false;
    cityName = "0";
    preCityName = cityName;
    cityYear = 2005;
    preCityYear = cityYear;
    
//    for (int i= mySuperBall.size() ; i>=0; i--) {
//        mySuperBall[i].destroy();
//    }
}
