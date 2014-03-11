//
//  Timeline.h
//  3dtextures
//
//  Created by Omer Shapira on 10/03/14.
//
//

#pragma once
#include <iostream>
#include "ofMain.h"
#include "RangedCursor.h"
#include "Clip.h"

typedef std::pair< ofPtr<Clip>, ofRange_<int> > TClip;

class Timeline {
    
public:
    
    void setup();
    void draw();
    
    void play();
    void pause();
    void update();
    
    void changeSpeed(int delta);
    void setWorkArea(int inPoint, int outPoint);
    void setCursorSpan(int span);
    int add(TClip clip);
    
    void toggleOrtho();
    
private:
    void initGui();
    void drawMonitors();
    void drawGUI();

    
    int play_speed_;
    
    int mode;
    
    ofRange_<int> work_area;
    RangedCursor cursor;
    //For now, we'll use one video channel
    vector<TClip> sequence;
    ofShader clip_shader;
    
    ofPlanePrimitive plane;
    ofBoxPrimitive box;
    
    TClip* current_clip;
    
    float modelDepth = 600.0;
    float orbit;
    ofEasyCam cam;
    
    ofPath guiCursor;
    ofPath guiFrame;
    
};
