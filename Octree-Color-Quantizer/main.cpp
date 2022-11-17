#include "Octree.h"
#include "octreeColorQuantizer.h"
#include "octreeNode.h"
#include "utils.h"
#include <opencv2/highgui.hpp>

int main(int /*argc*/, char** /*argv*/)
{
    const cv::Mat demoPaletteImg = utils::getDemoPaletteImage(600);

    OctreeColorQuantizer octreeColorQuantizer(demoPaletteImg);

    const unsigned int paletteSize = 128;
    octreeColorQuantizer.setPaletteSize(paletteSize);

    cv::Mat originalVsQuantized = cv::Mat::zeros(demoPaletteImg.rows, demoPaletteImg.cols * 2 + 1, demoPaletteImg.type());
    demoPaletteImg.copyTo(originalVsQuantized(cv::Rect({0, 0}, demoPaletteImg.size())));
    octreeColorQuantizer.getQuantizedImage(demoPaletteImg).copyTo(originalVsQuantized(cv::Rect({demoPaletteImg.cols + 1, 0}, demoPaletteImg.size())));

    cv::imshow("Original (izquierda) vs Quantized " + std::to_string(paletteSize) + " colors (derecha)", originalVsQuantized);
    cv::waitKey();

    return 0;
}
