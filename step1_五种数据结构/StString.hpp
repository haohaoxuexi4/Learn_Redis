//
//  StString.hpp
//  suitredies
//
//  Created by 仙女 on 2017/5/23.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef StString_hpp
#define StString_hpp

#include <stdio.h>
#include <vector>
#define MAX_INITSIZE 1024;

class StString
{
public:
    StString();// 空的ststing
    StString(const char* init,ssize_t initsize);
    StString(const char* init);
    ~StString();
    
    bool appendData(const char* append,ssize_t appendlen);//将长度为appendlen的数据追加到buf末尾
    bool appendData(const char* append);
    ssize_t Usedlen(){return data.size();} //返回已使用长度
    //ssize_t Freelen(){return freelen;}  //返回空闲长度
    //char* BackBuf(){return buf;};   //返回buf指针
    //void  SetUsedlen(ssize_t len){userdlen=len;}
    //void  SetFreelen(ssize_t len){freelen=len;}
private:
    
    
    std::vector<char> data;
};

#endif /* StString_hpp */
