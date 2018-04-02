#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string zeroones;

    int zerosum = 0;
    int n = 0;

    ifstream fin;
    fin.open("input.txt");
    fin >> zeroones;
    fin.close();

    for (int i = 0; i < zeroones.length(); ++i)
    {
        if(zeroones[i] == '0')
            zerosum++;
        else
            n += zerosum;
    }

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << n;
    fout.close();

    return 0;
}