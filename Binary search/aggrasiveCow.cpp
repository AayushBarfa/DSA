
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi
// Output
// For each test case output one integer: the largest minimum distance.

// input
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9

// output
// 3


#include <bits/stdc++.h>
using namespace std;

bool ch(long long int mid,vector<long long int> a,long long int n,long long int c)
{
    long long int cow=1;
    long long int k=a[0];
    for(long long int i=1;i<n;i++)
    {
        if(a[i]-k>=mid){
            k=a[i];
            cow++;
        }
        
        
        if(cow==c)return true;
    }
    return false;
}



long long int bs(vector<long long int> a, long long int n,long long int c)
{
    sort(a.begin(),a.end());
    long long int l=a[0],h=a[n-1],mn=-1;
    while(l<=h){
        long long int mid=l+(h-l)/2;
        if(ch(mid,a,n,c)){
            mn=mid;
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return mn;
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
    long long int n,c;
    cin>>n>>c;
    vector<long long int> A(n);
    for(long long int i=0;i<n;i++){
        cin>>A[i];
    }
    
    long long int ans= bs(A,n,c);
    
    cout<<ans;
    }
    return 0;
}
