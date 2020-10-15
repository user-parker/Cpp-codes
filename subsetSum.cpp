#include <bits/stdc++.h>
using namespace std;

bool hasSubsetSum(int* arr, int n, int sum){

    bool** dp = new bool*[n+1];       //dp[i][j] indicate whether you could create a subset with sum j till the index i
    for(int i = 0; i <= n ; i++){
        dp[i] = new bool[sum + 1];
    }

    for(int i = 1; i<=sum; i++){    //false since, without using any element we cant genrate any sum
        dp[0][i] = false;
    }

    for(int i = 0; i<=n; i++){    //true since, for generating sum=0 we can use subset : null set, so 1 possibility
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){

            dp[i][j] = dp[i-1][j];
            if( j >= arr[i-1]){
                dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    bool ans = dp[n][sum];
    for(int i = 0; i <= n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    int n,sum;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> sum;

    if(hasSubsetSum(arr, n, sum)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    delete [] arr;
    return 0;
}
