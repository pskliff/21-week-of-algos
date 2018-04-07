#include <fstream>
#include <unordered_map>

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N, M;
    fin >> N >> M;
    std::unordered_map<std::string, bool> dict;
    for (int i = 0; i < N; ++i)
    {
        std::string word;
        fin >> word;
        dict[word] = false;
    }
    char a[M][M];
    for (int i = 0; i < M * M; ++i)
    {
        char c;
        fin >> c;
        a[i / M][i % M] = c;
    }



    fin.close();
    fout.close();

    return 0;
}