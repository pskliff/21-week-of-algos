#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    int* arr = nullptr;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> n;
        arr = new int[n-1];
        for (int i = 0; i < n - 1; i++)
            fin >> arr[i];
        fin.close();
    }

    int sum = 0;

    for(int i = 0; i < n - 1; i++)
        sum += i - arr[i];

    sum += 2 * n - 1;

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << sum;
    fout.close();

    return 0;

}