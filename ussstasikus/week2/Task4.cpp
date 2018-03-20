//
// Created by Stas Don on 13/03/2018.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> readArray(int n);

vector<int> getSums(int n, std::vector<int> &array);


int main(){
    int n;
    std::cin >> n;
    std::vector<int> numbers = readArray(n);
    std::vector<int> sums = getSums(n, numbers);

    std::pair<int, int> longest_subarray = {0, 0};//максимальная пара начало/длина
    std::unordered_map<int, std::pair<int, int>> subarrays;// элемент/(начало/длина)

    for (int i = 0; i < n; ++i) {
        if(subarrays.find(sums[i]) == subarrays.end())
            subarrays[sums[i]] = {i, 0};
        else
        {
            subarrays[sums[i]].second = i - subarrays[sums[i]].first;
            if(subarrays[sums[i]].second > longest_subarray.second){
                longest_subarray = subarrays[sums[i]];
            }
        }
    }
    for(int i = 0; i < longest_subarray.second - 1; ++i)
        std::cout<<numbers[i + longest_subarray.first + 1];
}


std::vector<int> getSums(int n, std::vector<int> &array) {
    std::vector<int> sums;
    sums.emplace_back(array[0]);
    for (int i = 1; i < array.size(); ++i) {
        sums.emplace_back(sums[i - 1] + array[i]);
    }
    return sums;
}

std::vector<int> readArray(int n)
{
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
        std::cin >> numbers[i];
    return numbers;
}