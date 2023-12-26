#include <bits/stdc++.h>
using namespace std;


int maxSA(vector<int> &arr)
{
    int maxs = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
    {

        for (int j = i + 1; j < arr.size(); ++j)
        {
            int csum = accumulate(arr.begin() + i, arr.begin() + j, 0);
            maxs = max(maxs, csum);
        }
    }
    return maxs;
}

int maxSP(vector<int> &arr)
{
    int maxs = INT_MIN;
    for (int i = 0; i < arr.size(); ++i)
    {
        int csum = 0;
        for (int j = i + 1; j < arr.size(); ++j)
        {
            csum += arr[j];
            maxs = max(maxs, csum);
        }
    }
    return maxs;
}

int maxSPR(vector<int> &arr)
{
    int maxs = INT_MIN;
    vector<int> psum;
    partial_sum(arr.begin(), arr.end(), back_inserter(psum));
    int csum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            csum = psum[j] - psum[i - 1];
            maxs = max(maxs, csum);
        }
    }
    return maxs;
}
// TODO : wrong somewhere, fix it.we are not checking if two sub vectors are adjoining.
int maxSDQ(vector<int> &arr, int l, int u)
{
    if (l > u)
        return 0;
    if (l == u)
        return max(0, arr[l]);
    int lmax = 0, rmax = 0, sum = 0;
    int m = l + (u - l) / 2;
    for (int i = m; i >= l; --i)
    {
        sum += arr[i];
        lmax = max(lmax, sum);
    }
    sum = 0;
    for (int i = m + 1; i <= u; ++i)
    {
        sum += arr[i];
        rmax = max(rmax, sum);
    }
    int ll = maxSDQ(arr, l, m);
    int rr = maxSDQ(arr, m + 1, u);
    int lm = max(ll, rr);
    int total = max(lmax + rmax, lm);

    return total;
}

long maxSC(vector<int> &arr)
{
    long maxs = INT_MIN;
    long maxe = INT_MIN;

    for (auto n : arr)
    {
        maxs = max(maxs + n, 0L);
        maxe = max(maxs, maxe);
    }
    return maxe;
}

int main()
{
    using chrono::duration;
    using chrono::duration_cast;
    using chrono::high_resolution_clock;
    using chrono::nanoseconds;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(-10000, 10000);

    auto gen = [&dist, &rng]()
    {
        return dist(rng);
    };
    vector<int> v(100);
    generate(v.begin(), v.end(), gen);

    //    vector<int> v = {31, -49, 59, 26, -53, 58, 97, -93, -23, 85};
    auto t1 = high_resolution_clock::now();
    int maxs = maxSA(v);
    auto t2 = high_resolution_clock::now();
    auto g1 = duration_cast<nanoseconds>(t2 - t1);
    cout << "Brute time " << g1.count() << " ns :" << maxs << endl;

    auto t3 = high_resolution_clock::now();
    int maxp = maxSP(v);
    auto t4 = high_resolution_clock::now();
    auto g2 = duration_cast<nanoseconds>(t4 - t3);
    cout << "Progressive time " << g2.count() << " ns :" << maxp << endl;

    auto t5 = high_resolution_clock::now();
    int maxpr = maxSPR(v);
    auto t6 = high_resolution_clock::now();
    auto g3 = duration_cast<nanoseconds>(t6 - t5);
    cout << "Progressive time " << g3.count() << " ns :" << maxpr << endl;

    auto t7 = high_resolution_clock::now();
    int maxdq = maxSDQ(v, 0, v.size() - 1);
    auto t8 = high_resolution_clock::now();
    auto g4 = duration_cast<nanoseconds>(t8 - t7);
    cout << "Divide & Rule time " << g4.count() << " ns :" << maxdq << endl;

    auto t9 = high_resolution_clock::now();
    int maxsc = maxSC(v);
    auto t10 = high_resolution_clock::now();
    auto g5 = duration_cast<nanoseconds>(t10 - t9);
    cout << "Scanning/Kadane time " << g5.count() << " ns :" << maxsc << endl;

    return 0;
}