#include "QuickSort.h"
#include <iostream>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    QuickSort(nums);
    for(auto &num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}