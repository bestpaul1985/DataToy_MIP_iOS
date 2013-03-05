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
    bg2.loadImage("images/bg2.png");
    cityIcon.loadImage("images/cityIcon.png");
    charactor01.loadImage("images/character01.png");
    name01.loadImage("images/name01.png");
    chooseCity.loadImage("images/choosecity.png");
    formula.loadImage("images/formula.png");
    city.loadFont("fonts/[z] Arista light.ttf", 28);
    city2.loadFont("fonts/[z] Arista ExtraFilled.ttf", 27);
    for (int i =0; i<3; i++) {
        platForm[i].loadImage("images/c0" + ofToString(i+1)+".png");
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
    cout = 0;
    name = "ok";
    mouseOver = false;
    bPressed = false;
    year = 2005;
    ButtonSize = 70;
    
    //stopClork
    myClork.setup(year);
    myBall.setup();
}
//-------------------------------
void scene02::update(){
    
    
    switch (myCase) {
      
            
        case 0:{
            if (bAddOutwardCircle) {
                VF.addOutwardCircle(AddOutwardCirclePos.x,AddOutwardCirclePos.y, 180, 5) ;
                VF.addOutwardCircle(AddOutwardCirclePos.x+150,AddOutwardCirclePos.y, 180, 5) ;
            }
            
            
            
            
            for (int i = 0; i < particles.size(); i++){
                particles[i].resetForce();
            }
            
            for (int i = 0; i < particles.size(); i++){
                
                particles[i].addAttractionForce(-500, particles[i].initialY, 2000, 1.1);
                
                ofVec2f frc;
                frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
                particles[i].addForce(frc.x, frc.y);
                
                for (int j = 0; j < i; j++){
                    particles[i].addRepulsionForce(particles[j], 50, 0.4);
                }
            }
            
            for (int i = 0; i < particles.size(); i++){
                
                particles[i].addDampingForce();
                particles[i].update();
                
                if (particles[i].pos.x < 0) {
                    particles[i].setInitialCondition(ofGetWidth(), ofRandom(ofGetHeight()), -10, 0);
                    
                }
            }
            
            VF.fadeField(0.97f);
            
            //stopClork
            float a = 30;
            myClork.update(a);
           
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
            }

            float a = 30;
            myClork.update(a);
            
        }
            break;
            
        case 2:{
            myCities.update();
            float a = 255;
            myClork.update(a);
            myBall.update();
        }
            break;
    }

   
}
//-------------------------------
void scene02::draw(){
    ofSetColor(255, 255, 255,255);
    bg2.draw(0, 0);
    
    switch (myCase) {
        case 0:{
            
           
            myClork.draw();

            ofPushStyle();            
            ofColor myColor;
            mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
            ofSetColor(myColor);
            platForm[0].draw(143,326);
           
            ofPopStyle();
            
            platForm[2].draw(338,100);
            charactor01.draw(420,230);
            name01.draw(420, 140);
            
            
            ofPushStyle();
            mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
            ofSetColor(myColor);
            
            if (ofGetElapsedTimeMillis()-startTime > 120) {
                startTime = ofGetElapsedTimeMillis();
                cout ++;
                if (cout>3) {
                    cout = 0;
                }
            }
            
            halo[cout].draw(210, 495,halo[3-cout].getWidth()-40, halo[3-cout].getHeight()-40);
            cityIcon.draw(250, 430+(5*sin(ofGetElapsedTimef()*10)));
            chooseCity.draw(250,530);
            ofPopStyle();
            
            //    VF.draw();
            
            for (int i = 0; i < particles.size(); i++){
                particles[i].draw();
            }

        }
            break;
            
        case 1:{
            
            myClork.draw();
            
            
            formula.draw(700, 50);

            
            ofPushStyle();
            ofColor myColor;
            myColor.set(255, 255, 255,100);
            ofSetColor(myColor);
            platForm[0].draw(143,326);
            ofPopStyle();
            
            ofPushStyle();
            myColor.set(255, 255, 255,100);
            ofSetColor(myColor);
            platForm[2].draw(338,100);
            charactor01.draw(420,230);
            //        name01.draw(420, 140);
            ofPopStyle();
            
            ofPushStyle();
            myColor.set(255, 255, 255,50);
            ofSetColor(myColor);
            halo[4].draw(210, 495,halo[3-cout].getWidth()-40, halo[3-cout].getHeight()-40);
            cityIcon.draw(250, 430);
            //        chooseCity.draw(250,530);
            ofPopStyle();
            
            myCities.draw();
            
            
            
        }
            break;
        case 2:{
            myClork.draw();
            
            ofPushStyle();
            ofColor myColor;
            mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
            ofSetColor(myColor);
            platForm[0].draw(143,326);
            ofPopStyle();
            
            platForm[2].draw(338,100);
            charactor01.draw(420,230);
            name01.draw(420, 140);
            
            
            ofPushStyle();
            mouseOver ? myColor.set(255, 255, 255,150) : myColor.set(255, 255, 255, 250);
            ofSetColor(myColor);
            
           
            halo[4].draw(210, 495,halo[4].getWidth()-40, halo[4].getHeight()-40);
            cityIcon.draw(250, 430+(5*sin(ofGetElapsedTimef())));
            ofPopStyle();
            
            ofPushStyle();
            
            ofRectangle rect;
            ofSetColor(255, 255, 255);
            rect = city2.getStringBoundingBox(name, 0, 0);
            city2.drawString(name, 343-rect.getWidth()/2+2, 526+rect.getHeight()/2-3);
            ofSetColor(0, 0, 0);
            rect = city.getStringBoundingBox(name, 0, 0);
            city.drawString(name, 343-rect.getWidth()/2, 526+rect.getHeight()/2);
            ofPopStyle();
            
            myBall.draw();
            
        }
            
    }
    
    


  
    
}
//-------------------------------
void scene02::touchDown(int id, int number, float x, float y){
    
    switch (myCase) {
        case 0:{
            if (id == 0) {
                AddOutwardCirclePos.set(x, y);
                bAddOutwardCircle = true;
            }
            
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
            if (id == 0) {
                AddOutwardCirclePos.set(x, y);
            }
            
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
            if (id == 0) {
                bAddOutwardCircle = false;
            }
            
            ofPoint p1;
            p1.set(x,y);
            ofPoint p2;
            p2.set(343,526);
            float dis = p1.distance(p2);
            
            if (dis <ButtonSize&& bPressed) {
                mouseOver = false;
                bPressed = false;
                myCase = 1;
                myCities.setup(particles,myCase,name,year,myBall);
            }
            
            else{
                mouseOver = false;
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

