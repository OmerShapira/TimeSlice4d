//
//  RangedCursor.h
//  3dtextures
//
//  Created by Omer Shapira on 10/03/14.
//
//

#pragma once
#include "ofRange.h"

class RangedCursor {
    
public:
    ofRange_<int> range;
    
    void increment(int inc = 1){
        range = inc + range;
    }
    int getPosition(){
        return range.min;
    }
    void move(int amount){
        range = amount + (range - range.min);
    }
};