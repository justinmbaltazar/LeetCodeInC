#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode result = { .next = NULL };
    struct ListNode *p = &result;
    int track = 0;
    while (l1 || l2 || track) {
        int temp1 = 0;
        int temp2 = 0;
        if(l1 != 0){
            temp1 = l1->val;
            l1 = l1->next;
        }
        if(l2 != 0){
            temp2 = l2->val;
            l2 = l2->next;
        }
        int sum = temp1 + temp2 + track;
        track = sum >= 10;
        p->next = malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = sum % 10;
        p->next = NULL;
    }
    return result.next;
}

