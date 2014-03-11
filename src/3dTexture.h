//
//  3dTexture.h
//  3dtextures
//
//  Created by Omer Shapira on 13/02/14.
//
//

#pragma once
#include "ofMain.h"

class texture3D {
    GLuint tex3dId;
    int w,h,d;
    vector<ofFloatColor> texPixelBuffer;
    
public:
    
    GLuint getTextureID();
    
    void init(int w_, int h_, int d_, bool wrap=false, bool interpolate=true);
    
    void allocate();
    
    void update();
    
    vector<ofFloatColor>& getBuffer();
    
    void setParams(unsigned int minMode = GL_LINEAR,
                   unsigned int magMode = GL_LINEAR,
                   unsigned int wrapS = GL_REPEAT,
                   unsigned int wrapT = GL_REPEAT,
                   unsigned int wrapR = GL_REPEAT);
};