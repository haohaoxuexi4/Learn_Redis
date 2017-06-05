//
//  StString.cpp
//  suitredies
//
//  Created by 仙女 on 2017/5/23.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include "StString.hpp"
#include <assert.h>
#include <string>

#include <algorithm>
StString::StString()
{
    
}
StString::StString(const char* init,ssize_t initsize)
{
    assert(init!=NULL);
    
    for(int i=0;i<initsize;i++)
        data.push_back(init[i]);
    
}
StString::StString(const char* init)
{
    ssize_t initsize=(init==NULL)? 0:strlen(init);
    for(int i=0;i<initsize;i++)
        data.push_back(init[i]);
}
StString::~StString()
{

}
/*
 将长度为appendlen的数据追加到buf末尾
 成功返回 true ,失败返回false
 
 第一种情况：free >= appendlen
 第二种： free<appendlen
 */


bool StString::appendData(const char* append,ssize_t appendlen)
{
    assert(append!=NULL);
    for (int i=0; i<appendlen; i++) {
        data.push_back(append[i]);
    }
    return true;
}
bool StString::appendData(const char *append)
{
    assert(append!=NULL);
    for (int i=0; i<strlen(append); i++) {
        data.push_back(append[i]);
    }
    return true;
}
