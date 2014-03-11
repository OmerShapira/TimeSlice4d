#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofLog(OF_LOG_VERBOSE);
    ofSetBackgroundAuto(true);
    ofSetBackgroundColor(0);
    ofSetFrameRate(24);
    
    timeline.setup();
    
    filename  = "/Volumes/SSD/Misc/Topgun.mov";
    clip_ptr = ofPtr<Clip>(new Clip(filename));
    clip_ptr->makeTexture();

    timeline.add(TClip(clip_ptr, ofRange_<int>(0, 99)));
    
//    shader.load("shaders/3d_texture_mesh.vert", "shaders/3d_texture_map.frag");

    timeline.play();
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    timeline.setCursorSpan((int) ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 99));
    timeline.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableDepthTest();
    timeline.draw();
    ofDisableDepthTest();
 
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'j':
            timeline.changeSpeed(-1);
            break;
        case 'k':
            timeline.pause();
            break;
        case 'l':
            timeline.changeSpeed(1);
            break;
        case 'o':
            timeline.toggleOrtho();
            break;

        default:
            break;
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
