#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofLog(OF_LOG_VERBOSE);
    filename  = "/Volumes/SSD/Misc/Topgun.mov";
    player.loadMovie(filename);
    
    int w = 100;
    int h = 100;
    int d = 100;
    
    int arraySize = w * h * d;
    std::vector<ofFloatColor> mPixels(arraySize);
    
    for (int i = 0 ; i < d ; i++){
        ofPixelsRef pix = player.getPixelsRef();
        for (int j = 0 ; j < w * h ; j++){
            mPixels[i * (w * h) + j] = pix.getColor(j % h, j / h);
        }
        player.nextFrame();
    }
    
    glGenTextures(1, &m3dTex);
    glBindTexture( GL_TEXTURE_3D, m3dTex );
    glTexParameteri( GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameterf( GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf( GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf( GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    glTexImage3D( GL_TEXTURE_3D, 0, GL_RGBA, w, h, d, 0, GL_RGBA, GL_FLOAT, mPixels.data() );
    
    plane.set(640, 480, 20, 20);
    plane.setPosition(0, 0, -400);
    box.set(640, 480, 400);
    box.setPosition(0, 0, -400);
    
    shader.load("shaders/shader");
    cam.enableMouseInput();
}

//--------------------------------------------------------------
void testApp::update(){
//    cout << cam.get
}

//--------------------------------------------------------------
void testApp::draw(){
    glEnable(GL_TEXTURE_3D);
    cam.begin();
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniformTexture("tex", GL_TEXTURE_3D, m3dTex, 0);
    ofSetColor(ofFloatColor(1.,1.));
    plane.drawFaces();

    shader.end();
    cam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
