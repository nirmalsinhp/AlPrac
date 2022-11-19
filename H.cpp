#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

void twoSum(const vector<int> in, int target)
{
    unordered_map<int, int> hmap;
    for(int i = 0; i < in.size(); ++i)
    {
        auto it = hmap.find(target - in[i]);
        if (it != hmap.end())
        {
            cout << "found" << endl;
            cout << in[i] << " " << it->first << endl;

            cout << i << " " << it->second << endl;
        }
        hmap[in[i]] = i;
    }

}

// int main()
// {

//     vector <int> in {1,2,3,4,5,2,32,4,5,34,3,2,4,232};
//     int var = 1;
//     cout << "hello" << var <<  endl;
//     twoSum(in, 9);
//     return 0;

// }


