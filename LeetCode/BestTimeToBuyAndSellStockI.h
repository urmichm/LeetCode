#pragma once
/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 *
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *			 Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 * Example 2:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static int maxProfit(vector<int>& prices);
static void maxProfit_run(void);

static void maxProfit_run(void)
{
	cout << "Best Time to Buy and Sell Stock I" << endl;

	{
		vector<int> test({ 2, 3, 1, 7 });
		int expected = 6;
		int actual = maxProfit(test);
		cout << "Test case 0: " << (actual == expected) << endl;
	}
	{
		vector<int> test({ 7, 1, 5, 3, 6, 4 });
		int expected = 5;
		int actual = maxProfit(test);
		cout << "Test case 1: " << (actual == expected) << endl;
	}
	{
		vector<int> test({ 1, 2, 3, 4, 5 });
		int expected = 4;
		int actual = maxProfit(test);
		cout << "Test case 2: " << (actual == expected) << endl;
	}
	{
		vector<int> test({ 7, 6, 4, 3, 1 });
		int expected = 0;
		int actual = maxProfit(test);
		cout << "Test case 3: " << (actual == expected) << endl;
	}

	system("pause");
}


static int maxProfit(vector<int>& prices)
{
	int res = 0;
	if (prices.size() < 2) return 0;

	int cur = prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		if (cur > prices[i])
			cur = prices[i];
		if (res < prices[i] - cur)
			res = prices[i] - cur;
	}
	return res;
}
