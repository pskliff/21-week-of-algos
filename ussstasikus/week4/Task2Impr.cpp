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

//int checkIfExists(int day, int time_in_minutes, int duration, map<int, vector<pair<int, int>>> &appointments, vector<Meeting> &meetings)
//{
//    for(auto it = appointments[day].begin(); it != appointments[day].end(); ++it)
//    {
//        if(it->first == time_in_minutes)
//            return it->second;
//        else if(it->first > time_in_minutes && it->first < time_in_minutes + duration)
//            return it->second;
//        else if(it->first < time_in_minutes && it->first + meetings[it->second].duration > time_in_minutes)
//            return it->second;
//    }
//    return -1;
//}

bool checkIfExists(int day, int time_in_minutes, int duration, map<int, map<string, vector<int>>> &print_command, vector<Meeting> &meetings, map<string, bool> &names)
{
    bool is_reserved = false;
    for(auto it = names.begin(); it != names.end(); ++it)
    {
        if(print_command.find(day) != print_command.end() && print_command[day].find(it->first) != print_command[day].end())
        {
            for(int meeting_id: print_command[day][it->first])
            {
                int meeting_time_in_minutes = stringTimeToInt(meetings[meeting_id].time);
                if(meeting_time_in_minutes == time_in_minutes)
                {
                    if(!is_reserved)
                        cout<<"FAIL"<<endl;
                    is_reserved = true;
                    cout<<it->first<<" ";
                    break;
                }
                else if(meeting_time_in_minutes < time_in_minutes && meeting_time_in_minutes + meetings[meeting_id].duration > time_in_minutes)
                {
                    if(!is_reserved)
                        cout<<"FAIL"<<endl;
                    is_reserved = true;
                    cout<<it->first<<" ";
                    break;
                }
                else if(meeting_time_in_minutes > time_in_minutes && time_in_minutes + duration > meeting_time_in_minutes)
                {
                    if(!is_reserved)
                        cout<<"FAIL"<<endl;
                    is_reserved = true;
                    cout<<it->first<<" ";
                    break;
                }
            }
        }
    }
    return is_reserved;
}
int main()
{
    int n;
    cin >> n;

    map<int, map<string, vector<int>>> print_command;
    vector<Meeting> meetings;//all names of event participants
    map<int, vector<pair<int, int>>> appointments;//day/vector<>24*60 where vector[i] = meetings[i], who appointed

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


            int id = meetings.size();

            int index_of_crossing;

//            if () {
//                cout<<"OK"<<endl;
//                appointments[day].emplace_back(index, id);
////                appointments[day].resize(24 * 60);
////                fill(appointments[day].begin(), appointments[day].end(), -1);
//            }

            map<string, bool> names_map;
            string names = "";
            for (int j = 0; j < n_people; ++j) {
                cin >> name;
                names += name + " ";
                names_map[name] = true;
            }

            if(appointments.find(day) == appointments.end() || !checkIfExists(day, index, duration, print_command, meetings, names_map))//if is free
            {
                cout<<"OK";
                appointments[day].emplace_back(index, id);
//                for(int j = 0; j < duration; ++j)
//                    appointments[day][index + j] = id;//sign that reserved


                for(auto nam: names_map)
                {
                    print_command[day][nam.first].emplace_back(id);
                }
                Meeting meeting(time, duration, names);
                meetings.emplace_back(meeting);
            }
            cout<<endl;
//            else//if is reserved
//            {
//                for (int j = 0; j < n_people; ++j)
//                    cin >> name;
//                cout<<"FAIL"<<endl<<meetings[appointments[day][index_of_crossing].second].names;
//            }
        }
        else{
            cin>>name;

            if(print_command.find(day) != print_command.end() && print_command[day].find(name) != print_command[day].end())
            {
                for(auto meeting_id: print_command[day][name])
                {
                    Meeting meeting = meetings[meeting_id];
                    cout<<meeting.time << " " << meeting.duration << " " << meeting.names << endl;
                }

            }

        }
    }
}

//6
//APPOINT 1 12:30 30 2 andrey alex
//APPOINT 1 12:00 30 2 alex sergey
//APPOINT 1 12:59 60 2 alex andrey
//PRINT 1 andrey
//PRINT 1 sergey
//PRINT 2 alex