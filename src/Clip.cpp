#include "Clip.h"

Clip::Clip(string path){
    path_ = path;
}

void Clip::makeTexture(){
    player.loadMovie(path_);
    
    //TODO: Make parametric
    int w = 100;
    int h = 100;
    int d = 100;
    
    tex.init(w,h,d);
    vector<ofFloatColor>& mPixels = tex.getBuffer();
    
    for (int i = 0 ; i < d ; i++){
        ofPixelsRef pix = player.getPixelsRef();
        for (int j = 0 ; j < w * h ; j++){
            mPixels[i * (w * h) + j] = pix.getColor(j % h, j / h);
        }
        player.nextFrame();
    }
    tex.update();
}

GLuint Clip::getTextureID(){
    //TODO: Add init checks
    return tex.getTextureID();
}