#include<bits/stdc++.h>
using namespace std;

int kadane(int* arr, int* start, int* finish, int n) 
{ 
	int sum = 0, maxSum = INT_MIN; 
	*finish = -1;           // Just some initial value to check for all negative values case 
	int local_start = 0; 

	for (int i = 0; i < n; i++) { 
		sum += arr[i]; 
		if (sum < 0) { 
			sum = 0; 
			local_start = i + 1; 
		} 
		else if (sum > maxSum) { 
			maxSum = sum; 
			*start = local_start; 
			*finish = i; 
		} 
	} 
	if (*finish != -1) {     // There is at-least one non-negative number 
		return maxSum; 
    }
	maxSum = arr[0];        // Special Case: When all numbers in arr[] are negative 
	*start = *finish = 0; 
	
	for (int i = 1; i < n; i++) {    // Find the maximum element in array 
		if (arr[i] > maxSum) { 
			maxSum = arr[i]; 
			*start = *finish = i; 
		} 
	} 
	return maxSum; 
} 

int findMaxSum(int** arr,int row,int col) { 
	int maxSum = INT_MIN, finalLeft, finalRight,finalTop, finalBottom; 

	int left, right, i; 
	int temp[row], sum, start, finish; 

	// Set the left column 
	for (left = 0; left < col; ++left) 
	{ 
		// Initialize all elements of temp as 0 
		memset(temp, 0, sizeof(temp)); 
		// Set the right column for the left column set by outer loop 
		for (right = left; right < col; ++right) 
		{   
			for (i = 0; i < row; ++i)           // Calculate sum between current left and right for every row 'i' 
				temp[i] += arr[i][right]; 

			// Find the maximum sum subarray in temp[] using kadane() function. So 'sum' is sum of rectangle 
            // between (start, left) and (finish, right) which is the maximum sum with boundary columns strictly as left and right. 
			sum = kadane(temp, &start, &finish, row); 
	
			if (sum > maxSum) {         // Compare sum with maxsum so far. If so,update maxSum and other output values 
				maxSum = sum; 
				finalLeft = left; 
				finalRight = right; 
				finalTop = start; 
				finalBottom = finish; 
			} 
		} 
	}
    cout << "(Top, Left) (" << finalTop 
         << ", " << finalLeft << ")" << endl;  
    cout << "(Bottom, Right) (" << finalBottom  
         << ", " << finalRight << ")  : Max Sum =  " ;  
	return maxSum;
} 

int main(){

    int row,col;
    cin >> row >> col;
    
    int** arr = new int*[row];
    for(int i = 0; i< row; i++){
        arr[i] = new int[col];
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    int ans = findMaxSum(arr,row,col);
    cout << ans << endl;
    
    for(int i = 0; i < row; i++){
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}

