#ifndef RESULT_H
#define RESULT_H
#include <string>
#include <vector>

class Result
{
public:
    Result(unsigned int TP,
           unsigned int FP,
           unsigned int FN,
           unsigned int TN,
           std::string method,
           std::string video,
           std::string category);

    double Recall();
    double Specificity();
    double FPR();
    double FNR();
    double PWC();
    double Precision();
    double FMeasure();
    std::string description();

private:
    unsigned int TP;
    unsigned int FP;
    unsigned int FN;
    unsigned int TN;

    std::string method;
    std::string video;
    std::string category;


};

#endif // RESULT_H
