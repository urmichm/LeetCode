#pragma once
/**
 * Merge two sorted linked lists and return it as a new sorted list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * 
 * Input:   1->2->4, 1->3->4
 * Output : 1->1->2->3->4->4
 */

#include <algorithm>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
static void mergeTwoLists(void);

static void print_list(struct ListNode* _head);
static void push_list(struct ListNode*& _head, int _val);

static void push_list(struct ListNode*& _head, int _val)
{
	
	if (NULL == _head)
	{
		_head = new ListNode(_val);
	}
	else
	{
		ListNode* tmp = _head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new ListNode(_val);
	}
}

static void print_list(struct ListNode* node)
{
//	ListNode* node = (_node);

	while (node != NULL)
	{
		std::cout << node->val << " ";
		node = node->next;
	}
	std::cout << std::endl;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{

}


static void mergeTwoLists(void)
{
	ListNode* l1 = NULL;

	push_list(l1, 1);
	push_list(l1, 2);
	push_list(l1, 3);
	push_list(l1, 4);

	print_list(l1);

}