#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string str;

    int len_norm, len_exp;

    ifstream fin;
    fin.open("input.txt");
    getline(fin, str);
    fin >> len_norm;
    fin >> len_exp;
    fin.close();

    int j = len_exp - 1;
    for (int i = len_norm - 1; i >= 0; --i)
    {
        if(str[i] == '_')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else str[j--] = str[i];
    }

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << str;
    fout.close();

    return 0;
}

//TESTS

//a_d_bt_w______
//8
//14

//__adbtw____
//7
//11

//adbtw
//5
//5

