//
// Created by Маргарита Мариампиллай on 28.04.2018.
//

#include <fstream>
#include <cmath>

using namespace std;

typedef long long ll;

// ИЗИ ЗАШЛО БЕЗ БИНПОИСКА (ну да, чуть-чуть медленнее)
ll diploma_party(ll n, ll h, ll w) {

    ll lol = sqrt(n * h * w);
    ll res = max(lol, max(h, w));
    ll H, W;
    ll row = res / w, col = res / h,  curr_n = row * col;

    while(curr_n < n)
    {
        H = h - (res % h);
        W = w - (res % w);
        if(H < W)
        {
            res += H;
            curr_n += row;
            col++;
            continue;
        }
        if(H > W){
            res += W;
            curr_n += col;
            row++;
        } else{
            res += H;
            curr_n += col + row + 1;
            col++; row++;
        }
    }
    return res;
}


int main()
{

    ifstream fin("input.txt");
    ll n, h, w;
    fin >> h >> w >> n;
    fin.close();

    ofstream fout("output.txt");
    fout << diploma_party(n, h, w);
    fout.close();

    return 0;
}
