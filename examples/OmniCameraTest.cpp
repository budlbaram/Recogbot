#include "devices/OmniCamera.h"
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace Recogbot;
using namespace std;

void main(void) {

	OmniCamera omnicam;
	cout << omnicam.connect();
	IplImage *frame=cvCreateImage(cvSize(omnicam.getWidth(),omnicam.getHeight()),8,3);
	cvNamedWindow("w");
	while(omnicam.isConnected()) {
		omnicam.grab(frame);
		cvShowImage("w",frame);
		cvWaitKey(10);
	}
}
