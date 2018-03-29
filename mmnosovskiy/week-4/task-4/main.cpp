using namespace std;

#include <fstream>
#include <vector>
#include <queue>

const char NONE = -1, LEFT = 0, RIGHT = 1;
const unsigned int MAXN = static_cast<const int>(5e3);
unsigned int N, M;
vector<int> parts[2];
vector<char> part;
bool graph[MAXN][MAXN];

bool bfs(int start, char currentPart)
{
    queue<int> q;
    parts[part[start] = currentPart].push_back(start);
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < N; ++i)
        {
            if (i == cur || graph[i][cur])
                continue;
            if (part[i] != NONE)
            {
                if (part[i] == part[cur])
                    return false;
                continue;
            }
            char p = (part[cur] == LEFT) ? RIGHT : LEFT;
            parts[part[i] = p].push_back(i);
            q.push(i);
        }
    }
    return true;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    fin >> N >> M;
    part = vector<char>(N, NONE);

    for (int i = 0; i < M; ++i)
    {
        int to, from;
        fin >> to >> from;
        --to;
        --from;
        graph[to][from] = graph[from][to] = true;
    }

    bool success = true;
    char currentPart = LEFT;
    for (int i = 0; i < N; ++i)
    {
        if (part[i] == NONE)
        {
            success = bfs(i, currentPart);
            if (!success)
                break;
            currentPart = (currentPart == LEFT) ? RIGHT : LEFT;
        }
    }

    if (success)
    {
        int size = parts[0].size();
        fout << size << endl;
        for (int i = 0; i < size; ++i)
            fout << parts[0][i] + 1 << " ";
        fout << endl;
        size = parts[1].size();
        for (int i = 0; i < size; ++i)
            fout << parts[1][i] + 1 << " ";
    }
    else
        fout << -1;

    fin.close();
    fout.close();

    return 0;
}