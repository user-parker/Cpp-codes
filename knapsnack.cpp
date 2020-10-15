#include<bits/stdc++.h>
using namespace std;

//Dynamic iterative approach O(n) two 1D array
int knapsack3(int* weights, int* values, int n, int maxWeight){
   
    int W = maxWeight;            
    int* a = new int[W+1]();
    int* b = new int[W+1]();
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            b[w] = a[w];
            if(weights[i-1]<=w){
                b[w] = max(b[w] , values[i-1] + a[w - weights[i-1]]);
            }
        }
        swap(a,b);
    }
    int ans = a[W];
    delete[] a,b;
    return ans;
}
//Dynamic iterative approach O(n^2) used 2D array
int knapsack2(int* weights, int* values, int n, int maxWeight)  {    

    int** dp = new int*[n + 1];
    for(int i = 0; i <= n ; i++){
        dp[i] = new int[maxWeight + 1];
    }
    // Build table dp[][] in bottom up manner 
    for(int i = 0; i <= n ; i++){
       for(int j = 0; j <= maxWeight; j++){

           if(i == 0 || j == 0){
               dp[i][j] = 0;
           }
           else if(weights[i-1] <= j){

               int including = values[i-1] + dp[i-1][j - weights[i-1]];
               int excluding = dp[i-1][j]; 
               dp[i][j] = max(including, excluding);
           }
           else{
               dp[i][j] = dp[i-1][j];
           }
       }
    }
   return dp[n][maxWeight]; 
}  

//Naive recursive implementation
int knapsack1(int* weights, int* values, int n, int maxWeight){

    if (n == 0 || maxWeight == 0)  {
        return 0;  
    }
    if (weights[n-1] > maxWeight)  {        // If weight of the nth item > W, then item cannot be included 
        return knapsack1(weights, values, n-1, maxWeight);  
    } 
    else {      
        int option1 = values[n-1] + knapsack1(weights, values, n-1, maxWeight-weights[n-1]);     //nth item included 
        int option2 = knapsack1(weights, values, n-1, maxWeight);                                //not included 
        return max(option1, option2);       // Return the maximum of two cases 
    } 
}


int main(){

    int n;
    cin >> n;

    int* weights = new int[n];
    for(int i = 0; i<n ; i++){
        cin >> weights[i];
    }

    int* values = new int[n];
    for(int i = 0; i<n ; i++){
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack2(weights, values, n, maxWeight) << endl;
    return 0;
}
