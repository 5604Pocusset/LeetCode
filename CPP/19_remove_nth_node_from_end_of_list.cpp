#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        for (int i = 0; i < n; i++)
            q = q->next;
        
        if (q == NULL) {
            head = p -> next;
            free(p);
            return head;
        }

        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }

        ListNode* temp = p->next;
        p->next = temp->next;
        free(temp);
        return head;
    }
};

void printListNode(ListNode* head) {
    if (head == NULL)
        return;
    cout << head->val;
    if (head->next != NULL) {
        cout << "->";
        printListNode(head->next);
    } else {
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    ListNode* l1 = new ListNode(1);

    ListNode* l2 = new ListNode(2);
    l1->next = l2;
    ListNode* l3 = new ListNode(3);
    l2->next = l3;
    ListNode* l4 = new ListNode(4);
    l3->next = l4;
    ListNode* l5 = new ListNode(5);
    l4->next = l5;

    printListNode(l1);

    Solution* s = new Solution();
    ListNode* head = l1;

    cout << "I'm here." << endl;
    cout.flush();

    head = s->removeNthFromEnd(head, 2);
    printListNode(head);

    head = s->removeNthFromEnd(head, 4);
    printListNode(head);
    return 0;
}
