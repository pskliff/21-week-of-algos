#include <iostream>
#include <vector>


using namespace std;

bool find_word(vector< vector<char> > &grid, int i, int j, string word);

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<char> > grid(n,vector<char>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
        for(int grid_j = 0;grid_j < m;grid_j++){
            cin >> grid[grid_i][grid_j];
        }
    }

    string word;
    cin >> word;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (find_word(grid, i, j, word))
                printf("found at: (%d, %d)\n", i, j);
        }
    }


    return 0;
}


bool find_word(vector< vector<char> > &grid, int i, int j, string word)
{


    if (grid[i][j] != word[0])
        return false;

    for (pair<int, int> k : {make_pair(-1, 0), make_pair(0, 1),
                             make_pair(1, 0), make_pair(0, -1)})
    {
        int i_ = i;
        int j_ = j;
        int l = 1;
        for (; l < word.length(); ++l)
        {
            i_ += k.first;
            j_ += k.second;

            if (i_ < 0 || i_ >= grid.size() || j_ < 0 || j_ >= grid[0].size())
                break;

            if (grid[i_][j_] != word[l])
                break;
        }

        if(l == word.length())
            return true;
    }

    return false;


}





