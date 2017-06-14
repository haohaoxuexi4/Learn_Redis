//
//  StString.cpp
//  suitredies
//
//  Created by 仙女 on 2017/5/23.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include "StString.hpp"
#include <assert.h>

#define MAXININSIZE  100

StString::StString()
{
    data=new char[1];
    data[0]='\0';
    freelen=0;
    usedlen=0;
}
StString::StString(const char* init,ssize_t initsize)
{
    assert(init!=NULL);
    
    data=new char[initsize+1];
    memcpy(data,init,initsize);
    data[initsize]='\0';
    
    freelen=0;
    usedlen=initsize;

}
StString::StString(const char* init)
{
    assert(init!=nullptr);
    ssize_t len=strlen(init);
    data=new char [len+1];
    memcpy(data, init, len);
    data[len]='\0';
    
    freelen=0;
    usedlen=len;
}
StString::StString(const StString& st)
{
    usedlen=st.usedlen;
    freelen=st.freelen;
    ssize_t len=strlen(st.data);
    data=new char[len+1];
    memcpy(data, st.data, len);
    data[len]='\0';
    
}
StString& StString::operator=(const StString &st)
{
    if(&st==this) return *this;
    delete []data;
    usedlen=st.usedlen;
    freelen=st.freelen;
    data=new char[strlen(st.data)+1];
    memcpy(data, st.data, strlen(st.data));
    data[strlen(st.data)]='\0';
    return *this;
}
StString::~StString()
{

    delete [] data;
    freelen=0;
    usedlen=0;
}
void StString::MakeRoom(ssize_t len)
{
    const char* tmp=data;
    ssize_t usedlentmp=usedlen;
    //ssize_t freelentmp=freelen;
    
    data=new char[len+1];
    
    memcpy(data, tmp, usedlentmp);
    data[usedlentmp]='\0';
    usedlen=usedlentmp;
    freelen=len-usedlentmp;
    
    delete [] tmp;
}
/*
 将长度为appendlen的数据追加到buf末尾
 返回追加了多少字节
 
 第一种情况：free >= appendlen
 第二种： free<appendlen
 
 默认，如果总长度小于1024，则扩展2倍，如果大于1024，就扩展所需空间
 */
ssize_t StString::AppendData(const char *apdata, ssize_t aplen)
{
    assert(apdata!=nullptr);
    if(freelen>=aplen)
    {
        //直接扩展
        memcpy(data+usedlen, apdata, aplen);
        usedlen=usedlen+aplen;
        freelen=freelen-aplen;
        data[usedlen]='\0';
    }
    else
    {
        //先申请空间
        if((usedlen+aplen)<MAXININSIZE)
        {
            ssize_t len=(usedlen+aplen)*2;
            MakeRoom(len);
            
            memcpy(data+usedlen, apdata, aplen);
            usedlen=usedlen+aplen;
            //printf("len=%d,uselen=%d\n",len,usedlen);
            freelen=len-usedlen;
            
            data[usedlen]='\0';
        }
        else
        {
            ssize_t len=usedlen+aplen;
            MakeRoom(len);
            
            memcpy(data+usedlen, apdata, aplen);
            usedlen=usedlen+aplen;
            freelen=len-usedlen;
            data[usedlen]='\0';
        }
    }
    return aplen;
}
ssize_t StString::AppendDate(const char *apdata)
{
    assert(apdata!=nullptr);
    ssize_t len=strlen(apdata);
    return AppendData(apdata, len);
}
