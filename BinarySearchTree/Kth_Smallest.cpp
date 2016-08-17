//Find K'th Smallest in Unsorted Array. Solved by Using Max-Heap. An Easy Implementation using Priority_Queue STL, C++.

#include <iostream>
#include<queue>
using namespace std;
// Author : K.Dilip

int KthSmallest(int a[],int n,int k) // Time complexity of this solution is O(k + (n-k)*Logk).
{
    priority_queue <int> q; // maxheap
    int i;
    for(i=0;i<k;i++) // TimeComplexity for this loop : O(k)
        q.push(a[i]); 
    
    for(;i<n;i++)    // TimeComplexity for this loop : O((n-k)*Logk)
    {
        if(q.top()>a[i])
        {
            q.pop();
            q.push(a[i]);
        }
    }
    return q.top();
}

int main()
{  
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout<<KthSmallest(arr,n,k)<<endl; 
    return 0;
}
