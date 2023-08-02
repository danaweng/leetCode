//
//  LinkList.hpp
//  LeetCode
//
//  Created by danaweng on 2023/8/2.
//  链表对应题目

#ifndef LinkList_hpp
#define LinkList_hpp

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(0), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

#endif /* LinkList_hpp */
