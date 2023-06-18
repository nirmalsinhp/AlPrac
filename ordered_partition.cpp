#include <bits/stdc++.h>
using namespace std;


void reconstruct_partition(vector<int>& S, vector<vector<int>>& D, int n, int k)
{
    if(k == 1)
    {
        cout << "{ ";
        for(auto iter = S.begin() + 1; iter != S.begin() + n + 1; ++iter)
        {
            cout << *iter << " " << endl;
        } 
        cout << " }" << endl;
    }
    else
    {
        reconstruct_partition(S,D, D[n][k], k-1);
        cout << "{ " << endl;
        for(auto iter = S.begin() + (D[n][k] + 1); iter != S.begin() + n + 1; ++iter)
        {
            cout << *iter << " " << endl;
        } 
        cout << " }" << endl;   
    }
}

void print_matrix(const vector<vector<int>> & M)
{
    cout << " --------------------------------------" << endl;
    for(const auto & R : M)
    {
        for(const auto & C : R)
            cout << C << " " ;
        cout << endl;
    }
    cout << " --------------------------------------" << endl;
}

void order_partiotion(vector<int>& S, int n, int k)
{
    vector<int> P = S;
    partial_sum(P.begin(), P.end(), P.begin());
    vector<vector<int>> M(n+1, vector<int>(k+1));
    vector<vector<int>> D(n+1, vector<int>(k+1));

    // P.insert(P.begin(), 0);
    for(int i = 1; i <= n; ++i)
    {
        M[i][1] = P[i];
    }

    for(int j = 1; j <=k; ++j)
    {
        M[1][j] = S[1];  
    }

    int cost = INT_MIN;
    for(int i =2; i <= n; ++i)
    {
        for(int j = 2; j <= k; ++j)
        {
            M[i][j] = INT_MAX;
            for(int x = 1 ; x < i; ++x)
            {
                cost = max(M[x][j - 1], P[i] - P[x] );
                if(cost < M[i][j])
                {
                    M[i][j] = cost;
                    D[i][j] = x;
                }
            }
        }
    }

    reconstruct_partition(S, D, n, k);

    cout << "Matrix " << endl;
    print_matrix(M);
    cout << "Devider " << endl;
    print_matrix(D);

}



int main()
{

	int n;				/* how many books? */
	int k;				/* how many partitions? */


    cout  << "number of books :" ;
    cin >> n;

    cout << endl << "number of partition :";
    cin >> k;

    vector<int> S;
    cout << "enter book lengths" << endl;

    for(int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        S.push_back(l);
    }
    S.insert(S.begin(), 0);

    order_partiotion(S, n, k);

}