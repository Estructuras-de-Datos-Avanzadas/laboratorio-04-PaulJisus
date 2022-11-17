#ifndef OCTREE_H_
#define OCTREE_H_

#define MAX_DEPTH 8

#include "octreeNode.h"

namespace impl
{
    class Octree
    {
        public:
            void insertColor(const cv::Vec3b& color);
            cv::Vec3b getQuantizedColor(const cv::Vec3b& color) const;
            void makePalette(const unsigned long paletteSize);
            void resetPalette();
            std::vector<cv::Vec3b> getPaletteColors() const;

        private:
            OctreeNode m_root;
            std::array<std::vector<OctreeNode*>, MAX_DEPTH> m_nodePtrsArray;
            bool m_nodesSorted;
            void insertColor(const unsigned int mortonCode, OctreeNode& node, const uchar currentDepth = 0);
            cv::Vec3b getQuantizedColor(const unsigned int mortonCode, const OctreeNode& node, const uchar currentDepth = 0) const;
    };
}

#endif
