//
// Created by Stas Don on 20/03/2018.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

typedef pair<double, double> point;
struct line{
    double A, B, C;
};


vector<point> readArray(int n);

vector<int> getSums(int n, std::vector<int> &array);
line makeLine(point a, point b);
bool checkLines(vector<point> points, line l);
line makePerp(point a, point b);
line makePerp(point a, line to_perp);
bool checkOs(vector<point> points);


int main(){
    int n;
    std::cin >> n;

    bool is_possible = false;
    vector<point> points = readArray(n);

    auto start_point = points[0];
    line l, perp;
    is_possible = checkOs(points);

    if(!is_possible && n%2 == 1){
        swap(points[0], points[1]);
        is_possible = checkOs(points);
    }

    cout << is_possible;

}

bool checkOs(vector<point> points)
{
    bool is_possible = false;
    auto start_point = points[0];
    line l, perp;
    for(int i = 1; i < points.size(); ++i){
        l = makeLine(start_point, points[i]);
        if(checkLines(points, l))
        {
            is_possible = true;
            break;
        }
        perp = makePerp(start_point, points[i]);
        if(checkLines(points, perp))
        {
            is_possible = true;
            break;
        }
    }
    return is_possible;
}

//6
//0 -5
//0 -8
//-5 3
//5 3
//2 2
//-2 -2
std::vector<point> readArray(int n)
{
    vector<point> numbers(n);
    for (int i = 0; i < n; ++i)
        cin >> numbers[i].first >> numbers[i].second;
    return numbers;
}


line makeLine(point a, point b) {
    line l;
    l.A = a.second - b.second;
    l.B = b.first - a.first;
    l.C = b.second * a.first -  b.first * a.second;
    return l;
}

line makePerp(point a, point b) {
    line l;
    point av = {(a.first + b.first)/2, (a.second + b.second)/2};
    l.A = a.first - b.first;
    l.B = a.second - b.second;
    l.C = -l.A * av.first - l.B * av.second;
    return l;
}


line makePerp(point a, line to_perp)
{
    line l;
    l.A = -to_perp.B;
    l.B = to_perp.A;
    l.C = to_perp.B * a.first - to_perp.A * a.second;
    return l;
}

point linesIntersect(line os, line perp){
    point p;
    p.first = (-os.C*perp.B + os.B*perp.C)/(os.A*perp.B - perp.A*os.B);
    p.second = (-os.A*perp.C + os.C*perp.A)/(os.A*perp.B - perp.A*os.B);
    return p;
}

bool checkLines(vector<point> points, line l) {
    unordered_map<double, list<point>> checker;

    for(auto p: points)
    {
        if(l.A*p.first + l.B*p.second + l.C == 0)
            continue;
        double d = abs(l.A * p.first + l.B * p.second + l.C)/sqrt(l.A*l.A + l.B*l.B);
        line perp = makePerp(p, l);
        point inters = linesIntersect(l, perp);
        if(checker.find(d) == checker.end())
            checker[d] = {inters};
        else{
            bool was_found = false;
            for (auto pp = checker[d].begin();  pp != checker[d].end(); ++pp)
            {
                if(inters.first == pp->first && inters.second == pp->second)
                {
                    checker[d].erase(pp);
                    was_found = true;
                    break;
                }
            }
            if(!was_found)
                checker[d].emplace_back(inters);
        }
    }
    for(auto it = checker.begin(); it != checker.end(); ++it)
        if(it->second.size() != 0)
            return false;

    return true;
}

//6
//0 -8
//0 -5
//-5 3
//5 3
//-2 -2
//2 -2

//5
//-1 -1
//1 1
//1 -1
//0 3
//-3 0
