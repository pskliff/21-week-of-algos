//
// Created by Stas Don on 31/05/2018.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int formTeams(const vector<int> &people, int teamNumber, int teamSize, int difConstriant)
{
    int maxDif = people[people.size() - 1];
    int start = 0, end = 1;
    for (int team = 0; team < teamNumber; ++team) {
        int peopleInTeam = 1;
        int teamUncomf = 0;
        while(peopleInTeam < teamSize && end < people.size())
        {
            teamUncomf += people[end] - people[end - 1];
            ++peopleInTeam;
            if(teamUncomf > difConstriant)
            {
                teamUncomf -= people[start + 1] - people[start];
                ++start;
                --peopleInTeam;
            }
            ++end;
        }

        if(peopleInTeam < teamSize)
            return -1;
        else
            if(teamUncomf < maxDif)
                maxDif = teamUncomf;

        start = end;
        ++end;
    }
    return maxDif;
}

int binarySearch(const vector<int> &people, int teamNumber, int teamSize)
{
    int l = 0, r = people[people.size() - 1];

    while(l < r)
    {
        int m = l + (r - l)/2;
        int uncomfLevel = formTeams(people, teamNumber, teamSize,  m);
        if(uncomfLevel != -1)
            r = m;
        else
            l = m + 1;
    }

    return r;
}

int main()
{
    ifstream fin("input.txt");
    int n, r, c;
    fin >> n >> r >> c;

    vector<int> students(n);
    for (int i = 0; i < n; ++i)
        fin >> students[i];

    sort(students.begin(), students.end());
    ofstream fout("output.txt");
    fout << binarySearch(students, r, c);

}