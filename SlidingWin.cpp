#include <bits/stdc++.h>

using namespace std;
// expand window till the point, condition required is satisfied, once violated, shrink the window & continue till condition is satisfied again, repeat till end.
/*
while(!end)
{
    expand & update current running value
    while(cond) // criteria matches
    {
        // update the optimal value needs to be calculated
        shrink
    }
    return max;
}

*/

/* suitable for
- sequentially iterable containers like array, strings, linked list etc.
- find min/max, longest/shortest, contains etc
*/
// optimization problems, is this the best i can do?

// fixed size sliding window
// find maximum sum of contiguios subarray of  size k
// running sum , and max sum,
int findMaxSubArraySum(const vector<int> &arr, int k)
{
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        currSum += arr[i];
        if (i >= k - 1) // reached K // window size
        {
            maxSum = max(maxSum, currSum);
            currSum -= arr[i - (k - 1)]; // slide & subtract the furthesr left  value.
        }
    }
    return maxSum;
}

// dynamic size sliding window
// 2 ways in dynamic sliding
// 1. finding max/longest, keep increasing till condition satisfied & checking max. if cond false keep shrinking.
// 2. find min/smallest. once satisfying condition is hit, check window size, keep shrinking till cond it satisfied.

int smallestSubArray(const vector<int> &arr, int sum)
{
    int wSize = INT_MAX;
    int currSum = 0;
    int ws = 0;
    for (int we = 0; we < arr.size(); ++we)
    {
        currSum += arr[we];
        while (currSum >= sum) // check if condition is satisfied,
        {
            wSize = min(wSize, we - ws + 1);
            currSum -= arr[ws]; // try to improve/optimize further till cond is true.
            ws++;
        }
    }
    return wSize;
}

int lengthOfLongestSubstring(string s)
{
    int ws = 0;
    int we = 0;
    int wm = INT_MIN;
    unordered_set<char> map;

    for (; we < s.length(); we++)
    {
        while (map.count(s[we]))
        {
            map.erase(s[ws]);
            ws++;
        }
        map.insert(s[we]);
        wm = max(wm, we - ws + 1);
    }
    return wm == INT_MIN ? 0 : wm;
}

void decrFreq(unordered_map<char, int> &map, char c)
{
    if (--map[c] == 0)
        map.erase(c);
}

// dynamic sliding window with auxilary data structure
int longestSubStrDist(const string &s, int k)
{
    int maxS = INT_MIN;
    int currS = 0;
    unordered_map<char, int> freq;
    int ws = 0;
    for (int we = 0; we < s.size(); ++we)
    {
        currS++;
        freq[s[we]]++;
        while (freq.size() > k)
        {
            decrFreq(freq, s[ws]);
            currS--;
            ws++;
            maxS = max(maxS, currS);
        }
    }
    return (maxS == INT_MIN) ? currS : maxS;
}

// longest substring if k chars can be replaces
int characterReplacement(string s, int k)
{

    unordered_map<char, int> fmap;
    int start = 0;
    int end = 0;
    int max_freq = 0;
    int ws = 0;
    int max_len = 0;
    for (; end < s.size(); ++end)
    {
        fmap[s[end]]++;
        max_freq = max(max_freq, fmap[s[end]]);
        ws = end - start + 1;
        if (ws - max_freq > k)
        {
            // max_len = max(max_len,ws);
            fmap[s[start]]--;
            start++;
        }
        max_len = max(max_len, end - start + 1);
    }
    return max_len;
}

int findMinOps(const vector<int> &arr, int x)
{
    auto sum = accumulate(arr.begin(), arr.end(), 0);
    int target = sum - x;
    if (target < 0)
        return -1;
    int currSum = 0;
    int wSize = INT_MIN;
    int ws = 0;
    for (int we = 0; we < arr.size(); ++we)
    {
        currSum += arr[we];
        while (currSum > target) // check if condition is satisfied,
        {
            currSum -= arr[ws]; // try to improve/optimize further till cond is true.
            ws++;
        }
        if (currSum == target)
        {
            wSize = max(wSize, we - ws + 1);
        }
    }
    if (wSize == INT_MIN)
        return -1;
    return arr.size() - wSize;
}

// TODO : goes TLE, find more optimal solutions
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<string> perms;
    vector<int> ret;
    sort(words.begin(), words.end());
    do
    {
        string str = "";
        for (const auto w : words)
            str += w;
        perms.push_back(str);
    } while (next_permutation(words.begin(), words.end()));

    string current = "";
    int csz = perms[0].size();
    if (s.size() < csz)
        return ret;
    int start = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        current += s[i];
        if (current.size() >= csz)
        {
            if (find(perms.begin(), perms.end(), current) != perms.end())
            {
                ret.push_back(start);
            }
            current.erase(current.begin());
            start++;
        }
    }
    return ret;
}

string minWindow(string s, string t)
{
    string ret = "";
    // s = "ADOBECODEBANC", t = "ABC"
    unordered_map<char, int> tmap;
    int counter = t.length();
    if (s.length() < t.length())
        return ret;
    if (s.empty() || t.empty())
        return ret;
    // create tmap;
    for (auto c : t)
    {
        tmap[c]++;
    }
    int start = 0;
    int end = 0;
    int head = 0;
    int ws = INT_MAX;
    for (; end < s.size(); ++end)
    {
        if (tmap[s[end]]-- > 0)
            counter--;

        while (counter == 0)
        {
            if (ws > end - start)
            {
                ws = end - start;
                head = start;
            }
            // below line is tricky, it checks for tmap[c] == 0 first,and increments afterwards,
            if (tmap[s[start]]++ == 0)
                counter++;
            start++;
        }
    }
    return ws == INT_MAX ? "" : s.substr(head, ws + 1);
}

string minWindow2(string s, string t)
{
    vector<int> map(128, 0);
    for (auto c : t)
        map[c]++;
    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < s.size())
    {
        if (map[s[end++]]-- > 0)
            counter--; // in t
        while (counter == 0)
        { // valid
            if (end - begin < d)
                d = end - (head = begin);
            if (map[s[begin++]]++ == 0)
                counter++; // make it invalid
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}

int main()
{
    vector<int> vec{4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    auto maxSum = findMaxSubArraySum(vec, 3);
    cout << "MaxSum : " << maxSum << endl;

    return 0;

    auto srt = minWindow("ADOBECODEBANC", "ABC");
    auto srt2 = minWindow2("ADOBECODEBANC", "ABC");
    int minW = smallestSubArray(vec, 8);
    int minW11 = smallestSubArray(vec, 11);
    cout << "minW8 : " << minW << endl;
    cout << "minW11 : " << minW11 << endl;
    string S = "AAAHHIBCC";
    auto maxStr = longestSubStrDist(S, 2);
    auto maxStr3 = longestSubStrDist(S, 4);

    cout << "maxS :" << maxStr << endl;
    cout << "maxS3 :" << maxStr3 << endl;

    vector<int> arrs{3, 2, 20, 1, 1, 3};
    auto ops = findMinOps(arrs, 10);
    cout << ops << endl;
    vector<int> arr{1, 1};
    auto ops1 = findMinOps(arr, 3);
    cout << ops1 << endl;

    string cons = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    auto vret = findSubstring(cons, words);
    copy(vret.begin(), vret.end(), ostream_iterator<int>(cout, " "));
    return 0;
}