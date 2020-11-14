 ///
 /// @file    configure.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-24 20:47:25
 ///
 
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "utilities/configure.hpp"
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::stringstream;

Configuration::Configuration(const string & filePath):
_filePath(filePath)
{
	cout<<"Configuration() ctor"<<endl;
	readFile();
}
map<string,string>  Configuration::getConf() {
	return _conf;
}

void Configuration::readFile(){
	cout<<"readFile()"<<endl;
    ifstream ifs(_filePath);
    if(!ifs){
        cerr<<"ifs error"<<endl;
        return ;
    }
	string key,val,line;
	stringstream ss;
	while(getline(ifs,line)){
		ss.clear();
		ss<<line;
		ss>>key>>val;
		cout<<key<<"$"<<val<<endl;
		_conf[key]=val;
	}

}
Configuration::~Configuration(){
	cout<<"~Configuration()"<<endl;
}
void Configuration::showConfig(){
    cout<<"showConfig()"<<endl;
	for(auto &p:_conf){
		cout<<"key-val:"<<p.first<<",";
		if(p.first!="thread_num")
			cout<<p.second<<endl;
		else
			cout<<p.second<<endl;
		//	cout<<atoi(p.second.c_str())<<endl;
	}
		
}

#if __MAIN__
int main(){
	Configuration c("../../conf/conf.dat");
	c.showConfig();
	return 0;


}
#endif
