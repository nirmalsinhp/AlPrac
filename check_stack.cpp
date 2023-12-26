#include "mstack.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    mstack<int> s1(2), s2(2);
    auto s3 = s1;
    auto s4(std::move(s3));

    int item = 0;

    while(!s1.full())
        s1.push(item++);
    
    while(!s1.empty())
    {
        std::cout << s1.top() << std::endl;
        s1.pop();
    }

    s4 = s1;
    s4 = std::move(mstack<int>());

    using namespace std::string_literals;
    throw std::runtime_error("runtime errir");
    return 0;
}