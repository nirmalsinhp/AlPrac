#include <bits/stdc++.h>

using namespace std;

class Sub {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        out = {{}};
        for(auto n : nums)
        {
            int s = out.size();
            for(int i = 0; i < s; ++i)
            {
                out.push_back(out[i]);
                out.back().push_back(n);
            }
        }        
        return out;
    }
    private:
    vector<vector<int>> out;
};

int main()
{
    vector<int> nums ={1,2,3};

    Sub S;
    auto sets = S.subsets(nums);
    return 0;
}