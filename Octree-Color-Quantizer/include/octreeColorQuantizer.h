#ifndef OCTREECOLORQUANTIZER_H
#define OCTREECOLORQUANTIZER_H

#include "octree.h"

class OctreeColorQuantizer
{
    public:
        OctreeColorQuantizer(const cv::Mat& src);
        void setPaletteSize(const unsigned long paletteSize);
        void resetPalette();
        cv::Mat getQuantizedImage(const cv::Mat& src) const;
        cv::Mat getPaletteImage() const;
    private:
        impl::Octree m_octree;
};


#endif
