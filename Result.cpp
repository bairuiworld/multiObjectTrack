#include "Result.h"
#include <sstream>

Result::Result(unsigned int TP,
       unsigned int FP,
       unsigned int FN,
       unsigned int TN,
       std::string method,
       std::string video,
       std::string category){
    this->TP = TP;
    this->FP = FP;
    this->FN = FN;
    this->TN = TN;

    this->method = method;
    this->video = video;
    this->category = category;

}

double Result::Recall(){
    if(TP + FN == 0) return 1;
    else return double(TP)/(TP+FN);
}

double Result::Specificity(){
    if(TP + FN == 0) return 1;
    else return double(TP)/(TN+FP);
}

double Result::FPR(){
    if(FP + TN == 0) return 0;
    else return double(FP)/(FP+TN);
}

double Result::FNR(){
    if(TP + FN == 0) return 0;
    else return double(FN)/(TP+FN);

}

double Result::PWC(){
    if(TP+FN+FP+TN == 0) return 0;
    else return 100.0*(FN+FP)/(TP+FN+FP+TN);

}

double Result::Precision(){
    if(TP+FP == 0) return 0;
    else return double(TP)/(TP + FP);
}

double Result::FMeasure(){
    double recall = Recall();
    double precision = Precision();
    if( recall + precision == 0) return 0;
    else return (2.0 * recall * precision) / (recall + precision);
}

std::string Result::description(){
    std::ostringstream oss;
    oss <<"Method:"<< method << "\n" << "Video:" << video << "\n" << "TP:"<< TP << "\n" << "FP:" << FP << "\n" << "FN:" << FN << "\n" << "TN:" <<TN <<"\n";
    return oss.str();
}
