#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//11.给定一个链表，每个节点包含一个额外增加的随机指针，
//该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝
/**

 * Definition for a Node.

 * struct Node {

 *     int val;

 *     struct Node *next;

 *     struct Node *random;

 * };

 */

//typedef struct Node  Node;
//
//struct Node* copyRandomList(struct Node* head) {
//
//    if (head == NULL)
//
//        return NULL;
//
//    //分别copy一份链接在原链表后面，方便radom操作
//
//    Node* cur = head;
//
//    while (cur)
//
//    {
//
//        Node* new = (Node*)malloc(sizeof(Node));
//
//        new->next = NULL;//此处初始化使插入最后一个节点next为空
//
//        new->val = cur->val;
//
//        new->random = NULL;
//
//        new->next = cur->next;
//
//        cur->next = new;
//
//        cur = new->next;
//
//    }
//
//    //不能使用cur->next,cur已经为空
//
//    //原链表radom—>next即为新链表
//
//    cur = head;
//
//    while (cur)
//
//    {
//
//        Node* next = cur->next;
//
//        if (cur->random != NULL)
//
//        {
//
//            next->random = cur->random->next;
//
//        }
//
//        //已经初始化radom可省略
//
//        //    else
//
//         //  next->random=NULL;
//
//        cur = next->next;
//
//    }
//
//    //分离链表
//
//    //且需要恢复原链表
//
//    cur = head;
//
//    Node* newhead = cur->next;
//
//    while (cur)
//
//    {
//
//        Node* newcur = cur->next;
//
//        cur->next = newcur->next;
//
//
//
//        if (newcur->next == NULL)
//
//            return newhead;
//
//
//
//        newcur->next = newcur->next->next;
//
//        cur = cur->next;
//
//    }
//
//    return newhead;
//
//}


//8.输入两个链表，找出它们的第一个公共结点
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */
///*
//    struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)*/ {
//
//    struct ListNode* curA = headA, * curB = headB;
//
//    int lenA = 0, lenB = 0;
//
//    while (curA->next)
//
//    {
//
//        lenA++;
//
//        curA = curA->next;
//
//    }
//
//    while (curB->next)
//
//    {
//
//        lenB++;
//
//        curB = curB->next;
//
//    }
//
//    if (curA != curB)
//
//        return NULL;
//
//    int gap = abs(lenA - lenB);
//
//    struct ListNode* longlist = headA, * shortlist = headB;
//
//    if (lenB > lenA)
//
//    {
//
//        longlist = headB;
//
//        shortlist = headA;
//
//    }
//
//    while (gap--) {
//
//        longlist = longlist->next;
//
//    }
//
//    while (longlist != shortlist)
//
//    {
//
//        longlist = longlist->next;
//
//        shortlist = shortlist->next;
//
//    }
//
//    return longlist;
//
//}
//7.链表的回文结构
//struct ListNode {
//
//    int val;
//
//    struct ListNode* next;
//
//    ListNode(int x) : val(x), next(NULL) {}
//
//}; */
//
//#include <algorithm>
//
//#include <cstddef>
//
//#include <sys/ucontext.h>
//
//ListNode * midpointer(ListNode * head)
//
//{
//
//    ListNode* fast = head;
//
//    ListNode* slow = head;
//
//    while (fast && fast->next)
//
//    {
//
//        slow = slow->next;
//
//        fast = fast->next->next;
//
//
//
//    }
//
//    return slow;
//
//}
//
//ListNode* reverse(ListNode* head)
//
//{
//
//    ListNode* l1 = nullptr;
//
//    ListNode* l2 = head->next;
//
//    while (l2)
//
//    {
//
//        head->next = l1;
//
//        l1 = head;
//
//        head = l2;
//
//        l2 = l2->next;
//
//
//
//    }
//
//    head->next = l1;
//
//    return head;
//
//}
//
//class PalindromeList {
//
//public:
//
//    bool chkPalindrome(ListNode* A) {
//
//        // write code here
//
//        ListNode* mid = midpointer(A);
//
//        mid = reverse(mid);
//
//        while (A) {
//
//            if (A->val != mid->val)
//
//            {
//
//                return false;
//
//            }//偶数个时
//
//            else if (A->next == mid) {
//
//                return true;
//
//            }
//
//            A = A->next;
//
//            mid = mid->next;
//
//        }
//
//        return true;
//
//    }
////
////};
//4.输入一个链表，输出该链表中倒数第k个结点
///**
//
// * Definition for singly-linked list.
//
// * struct ListNode {
//
// *     int val;
//
// *     struct ListNode *next;
//
// * };
//
// */
//
//    int kthToLast(struct ListNode* head, int k) {
//
//    struct ListNode* slow = head;
//
//    struct ListNode* fast = head;
//
//    while (k--)
//
//    {
//
//        fast = fast->next;
//
//    }
//
//    while (fast != NULL)
//
//    {
//
//        fast = fast->next;
//
//        slow = slow->next;
//
//
//
//    }
//
//    return slow->val;
//
////}
//8.消失的数字
//int missingNumber(int* nums, int numsSize) {
//
//    //异或
//
//    int x = 0;
//
//    for (int i = 0; i <= numsSize; i++)
//
//    {
//
//        x ^= i;
//
//    }
//
//    for (int i = 0; i < numsSize; i++)
//
//    {
//
//        x ^= nums[i];
//
//    }
//
//    return x;