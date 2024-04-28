#include <bits/stdc++.h>
using namespace std;

// template <typename ... Args>
// auto maxf(Args ... args)
// {
//     auto mf = [](auto&& a, auto&& b){return a > b ? a : b;};
//     return (... + mf(args));
// }

template<typename T, T... Args>
constexpr T amax(std::integer_sequence<T, Args...>)
{

    auto mmax = make_named_operator([](auto&& a, auto&& b){ return std::max(a,b); });
    return (... + mmax(Args));
}
int main()
{
    //auto mf = maxf(1,2,40,3,33,6,1000,3,2,3,41,44,-1);
    auto af = amax({1,2,40,3,33,6,1000,3,2,3,41,44,-1});
    // auto zf = maxf();
    cout << af << endl;
    return 0;
}