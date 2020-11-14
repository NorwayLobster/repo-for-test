//
//  main.cpp
//  最小编辑距离算法
//
//  Created by Ruler on 14-8-9.
//  Copyright (c) 2014年 Ruler. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "utilities/utilities.hpp"
using namespace std;

namespace utilities{
void splitEnglishAndChineseCharacter(const string & bytesFlow, vector<string> & v){
	int bytesSize=bytesFlow.size();
//	cout<<"bytesSize:"<<bytesSize<<endl;
	int index=0;
//		cout<<"index:"<<index<<endl;
	while(index<bytesSize){
		int bytesSizeThisCharacter=1;
//		cout<<"bytesSizeThisCharacter:"<<bytesSizeThisCharacter<<endl;
		int bitsNumShiftToLeft=7;
		if(bytesFlow[index]>>bitsNumShiftToLeft & 0x1){
//			cout<<"bit:"<<((bytesFlow[index]>>bitsNumShiftToLeft) & 0x1)<<endl;
			--bitsNumShiftToLeft;

		//	++bytesSizeThisCharacter;
		//	--bitsNumShiftToLeft;//2nd bit 上必定为1
		
//			cout<<"bytesSizeThisCharacter:"<<bytesSizeThisCharacter<<endl;
		//	cout<<"bit:"<<((bytesFlow[index]>>bitsNumShiftToLeft) & 0x1)<<endl;
//			cout<<"bitsNumShiftToLeft:"<<bitsNumShiftToLeft<<endl;
//			int i=0;
			while(bytesFlow[index]>>bitsNumShiftToLeft & 0x1){//一个字符最多6个字节
//				cout<<"while bit:"<<((bytesFlow[index]>>bitsNumShiftToLeft) & 0x1)<<endl;
				++bytesSizeThisCharacter;
//				cout<<"bytesSizeThisCharacter:"<<bytesSizeThisCharacter<<endl;
				--bitsNumShiftToLeft;//2nd bit 上必定为1
//				cout<<"bitsNumShiftToLeft:"<<bitsNumShiftToLeft<<endl;
//				++i;
//				if(i>8)
//					break;
			}
		}
		string oneCharacter=bytesFlow.substr(index,bytesSizeThisCharacter);
//		cout<<"oneCharacter:"<<oneCharacter<<endl;
		v.push_back(oneCharacter);
		index+=bytesSizeThisCharacter;
//		cout<<"index:"<<index<<endl;
	}
}
//递归
//技巧:从字符串的末尾开始匹配
//inline int min_destance(const char * str, int index_str/*填入最大下标*/, const char * target, int index_target)
int editDistance(vector<vector<int>>&memo, vector<string> & str, int index_str/*填入最大下标*/, vector<string> & target, int index_target)
{
    if (index_target < 0)  return index_str + 1;
    if (index_str < 0) return index_target + 1;
    
    if (0 != memo[index_str][index_target]) return memo[index_str][index_target];//该序列已经计算过
    
    if (str[index_str] == target[index_target])
        return editDistance(memo,str, index_str-1, target, index_target-1);
//递归
    int cand1 = editDistance(memo,str, index_str, target, index_target-1) + 1;
    int cand2 = editDistance(memo,str, index_str-1, target, index_target) + 1;
    int cand3 = editDistance(memo,str, index_str-1, target, index_target-1) + 1;

    int min = (cand1<cand2) ? (cand1<cand3 ? cand1 : cand3) :
                              (cand2<cand3 ? cand2 : cand3) ;
    
    memo[index_str][index_target] = min;
    
    return min;
}
}//end of namespace utilities


