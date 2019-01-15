#include <opencv2/opencv.hpp>
#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;
using namespace cv;

#define GAUSS_R 4

void bilateralFilter(const Mat & input, Mat & output, int r, double sI, double sS);

int main() {
	double sI, sS;
	sI = 75.0;
	sS = 75.0;

	Mat input = imread("test_pic.png", IMREAD_GRAYSCALE);
	// Create output Mat
	Mat output_own(input.rows, input.cols, CV_8UC1);
	Mat output_cv;
	// Own bilateral filter (input,output,filter_half_size,sigmaI,sigmaS)
	bilateralFilter(input, output_own, GAUSS_R, sI, sS);
	// OpenCV bilateral filter
	clock_t start_s = clock();
	cv::bilateralFilter(input, output_cv, 2 * GAUSS_R + 1, sI, sS);
	clock_t stop_s = clock();
	cout << "Time for the CPU: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << " ms" << endl;
	// Display own bf image
	imshow("Image1", output_own);
	// Display opencv bf image
	imshow("Image2", output_cv);
	cv::waitKey();
}