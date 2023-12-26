#include <memory>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    /*cout << (void *) argv[argc] << endl;
    cout <<  argv[argc + 1] << endl;*/
    // this works because, environment variables are stored on stack like this.
    //*(char *) 0 = 0;
    // *reinterpret_cast<char*>(nullptr) = 0;
    // gcc puts a trap over here, so seg fault

    auto aup = make_unique<int []>(10);
    fill(aup.get(), aup.get() + 10, 22);
    copy(aup.get(), aup.get() + 10, ostream_iterator<int>(cout, " "));   
    return 0;
}