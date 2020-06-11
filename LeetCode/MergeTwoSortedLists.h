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


ListNode* mergeTwoLists_withHelper(ListNode* l1, ListNode* l2)
{
	struct ListNode* l = NULL;
	while (l1 != NULL || l2 != NULL)
	{
		if (l1 == NULL && l2 != NULL)
		{
			push_list(l, l2->val);
			l2 = l2->next;
		}
		else if (l1 != NULL && l2 == NULL)
		{
			push_list(l, l1->val);
			l1 = l1->next;
		}

		else if(l1->val < l2->val)
		{
			push_list(l, l1->val);
			l1 = l1->next;
		}
		else
		{
			push_list(l, l2->val);
			l2 = l2->next;
		}

	}

	return l;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	struct ListNode* result = NULL;
	struct ListNode* tail = NULL;
	
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			if (result == NULL)
			{
				result = new ListNode(l1->val);
				tail = result;
				l1 = l1->next;
			}else{
				tail->next = new ListNode(l1->val);
				l1 = l1->next;
				tail = tail->next;
			}
		}
		else
		{
			if (result == NULL)
			{
				result = new ListNode(l2->val);
				tail = result;
				l2 = l2->next;
			}
			else {
				tail->next = new ListNode(l2->val);
				tail = tail->next;
				l2 = l2->next;
			}
		}
	}

	ListNode* rest = (l2 == NULL ? l1 : l2);
	while (rest)
	{
		if (result == NULL)
		{
			result = new ListNode(rest->val);
			tail = result;
			rest = rest->next;
		}
		else {
			tail->next = new ListNode(rest->val);
			rest = rest->next;
			tail = tail->next;
		}
	}

	return result;
}


static void mergeTwoLists(void)
{
	ListNode* l1 = NULL;
	ListNode* l2 = NULL;
	// Input: 1->2->4, 1->3->4
	// Output: 1->1->2->3->4->4
	push_list(l1, 1);
	push_list(l1, 2);
	push_list(l1, 4);
	print_list(l1);

	push_list(l2, 1);
	push_list(l2, 3);
	push_list(l2, 4);
	print_list(l2);

	ListNode* l = mergeTwoLists(l1, l2);
	print_list(l);

}