//
//  scene02.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#include "scene02.h"

scene02::scene02(){

}
//-------------------------------
void scene02::setup(int &level){
    //images
    info01.loadImage("image/info01.png");
    character01.loadImage("image/character01.png");
    selectLayout01.loadImage("image/SelectingLayout01.png");
    selectLayout02.loadImage("image/SelectingLayout02.png");
    
    font.loadFont("fonts/Futura-CondensedMedium.ttf",30);
    font2.loadFont("fonts/Futura.ttc",18);

    for (int i =0; i<3; i++) {
        platForm[i].loadImage("image/c0" + ofToString(i+1)+".png");
    }
    
      //others
    myLevel = &level;
    myCase = 0;
    startTime = ofGetElapsedTimeMillis();
    count = 0;
    mouseOver = false;
    bPressed = false;
    bCitySeclect = false;
    bBalls = false;
    year = 2005;
    preYear = 2005;
    ButtonSize = 70;
    
    //select
    cityName = "0";
    cityYear = 2005;
    selectRect.set(228, 443, 190, 97);
    selectRect2.set(632, 443, 170, 97);
    select.setup(cityName,cityYear,bCitySeclect, bBalls);
    myCity.setup(cityName, cityYear);
    myBalls.setup(cityName, cityYear);
    
}
//-------------------------------
void scene02::update(){
    
    if (bCitySeclect) select.update();
    myCity.update();
    
    if (bBalls) {
    myBalls.update();
    };
   
}
//-------------------------------
void scene02::draw(){
 
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
    //            character01.draw(430, 337);
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

    if (bCitySeclect) {
    select.draw();
    }
    
    if(bBalls){
        myBalls.draw();
    }
}
//-------------------------------
void scene02::touchDown(int id, int number, float x, float y){
    
    if (selectRect.inside(x, y)&& bCitySeclect == false) {
        select.width = 0;
        select.height = 0;
        select.pct = 0;
        bCitySeclect = true;
        bBalls = false;
    }
    
    if (bCitySeclect) select.mouseDown(id, number, x, y);
}
//-------------------------------
void scene02::touchMove(int id, int number, float x, float y){
  
    if (selectRect.inside(x, y)&& bCitySeclect == false) {
        select.width = 0;
        select.height = 0;
        select.pct = 0;
        bCitySeclect = true;
        bBalls = false;
        
    }
    if (bCitySeclect) select.mouseMove(id, number, x, y);
         
}

//-------------------------------
void scene02::touchUp(int id, int number, float x, float y){
    

    if (bCitySeclect) {
    select.mouseUp(id, number, x, y);
    }

     
}

