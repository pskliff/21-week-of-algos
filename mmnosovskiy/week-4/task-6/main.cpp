//
// Created by Lucky13 on 23.03.2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

struct person
{
public:
    int pos{};
    int development;
    int management;

public:
    int score;
    int inverse;
    int role;

    person() = default;

    person(int dev, int man)
    {
        development = dev;
        management = man;
        if (development > management)
        {
            role = 1;
            score = development;
            inverse = development - management;
        }
        else
        {
            role = 2;
            score = management;
            inverse = management - development;
        }
    }
};

int getReplaceScore(person p, int role, const std::vector<person> &devs, const std::vector<person> &mans, int &pos);

void addPerson(person cur, std::vector<person> &devs, std::vector<person> &mans);

int total = 0, devSum = 0, manSum = 0;

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;
    int a[N], b[N];

    for (int i = 0; i < N; ++i)
        fin >> a[i];
    for (int i = 0; i < N; ++i)
        fin >> b[i];

    std::vector<person> devs, mans;
    std::unordered_map<int, person> map;

    for (int i = 0; i < N; ++i)
    {
        person cur(a[i], b[i]);
        map[i] = cur;
        addPerson(cur, devs, mans);
    }

    int M;

    fin >> M;

    for (int i = 0; i < M; ++i)
    {
        int num, role, power_up;
        fin >> num >> role >> power_up;

        person cur = map[num - 1];
        if (cur.role == 1)
        {
            devSum -= cur.development;
            devs.erase(devs.begin() + cur.pos);
        }
        else
        {
            manSum -= cur.management;
            mans.erase(mans.begin() + cur.pos);
        }
        total -= cur.score;

        if (role == 1)
        {
            cur.development += power_up;
            cur.score = cur.development;
            cur.inverse = cur.development - cur.management;
        }
        else
        {
            cur.management += power_up;
            cur.score = cur.management;
            cur.inverse = cur.management - cur.development;
        }
        addPerson(cur, devs, mans);
        fout << total << std::endl;
    }

    fin.close();
    fout.close();

    return 0;
}


int getReplaceScore(person p, int role, const std::vector<person> &devs, const std::vector<person> &mans, int &pos)
{
    int score = total;
    if (role == 1)
    {
        for (int i = 0; i < devs.size(); ++i)
        {
            if (p.development > devs[i].inverse && score < total + p.development - devs[i].inverse)
            {
                score = total + p.development - devs[i].inverse;
                pos = i;
            }
        }
    }
    else
    {
        for (int i = 0; i < mans.size(); ++i)
        {
            if (p.management > mans[i].inverse && score < total + p.management - mans[i].inverse)
            {
                score = total + p.management - mans[i].inverse;
                pos = i;
            }
        }
    }
    return score;
}

void addPerson(person cur, std::vector<person> &devs, std::vector<person> &mans)
{
    if (devs.size() < mans.size())
    {
        int simpleScore, replaceScore, pos;
        simpleScore = total + cur.development;
        replaceScore = getReplaceScore(cur, 2, devs, mans, pos);
        if (simpleScore >= replaceScore)
        {
            cur.pos = devs.size();
            cur.role = 1;
            devs.emplace_back(cur);
            devSum += cur.development;
            total = simpleScore;
        }
        else
        {
            person t = mans[pos];
            cur.pos = pos;
            cur.score = cur.management;
            cur.inverse = cur.management - cur.development;
            cur.role = 2;
            mans[pos] = cur;
            t.pos = devs.size();
            t.score -= t.inverse;
            t.inverse = -t.inverse;
            t.role = 1;
            devs.emplace_back(t);
            devSum += t.development;
            total = replaceScore;
            manSum = total - devSum;
        }
    }
    else if (mans.size() < devs.size())
    {
        int simpleScore, replaceScore, pos;
        simpleScore = total + cur.management;
        replaceScore = getReplaceScore(cur, 1, devs, mans, pos);
        if (simpleScore >= replaceScore)
        {
            cur.pos = mans.size();
            cur.role = 2;
            mans.emplace_back(cur);
            manSum += cur.management;
            total = simpleScore;
        }
        else
        {
            person t = devs[pos];
            cur.pos = pos;
            cur.score = cur.development;
            cur.inverse = cur.development - cur.management;
            cur.role = 1;
            devs[pos] = cur;
            t.pos = mans.size();
            t.score -= t.inverse;
            t.inverse = -t.inverse;
            t.role = 2;
            mans.emplace_back(t);
            manSum += t.management;
            total = replaceScore;
            devSum = total - manSum;
        }
    }
    else
    {
        int simpleScore, replaceScore1, replaceScore2, pos1, pos2;
        simpleScore = total + cur.score;
        replaceScore1 = getReplaceScore(cur, 1, devs, mans, pos1);
        replaceScore2 = getReplaceScore(cur, 2, devs, mans, pos2);
        if (simpleScore >= replaceScore2)
        {
            if (simpleScore >= replaceScore1)
            {
                total = simpleScore;
                if (cur.role == 1)
                {
                    devSum += cur.score;
                    cur.pos = devs.size();
                    cur.role = 1;
                    devs.emplace_back(cur);
                }
                else
                {
                    manSum += cur.score;
                    cur.pos = mans.size();
                    cur.role = 2;
                    mans.emplace_back(cur);
                }
            }
            else
            {
                person t = devs[pos1];
                cur.pos = pos1;
                cur.score = cur.development;
                cur.inverse = cur.development - cur.management;
                cur.role = 1;
                devs[pos1] = cur;
                t.pos = mans.size();
                t.score -= t.inverse;
                t.inverse = -t.inverse;
                t.role = 2;
                mans.emplace_back(t);
                manSum += t.management;
                total = replaceScore1;
                devSum = total - manSum;
            }
        }
        else
        {
            if (replaceScore2 > replaceScore1)
            {
                person t = mans[pos2];
                cur.pos = pos2;
                cur.score = cur.management;
                cur.inverse = cur.management - cur.development;
                cur.role = 2;
                mans[pos2] = cur;
                t.pos = devs.size();
                t.score -= t.inverse;
                t.inverse = -t.inverse;
                t.role = 1;
                devs.emplace_back(t);
                devSum += t.development;
                total = replaceScore2;
                manSum = total - devSum;
            }
            else
            {
                person t = devs[pos1];
                cur.pos = pos1;
                cur.score = cur.development;
                cur.inverse = cur.development - cur.management;
                cur.role = 1;
                devs[pos1] = cur;
                t.pos = mans.size();
                t.score -= t.inverse;
                t.inverse = -t.inverse;
                t.role = 2;
                mans.emplace_back(t);
                manSum += t.management;
                total = replaceScore1;
                devSum = total - manSum;
            }
        }
    }
}
