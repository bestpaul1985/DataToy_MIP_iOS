//
//  identity.cpp
//  DataToyPrototype002
//
//  Created by PengCheng on 3/2/13.
//
//

#include "identity.h"


identity::identity(){


}

//-------------------------------------------
void identity::setup(int &level, int &educationID){
    myLevel =                  &level;
    myEducation=               &educationID;
    dis =                       0;
    touchId =                   0;
    startTime =                 ofGetElapsedTimeMillis();
    delay =                     2500;
    touchSize =                 -1;
    
    bFail =                     false;
    bSound=                     true;
    bMultiTouches =             false;
    bDelay =                    false;

    //font
    font.loadFont("fonts/[z] Arista.ttf", 40);
    //sounds
    sound1.loadSound("sounds/Pickup_Key.wav");
    sound1.setMultiPlay(false);
    sound2.loadSound("sounds/failing.wav");
    sound2.setMultiPlay(false);
    
    //img
    for (int i =0; i<3; i++) {
        circle[i].loadImage("images/c0" + ofToString(i+1)+".png");
    }

    for (int i=0; i< num; i++) {
        touches[i].set(0, 0);
    }
    
}
//-------------------------------------------
void identity::update(){
    if (touchSize>1 && bDelay == false) {
        
        
        for (int i = touchSize-1; i>=1; i--) {
            for (int j = 0; j<touchSize-1; j++) {
                
                if (i!=j) {
                    dis = touches[i].distance(touches[j]);
                    
                    if (dis>250&&dis<280) {
                        bDelay = true;
                        startTime = ofGetElapsedTimeMillis();
                        cout<<dis<<endl;
                    }
                }
            }
        }
    }
    
    
    float timer = ofGetElapsedTimeMillis() - startTime;
    
    
    if (bDelay == true && timer > delay) {
        
        if(touchSize<2){
            bFail = true;
        }else{
            
            for (int i = touchSize-1; i>=1; i--) {
                for (int j = 0; j<touchSize-1; j++) {
                    
                    if (i!=j) {
                        dis = touches[i].distance(touches[j]);
                        cout<<dis<<endl;
                        if (dis>250 &&dis<280) { //declear charaters
                            
                            *myLevel = 1;
                            *myEducation = 0;
                            if (bSound) {
                                 sound1.play();
                                bSound = false;
                            }
                           
                            return;
                        }else{
                            
                            if (bSound) {
                                sound2.play();
                                bSound = false;
                            }
                        }
                    }
                }
            }
        }
        
        bDelay = false;
        
    }

}
//-------------------------------------------
void identity::draw(){
    
    if (bDelay) {
        
        ofPushMatrix();
        ofTranslate(touches[0].x, touches[0].y);
        ofRotateZ(RAD_TO_DEG*ofGetElapsedTimef());
        ofTranslate(100*sin(ofGetElapsedTimef()*3)-200, 0);
        ofRotateZ(RAD_TO_DEG*ofGetElapsedTimef()*2);
        ofSetColor(255, 255, 255);
        circle[0].draw(0,0);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(touches[0].x, touches[0].y);
        ofRotateZ(120+RAD_TO_DEG*ofGetElapsedTimef());
        ofTranslate(100*sin(ofGetElapsedTimef()*3)-200, 0);
        ofRotateZ(RAD_TO_DEG*ofGetElapsedTimef()*2);
        ofSetColor(255, 255, 255);
        circle[1].draw(0,0);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(touches[0].x, touches[0].y);
        ofRotateZ(240+RAD_TO_DEG*ofGetElapsedTimef());
        ofTranslate(100*sin(ofGetElapsedTimef()*3)-200, 0);
        ofRotateZ(RAD_TO_DEG*ofGetElapsedTimef()*2);
        ofSetColor(255, 255, 255);
        circle[2].draw(0,0);
        ofPopMatrix();
    }

}
//-------------------------------------------
void identity::touchDown(int id, int number, float x, float y){
    ofPoint tmp;
    tmp.set(x, y);
    touches[id] = tmp;
    touchSize = number;
}
//-------------------------------------------
void identity::touchMove(int id, int number, float x, float y){
    ofPoint tmp;
    tmp.set(x, y);
    touches[id] = tmp;
    touchSize = number;
}
//-------------------------------------------
void identity::touchUp(int id, int number, float x, float y){
    ofPoint tmp;
    tmp.set(x, y);
    touches[id] = tmp;
    touchSize = number;
    
    
    touchSize = number -1;
    
    if (id == 0) {
        bDelay = false;
        bSound = true;
    }
    
}
