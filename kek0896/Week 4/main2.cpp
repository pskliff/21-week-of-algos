#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Appointment
{
public:

    string time;
    int begin;
    int end;
    int duration;
    vector<string> names, sortedNames;

    bool operator<(const Appointment &app) const
    {
        return (begin < app.begin);
    }

    Appointment(string t, int dur, vector<string> n, int d) : time(std::move(t)), duration(dur),
                                                              names(std::move(n))
    {
        sortedNames = names;
        sort(sortedNames.begin(), sortedNames.end());

        int hours = stoi(time.substr(0, 2));
        int mins = stoi(time.substr(3, 2));
        begin = 24 * 60 * d + hours * 60 + mins;
        end = 24 * 60 * d + hours * 60 + mins + duration;
    };

};

string intersect(unordered_map<int, vector<Appointment>> &daysAppoints, Appointment &curr, int day, bool intersected, bool* arr)
{

    vector<Appointment> intersectsWith;
    std::vector<string>::iterator it;

    // проверяю встречи данного дня
    for (auto &app : daysAppoints[day])
    {

        // тут получаю пересечение векторов имён
        vector<string> conflictNames(app.sortedNames.size() + curr.sortedNames.size());
        it = set_intersection(app.sortedNames.begin(), app.sortedNames.end(),
                              curr.sortedNames.begin(), curr.sortedNames.end(), conflictNames.begin());
        conflictNames.resize(it - conflictNames.begin());

        // если пересечение не пусто - проверяю времечки - и если они пересекаются - добавляю
        if ((!conflictNames.empty()) && !(curr.begin >= app.end || curr.end <= app.begin))
        {

            for (int j = 0; j < curr.names.size(); ++j)
                if (find(conflictNames.begin(), conflictNames.end(), curr.names[j]) != conflictNames.end())
                    arr[j] = true;
            intersected = true;
            intersectsWith.emplace_back(app);
        }
    }

    // проверяю предыдущий день
    if ((!daysAppoints[day - 1].empty()))
        return intersect(daysAppoints, curr, day - 1, intersected, arr);


    // если накладывается на следующий день
    if ((!daysAppoints[day + 1].empty()))
            return intersect(daysAppoints, curr, day + 1, intersected, arr);


    if (!intersected)
        daysAppoints[day].emplace_back(curr);

    string names;
    if (intersected)
    {
        for (int i = 0; i < curr.names.size(); ++i)
            if (arr[i]) names += curr.names[i] + " ";
        names += "\n";
    }
    return names;

}

int main()
{

    int n;
    string requestType, time;
    int day, duration, nNames;

    unordered_map<int, vector<Appointment>> daysAppoints;

    ifstream fin;
    fin.open("input.txt");
    fstream fout;
    fout.open("output.txt", ios::out);

    fin >> n;

    string name;

    fin >> requestType;
    if (requestType == "APPOINT")
    {
        vector<string> names;

        // setting
        fin >> day >> time >> duration >> nNames;

        for (int j = 0; j < nNames; ++j)
        {
            fin >> name;
            names.push_back(name);
        }

        daysAppoints[day].emplace_back(Appointment(time, duration, names, day));
        fout << "OK" << endl;
    }

    for (int i = 1; i < n; i++)
    {
        fin >> requestType;

        if (requestType == "APPOINT")
        {
            vector<string> names;

            // sound check
            fin >> day >> time >> duration >> nNames;

            for (int j = 0; j < nNames; ++j)
            {
                fin >> name;
                names.push_back(name);
            }

            Appointment appointment(time, duration, names, day);

            auto *arr = new bool[names.size()];
            string fail = intersect(daysAppoints, appointment, day, false, arr);

            delete arr;

            if(fail.length() == 0) fout << "OK\n";
            else fout << "FAIL\n" + fail;


        } else {
            fin >> day;
            fin >> name;

            sort(daysAppoints[day].begin(), daysAppoints[day].end());
            for (auto j : daysAppoints[day])
            {
                if (find(j.names.begin(), j.names.end(), name) != j.names.end())
                {
                    fout << j.time + " " << j.duration << " ";
                    for (const auto &item : j.names)
                        fout << item << ' ';
                    fout << endl;
                }
            }
        }
    }

    fin.close();
    fout.close();

    return 0;

}