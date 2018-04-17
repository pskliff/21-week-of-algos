#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//int subarraySum(vector<int>& nums, int k)
//{
//    unordered_map<int, vector<int>> mapa;
//    int sum = 0;
//    int res = 0;
//    for (int i = 0; i < nums.size(); ++i)
//    {
//        sum += nums[i];
//        int key = sum - k;
//
//        if (mapa.find(key) != mapa.end())
//            res += mapa[key].size();
//
//        if (key == 0)
//                ++res;
//
//        mapa[sum].emplace_back(i);
//    }
//    return res;
//}

int subarraySumInd(vector<int>& nums, int k)
{
    unordered_map<int, vector<int>> mapa;
    int sum = 0;
    int len;
    int l = 0, r = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        int key = sum - k;

        if (mapa.find(key) != mapa.end())
        {
            l = mapa[key][0] + 1;
            if (nums[l] == 0) --l;
            r = i;
            len = r - l + 1;
        }


        if (key == 0)
        {
            l = 0;
            r = i;
            len = i + 1;
        }

        mapa[sum].emplace_back(i);
    }

    cout << endl << l << " " << r <<endl;
    return len;
}


int main()
{
//        int k = 0;
//    int arr[] = {1, 2, -3, 5};

//    int k = 0;
//    int arr[] = {0 , 0 ,0, 0,0,0,0,0,0,0};

    int k = 6;
    int arr[] = {2,0, 0, 1, 2, 3, 0};

//    int k = 0;
//    int arr[] = {-1, -1 , 1};

//    int k = 0;
//    int arr[] = {1};

//    int k = 2;
//    int arr[] = {1,1,1};

//    int k = 18;
//    int arr[] = {2,5,3,3,7,4,5,2,9};

    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << subarraySumInd(nums, k);
    return 0;
}




//    for(auto const & el : mapa){
//        int key = el.first - k;
//        if (key == 0)
//            ++res;
//        if (mapa.find(key) != mapa.end()){
//            res += mapa[key].size();
//
//            if (mapa[key].front() == el.second.front()) --res;
//        }
//
//    }

//    for (int i = 0; i < nums.size(); ++i)
//    {
//        int key = sums[i] - k;
//        if (key == 0)
//            ++res;
//        if (mapa.find(key) != mapa.end()){
//            res += mapa[key].size();
//
//            if (mapa[key].front() == mapa[sums[i]].front()) --res;
//        }
//    }


//            if (mapa[key].front() == mapa[sums[i]].front()) --res;

//        sums[i] = sum;