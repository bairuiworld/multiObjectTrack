#ifndef MYMETHOD_H
#define MYMETHOD_H

#include "Method.h"
#include "BackgroundSubtract.h"


class MyMethod : public Method
{
    public:
        MyMethod(const VideoFolder &videoFolder, const Arguments& arguments);
        MyMethod(const VideoFolder &videoFolder);

        ~MyMethod();

        virtual void train(const uint fromIdx, const uint toIdx);
        virtual void detect(const uint fromIdx, const uint toIdx, const uint startSavingAt);

    private:
        // TODO Create constants and variables
        BackgroundSubtract *bs;
};

#endif // MYMETHOD_H
