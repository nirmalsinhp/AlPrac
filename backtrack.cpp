#include <bits/stdc++.h>


using namespace std;
bool finished = false;


bool is_solution(vector<bool>& a, int k, int n)
{
    return k == n;
}

void unmake_move(vector<bool>& a, int k, int n)
{
}

void make_move(vector<bool>& a, int k, int n)
{
}

void construct_subsets(vector<bool>& a, int k, int n, int& nc, vector<bool>& C)
{
    C[0] = true;
    C[1] = false;
    nc = 2;
}
void process_solution(vector<bool>& a, int k, int n)
{
    cout << "k :" << k << " n :" << n << endl; 
    cout << "{";
    for(int i = 1; i < k + 1; i++)
    {
        if(a[i])
            cout << i;
    }
    cout << "}" << endl;
}

void back_track(vector<bool>& a, int k, int n)
{
    vector<bool> C(2, false);
    int nc;

    if(is_solution(a, k ,n))
    {
        process_solution(a, k, n);
    }
    else
    {
        k = k + 1;
        construct_subsets(a,k,n, nc, C);
        for(int i=0 ; i < nc; i++ )
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
    vector<bool> a(n+1, false);
    back_track(a, 0, n);
}
int main()
{
    generate_subsets(4);
    return 0;
}