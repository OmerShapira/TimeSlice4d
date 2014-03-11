//
//  Clip.h
//  3dtextures
//
//  Created by Omer Shapira on 10/03/14.
//
//

#pragma once
#include <iostream>
#include "ofRange.h"
//#include "ofxPlayable.h"
#include "RangedCursor.h"
#include "3dTexture.h"

class Clip {
    
    texture3D tex;
    string path_;
    ofVideoPlayer player;
    
public:
    
    Clip(string path);
    
    void makeTexture();
    GLuint getTextureID();
};