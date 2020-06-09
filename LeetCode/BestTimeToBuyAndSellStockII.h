#pragma once
/**
 * Best Time to Buy and Sell Stock II
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like(i.e., buy one and sell one share of the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time(i.e., you must sell the stock before you buy again).
 *
 *	Example 1 :
 *	Input : [7, 1, 5, 3, 6, 4]
 *	Output : 7
 *	Explanation : Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5 - 1 = 4.
 *	Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6 - 3 = 3.
 *
 *	Example 2 :
 *	Input : [1, 2, 3, 4, 5]
 *	Output : 4
 *	Explanation : Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5 - 1 = 4.
 *	Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *	engaging multiple transactions at the same time.You must sell before buying again.
 *
 *	Example 3 :
 *	Input : [7, 6, 4, 3, 1]
 *	Output : 0
 *	Explanation : In this case, no transaction is done, i.e.max profit = 0.
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static int maxProfit(vector<int>& prices);
static int maxProfit_easy(vector<int>& prices);
static void maxProfit_run(void);

static void maxProfit_run(void)
{
	cout << "Best Time to Buy and Sell Stock II" << endl;

	{
		vector<int> test({ 2, 3, 1, 7});
		int expected = 7;
		int actual = maxProfit_easy(test);
		cout << "Test case 0: " << (actual == expected) << endl;
	}
	{
		vector<int> test({ 7, 1, 5, 3, 6, 4 });
		int expected = 7;
		int actual = maxProfit_easy(test);
		cout << "Test case 1: " << (actual == expected) << endl;
	}
	{
		vector<int> test({ 1, 2, 3, 4, 5 });
		int expected = 4;
		int actual = maxProfit_easy(test);
		cout << "Test case 2: " << (actual == expected) << endl;
	}
	{
		vector<int> test({ 7, 6, 4, 3, 1 });
		int expected = 0;
		int actual = maxProfit_easy(test);
		cout << "Test case 3: " << (actual == expected) << endl;
	}

	system("pause");
}


static int maxProfit(vector<int>& prices)
{
	const int n = prices.size();
	vector<int> dp(n, 0);  // array of n zeros
	if (n < 2) return 0;
	int bought = prices[0];
	int res = 0;
	for (int i = 1; i < n; i++)
	{
		if (prices[i-1] > prices[i])
		{
			bought = prices[i];
			res += dp[i - 1];
		}
		else if (dp[i] < (prices[i] - bought)  )
		{
			dp[i] = (prices[i] - bought);
		}
	}
	if (bought < prices[n - 1])
		res += dp[n - 1];
	return res;
}

static int maxProfit_easy(vector<int>& prices)
{
	const int n = prices.size();
	int res = 0;
	for (int i = 1; i < n; i++)
	{
		if (prices[i] > prices[i-1])
		{
			res += (prices[i] - prices[i-1]);
		}
	}
	return res;
}

