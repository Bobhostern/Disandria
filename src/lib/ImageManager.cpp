#include "ImageManager.h"
#include "../helplib/Log.h"

RenderWindow* ImageManager::rwindow;
std::map<std::string, disandria::InternalImage> ImageManager::images;

void ImageManager::setRenderWindow(RenderWindow* rwin)
{
    rwindow = rwin;
}

void ImageManager::renderImage(std::string name, disandria::Image im)
{
    disandria::InternalImage imx;
    sf::Sprite spr;
    spr.setTexture(*im.tex);
    imx.spr = spr;
    imx.renderFrames = im.renderFrames;
    images[name] = imx;
}

void ImageManager::renders()
{
    for(std::map<std::string, disandria::InternalImage>::iterator iter = images.begin(); iter != images.end(); iter++) {
        disandria::InternalImage& img(iter->second);
        if(img.renderFrames > 0) {
            rwindow->draw(img.spr);
            img.renderFrames -= 1;
        } else if(img.renderFrames == 0) {
            images.erase(iter);
        } else {
            rwindow->draw(img.spr);
        }
    }
}

sf::Sprite* ImageManager::getImage(std::string image)
{
    if(images.find(image) != images.end()) {
        return &images.find(image)->second.spr;
    } else {
        return NULL;
    }
}

void ImageManager::deleteImage(std::string str)
{
    if(images.find(str) != images.end()) {
        images.erase(images.find(str));
    }
}
