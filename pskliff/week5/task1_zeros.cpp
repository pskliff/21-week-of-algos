//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void moveZeroes(vector<int>& nums) {
//    int p1 = 0, p2 = 0, n = nums.size();
//    while(p2 < n){
//        if(!nums[p2]) {
//            ++p2;
//            continue;
//        }
//
//        if(p2 > p1)
//            nums[p1] = nums[p2];
//
//        ++p1; ++p2;
//    }
//
//    while(p1 < n)
//    {
//        nums[p1] = 0;
//        ++p1;
//    }
//}
//
//int main()
//{
//
////    int arr[] = {0, 1, 0, 3, 1, 2};
////    int arr[] = {1,3,0,2,3,0,1};
//    int arr[] = {1,8,0,0,0,1,0,8};
//    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//    moveZeroes(nums);
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        cout << nums[i] << " ";
//    }
//    return 0;
//}