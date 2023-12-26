#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::setprecision;
// using std::sort;
// using std::streamsize;
// using std::string;
// using std::vector;
using namespace std;

void grades(vector<int>& grade)
{

}



template <typename T>
T median(vector<T>& vec)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
    {
        cout << endl
             << "You must enter your grades. "
                "Please try again."
             << endl;
        return 1;
    }
    // sort the grades
    sort(vec.begin(), vec.end());
    // compute the median vec grade
    vec_sz mid = size / 2;
    T median;
    median = size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2
                           : vec[mid];
    return median;

}

template <class In, typename Out>
Out mcopy(In begin, In end, Out dest)
{
    while(begin != end)
        *dest++ = *begin++; // (*dest = *begin; begin++, dest++)
    return dest;
}



int main()
{
  /**/  // ask for and read the student's name
/**/    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    auto & name1 = name;
    const string& cn =  name1;
    cout << &name << endl;
    cout << &name1 << endl;
    cout << &cn << endl;
    
    std::list<int> vec {1,2,3,4,5,5,6,6,7,7,7};
    //cout << vec.size() << " " << vec.capacity() << endl;
    //vec.erase(vec.begin() + 2);
    //cout << vec.size() << " " << vec.capacity() << endl;
    //grades(vector<int>());

    cout << "Hello, " << name << "!" << endl;
    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    // ask for and read the homework grades
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    vector<double> homework;
    double x;
    // invariant: homework contains all the homework grades read so far
    // while (cin >> x)
    //     homework.push_back(x);

    copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(homework));    
    auto med = median(homework);
    // check that the student entered some homework grades
    // compute and write the final grade
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * med
         << setprecision(prec) << endl;
    
    vector<double> hc;
    auto ou = mcopy(homework.begin(), homework.end(), back_inserter(hc));
    copy(hc.begin(), hc.end(), ostream_iterator<double>(cout, ", "));
    cout << endl;
    cout << *hc.end() << endl;
    return 0;
}


