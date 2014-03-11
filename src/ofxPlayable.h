//
//  ofxPlayable.h
//  3dtextures
//
//  Created by Omer Shapira on 13/02/14.
//
//

#pragma once
#include "ofMain.h"

class ofxPlayable {
    
    
public:
    bool hasNext();
    ofPixelsRef getPixelsRef();
    int getWidth();
    int getHeight();
    
    void load(string filename); //TODO: Create overloads.
    
private:

};