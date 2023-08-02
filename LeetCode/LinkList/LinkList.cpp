//
//  LinkList.cpp
//  LeetCode
//
//  Created by danaweng on 2023/8/2.
//

#include "LinkList.hpp"

//MARK: - 链表
// 合并链表
//https://leetcode.cn/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *preHeader = new ListNode();
    ListNode *tmpHeader = preHeader;
    
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tmpHeader->next = list1;
            list1 = list1 -> next;
        } else {
            tmpHeader->next = list2;
            list2 = list2 -> next;
        }
        tmpHeader = tmpHeader->next;
    }
    
    tmpHeader->next = list1 ? list1 : list2;
    return preHeader->next;
}


ListNode* mergeTwoLists_Recusion(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr)  {
        return list2;
    }
    
    if (list2 == nullptr) {
        return list1;
    }
    
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists_Recusion(list1->next, list2);
        return list1;
    } else {
        list2 ->next = mergeTwoLists_Recusion(list1, list2->next);
        return list2;
    }
}

ListNode *mergeTwoList2 (ListNode *l1, ListNode *l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    
    if (l1->val < l2 ->val) {
        l1->next = mergeTwoLists_Recusion(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists_Recusion(l2->next, l2);
        return l2;
    }
    return nullptr;
}

// 203. 移除链表元素
// https://leetcode.cn/problems/remove-linked-list-elements/
// 递归版本
ListNode* removeElements_recursion(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }
    
    head->next = removeElements_recursion(head->next, val);
    return head->val == val ? head->next : head;
}


ListNode* removeElements_iteration(ListNode* head, int val) {
    ListNode dummyHead = ListNode();
    dummyHead.next = head;
    ListNode* temp = &dummyHead;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return dummyHead.next;
}

/**
 https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 输入：head = [1,2,3,4,5], n = 2
 输出：[1,2,3,5]
 */
int getNodeListLength(ListNode *node) {
    int length = 0;
    while (node != nullptr) {
        length++;
        node = node->next;
    }
    return length;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = getNodeListLength(head);
    ListNode dumpNode = ListNode();
    dumpNode.next = head;
    ListNode *currentNode = &dumpNode;
    for(int i = 0; i < len - n; i++) {// 找到待删除节点的前一个节点
        currentNode = currentNode->next;
    }
    currentNode->next = currentNode->next->next;
    return dumpNode.next;
}

ListNode* removeNthFromEnd_FastSlowPointer(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* first = head;
    ListNode* second = dummy;
    for (int i = 0; i < n; ++i) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}

/**
 作者：LeetCode-Solution
 链接：https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/solution/lian-biao-xiang-jiao-by-leetcode-solutio-2kne/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。**/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    if (!headA || !headB ) {
        return nullptr;
    }
    
    ListNode *pA = headA;
    ListNode *pB = headB;
    while(pA != pB) {
        pA = (pA == nullptr) ? pB : pA->next;
        pB = (pB == nullptr) ? pA : pB->next;
    }
    
    return pA;
}

/**
 https://leetcode.cn/problems/linked-list-cycle/solution/huan-xing-lian-biao-by-leetcode-solution/
 */
//ListNode *detectCycle(ListNode *head) {
//    if (head == nullptr) {
//        return nullptr;
//    }
//
//    ListNode *fastNode = head;
//    ListNode *slowNode = head;
//    while (fastNode != nullptr || slowNode != nullptr) {
//        fastNode
//    }
//}


//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//ListNode *detectCycle_2(ListNode *head) {
//        unordered_set<ListNode *> visited;
//        while (head != nullptr) {
//            if (visited.count(head)) {
//                return head;
//            }
//            visited.insert(head);
//            head = head->next;
//        }
//        return nullptr;
//}



bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for(char c: magazine) {
        map[c]++;
    }
    for(char c: ransomNote) {
        if (map[c] > 0) {
            map[c]--;
        } else {
            return false;;
        }
    }
    return true;
}


void reverseString(vector<char>& s) {
    int size = s.size();
    for(int start = 0, end = size - 1 ; start < end; start--, end++) {
        swap(s[start], s[end]);
    }
}


ListNode* swapPairs(ListNode* head) {
    
    ListNode *tmpNode = head;
    while (head) {
        
        ListNode *secondNode = head->next;
        ListNode *thirdNode = head->next->next;
        secondNode->next = head;
        head->next = thirdNode;
        head = thirdNode;
    }
    
    return head;
}


// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };


//MARK: - 【字符串】
string replaceSpace(string s) {
    int size = s.size();
    int sapceNum = 0;
    for(char c : s) {
        if (c == ' ') {
            sapceNum++;
        }
    }
    
    s.resize(size + sapceNum * 2);
    int newSize = s.size() - 1;
    for (int i = size - 1; i > 0; i--) {
        if (s[i] == ' ') {
            s[newSize--] = '0';
            s[newSize--] = '2';
            s[newSize--] = '%';
        } else {
            s[newSize--] = s[i];
        }
    }
    return s;
}


string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }

//作者：LeetCode-Solution
//链接：https://leetcode.cn/problems/reverse-words-in-a-string/solution/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

