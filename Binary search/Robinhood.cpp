

// We all know the impressive story of Robin Hood. Robin Hood uses his archery skills and his wits to steal the money from rich, and return it to the poor.

// There are n citizens in Kekoland, each person has ci coins. Each day, Robin Hood will take exactly 1 coin from the richest person in the city and he will give it to the poorest person (poorest person right after taking richest's 1 coin). In case the choice is not unique, he will select one among them at random. Sadly, Robin Hood is old and want to retire in k days. He decided to spend these last days with helping poor people.

// After taking his money are taken by Robin Hood richest person may become poorest person as well, and it might even happen that Robin Hood will give his money back. For example if all people have same number of coins, then next day they will have same number of coins too.

// Your task is to find the difference between richest and poorest persons wealth after k days. Note that the choosing at random among richest and poorest doesn't affect the answer.

// Input
// The first line of the input contains two integers n and k (1 ≤ n ≤ 500 000, 0 ≤ k ≤ 109) — the number of citizens in Kekoland and the number of days left till Robin Hood's retirement.

// The second line contains n integers, the i-th of them is ci (1 ≤ ci ≤ 109) — initial wealth of the i-th person.

// Output
// Print a single line containing the difference between richest and poorest peoples wealth.

// input
// 4 1
// 1 1 4 2
// output
// 2


#include<bits/stdc++.h>

using namespace std;



 int ch(long long int mx, vector<long long int> b,int n,int k) {
    long long int big = 0,small = 0;
    for( int i = 0; i < n; i++) {
        if(b[i] > mx) {
            big += (b[i]-mx);
        } else {
            small += (mx-b[i]);
        }
    }
     if(big <= k && small >= big) return 1;
    
    return 0;
}
 int ch2(long long int mi, vector<long long int> b,int n,int k) {
    long long int small = 0,big = 0;
    for( int i = 0; i < n; i++) {
        if(b[i] < mi) {
            small += (mi-b[i]);
        } else {
            big += (b[i]-mi);

        }
    }
    if(small <= k && big >= small) return 1;
    
    return 0;
}

int main() {
    
    
    int n,k;
    cin>>n>>k;
    
    vector<long long int> b(n);
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    long long int mx = b[n-1],mi = b[0];
    long long int high= b[n-1],low = b[0];
    while(low<= high) {
        long long int mid = (low+high)/2;
        if(ch(mid,b,n,k)) {
            high = mid-1;
            mx = mid;
        } else {
            low = mid+1;
        }
    }
    high = b[n-1];
    low = b[0];
    while(low<= high) {
        long long int mid = (low+high)/2;
        if(ch2(mid,b,n,k)) {
            low = mid+1;
            mi = mid;
        } else {
            high = mid-1;
        }
    }
    cout<<(mx-mi);
    return  0;
}