// spoj: DEFKIN : Defense of a Kingdom

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int solve(int row, int col, vector<pair<int,int>> v, int n){
	vector<int>rowLoc;
	rowLoc.push_back(0);
	rowLoc.push_back(row + 1);
	for(int i = 0; i < n; i++){
		rowLoc.push_back(v[i].first);
	}
	sort(rowLoc.begin(), rowLoc.end());
	// calculate rowDiff
	int maxRowDiff = INT_MIN;
	for(int i = 0; i < rowLoc.size(); i++){
		int diff = rowLoc[i] - rowLoc[i - 1] - 1;
		maxRowDiff = max(maxRowDiff, diff);
	}

	vector<int>colLoc;
	colLoc.push_back(0);
	colLoc.push_back(col + 1);
	for(int i = 0; i < n; i++){
		colLoc.push_back(v[i].second);
	}
	sort(colLoc.begin(), colLoc.end());
	// calculate colDiff
	int maxColDiff = INT_MIN;
	for(int i = 0; i < colLoc.size(); i++){
		int diff = colLoc[i] - colLoc[i - 1] - 1;
		maxColDiff = max(maxColDiff, diff);
	}

	return maxRowDiff * maxColDiff;
}

int main() {
	int t;
	cin >> t;

	while(t--){
		int row, col, n;
		cin >> row >> col >> n;
		vector<pair<int,int>>v;
		for(int i = 0; i < n;i ++){
			int a, b;
			cin >> a >> b;
			v.push_back({a,b});
		}
		int ans = solve(row,col,v,n);
		cout << ans << endl;
	}
	return 0;
} 