 ///
 /// @file    editDistance.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-05 20:46:15
 ///
#ifndef __editDistance__
#define __editDistance__
#include <iostream>
#include <vector>
using std::vector;
using std::string;
// using namespace std;
namespace utilities{
void splitEnglishAndChineseCharacter(const string & bytesFlow, vector<string> & v);
int editDistance(vector<vector<int>>&memo, vector<string> & str, int index_str/*填入最大下标*/, vector<string> & target, int index_target);
}//end of namespace utilities
#endif
