//#include <iostream>
//#include <vector>
//
//
//using namespace std;
//
//
//int findSeq(vector<int> nums)
//{
//    int buf1 = 0, buf2 = 0, max = 0;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        buf2 += nums[i];
//        max = max < buf1 + buf2 ? buf1 + buf2 : max;
//        if (nums[i] == 0)
//        {
//            buf1 = buf2;
//            buf2 = 0;
//        }
//    }
//
//    return max == nums.size() ? max - 1 : max;
//}
//
//
//int main()
//{
////    int arr[] = {1, 0, 1,1,1,0,1,1,1,1};
////    int arr[] = {1, 1, 1,1,1,1,1,1,1,1};
//    int arr[] = {0,0,0,0,0,0,0,0,0};
//    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
//    cout << findSeq(nums);
//    return 0;
//}