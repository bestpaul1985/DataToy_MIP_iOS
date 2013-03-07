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
    cityIcon.loadImage("images/cityIcon.png");
    charactor01.loadImage("images/character01.png");
    info01.loadImage("image/info01.png");
    chooseCity.loadImage("images/choosecity.png");
    formula.loadImage("images/formula.png");
    character01.loadImage("image/character01.png");
    selectLayout01.loadImage("image/SelectingLayout01.png");
    selectLayout02.loadImage("image/SelectingLayout02.png");
    
    font.loadFont("fonts/Futura-CondensedMedium.ttf",30);
    font2.loadFont("fonts/Futura.ttc",18);
    city.loadFont("fonts/[z] Arista light.ttf", 28);
    city2.loadFont("fonts/[z] Arista ExtraFilled.ttf", 27);
    for (int i =0; i<3; i++) {
        platForm[i].loadImage("image/c0" + ofToString(i+1)+".png");
    }
    
    for (int i =0; i<5; i++) {
        halo[i].loadImage("images/halo0" + ofToString(i+1)+".png");
    }

    for (int i =0; i<5; i++) {
        icons[i].loadImage("images/icon0" + ofToString(i+1)+".png");
    }
    
    //vectorfiled
    for (int i = 0; i < 50; i++){
		particle p;
        p.img = &icons[int(ofRandom(0,4))];
		p.setInitialCondition(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, 0);
		p.damping = ofRandom(0.07, 0.08);
		particles.push_back(p);
	}
  
    
	VF.setupField(ofGetWidth()/50, ofGetHeight()/50,ofGetWidth(), ofGetHeight());
    
    //others
    myLevel = &level;
    myCase = 0;
    startTime = ofGetElapsedTimeMillis();
    count = 0;
    name = "ok";
    mouseOver = false;
    bPressed = false;
    bCitySeclect = false;
    year = 2005;
    preYear = 2005;
    ButtonSize = 70;
    
    //stopClork
    myClork.setup(year);
    myBall.setup();
    
    
    //select
    cityName = "0";
    cityYear = 2005;
    selectRect.set(228, 443, 190, 97);
    selectRect2.set(632, 443, 170, 97);
    select.setup(cityName,cityYear,bCitySeclect);
    myCity.setup(cityName, cityYear);
    
}
//-------------------------------
void scene02::update(){
    
    switch (myCase) {
        case 0:{
            
            if (bCitySeclect) {
                 select.update();
            }
            myCity.update();
           
        }
            break;
        case 1:{
            
            myCities.update();
            if (myCities.bDestry) {
                for (int i=0; i<myCities.myBall->IMM_Balls_BA.size(); i++) {
                    myCities.myBall->IMM_Balls_BA[i].destroy();
                                  }
                for (int i=0; i<myCities.myBall->IMM_Balls_HS.size(); i++) {
                    myCities.myBall->IMM_Balls_HS[i].destroy();
                                    }
                for (int i=0; i<myCities.myBall->IMM_Balls_NO.size(); i++) {
                    myCities.myBall->IMM_Balls_NO[i].destroy();
                    
                }
                
                for (int i=0; i<myCities.myBall->Native_Balls_BA.size(); i++) {
                  myCities.myBall->Native_Balls_BA[i].destroy();
                    
                    
                }
                for (int i=0; i<myCities.myBall->Native_Balls_HS.size(); i++) {
                    myCities.myBall->Native_Balls_HS[i].destroy();
                    
                }
                for (int i=0; i<myCities.myBall->Native_Balls_NO.size(); i++) {
                    myCities.myBall->Native_Balls_NO[i].destroy();
                    
                }
                
                myCities.myBall->IMM_Balls_BA.resize(0);
                myCities.myBall->IMM_Balls_HS.resize(0);
                myCities.myBall->IMM_Balls_NO.resize(0);
                myCities.myBall->Native_Balls_HS.resize(0);
                myCities.myBall->Native_Balls_NO.resize(0);
                myCities.myBall->Native_Balls_BA.resize(0);
                myCities.bDestry = false;
                
                myClork.bClorkPressed = false;
                year = 2005;
                myClork.angle= 0;
            }

            float a = 30;
            myClork.update(a);
            
        }
            break;
            
        case 2:{
            if (year !=preYear) {
                for (int i=0; i<myCities.myBall->IMM_Balls_BA.size(); i++) {
                    myCities.myBall->IMM_Balls_BA[i].destroy();
                }
                for (int i=0; i<myCities.myBall->IMM_Balls_HS.size(); i++) {
                    myCities.myBall->IMM_Balls_HS[i].destroy();
                }
                for (int i=0; i<myCities.myBall->IMM_Balls_NO.size(); i++) {
                    myCities.myBall->IMM_Balls_NO[i].destroy();
                    
                }
                
                
                for (int i=0; i<myCities.myBall->Native_Balls_BA.size(); i++) {
                    myCities.myBall->Native_Balls_BA[i].destroy();
                    
                    
                }
                for (int i=0; i<myCities.myBall->Native_Balls_HS.size(); i++) {
                    myCities.myBall->Native_Balls_HS[i].destroy();
                    
                }
                for (int i=0; i<myCities.myBall->Native_Balls_NO.size(); i++) {
                    myCities.myBall->Native_Balls_NO[i].destroy();
                    
                }
                
                myCities.myBall->IMM_Balls_BA.resize(0);
                myCities.myBall->IMM_Balls_HS.resize(0);
                myCities.myBall->IMM_Balls_NO.resize(0);
                myCities.myBall->Native_Balls_HS.resize(0);
                myCities.myBall->Native_Balls_NO.resize(0);
                myCities.myBall->Native_Balls_BA.resize(0);
                
            }
            
            myCities.update();
            float a = 255;
            myClork.update(a);
            myBall.update();
        
            preYear = year;
            
        }
            break;
    }
    
   
   
}
//-------------------------------
void scene02::draw(){

    
    switch (myCase) {
        case 0:{
            
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
                
//                rect = font2.getStringBoundingBox("Pop", 0, 0);
//                font2.drawString("Pop:",int(317-rect.getWidth()/2),567);
                rect = font2.getStringBoundingBox("Population: " + myCity.pop, 0, 0);
                font2.drawString("Population: " + myCity.pop, int(317-rect.getWidth()/2), 567+30);
                rect = font2.getStringBoundingBox("Imm Pop Pct: "+ myCity.imm_pct, 0, 0);
                font2.drawString("Imm Pop Pct: " + myCity.imm_pct, int(317-rect.getWidth()/2), 567+60);
                rect = font2.getStringBoundingBox("Imm Job Pct: "+ myCity.imm_pct_job, 0, 0);
                font2.drawString("Imm Job Pct: " + myCity.imm_pct_job, int(317-rect.getWidth()/2), 567+90);
                rect = font2.getStringBoundingBox("Imm pop +/-: "+ myCity.imm_change, 0, 0);
                font2.drawString("Imm pop +/-: " + myCity.imm_change, int(317-rect.getWidth()/2), 567+120);
                
                
            }
            
            font.drawString(ofToString(cityYear), 685, 505);
            
            if (bCitySeclect) {
                select.draw();
            }
            
            
                       
        }
            break;
            
        case 1:{
//            
//            myClork.draw();
//            
//            
//            formula.draw(700, 50);
//
//            
//            ofPushStyle();
//            ofColor myColor;
//            myColor.set(255, 255, 255,100);
//            ofSetColor(myColor);
//            platForm[0].draw(143,326);
//            ofPopStyle();
//            
//            ofPushStyle();
//            myColor.set(255, 255, 255,100);
//            ofSetColor(myColor);
//            platForm[2].draw(338,100);
//            charactor01.draw(420,230);
            //        name01.draw(420, 140);
//            ofPopStyle();
//            
//            ofPushStyle();
//            myColor.set(255, 255, 255,50);
//            ofSetColor(myColor);
//            halo[4].draw(210, 495,halo[3-count].getWidth()-40, halo[3-count].getHeight()-40);
//            cityIcon.draw(250, 430);
            //        chooseCity.draw(250,530);
//            ofPopStyle();
//            
//            myCities.draw();
            
            
            
        }
            break;
        case 2:{
//            myClork.draw();
//            
//            ofPushStyle();
//            ofColor myColor;
//            mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
//            ofSetColor(myColor);
//            platForm[0].draw(143,326);
//            ofPopStyle();
//            
//            platForm[2].draw(338,100);
//            charactor01.draw(420,230);
//            info01.draw(420, 140);
//            
//            
//            ofPushStyle();
//            mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
//            ofSetColor(myColor);
//            
//           
//            halo[4].draw(210, 495,halo[4].getWidth()-40, halo[4].getHeight()-40);
//            cityIcon.draw(250, 430+(5*sin(ofGetElapsedTimef())));
//            ofPopStyle();
//            
//            ofPushStyle();
//            
//            ofRectangle rect;
//            ofSetColor(255, 255, 255);
//            rect = city2.getStringBoundingBox(name, 0, 0);
//            city2.drawString(name, 343-rect.getWidth()/2+2, 526+rect.getHeight()/2-3);
//            ofSetColor(0, 0, 0);
//            rect = city.getStringBoundingBox(name, 0, 0);
//            city.drawString(name, 343-rect.getWidth()/2, 526+rect.getHeight()/2);
//            ofPopStyle();
//            
//            myBall.draw();
//            
        }
            
    }
    
    


  
    
}
//-------------------------------
void scene02::touchDown(int id, int number, float x, float y){
    
    switch (myCase) {
        case 0:{
            if (bCitySeclect) {
                 select.mouseDown(id, number, x, y);
            }
        }
            break;
        
        case 1:{
             myCities.touchDown(id, number, x, y);
        }
            break;
       
        case 2:{
            myClork.touchDown(id, number, x, y);
            
            ofPoint p1;
            p1.set(x,y);
            ofPoint p2;
            p2.set(343,526);
            float dis = p1.distance(p2);
            
            if (dis <ButtonSize) {
                mouseOver = true;
                bPressed = true;
            }else{
                mouseOver = false;
            }
           
        }
            break;
    }
}
//-------------------------------
void scene02::touchMove(int id, int number, float x, float y){
    switch (myCase) {
        case 0:{
            
                if (bCitySeclect) {
                     select.mouseMove(id, number, x, y);
                }
           
            }
            
            break;
        case 1:
            myCities.touchMove(id, number, x, y);
            break;
        case 2:
            
            myClork.touchMove(id, number, x, y);
            ofPoint p1;
            p1.set(x,y);
            ofPoint p2;
            p2.set(343,526);
            float dis = p1.distance(p2);
            
            if (dis <ButtonSize) {
                mouseOver = true;
            }else{
                mouseOver = false;
            }
                       break;
        }
}

//-------------------------------
void scene02::touchUp(int id, int number, float x, float y){
    
    
       
    switch (myCase) {
        case 0:{
            
   
            if (selectRect.inside(x, y)&& bCitySeclect == false) {
                select.width = 0;
                select.height = 0;
                select.pct = 0;
                bCitySeclect = true;
            }
            
            if (bCitySeclect) {
                select.mouseUp(id, number, x, y);
            }
            

           

        }
            break;
        case 1:{
            myCities.touchUp(id, number, x, y);
        }
            break;
            
        case 2:{
            myClork.touchUp(id, number, x, y);
            
            ofPoint p1;
            p1.set(x,y);
            ofPoint p2;
            p2.set(343,526);
            float dis = p1.distance(p2);
            
            if (dis <ButtonSize&& bPressed) {
                mouseOver = false;
                bPressed = false;
                myCase = 1;
            }
            
            else{
                mouseOver = false;
            }
            
            
        }
            break;
            
    }
    
 
    
     
}

