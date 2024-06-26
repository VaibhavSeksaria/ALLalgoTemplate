
#include <bits/stdc++.h>
using namespace std;
bool binary(vector<int> &arr, int target)
{
    int lb = 0;
    int up = arr.size();
    while (lb <= up)
    {
        int mid = lb + (up - lb) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] < target)
        {
            lb = mid + 1;
        }
        else if (arr[mid] > target)
        {
            up = mid - 1;
        }
    }
    return false;
}
int lowerbound(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (target <= arr[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
        if (left < arr.size() and arr[left] < target)
        {
            left++;
            return left;
        }
    }
    return right;
}
int upperbound(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size();
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (target >= arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        if (left < arr.size() and arr[left] <= target)
        {
            left++;
            return left;
        }
    }
    return right;
}
int partition(vector<int> &a, int left, int right)
{
    int pivot = left;
    int end = a[right];
    for (int i = left; i < right; i++)
    {
        if (a[i] <= end)
        {
            swap(a[i], a[pivot]);
            pivot++;
        }
    }
    swap(a[pivot], a[right]);
    return pivot;
}
void quicksort(vector<int> &a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = partition(a, left, right);
    quicksort(a, left, pivot - 1);
    quicksort(a, pivot + 1, right);
}
void merge(vector<int> &a, int start, int mid, int end)
{
    vector<int> left, right;
    for (int i = start; i <= mid; i++)
        left.push_back(a[i]);
    for (int i = mid + 1; i < end; i++)
        right.push_back(a[i]);
    int n = left.size();
    int m = right.size();
    int left_ptr = 0;
    int right_ptr = 0;
    int curr = start;
    while (left_ptr < n && right_ptr < m)
    {
        if (left[left_ptr] < right[right_ptr])
        {
            a[curr] = left[left_ptr];
            curr++;
            left_ptr++;
        }
        else
        {
            a[curr] = right[right_ptr];
            curr++;
            right_ptr++;
        }
    }
    while (left_ptr < n)
    {
        a[curr] = left[left_ptr];
        curr++;
        left_ptr++;
    }
    while (right_ptr < m)
    {
        a[curr] = right[right_ptr];
        curr++;
        right_ptr++;
    }
}
void MergeSort(vector<int> &a, int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    MergeSort(a, start, mid);
    MergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
}
void countingsort(vector<int>&a,int n){
    int min=*min_element(a.begin(),a.end());
    int max=*max_element(a.begin(),a.end());
    int siz=max-min+2;
    vector<int>count(siz,0);
    for(int i=0;i<n;i++){
        count[a[i]-min]++;
    }
    int i=0;
    int j=0;
    while(i<n){
        int f=count[j];
        for(int k=0;k<f;k++){
            a[i]=min+j;
            i++;
        }
        j++;
    }
}