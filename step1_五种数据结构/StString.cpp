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
StString::StString(const char* init,ssize_t initsize)
{
    assert(init!=NULL);
    buf[initsize]='\0';
    memcpy(buf,init,initsize);
    userdlen=initsize;
    freelen=0;
}

StString::~StString()
{

}
