#include <iostream>
#include <fstream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<pair<int, int>, int> tPeriod;
//typedef pair<tPeriod, vector<string>> tAppoint;

struct Appoint
{
    tPeriod period;
    string time;
    vector<string> members;
    Appoint(tPeriod period, string time) : period(period), time(time){}
    void represent(ofstream &fout)
    {
        fout << time << " " << period.second << " ";
        for (const auto &member : members)
            fout << member << " ";
        fout << endl;
    }
};
unordered_map<string, vector<Appoint*>> members;

pair<int, int> create_time(int day, int hour, int min);



bool interfere_with(tPeriod t1, tPeriod t2);

int main() {

    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        string type;
        fin >> type;
        if (type == "APPOINT") {
            int day, duration, hour, min, amount;
            string time;
            fin >> day >> time >> duration >> amount;
            hour = stoi(time.substr(0, 2));
            min = stoi(time.substr(3));
            pair<int, int> newtime = create_time(day, hour, min);
            tPeriod period = make_pair(newtime, duration);

            string names[amount];
            Appoint *appoint = new Appoint(period, time);
            for (int j = 0; j < amount; ++j)
            {
                fin >> names[j];
                appoint->members.push_back(names[j]);
            }

            vector<int> not_success;
            for (int k = 0; k < amount; ++k) {
                if (members.find(names[k]) == members.end())
                    members[names[k]] = vector<Appoint*>();

                for (auto &t: members[names[k]])
                    if (!interfere_with(t->period, period))
                        not_success.push_back(k);
            }

            if (not_success.empty()) {
                for (int j = 0; j < amount; ++j)
                {

                    members[names[j]].push_back(appoint);

                }
                fout << "OK" << endl;
            } else
            {
                fout << "FAIL" << endl;
                for (auto it : not_success)
                    fout << names[it] << " ";
                fout << endl;
            }

        } else
        {
            int day;
            string name;
            fin >> day >> name;
            for (auto &it : members[name])
            {
                if (it->period.first.second == day)
                    it->represent(fout);

            }
        }


    }
    fin.close();
    fout.close();
    return 0;
}

pair<int, int> create_time(int day, int hour, int min) {
    return make_pair(hour * 60 + min, day);
}

bool interfere_with(tPeriod t1, tPeriod t2) {
    if (t1.first.first > t2.first.first)
        return t1.first.first - t2.first.first >= t2.second;
    else
        return t2.first.first - t1.first.first >= t1.second;
}
