#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto span = 45;
	auto radius = span * 0.5;
	for (int x = radius; x < ofGetWidth(); x += span) {

		for (int y = radius; y < ofGetHeight(); y += span) {

			auto noise_value = ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005);
			auto deg_start = 0;

			if (noise_value < 0.2) { deg_start = 0; }
			else if (noise_value < 0.25) { deg_start = ofMap(noise_value, 0.2, 0.25, 0, 90); }
			else if (noise_value < 0.45) { deg_start = 90; }
			else if (noise_value < 0.50) { deg_start = ofMap(noise_value, 0.45, 0.50, 90, 180); }
			else if (noise_value < 0.70) { deg_start = 180; }
			else if (noise_value < 0.75) { deg_start = ofMap(noise_value, 0.7, 0.75, 180, 270); }
			else if (noise_value < 0.95) { deg_start = 270; }
			else if (noise_value < 1.0) { ofMap(noise_value, 0.95, 1.0, 270, 360); }
			
			ofNoFill();
			ofBeginShape();
			for (int deg = deg_start; deg <= deg_start + 270; deg++) {

				ofVertex(x + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD));
			}
			ofEndShape();

			ofFill();
			ofDrawCircle(glm::vec2(x + radius * cos(deg_start * DEG_TO_RAD), y + radius * sin(deg_start * DEG_TO_RAD)), 5);
			ofDrawCircle(glm::vec2(x + radius * cos((deg_start + 270) * DEG_TO_RAD), y + radius * sin((deg_start + 270) * DEG_TO_RAD)), 5);
		}
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}