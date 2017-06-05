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

class StString
{
public:

    StString(const char* init,ssize_t initsize);
    ~StString();
    
    ssize_t Usedlen(){return userdlen;} //返回已使用长度
    ssize_t Freelen(){return freelen;}  //返回空闲长度
private:
    ssize_t userdlen;//已使用字符串长度
    ssize_t freelen;//空闲长度
    char buf[]; //字符串
};

#endif /* StString_hpp */
