#pragma once


/**
  You are given coins of different denominations and a total amount of money. 
  Write a function to compute the number of combinations that make up that amount. 
  You may assume that you have infinite number of each kind of coin.

  Example 1:
  Input: amount = 5, coins = [1, 2, 5]
  Output: 4
  Explanation: there are four ways to make up the amount:
   5=5
   5=2+2+1
   5=2+1+1+1
   5=1+1+1+1+1

  Example 2:
  Input: amount = 3, coins = [2]
  Output: 0
  Explanation: the amount of 3 cannot be made up just with coins of 2.
 
  Example 3:
  Input: amount = 10, coins = [10]
  Output: 1

  Note: You can assume that
  0 <= amount <= 5000
  1 <= coin <= 5000
  the number of coins is less than 500
  the answer is guaranteed to fit into signed 32-bit integer
 */

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


static void change(void);
static int change(int amount, vector<int>& coins);

static int change(int amount, vector<int>& coins)
{
	vector<int> dp(amount+1, 0);
	dp[0] = 1;

	/* take each coin */
	for(int c = 0; c < coins.size(); c++)
	{
		for (int a = coins[c]; a <= amount; a++)
		{
			dp[a] = dp[a] + dp[ a - coins[c] ];
		}
	}

	return dp[amount];
}

static void change(void) 
{
	{
		vector<int> coins({ 1, 2, 5 });
		int amount = 5;
		int expected = 4;
		int res = change(amount, coins);
		cout << "Test case 1 " << (res == expected ? "passed" : "failed") 
			<< " e = " << expected << " a = " << res << endl;
	}
	{
		vector<int> coins({ 2 });
		int amount = 3;
		int expected = 0;
		int res = change(amount, coins);
		cout << "Test case 2 " << (res == expected ? "passed" : "failed") << " e = " << expected << " a = " << res << endl;

	}
	{
		vector<int> coins({ 10 });
		int amount = 10;
		int expected = 1;
		int res = change(amount, coins);
		cout << "Test case 3 " << (res == expected ? "passed" : "failed") << " e = " << expected << " a = " << res << endl;
	}
}