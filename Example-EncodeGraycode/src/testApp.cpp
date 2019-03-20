#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//avoid output video tearing
	ofSetVerticalSync(true);
	
	//initialise everything
    //auto p = ofxGraycode::Payload::Graycode();
    payload = make_shared<ofxGraycode::Payload::Graycode>();
    payload->init(1920, 1080);
	encoder.init(payload);

	//load first frame
	encoder >> output;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	output.draw(0,0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 'r')
		encoder.reset();
	if (key == 'f')
		ofToggleFullscreen();
	else {
		//feed out a new frame
		//returns false if no new frames
 		if (!(encoder >> output))
			ofLogNotice() << "End of frames";
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
