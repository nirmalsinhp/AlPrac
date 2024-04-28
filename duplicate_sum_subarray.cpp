#include <bits/stdc++.h>
using namespace std;

/*
Given N numbers: a[0], a[1], ..., a[N-1] find i <= j such that a[i] = a[j] and sum a[i] + a[i+1] + ... + a[j-1] + a[j] is maximized.

Example

Input: [1, 2, 3, 2, 5]

Output: i = 1, j = 3   sum: 7

  */
/*
pair<int, int> getMaximumSumPair(const vector<int> &arr)
{
    vector<int> ps;
    partial_sum(arr.begin(), arr.end(), back_inserter(ps));
    unordered_map<int, vector<int>> duplicates;

    for (int i = 0; i <)
        int psum;
    pair<int, int> out;
    long maxval = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (duplicates.count(arr[i]))
        {
        psum = ps[i] - ps[duplicates[arr[i]];
        if(psum > maxval)
        {
                maxval = psum;
                out = make_pair(duplicates[arr[i]], i);
        }
        }
        else
            duplicates[arr[i]] = i;
    }


    /// ignore below
    //remove if only one element present
    duplicates.erase(remove_if(duplicates.begin(), duplicates.end(), [](auto ele)
                                                                      {
                                                                        return ele.second.size() <= 1;
                                                                       }), duplicates.end());

    for(auto dp : duplicates)
    {
      for(int i = 0; i < dp.second.size(); i++)
      {
        for(int j = i; j < dp.second.size(); ++j)
        {
          psum = ps[j] - ps[i];
          if(psum > maxval)
          {
            maxval = psum;
            out = make_pair(i,j);
          }
        }
      }

      return out;
    }
}
*/
pair<int, int> getMaximumSumPairH(const vector<int> &arr)
{
    vector<int> ps;
    partial_sum(arr.begin(), arr.end(), back_inserter(ps));
    unordered_map<int, vector<int>> dup_ind;
    for (int i = 0; i < arr.size(); ++i)
    {
        dup_ind[arr[i]].push_back(i);
    }
    // dup_ind.erase(remove_if(dup_ind.begin(), dup_ind.end(), [](auto ele)
    //                            { return ele.second.size() <= 1; }),
    //                  dup_ind.end()); // can not use it.

    pair<int, int> out; 
    int maxsum = INT_MIN;
    for(auto di : dup_ind)
    {
        cout << "element :" << di.first << endl;
        auto indices = di.second;
        if(indices.size() < 2)
            continue;
        int csum = 0;
        pair<int, int> co = make_pair(indices[0], indices[1]);
        for(int i = 1; i < indices.size(); i++)
        {
            int psum = ps[indices[i]] - ps[indices[i-1] - 1];
            if(psum > csum + psum)
            {
                csum = psum;
                co = make_pair(indices[i-1], indices[i]);
            }
            else
            {
                csum = csum + psum;
                co.second = indices[i];
            }
            cout << psum << " " << csum << " ";
            if(csum > maxsum)
            {
                cout  << " - " << csum << " " << maxsum << endl;
                maxsum = csum;
                out = co;
            }
        }
    }
    return out;
}

int main()
{
    vector<int> arr = {1,2,3,-24,2,4,10,-20,4,2,100,4};
    auto out = getMaximumSumPairH(arr);
    cout << out.first <<" - " <<  out.second << endl;
    return 0;
}
