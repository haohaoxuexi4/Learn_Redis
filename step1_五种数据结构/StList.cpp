//
//  StList.cpp
//  suitredies
//
//  Created by 仙女 on 2017/5/23.
//  Copyright © 2017年 仙女. All rights reserved.
//

#include "StList.hpp"
#include <assert.h>
StList::StList():head(NULL),tail(NULL),listlen(0)
{
    

}

StList::~StList()
{
    ListNode* currnode=head;
    ListNode* next=NULL;
    while (listlen--) {
        next=currnode->next;
        //free 当前节点
        freeOneNode(currnode);
        currnode=next;
    }
    
}
void StList::freeOneNode(ListNode *node)
{
    assert(node!=NULL);
    delete node;
    node->prev=NULL;
    node->next=NULL;
    //delete node->value;
}
//在表头插入
void StList::push_Head(void *value)
{
    assert(value!=nullptr);
    //初始化
    ListNode* node=new ListNode();
    node->value=value;
    node->prev=NULL;
    node->next=NULL;
    
    if (listlen==0) {
        head=tail=node;
        
    }
    else
    {
        node->next=head;
        head->prev=node;
        head=node;
    }
    listlen++;//表节点数目增加1
}
//在表尾插入
void StList::push_Back(void *value)
{
    assert(value!=NULL);
    //初始化
    ListNode* node=new ListNode();
    node->value=value;
    node->prev=NULL;
    node->next=NULL;
    if(listlen==0){
        head=tail=node;
    }
    else
    {
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
    
    listlen++;//表节点数目增加1
}
void StList::push_OneNode_After(ListNode *node, void* value,bool after)
{
    assert(value!=NULL);
    //初始化
    ListNode* addnode=new ListNode();
    addnode->value=value;
    addnode->prev=NULL;
    addnode->next=NULL;
    
    if (after) {
        //addnode 添加到node 之后
        if (node==tail) {
            //如果是尾节点
            node->next=addnode;
            addnode->prev=node;
            tail=addnode;
        }
        else
        {
            ListNode* next=node->next;
            node->next=addnode;
            addnode->prev=node;
            addnode->next=next;
            next->prev=addnode;
        }
    }
    else
    {
        //addnode 添加到node之前
        if (node==head) {
            //如果是头节点
            node->prev=addnode;
            addnode->next=node;
            head=addnode;
        }
        else
        {
            ListNode* prev=node->prev;
            prev->next=addnode;
            addnode->prev=prev;
            addnode->next=node;
            node->prev=addnode;
        }
    }
    listlen++;
}

void StList::delnode(ListNode *node)
{

    if (node->prev) {
        head=node->next;
    }
    
    if (node->next) {
        tail=node->prev;
    }
    
    freeOneNode(node);
}
