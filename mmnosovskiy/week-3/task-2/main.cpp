#include <fstream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>

typedef std::pair<int, int> point;

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N;
    fin >> N;

    point arr[N];

    std::unordered_map<int, std::unordered_map<int, int>> container;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        fin >> x >> y;
        arr[i].first = x, arr[i].second = y;
        container[x][y] = y;
    }

    int count = 0;
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
        {
            point dl = arr[i];
            point ur = arr[j];

            if (dl.first == ur.first || dl.second == ur.second)
                continue;

            if (container.find(dl.first) != container.end()
                && container[dl.first].find(ur.second) != container[dl.first].end()
                && container.find(ur.first) != container.end()
                && container[ur.first].find(dl.second) != container[ur.first].end())
                ++count;
        }

    fout << count / 2;


    fin.close();
    fout.close();

    return 0;
}