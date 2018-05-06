//
// Created by Stas Don on 29/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<double, double> dandeleion;//time/distance

pair<double, int> reachTime(double wait, int speed, int eat, int n, const vector<dandeleion> &path)
{
    double curr_time = wait;
    int eaten = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        curr_time += path[i].second / speed;
        if(curr_time >= path[i].first)
        {
            curr_time += eat;
            ++eaten;
        }
    }
    return {curr_time + path[n - 1].second / speed, n - eaten};
}

int findFastestPath(double speed, double eat, double n,  vector<dandeleion> path, double dist)
{
    pair<double, double> reach_time;
    double l = 0, r = path[n - 1].first;
    while(r - l >= 0.1)
    {
        double wait = int(l + (r - l)/2);
        reach_time = reachTime(wait, speed, eat, n, path);
        if(reach_time.first == path[n - 1].first) {
            r = wait;
            break;
        }
        else if(reach_time.first < path[n - 1].first)
            l = wait + 1;
        else
            r = wait;
    }
    reach_time = reachTime(r, speed, eat, n, path);
    double res = reach_time.first + reach_time.second * eat + dist / speed;
    if ((int) res < res)
        return (int)res + 1;
    return (int)res;

}

int main()
{
    double speed, eat, n, last_dist = 0;
    vector<dandeleion> path;
    cin >> speed >> eat >> n;
    for (int i = 0; i < n; ++i) {
        int h, m, dist;
        cin >> dist;
        scanf("%d:%d", &h, &m);
        if(i == 0)
            path.emplace_back(h*60 + m, dist);
        else
            path.emplace_back(h*60 + m, dist - path[i - 1].second);

        last_dist += path[i].second;

    }

    int res = findFastestPath(speed, eat, n, path, last_dist);
    printf("%02d:%02d", res/60, res % 60);



}