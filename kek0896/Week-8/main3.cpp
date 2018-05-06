//
// Created by Маргарита Мариампиллай on 28.04.2018.
//

#include <iostream>
#include <vector>

using namespace std;

void hungry_turtle(vector<pair<double, double>> x, double v, double d, double last_dist) {

    double min = 0, max = x[x.size() - 1].second, wait, time;
    int eaten = 0;
    while(max - min >= 0.1){
        wait = (max + min) / 2;
        time = wait;
        for (int i = 0; i < x.size() - 1; ++i)
        {
            time += x[i].first / v;
            if(time >= x[i].second) { eaten++; time += d; }
        }
        time += x[x.size() - 1].first / v;

        if(time == x[x.size() - 1].second) break;
        if(time > x[x.size() - 1].second) max = wait;
        else min = wait;

    }

    time += (x.size() - eaten) * d + last_dist / v;

    printf("%02d:%02d", (int)time / 60, (int)time % 60);

}

int main()
{

    int v, d, n, h, m, xi;
    vector<pair<double, double>> x;

    cin >> v >> d >> n >> xi;
    scanf("%d:%d", &h, &m);
    x.emplace_back(pair<double, double>(xi, h * 60 + m));

    double last_dist;

    for (int i = 1; i < n; ++i)
    {
        cin >> xi;
        scanf("%d:%d", &h, &m);
        x.emplace_back(pair<double, double>(xi - x[i - 1].first, h * 60 + m));
    }

    hungry_turtle(x, v, d, xi);

}