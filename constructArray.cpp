#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007    //to make result with integer range

//Return number of ways to fill in the array
long countArray(int n,int k,int x){

    long oneCount = 1;      //initial position filled with 1
    long nonOneCount = 0;   //to count 

    for(int i = 1; i<n; i++){
        
        long prevOneCount = oneCount;
        oneCount = (nonOneCount * (k-1) % MOD ); //#ways to fill the position with 1 is #ways nonOne filled times k-1 nonOne numbers possible
        nonOneCount = (prevOneCount + ((nonOneCount * (k-2)) % MOD ) % MOD); //filled the prev posi with 1 i.e prevoneCount or any of possible k-2 nonOne (k-2 since consecutive cannot be same)
    }
    if(x == 1){
        return oneCount;
    }else{
        return nonOneCount;
    }
}

int main(){

    int size,range,lastItem;
    cin >> size >> range >> lastItem;

    long ans = countArray(size, range, lastItem);
    cout << ans << endl;
    return 0;
}