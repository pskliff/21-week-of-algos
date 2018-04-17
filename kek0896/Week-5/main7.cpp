#include <unordered_map>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    // sorry, done vlob

    int nDays, in, out, min = 367, max = 0;
    pair<int, int> most_clowded(0, 0); // first - day, second - crowd size

    unordered_map<int, int> dayNpeople; // key - day, value - crowd size

    ifstream fin;
    fin.open("input.txt");
    fin >> nDays;
    for (int i = 0; i < nDays; i++)
    {
        fin >> in >> out;
        if(in < min) min = in;
        if(out > max) max = out;
        for (int j = in; j <= out; ++j)
            dayNpeople[j]++;

    }
    fin.close();

    for (int k = min; k < max; ++k)
        if(most_clowded.second < dayNpeople[k]) most_clowded = pair<int, int>(k, dayNpeople[k]);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << most_clowded.first;
    fout.close();

    return 0;
}