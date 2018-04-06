//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <unordered_set>
//
//using namespace std;
//typedef pair<int,int> iPair;
//
//
//bool hasSymmetry(vector<iPair> pairs)
//{
//    unordered_map<int, unordered_set<int>> points;
//    int sum = 0;
//    for (int i = 0; i < pairs.size(); ++i)
//    {
//        points[pairs[i].first].insert(pairs[i].second);
//        sum += pairs[i].first;
//    }
//
//    double line_x = sum * 1.0 / pairs.size();
//    int new_x = 0;
//    for (int i = 0; i < pairs.size(); ++i)
//    {
//        new_x = (int)(2 * line_x - pairs[i].first);
//        if (points.find(new_x) == points.end() || points[new_x].find(pairs[i].second) == points[new_x].end())
//            return false;
//    }
//
//    return true;
//}
//
//int main()
//{
////    iPair arr[] = {make_pair(1,2), make_pair(2, 2), make_pair(3, 3), make_pair(1,3), make_pair(1,5), make_pair(2, 5),
////                   make_pair(-1, 2), make_pair(-2, 2), make_pair(-3, 3), make_pair(-1, 3), make_pair(-1, 5), make_pair(-2, 5)};
////    iPair arr[] = {make_pair(365, 365), make_pair(365, 365), make_pair(365, 365), make_pair(365, 365)};
//
////    iPair arr[] = {make_pair(2,2), make_pair(3, 2), make_pair(4, 3), make_pair(2,3), make_pair(2,5), make_pair(3, 5),
////                   make_pair(0, 2), make_pair(-1, 2), make_pair(-2, 3), make_pair(0, 3), make_pair(0, 5), make_pair(-1, 5)};
////    vector<iPair> pairs(arr, arr + sizeof(arr) / sizeof(arr[0]));
////    cout << hasSymmetry(pairs);
//    return 0;
//}