#include "Quantizer.h"

OctreeQuantizer::OctreeQuantizer()
{
    for(int i=0; i<8; i++){
        levels[i].reserve(8);
        for(int j = 0 ; j<8; j++){
            levels[i][j]=nullptr;
        }
    }
    root= new OctreeNode(0,this);
}

void OctreeQuantizer::add_level_node(int level,OctreeNode *node)
{
    levels[level].push_back(node);
}

int OctreeQuantizer::get_max_depth()
{
    return max_depth;
}

void OctreeQuantizer::add_color(Color color)
{
    root->add_color(color, 0, this);
}
