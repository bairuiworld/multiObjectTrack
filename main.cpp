#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <utility>

#include "MyMethod.h"
#include "VideoFolder.h"
#include "Comparator.h"
#include "json/json.h"

using namespace std;

typedef map<string,vector<string> > DataSet;
typedef vector<pair<string, string> > Path;

const string datasetPath = "/home/xiongqiang/CDNetDataSet";
const string jsonPath    = "/home/xiongqiang/workspace/ViBePlusByCDNet/DataSet.json";

DataSet parseJsonFromFile(const string& path){
    std::ifstream file(path,std::ifstream::binary);
    boost::property_tree::ptree pt;
    DataSet dataset;
    try{
        boost::property_tree::read_json(file,pt);
    }catch(boost::property_tree::ptree_error &e){
      std::cout  << "Failed to parse configuration\n"<<std::endl;
    }
    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("DataSet")){
        vector<string> video;
        for (boost::property_tree::ptree::const_iterator it = v.second.begin(); it != v.second.end(); ++it) {
            video.push_back(it->second.get_value<std::string>());
        }
        dataset.insert(make_pair(v.first,video));
    }
    return dataset;
}

Path getVideoPathAndBinaryPath(const string& datasetPath,DataSet dataset){
    Path allPath;
    for(DataSet::iterator iter = dataset.begin(); iter!=dataset.end(); ++iter){
        string videoPath = datasetPath + "/" + iter->first+"/"+iter->first + "/";
        string binaryPath = datasetPath + "/" + iter->first+"/results/";
        vector<string> video = iter->second;
        for(int i = 0 ; i < video.size(); ++ i){
            string new_videoPath =videoPath+video[i]+"/";
            string new_binaryPath =binaryPath+video[i]+"/";
            allPath.push_back(pair<string,string>(new_videoPath,new_videoPath));
        }
    }
    return allPath;
}

void process(string& videoPath,string& binaryPath){
    cout<<videoPath<<"...."<<endl;
    VideoFolder videoFolder(videoPath, binaryPath);
    bool error = false;
    try {
        videoFolder.readTemporalFile();
        videoFolder.setExtension(".jpg");
    } catch (const string &s) {
        error = true;
        cout << "An exception has occured : " << s << "\n";
    }
    MyMethod *test = new MyMethod(videoFolder);
    test->process();
    if(!error){
        Comparator comparator(videoFolder);
        comparator.compare();
        comparator.save();
        cout<<"DONE.\n";
    }

}

int main()
{
    Path path = getVideoPathAndBinaryPath(datasetPath,parseJsonFromFile(jsonPath));
    for(int i = 0 ; i < path.size(); ++ i){
        process(path[i].first,path[i].second);
    }
    return 0;
}

