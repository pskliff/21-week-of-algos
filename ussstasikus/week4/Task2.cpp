//
// Created by Stas Don on 23/03/2018.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Meeting{
public:
    string time;
    int duration;
    string names;
    Meeting(string t, int dur, string nams): time(t), duration(dur), names(nams)
    {};

};

int stringTimeToInt(string time)
{
    string h, m;
    int hours, minutes;
    int index = 0;
    while(time[index] != ':')
        h += time[index++];
    m = time.substr(++index, time.size());
    hours = stoi(h);
    minutes = stoi(m);
    return hours*60 + minutes;
}

int main()
{
    int n;
    cin >> n;

    map<int, map<string, int>> print_command;
    vector<Meeting> meetings;//all names of event participants
    map<int, vector<int>> appointments;//day/vector<>24*60 where vector[i] = meetings[i], who appointed

    for (int i = 0; i < n; ++i) {
        string command, time, name;
        int day, duration, n_people, index;
        cin >> command;
        cin >> day;
        if(command == "APPOINT") {
            cin >> time;
            index = stringTimeToInt(time);
            cin >> duration;
            cin >> n_people;

            if (appointments.find(day) == appointments.end()) {
                appointments[day].resize(24 * 60);
                fill(appointments[day].begin(), appointments[day].end(), -1);
            }

            if(appointments[day][index] == -1)//if is free
            {
                cout<<"OK"<<endl;
                int id = meetings.size();
                for(int j = 0; j < duration; ++j)
                    appointments[day][index + j] = id;//sign that reserved

                string names = "";
                for (int j = 0; j < n_people; ++j) {
                    cin >> name;
                    names += name + " ";
                    print_command[day][name] = id;
                }
                Meeting meeting(time, duration, names);
                meetings.emplace_back(meeting);
            }
            else//if is reserved
            {
                for (int j = 0; j < n_people; ++j)
                    cin >> name;
                cout<<"FAIL"<<endl<<meetings[appointments[day][index]].names;
            }
        }
        else{
            cin>>name;

            if(print_command.find(day) != print_command.end() && print_command[day].find(name) != print_command[day].end())
            {
                Meeting meeting = meetings[print_command[day][name]];
                cout<<meeting.time << " " << meeting.duration << " " << meeting.names;
            }

        }
    }
}

//6
//APPOINT 1 12:30 30 2 andrey alex
//APPOINT 1 12:00 30 2 alex sergey
//APPOINT 1 12:59 60 2 alex andrey
//PRINT 1 andrey
