#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {

    vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;


    for(int i = 2; i <= sqrt(n) + 1; ++i)
    {
        cout << "i :" << i << endl;;
        auto div = [=](const int& v) -> bool { return v % i == 0;};
        // cout << div( i * i) << endl;
        //replace_if(primes.begin()+2, primes.end(), [&](const int& v) -> bool{ return (v % i) == 0;}, false);
        for(int j = 4 ; j < n+1; ++j)
        {
            auto d = div(j);
            if(d)
                primes[j] = false;

        }
    }
    
    auto pr = count(primes.begin(), primes.end(), true);

    return pr;
}


int main()
{
    auto c = countPrimes(10);
    cout << "count " << c << endl;
    return 0;
}