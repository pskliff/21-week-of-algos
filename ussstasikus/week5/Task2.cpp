//
// Created by Stas Don on 02/04/2018.
//

#include <iostream>
#include <string>
using namespace std;

void enchanceString(string &stroke, int or_len, int ench_len)
{
    int input_index = ench_len - 1;
    for (int i = or_len - 1; i >= 0; --i) {
        if(stroke[i] == ' ')
        {
            stroke[input_index--] = '0';
            stroke[input_index--] = '2';
            stroke[input_index--] = '%';
        }
        else
            stroke[input_index--] = stroke[i];
    }
}

int spaceNumber(string &stroke)
{
    int space_number = 0;
    for(char symb: stroke)
        if(symb == ' ')
        {
            ++space_number;
            stroke += "  ";
        }
    return space_number;
}


int main()
{
    int or_len, ench_len;
    string stroke;
    getline(cin, stroke);
    or_len = stroke.size();
    ench_len = or_len + 2 * spaceNumber(stroke);

    enchanceString(stroke, or_len, ench_len);
    cout << stroke;
}
