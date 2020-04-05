#include <iostream>

using namespace std;

// 二分查找法，在有序的数组arr中，查找target
// 如果找到target，返回相应的索引index，否则返回-1
template<typename T>
int binarySearch(T arr[], int n, T target) {
    //在arr[left,right]之中查找target
    int left = 0, right = n - 1;
    while (left <= right) {
//        int mid = (l+r)/2;  //若r和l都很大，相加可能会产生溢出
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])  // 在arr[left,mid-1]中查找
            right = mid - 1;
        else                         // 在arr[mid+1,right]中查找
            left = mid + 1;
    }
}

template<typename T>
int __binarySearch_r(T arr[],int left,int right,T target){
    if(left>right)
        return -1;
    int mid = left+(right-left)/2;
    if(arr[mid] == target)
        return mid;
    else if(target<arr[mid])
        __binarySearch_r(arr,left,mid-1,target);
    else
        __binarySearch_r(arr,mid+1,right,target);

}

template<typename T>
int binarySearch_r(T arr[],int n,T target){
    return __binarySearch_r(arr,left,right,target);
}

int main() {

    return 0;
}
