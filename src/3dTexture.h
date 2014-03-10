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
    void init(bool wrap=false, bool interpolate=true){
        unsigned int lerpMode = interpolate? GL_LINEAR : GL_NEAREST;
        unsigned int wrapMode = wrap ? GL_REPEAT : GL_CLAMP;

        glGenTextures(1, &tex3dId);
        glBindTexture( GL_TEXTURE_3D, tex3dId );
        setParams(lerpMode, lerpMode, wrapMode, wrapMode, wrapMode);
        allocate();
        
        //TODO: Throw if there's no more memory
        
    }
    void allocate(){
        texPixelBuffer.reserve( w * h * d );
        
        
        
        glTexImage3D( GL_TEXTURE_3D, 0, GL_RGBA, w, h, d, 0, GL_RGBA, GL_FLOAT, texPixelBuffer.data() );
    }
    
    void setParams(unsigned int minMode,
                   unsigned int magMode,
                   unsigned int wrapS,
                   unsigned int wrapT,
                   unsigned int wrapR){
        glTexParameteri( GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, minMode);
        glTexParameteri( GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, magMode);
        glTexParameterf( GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, wrapS);
        glTexParameterf( GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, wrapT);
        glTexParameterf( GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, wrapR);
    }
    
};