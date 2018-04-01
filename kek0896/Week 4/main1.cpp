#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    int n;

    // arr contains all products of a[i] and b[i]
    // (yeah, they should be divided by 100 - because
    // I need probabilities, but here it is unnecessary)
    int *arr = nullptr;

    int a, b;
    double sum = 0;

    ifstream fin;
    fin.open("input.txt");

    fin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> a >> b;
        arr[i] = a * b;
        sum += arr[i];
    }
    fin.close();


    fstream fout;
    fout.precision(12);
    fout.open("output.txt", ios::out);
    for (int j = 0; j < n; ++j)
    {
        fout << arr[j] / sum << endl;
    }

    fout.close();

    return 0;
}