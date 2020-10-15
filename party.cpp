#include<bits/stdc++.h>
using namespace std;

void optimalParty(int* fee, int* fun, int n, int budget){

    int** dp = new int*[n + 1];
    for(int i = 0; i <= n ; i++){
        dp[i] = new int[budget + 1];
    }
    
    for(int i = 0; i <= n ; i++){
       dp[i][0] = 0;
    }

    for(int i = 0; i <= budget ; i++){
       dp[0][i] = 0;
    }

    // Build table dp[][] in bottom up manner 
    for(int i = 1; i <= n ; i++){
       for(int j = 1; j <= budget; j++){

           if(fee[i-1] <= j){

               int including = fun[i-1] + dp[i-1][j - fee[i-1]];
               int excluding = dp[i-1][j]; 
               dp[i][j] = max(including, excluding);
           }
           else{
               dp[i][j] = dp[i-1][j];
           }
       }
    }
    int i=budget;
    while(i){
        if(dp[n][i]==dp[n][budget])
            i--;
        else
            break;
    }
    cout << i+1 << " " << dp[n][budget] << endl;

    for(int i = 0; i<=n; i++){
        delete [] dp[i];
    }   delete [] dp;
    return;
}

int main(){

    while(true){
        int budget,n;
        cin >> budget >> n;
        if(budget == 0 && n == 0){
            break;
        }

        int* fee = new int[n];
        int* fun = new int[n];
        for(int i = 0; i<n; i++){
            cin >> fee[i] >> fun[i];
        }

        optimalParty(fee, fun, n, budget);

        delete [] fee;
        delete [] fun;
    }
    return 0;
}