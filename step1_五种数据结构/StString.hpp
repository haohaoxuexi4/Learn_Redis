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
    StString(const char* init,ssize_t initsize);//定长字符串
    StString(const char* init);//只包含一个\0 的字符串
    
    StString(const StString& st);//拷贝构造函数
    StString& operator=(const StString &st);//重载赋值函数
    
    ~StString();
    
    ssize_t GetUsedlen(){return usedlen;} //返回已使用长度
    ssize_t GetFreelen(){return freelen;}//返回空闲长度
    
    ssize_t AppendData(const char* apdata,ssize_t aplen);//末尾追加数据
    ssize_t AppendDate(const char* apdata);
  
private:
    void MakeRoom(ssize_t len); //追加数据后，空间不够，申请空间
    char* data;         //字符数组
    ssize_t freelen;    //字符数组里空闲长度
    ssize_t usedlen;    //字符数组里已经使用的长度
};

#endif /* StString_hpp */
