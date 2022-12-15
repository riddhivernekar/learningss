#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int linear(int arr[],int n,int k) //time complexity O(n)
{
    for(int i=1;i<=n;i++){
        if(arr[i]==k){return i;}
    }
    return -1;
}
int binary(int arr[],int s,int e,int k)  //time complexity O(logn)
{  // sort(arr,arr+n);
  //  int s=0,e=n;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==k){return mid;}
        else if(arr[mid]<k){s=mid+1;}
else if(arr[mid]>k){e=mid-1;}

    }
    return -1;
}
int jump(int arr[],int n,int k)  //time complexity O(sqrt(n))
{sort(arr,arr+n);
    int lo=0,hi=sqrt(n);
    if(arr[hi]<=k&&hi>lo){lo=hi;
        hi+=sqrt(n);
    }
    if(hi>n-1){hi=n;}
    for(int i=lo;i<hi;i++){
        if(arr[i]==k){return i;}
    }
    return -1;
}
int interpolation(int arr[],int lo,int hi,int k)  //time complexity O(log(logn)))
{
   // int lo=0,hi=n;
    int pos=lo+((k-arr[lo])*(hi-lo))/(arr[hi]-arr[lo]);
    if(arr[pos]==k){return pos;}
    else if(arr[pos]>k){return interpolation(arr,lo,pos-1,k);}
    else if(arr[pos]<k){return interpolation(arr,pos+1,hi,k);}
    return -1;
}
int exponential(int arr[],int n,int k)  //time complexity O(logn)
{
    if(arr[0]==k){return 0;}
  int  i=1;
  while(i<n&&arr[i]<=k){
      i*=2;
      
  }
  return binary(arr,i/2,min(i,n-1),k); 
}

int main() {int f;
    int a[6]={3,8,12,16,18,25};
cin>>f;
   //for(int i=0;i<e;i++){cin>>a[i];}
    cout<<exponential(a,6,f);
	// your code goes here
	return 0;
}
