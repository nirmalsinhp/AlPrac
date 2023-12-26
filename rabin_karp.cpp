#include <bits/stdc++.h>
using namespace std;

/*
- Modular arithmatic property.
(a + b) mod Q = ((a mod Q) + (b mod Q)) mod Q
(a * b) mod Q = ((a mod Q) * (b mod Q)) mod Q
*/
/*
- compute hash of pattern,
- comoute hash for text chars, i + M, 
- if hash are equeal, match strings, 
*/

long horner_hash(const string& pattern)
{
    int R = 26; // for small chars alphabets
    long hash = 0;
    long prime = 997;
    for(int i = 0; i < pattern.length(); ++i)
    {
        hash = (hash * R + pattern[i] - 'a') % prime;
    }
    return hash;
}
int rabin_karp(const string& text, const string& pattern)
{
    auto t1 = chrono::high_resolution_clock::now();
    
    int N = text.length();
    int M = pattern.length();
    long ph = horner_hash(pattern);
    cout << "pattern : " << ph << endl;
    long th = horner_hash(string(text.substr(0, M)));
    long prime = 997;
    int R = 26;
    long RM = 1;
    for(int i = 0; i < M; ++i)
    {
        RM = (RM * R) % prime;
    }
    for(int i = M; i < N - M; ++i)
    {
        if(ph == th)
        {
            if(pattern == text.substr(i - M + 1, M));
                return (i - M + 1);
        }

        th = ((th + prime - RM * text[i - M] % prime) % prime);
        th = (th * R + text[i]) % prime;
        //cout << th << endl;
    }
    auto t2 = chrono::high_resolution_clock::now();
    auto d1 = t2 - t1;
    cout << " rabin :" << d1.count() << endl;
    return -1;
}

int brute(const string& text, const string& pattern)
{
    auto t1 = chrono::high_resolution_clock::now();
    
    int N = text.length();
    int M = pattern.length();
    for(int i = 0; i < N - M; ++i)
    {
        int j;
        for(j = 0; j < M; ++j)
        {
            if(text[i + j] != pattern[j])
                break;
        }
        if(j == M) return i;
    }
    auto t2 = chrono::high_resolution_clock::now();
    auto d1 = t2 - t1;
    cout << " brute :" << d1.count() << endl;
    return -1;
}

int main()
{
    string text("from the dusty mesa, her looming shadow grows, hidden in the branches of a poison creosto, mountain comes will come to take away your bones.");

    cout << ((brute(text, "looming") >= 0) ? " found" : " not found") << endl;
    cout << ((brute(text, "cones") >= 0) ? " found" : " not found") << endl;

    cout << ((rabin_karp(text, "looming") >= 0) ? " found" : " not found") << endl;
    cout << ((rabin_karp(text, "cones") >= 0) ? " found" : " not found") << endl;
    return 0;
}