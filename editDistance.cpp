#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2){

    int m = s1.length();
    int n = s2.length();

    int** dp = new int*[m + 1];
    for(int i = 0; i <= m ; i++){
        dp[i] = new int[n + 1];
    }
    // Fill d[][] in bottom up manner 
    for(int i = 0; i <= m ; i++){
        for(int j = 0; j <= n ; j++){
            
            if (i==0) {         // If first string is empty, insert all characters of second string 
                dp[i][j] = j;    // Min. operations = j 
            }
            else if (j==0) {         // If second string is empty,remove all characters of second string 
                dp[i][j] = i;        // Min. operations = i 
            }
            else if(s1[i-1] == s2[j-1]) {      // If last characters are same, ignore last char and recur for remaining string  
                dp[i][j] = dp[i-1][j-1];
            }
            else{                       // If the last character is different, consider all possibilities and find the minimum 
                dp[i][j] = 1 + min( dp[i-1][j-1],min( dp[i][j-1], dp[i-1][j] ) );
            }
        }
    }

    int ans = dp[m][n];
    for(int i = 0; i <= m ; i++){
        delete [] dp[i];
    }   delete [] dp;
    return ans;
}

int main(){

    string s1,s2;
    cin >> s1 >> s2;
    cout << editDistance(s1, s2) << endl;
    return 0;
}