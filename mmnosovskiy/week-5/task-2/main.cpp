#include <fstream>

std::string method(std::string line, int part_len, int length)
{
    if (part_len == length)
        return line;
    int i = part_len - 1, j = length - 1;
    while (i >= 0)
    {
        if (line[i] == ' ')
            line[j--] = '0', line[j--] = '2', line[j--] = '%';
        else
            line[j--] = line[i];
        --i;
    }
    return line;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    fin >> std::noskipws;
    std::string line;
    std::getline(fin, line);
    int part_len = line.length();
    for (int i = 0; i < part_len; ++i)
        if (line[i] == ' ')
            line += "  ";
    int length = line.length();

    fout << method(line, part_len, length);

    fin.close();
    fout.close();

    return 0;
}