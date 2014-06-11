#ifndef CATEGORYRESULT_H
#define CATEGORYRESULT_H

#include <vector>
#include <string>

class Result;

class CategoryResult
{
public:
    CategoryResult(std::string& method, std::string& category);

    std::vector<double> fillWithCategoryResults(const CategoryResult& result);

    double mean(const std::vector<double>& resultVector);

private:
    std::string method;
    std::string category;

    double aveOverallRanking;
    double avgRanking;

    double recall;
    double specificity;
    double FPR;
    double FNR;
    double PWC;
    double fmeasure;
    double precision;
};

#endif // CATEGORYRESULT_H
