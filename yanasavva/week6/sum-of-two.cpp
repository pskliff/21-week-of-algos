#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n, sum;
    fin >> n >> sum;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < n; ++i) {
        int numb;
        fin >> numb;
        hash_map[numb] = i;
    }
    fin.close();
    unordered_map<int,int>::iterator it_;
    for (auto &it : hash_map)
        if ((it_ = hash_map.find(sum - it.first)) != hash_map.end())
        {
            printf("Indices %d, %d: %d + %d = %d\n", it.second, it_->second, it.first, it_->first, sum);
            break;
        }

    return 0;
}