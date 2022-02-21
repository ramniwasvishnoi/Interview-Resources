#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// int maxSumSub(vector<int> input){
// 	int n=input.size(),i,currSum=0,ans=INT_MIN;
// 	for(i=0;i<n;i++){
// 		currSum+=input[i];
// 		if(currSum>ans){
// 			ans=currSum;
// 		}
// 		if(currSum<=0){
// 			currSum=0;
// 		}
// 	}
// 	return ans;
// }



typedef unsigned int uint;

uint fun(uint input, uint pos){
	int temp=input & (uint)pow(2, pos-1);
	if(temp){//already set
		return input;
	}
	return input+pow(2, pos-1);
}


int main() {
	
	// vector<int> input={-2, -3, -6, -1, -1, -1, -6, -3};
	// int maxSum=maxSumSub(input);
	// cout<<maxSum<<endl;

	uint input=8;//(1010)
	uint pos=2;
	uint ans=fun(input, pos);
	cout<<ans<<endl;
	return 0;
}
