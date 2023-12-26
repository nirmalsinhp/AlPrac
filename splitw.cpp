#include <bits/stdc++.h>
using namespace std;


class ExpenseManager
{
    public:
    
    void AddUser(string uname)
    {
        balances[uname] = unordered_map<string, double>();      
    }

    void AddExpense(double amount, string paid_by, vector<string> paid_tos)
    {
        double split = amount / (paid_tos.size() + 1);
        for(const auto kv : paid_tos)
        {
            balances[paid_by][kv] += split;
            balances[kv][paid_by] -= split;
        }
    }

    void showBalances()
    {
        for(const auto kv : balances)
        {
            cout << setw(15) << kv.first <<  "Owes " << endl;
            for(const auto& mp : kv.second)
            {
                cout << "   - " << mp.second << " to " << mp.first << endl;
            }
        }
    }

    private:
    unordered_map<string, unordered_map<string, double>> balances;
};


int main()
{
    ExpenseManager ex;
    ex.AddUser("U1");
    ex.AddUser("U2");
    ex.AddUser("U3");

    ex.AddExpense(300, "U1", {"U2", "U3"});
    ex.AddExpense(300, "U1", {"U2"});
    ex.AddExpense(300, "U3", {"U2", "U1"});
    ex.AddExpense(1000, "U2", {"U3"});

    ex.showBalances();
    return 0;
}