#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetBackgroundColor(0);
	ofSetWindowPosition(2049,0);
        payload = make_shared<ofxGraycode::Payload::Graycode>();
        payload->init(4096,1024);
	encoder.init(payload);

	//set the oF window size to match the payload size
	ofSetWindowShape(payload->getWidth(), payload->getHeight());

	//connect to server
	client.setup("localhost", SERVER_PORT);
	receiver.setup( 4321 );
	//show first message
	encoder >> output;
}

//--------------------------------------------------------------
void testApp::update(){
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		if ( strcmp( m.getAddress().c_str(), "/reset" ) == 0 )
		{
			encoder.reset();
			encoder >> output;
		}
		else
		{
			if (!(encoder >> output)) //returns false if no remaining frames
		                ofLogNotice() << "End of frames";
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	output.draw(0,0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 'r') {
		encoder.reset();
		ofxOscMessage msg;
		msg.setAddress("/clear");
		client.sendMessage(msg);
		encoder >> output;
	} else {
		//feed out a new frame
		//returns false if no new frames
 		if (!(encoder >> output)) //returns false if no remaining frames
			ofLogNotice() << "End of frames";

		ofxOscMessage msg;
		msg.setAddress("/capture");
		client.sendMessage(msg);
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
