//
// Created by Маргарита Мариампиллай on 26.04.2018.
//

#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

// самое сложное было подобрать количество нулей -__- - проверочка, целое ли число - мдэа - 92 ms
//bool isPowerOfThree(int n) {
//    return  (n > 0 && abs(ceil(logl(n) / logl(3) - 0.5) - logl(n) / logl(3)) < 0.000000000000001);
//}

// ну, больше этого числа n быть не должно, так что так тоже норм - 75 ms
bool isPowerOfThree(int n) {
    return  (n > 0 && 3486784401 % n == 0);
}


int main()
{

    ifstream fin("input.txt");
    int n;
    fin >> n;
    fin.close();

    ofstream fout("output.txt");
    fout << (isPowerOfThree(n) ? "YES" : "NO");
    fout.close();

    return 0;
}
