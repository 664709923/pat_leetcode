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
        ListNode *p = head;
        if(p == NULL) return NULL;
        while(p->next) {
            if(p->val == p->next->val){
                p->next = p->next->next;
            }else{
                p = p-> next;
            }
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	ListNode *p = new ListNode(1);
    p -> next = new ListNode(1);
    p -> next -> next = new ListNode(3);

    p = s.deleteDuplicates(p);
    while(p) {
        printf("%d\n", p -> val);
        p = p -> next;
    }
	

	return 0;
}