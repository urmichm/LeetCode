#pragma once

/***
 * Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image. 
 * 
 * To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 * 
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 */

#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
{
	for (int a = 0; a < A.size(); a++)
	{
		vector<int>& v = A[a];
		for (int i = 0; i < (v.size() + 1) / 2; i++)
		{
			int t = v[i];
			v[i] = 1 ^ v[v.size() - 1 - i];
			v[v.size() - 1 - i] = 1 ^ t;
		}

		// for(int i=0; i < v.size(); i++)
		//    v[i] = 1 ^ v[i];
	}
	return A;
}