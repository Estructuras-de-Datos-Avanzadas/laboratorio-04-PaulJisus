#include "Color.h"

Color::Color() = default;

Color::Color(int red=0,int green=0,int blue=0,int alpha=1)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

Color::~Color() = default;
