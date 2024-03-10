#include <bits/stdc++.h>
using namespace std;

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        set<int> s1(nums1.begin(), nums1.end());
  //      set<int> s2(nums2.begin(), nums2.end());
    vector<int> s1 = {1,2};
    vector<int> s2 = {2};
        vector<int> result;
        for(auto n : s1)
            cout << n << " ";
        cout << endl;
        for(auto n : s2)
            cout << n << " ";
        cout << endl;
        set_intersection(nums1.begin(), nums1.end(),
                        nums2.begin(), nums2.end(),
                        back_inserter(result));
        for(auto n : result)
            cout << n << " ";
        return result;
        
    }


    int main()
    {
        vector<int> v1 = {1,2,2,1};
        vector<int> v2 = {2,2};
        auto out = intersection(v1,v2);
        return 0;
    }