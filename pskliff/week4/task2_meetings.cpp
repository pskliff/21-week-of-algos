//#include <iostream>
//#include <string>
//#include <unordered_map>
//#include <vector>
//#include <queue>
//
////6
////APPOINT 1 12:30 30 2 andrey alex
////APPOINT 1 12:00 30 2 alex sergey
////APPOINT 1 12:59 60 2 alex andrey
////PRINT 1 andrey
////PRINT 1 sergey
////PRINT 2 alex
//
//using namespace std;
//
//
//class ustime
//{
//public:
//    int hour;
//    int minute;
//
//
//    ustime(int hh, int mm) : hour(hh), minute(mm)
//    {}
//
//
//    friend bool operator<(const ustime& t1, const ustime& t2)
//    {
//        return t1.hour == t2.hour ? t1.minute < t2.minute :  t1.hour < t2.hour;
//    }
//
//
////    friend bool operator>(const ustime& t1, const ustime& t2)
////    {
////        return t2 < t1;
////    }
//
//
//    friend bool operator<=(const ustime& t1, const ustime& t2)
//    {
//        return t1.hour == t2.hour ? t1.minute <= t2.minute :  t1.hour < t2.hour;;
//    }
//
//
////    friend bool operator>=(const ustime& t1, const ustime& t2)
////    {
////        return !(t1 < t2);
////    }
////
////
////    friend bool operator==(const ustime& t1, const ustime& t2)
////    {
////        return t1.hour == t2.hour && t1.minute == t2.minute;
////    }
////
////
////    friend bool operator!=(const ustime& t1, const ustime& t2)
////    {
////        return !(t1 == t2);
////    }
//};
//
//
//class meeting
//{
//public:
//    ustime start;
//    ustime end;
//    string names;
//    int duration;
//
//
//    meeting(int hh, int mm, int dur, string nms) : start(hh, mm), end(hh + (mm + dur) / 60, (mm + dur) % 60), duration(dur), names(nms)
//    {}
//
//
//    bool is_intersect(meeting other)
//    {
//        bool u1 = (other.start < end && start <= other.start);
//        bool u2 = (other.end <= end && start < other.end);
//        return u1 || u2;
//    }
//};
//
//
//int main()
//{
//    int n = 0, day = 0, duration = 0, k = 0;
//    // name -> <day, meeting>
//    unordered_map<string, unordered_map<int, vector<meeting>>> meetings;
//    string cmd, tm, names, name;
//    cin >> n;
//    for (int i = 0; i < n; ++i)
//    {
//        names = "";
//        cin >> cmd;
//        if (cmd == "APPOINT")
//        {
//            queue<string> names_vec;
//            bool intersect = false;
//            cin >> day;
//            cin >> tm;
//            cin >> duration;
//            cin >> k;
//            int hh = stoi(tm.substr(0, tm.find(":")));
//            tm.erase(0, tm.find(':') + 1);
//            int mm = stoi(tm);
//            for (int j = 0; j < k; ++j)
//            {
//                cin >> name;
//                names += name + " ";
//                names_vec.push(name);
//            }
//
//            for (int j = 0; j < k; ++j)
//            {
//                name = names_vec.front();
//                names_vec.pop();
//                if (meetings.find(name) == meetings.end())
//                {
//                    unordered_map<int, vector<meeting>> mp;
//                    meetings[name] = mp;
//
//                    meeting meet(hh, mm, duration, names);
//                    vector<meeting> vec;
//                    vec.push_back(meet);
//
//                    meetings[name][day] = vec;
////                    meetings[name][day].push_back(meet);
//                } else if (meetings[name].find(day) == meetings[name].end())
//                {
//                    meeting meet(hh, mm, duration, names);
//                    vector<meeting> vec;
//                    vec.push_back(meet);
//                    meetings[name][day] = vec;
//                    meetings[name][day].push_back(meet);
//                } else
//                {
//                    meeting meet(hh, mm, duration, names);
//                    for (int l = 0; l < meetings[name][day].size(); ++l)
//                        if (meet.is_intersect(meetings[name][day][l]))
//                        {
//                            intersect = true;
//                            names_vec.push(name);
//                            break;
//                        }
//                }
//            }
//
//            if (intersect)
//            {
//                cout << "FAIL\n";
//                int sz = names_vec.size();
//                for (int j = 0; j < sz; ++j)
//                {
//                    cout<< names_vec.front() << " ";
//                    names_vec.pop();
//                }
//            } else
//                cout << "OK\n";
//
//        }
//        else
//        {
//            int day = 0;
//            string name = "";
//            cin >> day;
//            cin >> name;
//            for(auto meet : meetings[name][day])
//            {
//                cout << meet.start.hour << ":" << (meet.start.minute < 10 ? ("0" + to_string(meet.start.minute)) : to_string(meet.start.minute))
//                     << " " << meet.duration << " " << meet.names << endl;
//            };
//        }
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
