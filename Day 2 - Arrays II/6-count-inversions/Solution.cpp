#include<bits/stdc++.h>
using namespace std;

long long merge(long long i,long long mid,long long j,vector<long long>& temp, long long* arr, int n)
{
    long long inv = 0;
    if(i>j) return 0;
    
   long long x = i;
    long long y = mid+1;
    long long z = i;
    while(x<=mid && y<=j)
    {
        if(arr[x]>arr[y]) {temp[z++] = arr[y++]; inv+=(mid+1-x);} //inversion case
        else temp[z++] = arr[x++]; //normal case
    }
    while(x<=mid)  //if elements left in 1st half (from i to mid)
        temp[z++] = arr[x++];
    while(y<=j) //if elements still left in 2nd half(from mid+1 to hi)
        temp[z++] = arr[y++];
    for(long long it=i; it<=j; it++) //finally copting all sorted values to arr from i to j
        arr[it] = temp[it];
    return inv;
}

long long mergeSort(long long i,long long j,vector<long long>&temp,  long long* arr, int n)
{
    if(i>=j) return 0;
    long long inv = 0;
    long long mid = i+((j-i)>>1);
    inv+=mergeSort(i,mid,temp,arr,n);
    inv+=mergeSort(mid+1,j,temp,arr,n);
    inv+=merge(i,mid,j,temp,arr,n);
    return inv;
}

long long getInversions(long long *arr, int n){
    vector<long long> temp(n);
    return mergeSort(0,n-1,temp,arr,n);
}