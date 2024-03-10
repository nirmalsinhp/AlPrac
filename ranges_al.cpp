#include <bits/stdc++.h>
using namespace std;

template <typename T, template <typename ...> class container> 
static void print_container(const container<T>& C, std::string del = " ")
{
    for(const auto& c: C)
        cout << c << " ";
    cout << endl;
}

vector<string> n_ranges(const vector<int>& arr)
{
    vector<string> out;
    vector<int> diff;
    adjacent_difference(arr.begin(), arr.end(), back_inserter(diff));
    print_container(arr);
    print_container(diff);
    /*auto aitr = arr.begin();
    auto itr = diff.begin();
    auto citr = itr;
    citr++;
    while(citr != diff.end)
    {
        auto citr = find_if(citr, diff.end(), [](auto n)
                                                        {
                                                            return n >1;
                                                        });

    }*/
    return out;

}

int main()
{
    vector<int> arr = {0,2,3,4,6,8,9};
    vector<string> vs = n_ranges(arr);
    return 0;
}