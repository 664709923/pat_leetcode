#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *node = new ListNode(0);
        node->next = head;
        ListNode *pre = node, *p = head;
        int same = 0;
        while(p && p->next) {
            if(p->val == p->next->val) {
                same = p->val;
                while(p && p->val == same) {
                    pre->next = p->next;
                    p = pre->next;
                }
            }else{
                pre = p;
                p = p->next;
            }
        }
        return node->next;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	ListNode *p = new ListNode(1);
    p -> next = new ListNode(1);
    //p -> next -> next = new ListNode(3);

    p = s.deleteDuplicates(p);
    while(p) {
        printf("%d\n", p -> val);
        p = p -> next;
    }
	

	return 0;
}