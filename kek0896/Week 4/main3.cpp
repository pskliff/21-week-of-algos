#include <iostream>
#include <fstream>

// оно не проходит( если кто-то поймёт почему - с меня шоколадка

using namespace std;

int main()
{
    int n;

    string *words = nullptr;

    ifstream fin;
    fin.open("input.txt");

    // Забиваем словечки
    fin >> n;
    words = new string[n];
    for (int i = 0; i < n; i++)
    {
        fin >> words[i];
    }
    fin.close();

    // сразу кладу длину первого элемента
    int result = words[0].length();

    bool repeated;
    int currMinLen;
    int prevMax, counter, i;

    // пробегаю от последнего до второго
    for (int k = n - 1; k > 0; --k)
    {
        repeated = false;
        prevMax = 0;
        counter = 0;
        i = 0;

        // сравниваю текущее с предыдущими
        for (int j = 0; j < k; ++j)
        {
            // если слова равны, пропускаю
            if (words[k] == words[j])
            {
                repeated = true;
                continue;
            }

            // минимумальная длина из двух слов
            currMinLen = min(words[k].length(), words[j].length());

            // пока слова совпадают инкрементирую счётчик
            while (words[k][i] == words[j][i] && (i <= currMinLen))
            {
                counter++;
                i++;
            }

            if (prevMax < counter) prevMax = counter;

        }

        // Если слово в строке повторяется и максимальный префикс не равен длине слова (на случай,
        // если есть слово, не равное текущему, но начинающееся с него)
        result += repeated && (prevMax < words[k].length()) ? prevMax + 1 : words[k].length();
    }

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << result;

    fout.close();

    return 0;
}