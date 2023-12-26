#include <bits/stdc++.h>
#include <execution>
using namespace std;



void sf(string_view sv)
{
    cout << sv << endl;
}

uintmax_t dirSize(const string& dir)
{
    vector<filesystem::path> paths;
    filesystem::recursive_directory_iterator rd(dir);
    copy(begin(rd), end(rd), back_inserter(paths));

    auto sz = transform_reduce( execution::par,
                                paths.begin(), paths.end(), uintmax_t(0), plus<>(),
                                [](const auto& file)
                                {
                                    return is_regular_file(file)?file_size(file) : 0;
                                });
    return sz;
}

int main()
{
    // structured binding
    tuple<int, int, string> tp(1, 11, string("one"));
    auto [a, b, c] = tp;
    cout << a << " - " << b << " - " << c << endl;

    // if init expression
    if(auto val = a; val == 1)
    {
        cout << "init works" << endl;
    }
    string s = "string view";
    sf(s);

    // CTAD
    vector vint{1,2,3,4};
    // cout << type(vint) << endl;

    vector vu = {make_shared<int>(1)};
    // if consexpr

    // transform_reduce
    auto sz = dirSize("/home/niro");
    cout << sz << endl;
}