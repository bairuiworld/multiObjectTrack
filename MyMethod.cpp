
#include "MyMethod.h"

MyMethod::MyMethod(const VideoFolder &videoFolder, const Arguments& arguments)
    : Method(videoFolder)
{
    // TODO Initialization

    // In the YourMethod class, you can use
    //   -videoFolder : get the path of input and binary frames
    //      with opencv : cv::imread(videoFolder.inputFrame(t));
    //   -frameSize : get the size (width, height)
}

MyMethod::MyMethod(const VideoFolder &videoFolder):Method(videoFolder){
    bs = new BackgroundSubtract();
    cv::Mat frame = cv::imread(videoFolder.firstFrame());
    cv::Mat gray;
    cv::cvtColor(frame,gray,cv::COLOR_BGR2GRAY);
    bs->init(gray);
   //cv::namedWindow("binaryFrame");
   // cv::imshow("binaryFrame",gray);
}

MyMethod::~MyMethod() {
    // TODO Cleaning
}

void MyMethod::train(const uint fromIdx, const uint toIdx) {
    // TODO Training
    // If your method requires no special code for training, we call detect
    detect(1, toIdx, toIdx + 1);
}

void MyMethod::detect(const uint fromIdx, const uint toIdx, const uint startSavingAt) {
    /* You can work the way you want. This code shows how to iterate over all the pixels */
    BinaryFrame binaryFrame(frameSize, CV_8UC1);
    for (uint t = fromIdx; t < toIdx; ++t) {
        //std::cout<<"train "<<t<<"....."<<std::endl;
        //binaryFrame = BLACK;
        InputFrame inputFrame = cv::imread(videoFolder.inputFrame(t));
        cv::Mat gray;
        cv::cvtColor(inputFrame,gray,cv::COLOR_BGR2GRAY);
        bs->subtract(gray,binaryFrame);
        //cv::imshow("binaryFrame",binaryFrame);
        //cv::waitKey(1);

        /*
        BinaryIterator itBinary = binaryFrame.begin();
        InputIterator itEnd = inputFrame.end();
        for (InputIterator itInput = inputFrame.begin(); itInput != itEnd; ++itInput, ++itBinary) {
            //const cv::Vec3d pixel = *itInput;
            //const uchar red = pixel[0];
            //const uchar green = pixel[1];
            //const uchar blue = pixel[2];
            //
            //
            //if (...) {
            //	*itBinary = WHITE;
            //}
        }
        */

        if (t >= startSavingAt) {
            //cout<<videoFolder.binaryFrame(t)<<endl;
            //cv::medianBlur(binaryFrame, binaryFrame, 5);
            cv::imwrite(videoFolder.binaryFrame(t), binaryFrame);
        }

        // Update model
        //
    }
}
