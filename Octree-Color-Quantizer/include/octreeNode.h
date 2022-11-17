#ifndef OCTREENODE_H_
#define OCTREENODE_H_

#include <opencv2/core/matx.hpp>

namespace impl
{
    struct OctreeNode
    {
        OctreeNode();
        ~OctreeNode();
        void addChild(const uchar childIdx);
        void addColor(const cv::Vec3b& color);
        cv::Vec3b getAverageColor() const;
        void getLeafsColor(std::vector<cv::Vec3b>& colors) const;
        std::array<OctreeNode*, 8> m_childPtrs;
        unsigned long m_colorCount;
        cv::Vec3f m_colorSum;
        uchar m_activeChildCount;
        bool m_leaf;
    };
}

#endif
