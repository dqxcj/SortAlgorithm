/*
 * @Author: ljy
 * @Date: 2023-05-17 20:44:43
 * @LastEditors: ljy
 * @LastEditTime: 2023-05-17 21:37:01
 * @FilePath: /SortAlgorithm/QuickSort.h
 * @Description: 快速排序不稳定，举个例子
 *               假如Partition中最后一步Swap函数前序列是    [2, 1, 1, 3]
 *               则 2 会和第二个 1 交换，导致两个 1 的相对位置改变
 * Copyright (c) 2023 by ljy.sj@qq.com, All Rights Reserved. 
 */


#ifndef QUICKSORT
#define QUICKSORT
#include <vector>

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// [beg, end) 左闭右开
int Partition(std::vector<int> &nums, int beg, int end) {
    int pivot = beg;
    int j = pivot + 1;

    for(int i = pivot + 1; i < end; i++) {
        if(nums[i] > nums[pivot]) {
            Swap(nums[i], nums[j]);
            j++;
        }
    }

    Swap(nums[pivot], nums[j - 1]);
    return j - 1;
}

// [beg, end) 左闭右开
void RealQuickSort(std::vector<int> &nums, int beg, int end) {
    // [beg, end)只能表示一个元素或者非法时结束递归
    if(beg + 1 >= end) return ;

    int pivot = Partition(nums, beg, end);
    RealQuickSort(nums, beg, pivot);
    RealQuickSort(nums, pivot + 1, end);
}

void QuickSort(std::vector<int> &nums) {
    RealQuickSort(nums, 0, nums.size());
}

#endif