#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;


Mat disparity(Mat img0, Mat img1, int win, int dmax) {
	int H = img0.size().height;
	int W = img0.size().width;
    Mat disp = Mat::zeros(H, W, CV_32SC1);

	for(int y=0; y < H; ++y){
		for(int x=0; x < W; ++x){
			int melhor_d = 0;
			int menor_SAD = INT_MAX;
			for(int d=0; d <= dmax; ++d){
				int SAD = 0;
				for(int u = -win; u <= win; ++u){
					for(int v = -win; v <= win; ++v){
						int esq = img0.at<uchar>(y+u, x+v);
						int dir = img1.at<uchar>(y+u, x+v-d);
						SAD += abs(esq - dir);
					}
				}
				if(SAD < menor_SAD){
					menor_SAD = SAD;
					melhor_d = d;
				}
			}
			disp.at<int>(y,x) = melhor_d;
		}
	}
	return disp;
}

int main( int argc, const char** argv ) {

    Mat img0 = imread(samples::findFile(argv[1]), IMREAD_GRAYSCALE);
    Mat img1 = imread(samples::findFile(argv[2]), IMREAD_GRAYSCALE);

    if(img0.empty()) {
        std::cerr << "Cannot read image file" << argv[1] << std::endl;
        return -1;
    }
    if(img1.empty()) {
        std::cerr << "Cannot read image file" << argv[2] << std::endl;
        return -1;
    }

	int maskHalfSize = atoi(argv[3]);
	int dmax = atoi(argv[4]);

	Mat disp = disparity(img0, img1, maskHalfSize, dmax);

	Mat dispDisplay;
	double maxValue, minValue;
	minMaxLoc(disp, &minValue, &maxValue);
	cout << minValue << " " << maxValue << endl;
	double s = 255.0/(maxValue-minValue);
	disp.convertTo(dispDisplay, CV_8U, s, -minValue*s);
	cout << disp.size().height << endl;

    namedWindow("image", 0);
	imshow("image", dispDisplay);
    waitKey();

    return 0;
}
