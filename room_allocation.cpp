#include <bits/stdc++.h>
#include <cassert>
using namespace std;

string random_string()
{
     string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

     random_device rd;
     mt19937 generator(rd());

     shuffle(str.begin(), str.end(), generator);

     return str.substr(0, 10); // assumes 32 < number of characters in str
}
class Apartment
{
public:
    Apartment() = default;
    Apartment(const Apartment &) = default;
    Apartment &operator=(Apartment const &) = default;
    Apartment(int aid, int nrooms) : appt_id(aid), num_rooms(nrooms)
    {
    }

public:
    int appt_id;
    int num_rooms;
};

class Student
{
public:
    Student() = default;
    Student(const Student &) = default;
    Student &operator=(const Student &) = default;
    Student(const string &sname, bool share = false)
        : name(sname), wants_to_share(share)
    {
    }

public:
    string name;
    bool wants_to_share;
};

unordered_map<int, vector<string>> AssignPeopleToAppartments
    ( const vector<Apartment> &apartments,
    const vector<Student> &people )
{
    unordered_map<int, vector<string>> pamap;
    unordered_map<int, int> sharing_map;
    vector<int> single_set;

    long rooms = 0;
    for(const auto& a : apartments)
    {
        rooms += a.num_rooms;
        if(a.num_rooms == 1)
            single_set.push_back(a.appt_id);
        else
            sharing_map[a.appt_id] = a.num_rooms;
        cout << rooms << endl;
    }

    cout << " Single " << single_set.size() << endl;
    cout << " sharing " << sharing_map.size() << endl;
    cout << " total " << apartments.size() << " rooms " << rooms << endl;
    cout << " People" <<  people.size() << endl;
    auto pitr = people.begin();
    auto itr = sharing_map.begin();
    int proc = 0;
    for(; pitr != people.end(); ++pitr)
    {
        if(itr == sharing_map.end() && single_set.empty())
            {
                cout << " everything is full" << endl;
                break;
            }

        if(!pitr->wants_to_share && !single_set.empty())
        {
            proc++;
            pamap[single_set.back()].push_back(pitr->name);
            single_set.pop_back();
        }
        else
        {
            if(itr != sharing_map.end() && itr->second <= pamap[itr->first].size())
                itr++;
            if(itr != sharing_map.end())
                pamap[itr->first].push_back(pitr->name);
        }
    }
    cout << " processed " << proc << endl;
    if(pitr!= people.end())
        cout << "not enought rooms" << endl;
    return pamap;
}

unordered_map<int, vector<string>> AssignPeopleToAppartmentsCopy
    ( const vector<Apartment> &in_apartments,
    const vector<Student> &people )
{
    unordered_map<int, vector<string>> pamap;
    vector<Apartment> apartments(in_apartments);
    auto acmp = [](const Apartment& a, const Apartment& b)
                {
                    return a.num_rooms < b.num_rooms;
                };
    sort(apartments.begin(), apartments.end(), acmp);

    vector<Student> ppl_set(people);

    auto pcmp = [](const Student& a, const Student& b)
                {
                    return a.wants_to_share < b.wants_to_share;
                };
    sort(ppl_set.begin(), ppl_set.end(), pcmp);
    auto aitr = apartments.begin();
    int proc = 0;
    for(auto p : ppl_set)
    {
        proc++;
        if(aitr == apartments.end())
        {
            cout << "not enought rooms" << endl;
            break;
        }
        if(aitr->num_rooms <= 0)
            aitr++;
        --aitr->num_rooms;
        pamap[aitr->appt_id].push_back(p.name);
    }

    cout << " processed " << proc << endl;

    return pamap;
}


int main()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,50);

    auto gen = [&dist, &rng](){
                    return dist(rng);
               };
    vector<int> v(1000);
    generate(v.begin(), v.end(), gen);

    int id = 1;
    vector<Apartment> appartments;
    for(int i = 0; i < v.size(); ++i)
    {
        appartments.emplace_back(Apartment{id++, v[i]});
    }

    vector<Student> people;
    for(int i = 0; i < 100000; ++i)
    {
        people.emplace_back(Student(random_string(), i % 2));
    }

    cout << people.size() << endl;
    cout << appartments.size() << endl;
    auto t1 = chrono::high_resolution_clock::now();
    auto pamap1 = AssignPeopleToAppartments(appartments, people);
    auto t2 = chrono::high_resolution_clock::now();
    auto d1 = chrono::duration_cast<chrono::microseconds>(t2 - t1);
    cout << "unordered " << d1.count() <<  " MicroSecond(s)" << endl;

    auto t11 = chrono::high_resolution_clock::now();
    auto pamap2 = AssignPeopleToAppartmentsCopy(appartments, people);
    auto t22 = chrono::high_resolution_clock::now();
    auto d11 = chrono::duration_cast<chrono::microseconds>(t22 - t11);
    cout << "copied & sorted " << d11.count() <<  " MicroSeconds(s)" << endl;

    cout << pamap1.size() << endl;
    cout << pamap2.size() << endl;
    return 0;
    //assert(pamap1 == pamap2);
    for(auto m : pamap1)
    {
        cout << "Appartment " << m.first << " : ";
        for(auto p : m.second)
        {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}