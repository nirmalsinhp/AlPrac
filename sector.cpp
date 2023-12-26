#include <bits/stdc++.h>
using namespace std;



auto comp = [](const pair<string, double> left, const pair<string, double> right)
{
    return left.second > right.second;
};

class sector
{
    public:
    sector() = default;
    

    void addInsToSector(string ins, string sec)
    {
        ins_mapping[ins].push_back(sec);
    }

    void updateTradeToIns(string ins, double val)
    {
        for(const auto sec: ins_mapping[ins])
        {
            topSecs[sec] += val;
            //find(topSecs2.begin(), topSecs2.en)

            //topSecs2.push({sec, val});
        }
    }

    vector<pair<string, double>> getTopSectors()
    {

        vector<pair<string, double>> ret(topSecs.begin(), topSecs.end());
        sort(ret.begin(), ret.end(), comp);

         return vector<pair<string, double>>(ret.begin(), ret.begin() + k - 1);

    }

    private:
    unordered_map<string, vector<string>> ins_mapping;
    int k = 5;
    // priority_queue
    unordered_map<string, double> topSecs;
    unordered_map<string, double> topSecs;
    priority_queue<pair<string, int>> topSecs2;

};

int main()
{
    sector ss;
    ss.addInsToSector("TCS", "IT");
    ss.addInsToSector("TECHM", "IT");
    ss.addInsToSector("CapGemini", "IT");
    ss.addInsToSector("Cognizant", "IT");

    ss.addInsToSector("TCS", "CONS");

    ss.addInsToSector("TATA Motors", "AUTO");
    ss.addInsToSector("TATA Motors", "EV");

    ss.addInsToSector("HDFC", "Banking");
    ss.addInsToSector("IDFC", "Banking");
    ss.addInsToSector("Axis", "Banking");
    ss.addInsToSector("SBI", "Banking");
    ss.addInsToSector("ICICI", "Banking");
    ss.addInsToSector("YES", "Banking");

    ss.addInsToSector("HDFC", "Insurance");
    ss.addInsToSector("AIG", "Insurance");
    ss.addInsToSector("MAX", "Insurance");
    ss.addInsToSector("BAJAJ", "Insurance");

    ss.addInsToSector("ITC", "consumer");
    ss.addInsToSector("Nestle", "consumer");
    ss.addInsToSector("Britania", "consumer");
    ss.addInsToSector("parle", "consumer");


    ss.updateTradeToIns("TCS", 400.40);
    ss.updateTradeToIns("TECHM", 400.40);
    ss.updateTradeToIns("CapGemini", 400.40);
    ss.updateTradeToIns("Cognizant", 400.40);

    ss.updateTradeToIns("TCS", 200.20);

    ss.updateTradeToIns("TATA Motors", 1000.30);
    ss.updateTradeToIns("TATA Motors", 2000.20);

    ss.updateTradeToIns("HDFC", 500);
    ss.updateTradeToIns("IDFC", 500);
    ss.updateTradeToIns("Axis", 500);
    ss.updateTradeToIns("SBI", 500);
    ss.updateTradeToIns("ICICI", 500);
    ss.updateTradeToIns("YES", 500);

    ss.updateTradeToIns("HDFC", 400);
    ss.updateTradeToIns("AIG", 400);
    ss.updateTradeToIns("MAX", 400);
    ss.updateTradeToIns("BAJAJ", 400);

    ss.updateTradeToIns("ITC", 800);
    ss.updateTradeToIns("Nestle", 800);
    ss.updateTradeToIns("Britania", 800);
    ss.updateTradeToIns("parle", 800);

    auto res = ss.getTopSectors();

    cout << "sector   :"  <<  "    Volume " << endl;
    for(const auto  p : res )
    {
        cout << p.first << " :   " << p.second << endl;
    }

    cout << "ss "<< endl;
    return 0;
}