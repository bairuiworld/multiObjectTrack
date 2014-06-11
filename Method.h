#ifndef METHOD_H
#define METHOD_H

#include <string>

#include <cv.h>
#include <highgui.h>

#include "types.h"
#include "VideoFolder.h"

class Method
{
    public:
        Method(const VideoFolder &videoFolder);
        virtual ~Method();

        virtual void train(const uint fromIdx, const uint toIdx) = 0;
        virtual void detect(const uint fromIdx, const uint toIdx, const uint startSavingAt) = 0;

        void process();

    protected:
        const VideoFolder &videoFolder;

        cv::Size frameSize;

    private:
        void process(const uint fromIdx, const uint toIdx);
};


#endif // METHOD_H
