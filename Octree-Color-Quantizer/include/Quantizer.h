#ifndef QUANTIZER_H_
#define QUANTIZER_H_

#include "Color.h"
#include "Octree.h"

using namespace std;
class OctreeNode;
class Color;

class OctreeQuantizer{
    vector<OctreeNode*> levels[8];
    OctreeNode* root;
public:
    OctreeQuantizer();
    void add_level_node(int level,OctreeNode *node);
    int get_max_depth();
    void add_color(Color color);
};

#endif
