#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



string binSearch(vector<int> &srt, int el)
{
    int l = 0, r = srt.size() - 1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if (srt[mid] < el)
            l = mid + 1;
        else
            r = mid;
    }

    return srt[r] == el ? "YES" : "NO";
}


int main()
{
    ifstream fin("input.txt");

    int n, k;
    fin >> n >> k;
    vector<int> srt(n);

    for (int i = 0; i < n; ++i)
        fin >> srt[i];

//    vector<int> fnd(k);
    int fnd;
    ofstream fout("output.txt");
    for (int i = 0; i < k; ++i)
    {
        fin >> fnd;
        fout << binSearch(srt, fnd) << endl;
    }


    fin.close();



    fout.close();

    return 0;
}