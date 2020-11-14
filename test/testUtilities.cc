 ///
 /// @file    testUtilities.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-14 00:23:51
 ///
 
#include <iostream>
#include "utilities.hpp"
using namespace std;


int main(int argc, const char * argv[])
{
//	string s1 = "中国人";
//	string s2 = "abc中国";
//	string s1 = "a中国人";
	string s2 = "abc中国人名";
 //   string aa("hello"), bb("World");
	string s1="i王成h递归; //技巧:从字符串的末尾开始匹配";
	vector<string> v1;
	vector<string> v2;
	splitEnglishAndChineseCharacter(s1,v1);
	for(auto &elem:v1)
		cout<<elem<<"$";
	cout<<endl;

	splitEnglishAndChineseCharacter(s2,v2);
	for(auto &elem:v2)
		cout<<elem<<"$";
	cout<<endl;

//    string aa("hello"), bb("to");
    
	int memo[128][128] = {0};
	vector<vector<int>> v(v1.size(),vector<int>(v2.size(),0));
    cout << editDestance(v,v1, v1.size()-1, v2, v2.size()-1) << endl;
//    cout << min_destance(aa.c_str(), int(aa.length()-1), bb.c_str(), int(bb.length()-1)) << endl;
    
    return 0;
}

#endif
