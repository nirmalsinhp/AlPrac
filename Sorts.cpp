#include <bits/stdc++.h>

using namespace std;



//O(n2), n2/2, comparison, n exchanges.
// in  every iteration i, find min in remaining entry and exchange with a[i].
// everything left of i is in correct position.
template <typename T>
void selection_sort(vector<T>& vec)
{
    auto size = vec.size();
    for(auto i = 0;  i < size; ++i)
    { // L --> R
        auto min = i;
        for(int j = i+1; j < size; ++j)
        { // L --> R
            if(vec[j] < vec[min])
                min = j;
        }
        swap(vec[min], vec[i]);
    }
}

template <typename T>
void mselection_sort(vector<T>& vec)
{
    for(auto itr = vec.begin(); itr!=vec.end(); ++itr)
    {
        auto mitr = min_element(itr, vec.end());
        swap(*itr, *mitr);
    }
}



// best case n, worst case  O(n2)
// in interation i, swap a[i] with each larget entry to it's left.
// entries on left are sorted, right is unseen.
template <typename T>
void insertion_sort(vector<T>& vec)
{
    int S = 0;
    auto size = vec.size();
    for(auto i = 0;  i < size; ++i)
    { // L --> R
        for(int j = i; j > 0; --j)
        { // R --> L || L <-- R
            if(vec[j] < vec[j-1])
            {
                S++;
                swap(vec[j], vec[j-1]);
            }
            else
                break; // everything in left is sorted, 
        }
    }
    cout << S  << " Swaps" << endl;
}

void merge(vector<int>& arr, vector<int>& aux, int lo, int mid, int hi)
{
    //assert(is_sorted(begin(arr) + lo, begin(arr) + mid ));
    //assert(is_sorted(begin(arr) + mid + 1, begin(arr) + hi ));

//    cout << " lo : " << lo << " mid :" << mid <<" hi : " << hi << endl;
    for(int k = lo; k <=hi; ++k)
        aux[k] = arr[k];    

    int i = lo;
    int j = mid + 1;
    for(int k = lo; k <= hi; ++k)
    {
       // k <= h, because lo-hi, is closed range.

        if(i > mid) arr[k] = aux[j++];
        else if (j > hi) arr[k] = aux[i++];
        else if(aux[i] < aux[j]) arr[k] = aux[i++];
        else arr[k] = aux[j++];
    }
}

void merge_sort(vector<int>& arr, vector<int>& aux, int lo, int hi)
{
    if(hi <= lo)
        return;
    auto mid = lo + (hi - lo) / 2;
    merge_sort(arr, aux, lo, mid);
    merge_sort(arr, aux, mid+1, hi);
    // if(arr[mid] < arr[mid + 1])
    //     return;
    merge(arr, aux, lo, mid, hi);
}


void merge_sort(vector<int>&arr)
{
    vector<int> aux(arr.size());
    merge_sort(arr, aux, 0, arr.size() - 1);
    return;
}


// also check 3 way partitioning, where if val == pivot, just increment, no swaps.
// quick - select -- run partition multiple times, till you get the element k, nth element.
// dutch flag problem
int partition(vector<int>& arr, int lo, int hi)
{
    int pi = hi;
    int first = lo;

    for(int i = lo; i < hi; ++i)
    {
        if(arr[i] < arr[pi])
        {
            swap(arr[i], arr[first]);
            first++;
        }
    }
    swap(arr[pi], arr[first]);
    return first;

}

void qsort(vector<int>& arr, int lo, int hi)
{
    if(lo < hi)
    {
        auto pivot = partition(arr, lo, hi);
        qsort(arr, lo, pivot - 1);
        qsort(arr, pivot + 1, hi);
    }
}

void quick_sort(vector<int>& arr)
{
    auto lo = 0;
    auto hi = arr.size() - 1;
    qsort(arr, lo, hi);
}

template<typename T>
void heap_sort(vector<T>& vec)
{
    priority_queue<T> pq;
    for(const auto & v : vec)
        pq.push(v);
    for(auto& v : vec )
    {
        v = pq.top();
        pq.pop();
    }

}

int main()
{

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,10000000);

    auto gen = [&dist, &rng](){
                   return dist(rng);
               };
    vector<int> v(100);
    generate(v.begin(), v.end(), gen);

    auto t1 = chrono::high_resolution_clock::now();
    insertion_sort(v);
    auto t2 = chrono::high_resolution_clock::now();
    auto d1 = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "Insertion " << d1.count() <<  " MicroSecond(s)" << endl;
    cout << boolalpha << is_sorted(v.begin(), v.end()) << endl;;

    auto t11 = chrono::high_resolution_clock::now();
    insertion_sort(v);
    auto t22 = chrono::high_resolution_clock::now();
    auto d11 = chrono::duration_cast<chrono::microseconds>(t22 - t11);
    cout << "Already Sorted Insertion " << d11.count() <<  " MicroSeconds(s)" << endl;
    cout << boolalpha << is_sorted(v.begin(), v.end()) << endl;;

    shuffle(v.begin(), v.end(), default_random_engine());
    auto t3 = chrono::high_resolution_clock::now();
    selection_sort(v);
    auto t4 = chrono::high_resolution_clock::now();
    auto d2 = chrono::duration_cast<chrono::microseconds> (t4 - t3);
    cout << boolalpha << is_sorted(v.begin(), v.end()) << endl;;
    cout << "Selection "  << d2.count() << " MicroSeconds(s)" << endl;

    shuffle(v.begin(), v.end(), default_random_engine());
    auto mt3 = chrono::high_resolution_clock::now();
    mselection_sort(v);
    auto mt4 = chrono::high_resolution_clock::now();
    auto md2 = chrono::duration_cast<chrono::microseconds> (mt4 - mt3);
    cout << boolalpha << is_sorted(v.begin(), v.end()) << endl;;
    cout << "MSelection "  << md2.count() << " MicroSeconds(s)" << endl;

    shuffle(v.begin(), v.end(), default_random_engine());
    auto t5 = chrono::high_resolution_clock::now();
    merge_sort(v);
    auto t6 = chrono::high_resolution_clock::now();
    auto d3 = chrono::duration_cast<chrono::microseconds> (t6 - t5);
    cout << boolalpha << is_sorted(v.begin(), v.end()) << endl;;
    cout << "merge "  << d3.count() << " MicroSeconds(s)" << endl;

    shuffle(v.begin(), v.end(), default_random_engine());
    auto t7 = chrono::high_resolution_clock::now();
    quick_sort(v);
    auto t8 = chrono::high_resolution_clock::now();
    auto d4 = chrono::duration_cast<chrono::microseconds> (t8 - t7);
    cout << boolalpha << is_sorted(v.begin(), v.end()) << endl;;
    cout << "Quick "  << d4.count() << " MicroSeconds(s)" << endl;

    shuffle(v.begin(), v.end(), default_random_engine());
    auto t9 = chrono::high_resolution_clock::now();
    heap_sort(v);
    auto t10 = chrono::high_resolution_clock::now();
    auto d5= chrono::duration_cast<chrono::microseconds> (t10 - t9);
    cout << boolalpha << is_sorted(v.rbegin(), v.rend()) << endl; // used reverse iterators as priority_queue is max_heap.
    cout << "Heap "  << d5.count() << " MicroSeconds(s)" << endl;

    return 0;
}