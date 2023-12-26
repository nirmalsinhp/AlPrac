#include <bits/stdc++.h>

using namespace std;


int main()
{
    vector<int> vec;
    list<int> list;
    // back_inserter creates back_insert_iterator<vector<int>> , function type deduction helps it adapt to any containers.

    cout << "enter value :";
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(),
        back_inserter(vec));
    
    copy(vec.cbegin(), vec.cend(),  ostream_iterator<int>(cout, ", "));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.clear();
    cout << "enter value :";
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(),
        front_inserter(list));
    
    copy(istream_iterator<int>(cin),
        istream_iterator<int>(),
        inserter(list, list.end()));
    
    copy(list.cbegin(), list.cend(),  ostream_iterator<int>(cout, ", "));


    copy(list.rbegin(), list.rend(),  ostream_iterator<int>(cout, ", "));

    multimap<string, string> mm = { 
        {"N", "N"},
        {"N", "NN"},
        {"N1", "NNN"},
        {"N2", "3N"},
        {"N2", "36N"},
        {"N", "6N"}
        };
            //multimap do not have [] --- check
        cout <<  mm["N"] << endl;



    return 0;
}
