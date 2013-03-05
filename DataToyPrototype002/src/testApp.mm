#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	ofxiPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_LEFT);
	ofSetCircleResolution(100);
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofxAccelerometer.setup();
    
    level =                     1;
    eductionID =                0;
    //sences
    myScene01.setup(level);
    myScene02.setup(level);
    
	// initialize the accelerometer
	balls.assign(10, Ball());
	arrow.loadImage("images/arrow.png");
	arrow.setAnchorPercent(1.0, 0.5);
    
	// initialize all of the Ball particles
	for(int i=0; i<balls.size(); i++){
		balls[i].init(i);
	}
    //background image
    bg3.loadImage("images/bg3.jpg");
    
    myidentity.setup(level, eductionID);
    myScene02.myBall.gravity = ofxAccelerometer.getForce();
}


//--------------------------------------------------------------
void testApp::update() {
    
       
   
    switch (level) {
        case 0:
        {
            
            myScene01.update();
            myidentity.update();
            
            for(int i=0; i < balls.size(); i++){
                balls[i].update();
            }
        }
            break;
            
        case 1:
        {
            myScene02.myBall.educationID = &eductionID;
            myScene02.myBall.gravity = ofxAccelerometer.getForce();
            myScene02.update();
            myidentity.update();
            cout<<myScene02.myClork.bClorkPressed<<endl;
           
        }
            break;
            
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw() {
    
    switch (level) {
        case 0:{
            myScene01.draw();
            myidentity.draw();
        }
            break;
            
       case 1:{
            myScene02.draw();
            myidentity.draw();
            }
            break;
            
        case 2:{
            ofSetColor(255, 255, 255,255);
            bg3.draw(0, 0);
            myidentity.draw();
        }
            break;
    }
    
    ofSetColor(54);
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    for(int i = 0; i< balls.size(); i++){
        balls[i].draw();
    }
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
   
	balls[touch.id].moveTo(touch.x, touch.y);
	balls[touch.id].bDragged = true;
  
    myScene01.touchDown(touch.id, touch.numTouches, touch.x, touch.y);
    myScene02.touchDown(touch.id, touch.numTouches, touch.x, touch.y);
    myidentity.touchDown(touch.id, touch.numTouches, touch.x, touch.y);
    
   
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
   
	balls[touch.id].moveTo(touch.x, touch.y);
	balls[touch.id].bDragged = true;
    

    myScene01.touchMove(touch.id, touch.numTouches, touch.x, touch.y);
    myScene02.touchMove(touch.id, touch.numTouches, touch.x, touch.y);
    myidentity.touchDown(touch.id, touch.numTouches, touch.x, touch.y);
   
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
  
	balls[touch.id].bDragged = false;
  
    myScene01.touchUp(touch.id, touch.numTouches, touch.x, touch.y);
    myScene02.touchUp(touch.id, touch.numTouches, touch.x, touch.y);
    myidentity.touchUp(touch.id, touch.numTouches, touch.x, touch.y);
    
    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){
   
}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotFocus(){
    
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){
    
}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

