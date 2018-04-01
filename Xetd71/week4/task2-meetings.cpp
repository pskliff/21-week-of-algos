#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


struct Meeting
{
    Meeting(int d, const string& t, int dur) : day(d), time(t), duration(dur), start_time(
            stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)))
    {}


    friend bool operator<(const Meeting& l, const Meeting& r)
    {
        return l.day < r.day || (l.day == r.day && l.start_time < r.start_time);
    }

    friend bool operator==(const Meeting& l, const Meeting& r)
    {
        return l.day == r.day
               && !(l.start_time >= r.start_time + r.duration
                    || r.start_time >= l.start_time + l.duration);
    }

    int day;
    int start_time;
    string time;
    int duration;
    vector<string> names;
};


int main()
{

    unordered_map<string, vector<Meeting>> nameMeeting;
    unordered_map<int, vector<Meeting>> dayMeeting;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string request_type;
        cin >> request_type;

        int day = 0, duration = 0, k = 0;
        string time;

        if (request_type == "APPOINT")
        {
            vector<string> err;
            vector<string> done;
            cin >> day >> time >> duration >> k;
            Meeting meet(day, time, duration);
            for (int j = 0; j < k; ++j)
            {
                string name;
                cin >> name;
                set<Meeting> names(nameMeeting[name].begin(), nameMeeting[name].end());
                set<Meeting> days(dayMeeting[day].begin(), dayMeeting[day].end());
                vector<Meeting> intersect;
                set_intersection(names.begin(), names.end(), days.begin(), days.end(), back_inserter(intersect));
                bool is_intersect = false;
                if (!intersect.empty())
                {
                    for (auto& l : intersect)
                    {
                        is_intersect = l == meet;
                        if (is_intersect)
                        {
                            err.emplace_back(name);
                            break;
                        }
                    }
                }
                if (!is_intersect)
                    done.emplace_back(name);
            }
            if (err.empty())
            {
                for (auto& d : done)
                    meet.names.emplace_back(d);
                for (auto& d : done)
                    nameMeeting[d].emplace_back(meet);
                dayMeeting[day].emplace_back(meet);
                cout << "OK" << endl;
            } else
            {
                cout << "FAIL" << endl;
                for (int j = 0; j < err.size(); ++j)
                    cout << err[j] << ((j < err.size() - 1) ? " " : "\n");
            }
        } else
        {
            string name;
            cin >> day >> name;
            set<Meeting> names(nameMeeting[name].begin(), nameMeeting[name].end());
            set<Meeting> days( dayMeeting[day].begin(), dayMeeting[day].end());
            vector<Meeting> intersection;
            set_intersection(names.begin(), names.end(), days.begin(), days.end(), back_inserter(intersection));
            for (auto& j : intersection)
            {
                cout << j.time << " " << j.duration << " ";
                for (int l = 0; l < j.names.size(); ++l)
                    cout << j.names[l] << ((l < j.names.size() - 1) ? " " : "\n");
            }
        }
    }

    return 0;
}