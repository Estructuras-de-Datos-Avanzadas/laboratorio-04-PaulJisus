#ifndef UTILS_H_
#define UTILS_H_

#include <opencv2/core/mat.hpp>

namespace utils
{
    unsigned int getMortonCodeFromColor(const cv::Vec3b& bgr);
    cv::Vec3b getColorFromMortonCode(const unsigned int mortonCode);
    cv::Mat getDemoPaletteImage(const int widthHeight);
}

#endif
