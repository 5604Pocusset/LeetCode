#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* Answer begin */

struct ListNode* createNode(int val)
{
	struct ListNode* new_node = malloc(sizeof(struct ListNode));
	new_node->val = val;
	new_node->next = NULL;
	return new_node;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* l3 = NULL;
    struct ListNode* head_node = NULL;
    struct ListNode* new_node = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
    	if (l1 != NULL)
    	{
    		carry += l1->val;
    		l1 = l1->next;
    	}
    	if (l2 != NULL)
    	{
    		carry += l2->val;
    		l2 = l2->next;
    	}

    	new_node = createNode(carry % 10);
    	
    	if (l3 == NULL)
    	{
    		l3 = new_node;
    		head_node = new_node;
    	}
    	else
    	{
    		head_node->next = new_node;
    		head_node = new_node;
    	}
    	carry = (int) carry / 10;
    }
    if (carry != 0)
    {
    	new_node = createNode(carry % 10);
    	head_node->next = new_node;
    	head_node = new_node;
    }
    return l3;
}

/* Answer end */

struct ListNode* intToNode(int n)
{
	struct ListNode* l = NULL;
	struct ListNode* head_node = NULL;
	struct ListNode* new_node = NULL;
	do
	{
		new_node = createNode(n % 10);
		if (l == NULL)
		{
			l = new_node;
			head_node = new_node;
		}
		else
		{
			head_node->next = new_node;
			head_node = new_node;
		}
		n = (int) n / 10;
	} while (n != 0);
	return l;
}

void printNode(struct ListNode* l)
{
	if (l == NULL)
	{
		printf("(NULL)\n");
		return;
	}
	printf("(%d", l->val);
	while (l->next != NULL)
	{
		l = l->next;
		printf(" -> %d", l->val);
	}
	printf(")\n");
}

int main()
{
	// int n1 = 5342;
	// int n2 = 5465;
	int n1 = 81;
	int n2 = 0;
	struct ListNode* l1 = intToNode(n1);
	struct ListNode* l2 = intToNode(n2);
	struct ListNode* l3 = addTwoNumbers(l1, l2);
	printNode(l1);
	printNode(l2);
	printNode(l3);
	return 0;
}