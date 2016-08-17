/* Given a keypad as shown in diagram, and a n digit number, list all words which are possible by pressing these numbers. 
Problem Link: http://www.practice.geeksforgeeks.org/problem-page.php?pid=386 */

// Author: K.DILIP 
#include <iostream> 
using namespace std;
 
char phone[10][5]={"","",{'a','b','c'},{'d','e','f'},{ 'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

void print(int a[],int len,int n,char output[])
{
    if(len==n)
    {
        
        output[n]='\0';
        cout<<output<<" ";
        return;
    }
    
    for(int i=0; phone[a[len]][i] ;i++)
    {
        output[len]=phone[a[len]][i];
        print(a,len+1,n,output);
    }
    return;
}

int main() { 
	int t,n;
  cin>>t;
	while(t--)
	{
            cin>>n;
            int a[n];
            for(int i=0;i<n;i++)
                cin>>a[i];
            
            char output[n+1];
            print(a,0,n,output); 
            cout<<endl; 
    }
      
	return 0;
}
