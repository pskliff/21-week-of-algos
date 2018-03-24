//
// Created by Lucky13 on 23.03.2018.
//

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

class appoint
{
private:

    bool time_intersection(const appoint &other)
    {
        if (min_time >= other.min_time + other.duration)
            return false;
        if (other.min_time >= min_time + duration)
            return false;
        return true;
    }

public:
    int day;
    int min_time;
    std::string time;
    int duration;
    std::vector<std::string> people;

    bool intersect(const appoint &other)
    {
        return day == other.day && time_intersection(other);
    }

    appoint(int day, const std::string &time, int duration)
    {
        this->day = day;
        this->time = time;
        this->min_time = std::stoi(time.substr(0, 2)) * 60 + std::stoi(time.substr(3, 2));
        this->duration = duration;
    }

    friend bool operator<(const appoint &l, const appoint &r)
    {
        return l.day < r.day || (l.day == r.day && l.min_time < r.min_time);
    }
};

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);
    const std::string request1 = "APPOINT";

    std::unordered_map<std::string, std::vector<appoint>> name_appoint;
    std::unordered_map<int, std::vector<appoint>> day_appoint;

    int N;
    fin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string request_type;
        fin >> request_type;

        int day = 0, duration = 0, k = 0;
        std::string time;

        if (request_type == request1)
        {
            std::vector<std::string> error_names;
            std::vector<std::string> good_names;
            fin >> day >> time >> duration >> k;
            appoint app(day, time, duration);
            for (int j = 0; j < k; ++j)
            {
                std::string name;
                fin >> name;
                std::set<appoint> set1(name_appoint[name].begin(), name_appoint[name].end()), set2(
                        day_appoint[day].begin(), day_appoint[day].end());
                std::vector<appoint> intersection;
                std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                                      std::back_inserter(intersection));
                bool error = false;
                if (!intersection.empty())
                {
                    for (auto &l : intersection)
                    {
                        error = l.intersect(app);
                        if (error)
                        {
                            error_names.emplace_back(name);
                            break;
                        }
                    }
                }
                if (!error)
                    good_names.emplace_back(name);
            }
            if (error_names.empty())
            {
                for (auto &n : good_names)
                    app.people.emplace_back(n);
                for (auto &n : good_names)
                    name_appoint[n].emplace_back(app);
                day_appoint[day].emplace_back(app);
                fout << "OK" << std::endl;
            }
            else
            {
                fout << "FAIL" << std::endl;
                for (int j = 0; j < error_names.size(); ++j)
                    fout << error_names[j] << ((j < error_names.size() - 1) ? " " : "\n");
            }
        }
        else
        {
            std::string name;
            fin >> day >> name;
            std::set<appoint> set1(name_appoint[name].begin(), name_appoint[name].end()), set2(
                    day_appoint[day].begin(), day_appoint[day].end());
            std::vector<appoint> intersection;
            std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                                  std::back_inserter(intersection));
            for (auto &j : intersection)
            {
                fout << j.time << " " << j.duration << " ";
                for (int l = 0; l < j.people.size(); ++l)
                    fout << j.people[l] << ((l < j.people.size() - 1) ? " " : "\n");
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}