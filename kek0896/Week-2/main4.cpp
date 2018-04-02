
#include <iostream>
#include <fstream>
#include <vector>

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
        for (int i = 0; i < n; i++)
            fin >> arr[i];
        fin.close();
    }

    int sum = 0;
    int sumCur = 0;
    int lenMax = 0;
    int indBeg = -1;

    for (int i = 0; i < n; i++)
    {
        sumCur += arr[i];
        if (sumCur == 0)
        {
            lenMax = i + 1;
            indBeg = 0;
        }

    }

    sumCur -= arr[0];

    for (int j = 1; j < n; ++j)
    {
        sum = sumCur;

        for (int i = n - 1; i > j + lenMax; i--)
        {
            if (sum == 0 && lenMax < i - j + 1)
            {
                lenMax = i - j + 1;
                indBeg = j;
                break;
            }
            sum -= arr[i];
        }

        sumCur -= arr[j];

        if (lenMax > n - 1 - j)
            break;

    }

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = indBeg; i < indBeg + lenMax; i++)
        fout << arr[i] << " ";
    fout.close();

    return 0;

}