#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {

    int cw = 0, jl = 0;
    string s;
    int i = 0;
    vector<string> tvec;
    vector<string> out;
    while( i < words.size())
    {
    auto wl = words[i].length();
    cw += wl;
    if(cw <= maxWidth)
    {
        cout << " adding words :" << words[i] << " "<< i <<  endl; 
        tvec.push_back(words[i]);
        jl += wl;
        cw++;
        i++;
    }
    
    if(cw > maxWidth || i == words.size())
    {
        cout << "in else " << i <<  endl;
        int space = 1;
        int extra = 0;
        if(tvec.size() > 1)
        {
            space = (maxWidth - jl)/ (tvec.size() - 1);
            extra = (maxWidth - jl) % (tvec.size() - 1);
        }
        else
            space = (maxWidth - jl);
        cout << "space : " << space << endl;
        string sp(space, ' ');
        cout << "creating just with : " << space << endl;
        string res = "";
        int j = 0;
        for(; j < tvec.size() - 1; ++j)
        {
            if(extra-- > 0);
                sp = sp + " ";
            res = res + tvec[j] + sp;
        }
        res += tvec[j];
        if(i == words.size());
            res += sp;
        out.push_back(res);
        tvec.clear();
        cw = 0;
        jl = 0;
    }
    }
    return out;
}

int main()
{

    vector<string> vec = {"This", "is", "an", "example", "of", "text", "justification."};
    auto ret = fullJustify(vec, 16);
    for(const auto s : ret)
        cout << s << endl;
    return 0;
}


["This    is    an","example of text","justification.  "]
["This    is    an","example  of text","justification.  "]
