//
// Created by Lucky13 on 23.03.2018.
//

using namespace std;

#include <iostream>
#include <fstream>
#include <set>
#include <list>

list<set<int>> kerbosh(int**&a, int SIZE)
{
    set<int> M, G, K, P;
    list <set<int>> RESULT;
    for (int i = 0; i < SIZE; i++)
    {
        K.insert(i);
    }
    int v, Count = 0, cnt = 0;
    int Stack1[100];
    set<int> Stack2[100];
    set<int>::iterator theIterator;
    theIterator = K.begin();
    while (!K.empty() || !M.empty())
    {
        if (!K.empty())
        {
            theIterator = K.begin();
            v = *theIterator;
            Stack2[++Count] = M;
            Stack2[++Count] = K;
            Stack2[++Count] = P;
            Stack1[++cnt] = v;
            M.insert(v);
            for (int i = 0; i < SIZE; i++)
            {
                if (!a[v][i])
                {
                    theIterator = K.find(i);
                    if (theIterator != K.end())
                    {
                        K.erase(theIterator);
                    }
                    theIterator = P.find(i);
                    if (theIterator != P.end())
                    {
                        P.erase(theIterator);
                    }
                }
            }
            theIterator = K.find(v);
            if (theIterator != K.end())
            {
                K.erase(theIterator);
            }
        }
        else
        {
            if (P.empty())
            {
                RESULT.emplace_back(M);
            }
            v = Stack1[cnt--];
            P = Stack2[Count--];
            K = Stack2[Count--];
            M = Stack2[Count--];
            theIterator = K.find(v);
            if (theIterator != K.end())
            {
                K.erase(theIterator);
            }
            P.insert(v);
        }
    }
    return RESULT;
}

int main()
{
    std::ifstream fin("input.txt", std::ios::in);
    std::ofstream fout("output.txt", std::ios::out);

    int N, M;

    fin >> N >> M;

    int** a = new int* [N];
    for (int i = 0; i < N; ++i)
        a[i] = new int[N]{0};

    for (int i = 0; i < M; ++i)
    {
        int from, to;
        fin >> from >> to;
        a[from - 1][to - 1] = a[to - 1][from - 1] = 1;
    }

    list <set<int>> res = kerbosh(a, N);

    if (res.size() > 2)
        fout << -1;
    else if (res.size() == 2)
    {
        int s = res.begin()->size();
        fout << s << endl;
        for (auto &el : *res.begin())
            fout << el + 1 << " ";
        fout << endl;
        for (auto &el : *res.rbegin())
            fout << el + 1 << " ";
    }
    else
    {
        fout << 1 << endl << 1 << endl;
        for (int i = 2; i <= N; ++i)
            fout << i << " ";
    }

    fin.close();
    fout.close();

    return 0;
}