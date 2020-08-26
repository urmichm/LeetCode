#pragma once

#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static void print_list(struct ListNode* node);
static void push_list(struct ListNode*& _head, int _val);

static ListNode* mergeKLists(vector<ListNode*>& lists);
static ListNode* mergeKLists_divideAndConquer(vector<ListNode*>& lists);
static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
static void mergeKLists(void);

static void mergeKLists(void)
{
	//Input:
	//[
	//	1->4->5,
	//	1->3->4,
	//	2->6
	//]
	//Output : 1->1->2->3->4->4->5->6
	ListNode* l1 = nullptr;
	push_list(l1, 1);
	push_list(l1, 4);
	push_list(l1, 5);
	ListNode* l2 = nullptr;
	push_list(l2, 1);
	push_list(l2, 3);
	push_list(l2, 4);
	ListNode* l3 = nullptr;
	push_list(l3, 2);
	push_list(l3, 6);
	vector<ListNode*> input({ l1, l2, l3 });
	//ListNode* output = mergeKLists(input);
	ListNode* output = mergeKLists_divideAndConquer(input);
	print_list(output);
	cout << "1->1->2->3->4->4->5->6" << endl;;
}

/// In-place solution with Divide and Conqure approach
static ListNode* mergeKLists_divideAndConquer(vector<ListNode*>& lists)
{
	const int N = lists.size();
	if (0 == N)
		return nullptr;
	int interval = 1;
	while (interval < N)
	{
		for (int i = 0; i <= N - interval - 1; i = i + 2 * interval)
			lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
		interval = interval << 1;
	}

	return lists[0];
}

/// in-place merging two lists
static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* res = nullptr;
	ListNode* tail = nullptr;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->val < l2->val)
		{
			if (res == nullptr)
			{
				res = l1;
				tail = l1;
				l1 = l1->next;
			}
			else
			{
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}
		}
		else
		{
			if (res == nullptr)
			{
				res = l2;
				tail = l2;
				l2 = l2->next;
			}
			else
			{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		}
	}

	if (res == nullptr)
		res = (l1 == nullptr ? l2 : l1);
	else
		tail->next = (l1 == nullptr ? l2 : l1);
	return res;
}


static ListNode* mergeKLists(vector<ListNode*>& lists)
{
	ListNode* result = nullptr;
	ListNode* tail = nullptr;
	int min_idx = 0;
	bool flag = false;

	// check if there is anything
	for (int i = 0; i < lists.size(); i++)
		if (lists[i] != nullptr)
		{
			min_idx = i; flag = true; break;
		}

	while (flag)
	{
		// find min
		for (int i = 0; i < lists.size(); i++)
			if (lists[i] != nullptr)
			{
				if (lists[min_idx]->val > lists[i]->val)
					min_idx = i;
			}
		// put min in a list
		if (result == nullptr)
		{
			result = new ListNode(lists[min_idx]->val);
			tail = result;
			lists[min_idx] = lists[min_idx]->next;
		}
		else
		{
			tail->next = new ListNode(lists[min_idx]->val);
			tail = tail->next;
			lists[min_idx] = lists[min_idx]->next;
		}

		// check if there are still elements
		flag = false;
		for(int i=0; i<lists.size(); i++)
			if (lists[i] != nullptr)
			{
				min_idx = i; flag = true; break;
			}
	}

	return result;
}



/// Private functions
static void print_list(struct ListNode* node)
{
	while (node != nullptr)
	{
		cout << node->val;;
		node = node->next;
		if (node != nullptr)
			cout << "->";
	}
	cout << endl;
}


static void push_list(struct ListNode*& _head, int _val)
{

	if (nullptr == _head)
	{
		_head = new ListNode(_val);
	}
	else
	{
		ListNode* tmp = _head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new ListNode(_val);
	}
}