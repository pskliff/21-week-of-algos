//#include <iostream>
//#include <vector>
//
//
//using namespace std;
//typedef pair<int, int> iPair;
//const int NDAYS = 365;
//
//
//int findMaxDay(vector<iPair> log)
//{
////    int days[NDAYS + 1] = {0};
//    vector<int> days(NDAYS + 1);
//    for (int i = 0; i < log.size(); ++i)
//    {
//        days[log[i].first] += 1;
//        days[log[i].second] -= 1;
//    }
//    int max = 0;
//    int max_i = 0;
//    int sum = 0;
//    for (int i = 1; i <= NDAYS; ++i)
//    {
//        sum += days[i];
//        max_i = max < sum ? i : max_i;
//        max = max < sum ? sum : max;
//
//    }
//    return max_i;
//}
//
//
//int main()
//{
////    iPair arr[] = {make_pair(2, 4), make_pair(1, 2), make_pair(3, 7), make_pair(2, 5), make_pair(3, 4), make_pair(4, 5),
////                   make_pair(5, 7)};
//    iPair arr[] = {make_pair(365, 365), make_pair(365, 365), make_pair(365, 365), make_pair(365, 365)};
//    vector<iPair> log(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//    cout << findMaxDay(log);
//    return 0;
//}