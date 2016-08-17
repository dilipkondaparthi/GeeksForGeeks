/* An array is bitonic if it is comprises of an increasing sequence of integers,
followed immediately by a decreasing sequence of integers.
Given such a array, you need to find a element X in it and print its index.
In case, X does not exist in the array print "OOPS! NOT FOUND" without quotes.

Problem Link: http://www.practice.geeksforgeeks.org/viewSol.php?subId=133706 */

#include<stdio.h>
#include<iostream>
#include<climits>  
using namespace std;

int searchpivot(int a[],int low,int high)
{
    if(low==high)
        return low;
    if(low==high+1 && a[low]>a[high])
        return low;
    else if(low==high+1 && a[low]<a[high])
        return high;
    
    int mid=low+(high-low)/2;
   
    if(a[mid]>a[mid-1] && a[mid]<a[mid+1])
        return searchpivot(a,mid+1,high);
    else if(a[mid]<a[mid-1] && a[mid]>a[mid+1])
        return searchpivot(a,low,mid-1);
     else if(a[mid]<a[mid-1] && a[mid] <a[mid+1])
        return searchpivot(a,low,mid-1);
    else
        return mid;
    
}

int binarysearch(int a[],int low,int high,int key)
{ 
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]<key)
            return binarysearch(a,mid+1,high,key);
        else if(a[mid]>key)
            return binarysearch(a,low,mid-1,key);
        else
            return mid;
    }
    return -1;
}

 int pivotedBinarySearch(int a[],int  n, int key)
 {
     int pivot=searchpivot(a,0,n-1); 
     if(a[pivot]==key)
         return pivot;
     if(a[0]>key)
        return binarysearch(a,pivot+1,n-1,key);
     else if(a[0]<key)
         return binarysearch(a,0,pivot-1,key); 
     else
         return 0;
         
 } 

int main()
{
    int t;
    cin>>t;
    while(t--){
   // Let us search 3 in below array
        int n,key;
        cin>>n>>key;
   int arr1[n];
   for(int i=0;i<n;i++)
       cin>>arr1[i];
   
    if(pivotedBinarySearch(arr1, n, key)==-1)
        cout<<"OOPS! NOT FOUND"<<endl;
    else
        cout<<pivotedBinarySearch(arr1, n, key)<<endl;
    }
   return 0;
}
