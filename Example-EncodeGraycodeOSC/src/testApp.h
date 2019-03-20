#pragma once

#include "ofMain.h"
#include "ofxGraycode.h"
#include "ofxOsc.h"

#define SERVER_PORT 5588

using namespace ofxGraycode;

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofImage output;
	shared_ptr<Payload::Graycode> payload;
	Encoder encoder;
	ofxOscSender client;
};
