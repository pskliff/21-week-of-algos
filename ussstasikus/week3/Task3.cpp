#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<double, double> point;

struct Point
{
public:
    Point(double x, double y): X(x), Y(y)
    {};
    Point()
    {};
    double X, Y;

};

struct Line
{
public:
    Line(double a, double b, double c): A(a), B(b), C(c)
    {};

    double A, B, C;

};

struct CompX {
    bool operator()(const Point &a, const Point &b) {

        if(a.X == b.X)
            return a.Y < b.Y;
        return a.X < b.X;
    }
};


Line makeLine(const Point &p1, const Point &p2)
{
    return Line(p1.Y - p2.Y, p2.X - p1.X, p1.X*p2.Y - p1.Y*p2.X);
}

Line makeNormal(const Line &l, const Point &p)
{

    return Line(-l.B, l.A, l.B*p.X - l.A*p.Y);
}

bool isOnTheLine(const Point &p, const Line &l)
{
    return (l.A * p.X + l.B * p.Y + l.C) == 0;
}

vector<Point> findPointsOnNormal(Line normal, set<Point, CompX>::iterator it, set<Point, CompX>::iterator end)
{
    vector<Point> res;
    ++it;
    while(it != end)
    {
        if(isOnTheLine(*it, normal))
            res.emplace_back(*it);
        ++it;
    }
    return res;
}

Point cross(const Line &n1,  const Line &n2)
{
    Point cross_point;
    cross_point.X = -(n1.C * n2.B - n2.C * n1.B)/(n1.A * n2.B - n1.B * n2.A);
    cross_point.Y = -(n1.A * n2.C - n2.A * n1.C)/(n1.A * n2.B - n1.B * n2.A);
    return cross_point;
}

bool isCrossExist(const Line &n1,  const Line &n2, set<Point, CompX> &points)
{
    return points.find(cross(n1, n2)) != points.end();
}

int main()
{
    int n;
    cin >> n;

    set<Point, CompX> sort_x;
    int id = 0;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        sort_x.insert({x, y});

    }

    int general_count = 0;

    for(auto p_point = sort_x.begin(); p_point != --sort_x.end(); ++p_point)
    {

        auto pair_point = p_point;
        ++pair_point;

        vector<Point> normal_points;
        while(pair_point != --sort_x.end())
        {
            Line pair = makeLine(*p_point, *pair_point);
            Line normal = makeNormal(pair, *p_point);

            normal_points = findPointsOnNormal(normal, pair_point, sort_x.end());

            for(auto p_normal: normal_points)
            {
                auto n1 = makeNormal(pair, *pair_point);
                auto n2 = makeNormal(normal, p_normal);
                if(isCrossExist(n1, n2, sort_x))
                    ++general_count;
            }
            ++pair_point;
        }

    }

    cout << general_count;


}
