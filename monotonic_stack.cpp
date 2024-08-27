#include <bits/stdc++.h>
/*A monotonic stack is a special type of stack in which all elements on the stack are sorted in either descending or ascending order. It is used to solve problems that require finding the next greater or next smaller element in an array.*/
using namespace std;

/*
DESCRIPTION
Given an array of integers, find the next greater element for each element in the array. The next greater element of an element x is the first element to the right of x that is greater than x. If there is no such element, then the next greater element is -1.

Example
Input: [2, 1, 3, 2, 4, 3]
Output: [3, 3, 4, 4, -1,
*/

vector<int> next_greater_element(const vector<int>& arr)
{
    stack<int> S;
    vector<int> res(arr.size(), -1);

    for(int i = 0; i < arr.size(); ++i)
    {
        while(!S.empty() && arr[i] > arr[S.top()]) // change the condition to find next_smaller element (arr[i] < arr[S.top()])
        {
            int idx = S.top(); S.pop();
            res[idx] = arr[i]; // add idx or value depending on what is asked.
        }
        S.push(i);
    }
    return res;
}

/*
Daily tempratures.

Given an integer array temps representing daily temperatures, write a function to calculate the number of days one has to wait for a warmer temperature after each given day. The function should return an array answer where answer[i] represents the wait time for a warmer day after the ith day. If no warmer day is expected in the future, set answer[i] to 0.

EXAMPLES
Inputs:

temps = [65, 70, 68, 60, 55, 75, 80, 74]
Output:

[1, 4, 1, 2, 1, 1, 0, 0]  
*/

vector<int> daily_temoratures(const vector<int>& arr)
{
    stack<int> S;
    vector<int> res(arr.size(), 0);

    for(int i = 0; i < arr.size(); ++i)
    {
        while(!S.empty() && arr[i] > arr[S.top()]) // change the condition to find next_smaller element (arr[i] < arr[S.top()])
        {
            int idx = S.top(); S.pop();
            res[idx] = i - idx; // add idx or value depending on what is asked.
        }
        S.push(i);
    }
    return res;
}

/*
Given an integer array heights representing the heights of histogram bars, write a function to find the largest rectangular area possible in a histogram, where each bar's width is 1.*/

/*
To calculate the largest rectangle at each index, we need to know the index of the first shorter bar to both the left and the right of the current bar. The width of the rectangle is the difference between the two indices - 1, and the height is the height of the current bar. right -left - 1, as left & right not part pf rectangle*/
long largestHistogram(const vector<int>& H)
{
    stack<int> S;
    int ma = 0;
    for(int i = 0; i < H.size(); ++i)
    {
        while(!S.empty() && H[i] < H[S.top()])
        {
            int h = H[S.top()]; S.pop();
            int ridx = i;
            int lidx = !S.empty() ? S.top() : 0;
            int w = ridx - lidx - 1;
            ma = max(ma, w * h);
        }
        S.push(i);
    }
    return ma;
}

int main()
{

    vector<int> arr{2, 1, 3, 2, 4, 3};
    auto res = next_greater_element(arr);
    for(auto r : res)
        cout << r << " ";
    cout << endl;
    auto res2 = daily_temoratures(arr);
    for(auto r : res2)
        cout << r << " ";
    cout << endl;
    vector<int> H {2,8,5,6,2,3};
    auto ma = largestHistogram(H);
    cout << ma << endl;
    return 0;
}