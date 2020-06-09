#pragma once


/***
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */
#include <cstdlib>
#include <iostream>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	struct Node 
	{
		int data;
		Node* next;

		Node(int x)
		{
			data = x;
			next = NULL;
		}
	};

	Node* head;
	Node* min;

	MinStack() 
	{
		head = NULL;
		min = NULL;
	}

	void findMin() 
	{
		min = head;
		Node* n = head;
		while (n) {
			if (n->data < min->data)
				min = n;
			n = n->next;
		}
	}

	void push(int x) {
		if (NULL == head)
		{
			head = new Node(x);
			min = head;
		}
		else
		{
			Node* n = new Node(x);
			n->next = head;
			head = n;
			if (head->data < min->data)
				min = head;
		}
	}

	void pop() {
		if (head == NULL)
			return;
		bool flag = false;
		if (min == head)
			flag = true;
		Node* n = head->next;
		delete head;
		head = n;
		if (flag)
			findMin();
	}

	int top() {
		if (head == NULL)
			return 0;
		return head->data;
	}

	int getMin() {
		if (min == NULL)
			return 0;
		return min->data;
	}
};

void minStuck()
{
	int t;
	MinStack *obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-3);

	t = obj->getMin();
	cout << t << endl;
	obj->pop();
	t = obj->top();
	cout << t << endl;
	t = obj->getMin();
	cout << t << endl;

}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */