//
//  StList.hpp
//  suitredies
//
//  Created by 仙女 on 2017/5/23.
//  Copyright © 2017年 仙女. All rights reserved.
//

#ifndef StList_hpp
#define StList_hpp

#include <stdio.h>

typedef  struct ListNode{

   struct ListNode* prev;//前向节点
   struct ListNode* next;//后置节点
   void* value;    //数据

}ListNode;


class StList
{
public:
    StList();
    ~StList();
    ssize_t GetListLen(){return listlen;} //返回节点数目
    void freeOneNode(ListNode* node);
    void push_Head(void* value);          //添加到表头
    void push_Back(void* value);          //添加到表尾
    void push_OneNode_After(ListNode* node,void* value,bool after);//添加到某个节点之前或者之后
    void delnode(ListNode* node);         //删除某个节点
    
    void *(*dup)(void* ptr);//节点值复制函数
    void (*free)(void* ptr);//节点值释放函数
    int (*match)(void* ptr,void* key);//节点值对比函数
private:
    ListNode* head; //头部
    ListNode* tail; // 尾部
    ssize_t listlen;//节点数量
};

#endif /* StList_hpp */
