//
//  Timeline.cpp
//  3dtextures
//
//  Created by Omer Shapira on 10/03/14.
//
//

#include "Timeline.h"

void Timeline::setup(){
    clip_shader.load("shaders/clip_shader.vert", "shaders/3d_texture_map.frag");
    
    //temp
    work_area = ofRange_<int>(0,99);
    cursor.range.min = 0;
    cursor.range.max = 14;
    
    plane.set(640, 480, 20, 20);
    plane.setPosition(0, 0, -modelDepth);
    box.set(640, 480, 600);
    box.setPosition(0, 0, -modelDepth * 0.5);
    
    cam.enableMouseInput();
    
    initGui();
}

void Timeline::draw(){
    cam.begin();
    ofPushMatrix();
    {
        ofTranslate(0, 100);
        drawMonitors();
    }
    ofPopMatrix();
   cam.end();
    
    drawGUI();
}

void Timeline::drawMonitors(){
    glPushAttrib(GL_TEXTURE_3D);
    glEnable(GL_TEXTURE_3D);
    
    clip_shader.begin();
    clip_shader.setUniform1f("modelDepth", modelDepth);
    clip_shader.setUniform1f("amtModifyPosition", 1.);
    clip_shader.setUniformTexture("tex", GL_TEXTURE_3D, (current_clip->first)->getTextureID(), 0);
    clip_shader.setUniform2f(
                             "range",
                             ofMap(cursor.range.min, (current_clip->second).min, (current_clip->second).max, 0, 1),
                             ofMap(cursor.range.max, (current_clip->second).min, (current_clip->second).max, 0, 1)
                             );
    
//    ofSetColor(ofFloatColor(1.,1.));
    
    plane.drawFaces();
    
    clip_shader.end();
    
    box.drawWireframe();
    glPopAttrib();
}

void Timeline::drawGUI(){
//    ofPushStyle();
//    ofEnableAlphaBlending();
    ofPushMatrix();
    {
        int w = ofGetWidth();
        int h = ofGetHeight();
        
        guiCursor.draw();
        guiFrame.draw();
        
        
        
    }
    ofPopMatrix();
//    ofPopStyle();
    
}

void Timeline::initGui(){
    int w =ofGetWidth();
    int h = ofGetHeight();
    
    guiCursor.setStrokeColor(ofColor(230,230,0,230));
    guiCursor.setFillColor(ofColor(230,230,0,90));
    guiCursor.setFilled(false);
    guiCursor.rectangle(ofPoint(w * .1, h * .8), w * .05, h * .2);
    
    
    guiFrame.setFilled(true);
    guiFrame.setFillColor(ofColor(128, 128, 128, 128));
    guiFrame.rectangle(w * .1, h * .85, w * .8, h * .08);

}


int Timeline::add(TClip clip){
    sequence.push_back(clip);
    if (sequence.size() == 1){
        current_clip = &(sequence[0]);
    }
    //TODO: Make this a status message
    return 0;
}

void Timeline::play(){
    play_speed_ = 1;
}

void Timeline::pause(){
    play_speed_ = 0;
}

void Timeline::changeSpeed(int delta){
    play_speed_ += delta;
}

void Timeline::update(){


    cursor.increment(play_speed_);
    if (! work_area.contains(cursor.range)){
        //FIXME: This assumes that the work area is never greater than the curor.
        cursor.move(work_area.min);
    }
    int w = ofGetWidth();
    int h = ofGetHeight();
    float progress = ofMap(cursor.range.min, (current_clip->second).min, (current_clip->second).max, 0, 1);
    float span = cursor.range.span() * 1.0/work_area.span();
    guiCursor.clear();
    guiCursor.rectangle(ofPoint(w * (progress * 0.8 + 0.08), h * .8), w * span, h * .15);
    cam.orbit(orbit, -20, 1000, box);
    orbit -=1;
}

void Timeline::setWorkArea(int inPoint, int outPoint){
    work_area.set(inPoint, outPoint);
}

void Timeline::setCursorSpan(int span){
    cursor.range.max = cursor.range.min + span - 1;
}

void Timeline::toggleOrtho(){
    if (mode == 0) {
//        cam.enableOrtho();
//        cam.orbit(-90, 0, 1000, box);
        mode = 1;
    } else {
        mode = 0;
    }
}