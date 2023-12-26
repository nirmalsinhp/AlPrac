#include <bits/stdc++.h>
using namespace std;

bool canJump(const vector<int>& vec)
{
    int m = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(i > m)
            return false;
        m = max(m, i + vec[i]);
    }
    return true;
}

int canJumpSteps(const vector<int>& vec)
{
    int m = 0, lastJumped = 0, jump = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        m = max(m, i + vec[i]);
        if(i == lastJumped)
        {
            lastJumped = m;
            jump++;

        }
    }
    return jump;
}

bool canJumpRev(const vector<int>& nums)
{
    int goal = nums.size() - 1;
    for(int i = nums.size() - 1; i >=0; --i)
    {
        if(i + nums[i] >= goal)
            goal = i;
    }

    return (goal == 0);
}

int main()
{
    vector<int> vec{2,3,1,1,4};
    vector<int> vec1{3,2,1,0,4};
    auto canj = canJump(vec);
    auto canj1 = canJump(vec1);
    auto jumps = canJumpSteps(vec1);
    auto canjr = canJumpRev(vec);
    auto canjr1 = canJumpRev(vec1);
    cout << canj <<  " " << canj1 << " " << jumps << endl;
    cout << canjr << " " << canjr1 << endl;
    
    return 0;
}