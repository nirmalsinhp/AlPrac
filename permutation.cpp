#include <bits/stdc++.h>


using namespace std;
bool finished = false;


bool is_solution(vector<int>& a, int k, int n)
{
    return k == n;
}

void unmake_move(vector<int>& a, int k, int n)
{
}

void make_move(vector<int>& a, int k, int n)
{
}

void construct_subsets(vector<int>& a, int k, int n, int& nc, vector<int>& C)
{
    vector<bool> in_perm(n+1, false);
    for(int i = 1; i < k; ++i)
    {
        in_perm[a[i]] = true;
    }

    nc = 0;
    for(int i = 1; i < n +1; ++i)
    {
        if(!in_perm[i])
        {
            C.push_back(i);
        }
    }

}
void process_solution(vector<int>& a, int k, int n)
{
    //cout << "k :" << k << " n :" << n << endl; 
    cout << "{";
    for(int i = 1; i < k + 1; i++)
    {
            cout << a[i];
    }
    cout << "}" << endl;
}

void back_track(vector<int>& a, int k, int n)
{
    vector<int> C;
    int nc;

    if(is_solution(a, k ,n))
    {
        process_solution(a, k, n);
    }
    else
    {
        k = k + 1;
        construct_subsets(a,k,n, nc, C);
        for(int i=0 ; i < C.size(); i++ )
        {
            a[k] = C[i];
            make_move(a, k, n);
            back_track(a, k, n);
            unmake_move(a, k, n);

        }
        if(finished)
            return;
    }

}

void generate_subsets(int n)
{
    vector<int> a(n+1);
    back_track(a, 0, n);
}

void permutations_stl(int n)
{
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    do
    {
        cout << "{";
        //copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
        for(const auto & i : a)
            printf("%d", i);
        cout << "}" << endl;
    }while(next_permutation(a.begin(),a.end()));
}
int main()
{
    using chrono::high_resolution_clock;
    using chrono::duration;
    using chrono::duration_cast;
    using chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    generate_subsets(8);
    auto t2 = high_resolution_clock::now();

    cout << "_______________"<< endl;
    auto t3 = high_resolution_clock::now();
    permutations_stl(8);
    auto t4 = high_resolution_clock::now();

    auto g1 = duration_cast<milliseconds>(t2 - t1);
    auto p1 = duration_cast<milliseconds>(t4 - t3);
    cout  << "gene time " << g1.count() << endl;
    cout  << "perm time " << p1.count() << endl;
    return 0;
}