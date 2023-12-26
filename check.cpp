#include <bits/stdc++.h>

using namespace std;



auto minmax(const vector<int>& a )
{
    auto [m1, n1] = minmax_element(a.begin(), a.end());
    return *n1 - *m1;
}
// find middle element, compare with item to be searched, if == return mid, if greater than item high = mid - 1
// else low  =  mid + 1, nlogn time
template <typename T>
int b_s(vector<T> seq,  T item) 
{

    int low = 0;
    int high = seq.size() - 1;
    
    int mid;

    while(low <= high)
    {
        mid = low + (high - low) / 2;
        T guess = seq[mid];
        if(guess == item)
            return mid;
        else if( guess > item)
            high = mid - 1;
        else if(guess < item)
            low = mid + 1;
    } 
    return -1;
}   


template <typename T>
int bsr(vector<T>& seq, T item, int low, int high)
{
    cout << "bsr called with " << item << " " << low << " " << high << endl;
    if(low <= high)
        return -1;
    int mid = low + (high - low) / 2;
    cout << low << " " << mid << " " << high << endl;
    if(seq[mid] == item)
        return mid;
    else if(seq[mid] > item)
        bsr(seq, item, low, mid - 1);
    else if(seq[mid] > item)
        bsr(seq, item, mid + 1, high);
}

template <typename T>
int b_s_r(vector<T>& seq,  T item) 
{
    return bsr(seq, item, 0, seq.size() - 1);
}   

int part(vector<int>& vec, int l, int h)
{
    int p = h;
    int fh = l;
    for(int i =l; i <h; i++)
    {
        if(vec[i] < vec[p])
        {
            swap(vec[i], vec[fh]);
            fh++;
        }
    }
    swap(vec[p], vec[fh]);
    return fh;
}


void qs(vector<int>& vec, int l, int h)
{
    if (l < h)
        return;
    int p = part(vec, l, h);
    qs(vec, l, p -1);
    qs(vec, p + 1, h);
}

void quicksort(vector<int>& vec)
{
     qs(vec, 0, vec.size() - 1);
     return;

}

// find smallest element, and swap values, repeat n times, n2 run time
template <typename T>
void selection_sort(vector<T>& vec)
{
    int min = 0;
    int size = vec.size();
    for(int i = 0; i < size; ++i)
    {
        min = i;
        for(int j = i; j < size; ++j)
        {
            if(vec[j] < vec[min])
                min = j;
        }
        swap(vec[i], vec[min]);
    }

}

int main()
{
    vector<int> nums {1,2,3,4,3,4,2,4,24,4,3,42,423,323,3};
    nth_element(nums.begin(), nums.begin() + 3, nums.end(), greater<int>());
    cout << *(nums.begin() + 2) << endl;
    vector<int> s = {1,2,3,4,5,6,7,8,9,12,22,23,45};
    cout << "search_out" << b_s(s, 5) << endl;
    cout << "search_out" << b_s(s, 25) << endl;
    cout << "search_out recursve :" << b_s_r(s, 25) << endl;
    cout << "lower_bound :" << *lower_bound(s.begin(), s.end(),5) << endl;
    cout << "lower_bound :" << *lower_bound(s.begin(), s.end(),25) << endl;
    cout << "upper_bound :" << *upper_bound(s.begin(), s.end(),5) << endl;
    cout << "upper_bound :" << *upper_bound(s.begin(), s.end(),25) << endl;
    cout << "binary_search :" << binary_search(s.begin(), s.end(),25) << endl;
 
    selection_sort( nums);
    vector<double> dv {1,2,3,4.4,4.3,4.1,4.2,4.6,3.5,89, 8.9};
    //selection_sort(dv);   
    quicksort(nums);   
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    copy(dv.begin(), dv.end(), ostream_iterator<double>(cout, ", "));
    vector<vector<int>> vec = { {1,2}, {2,3}};
    cout << " vec back : " << endl;
    cout << vec.back()[1] << endl;
    return 0;

}