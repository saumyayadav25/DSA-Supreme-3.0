// gfg : Rat in a Maze Problem-I

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:

    bool isSafe(int newx, int newy, vector<vector<int>> &m, vector<vector<bool>> &visited, int n){
        // out of bound
        if(newx<0 || newy<0 || newx>=n || newy>=n) return false;
        // already visited
        if(visited[newx][newy] == true) return false;
        // blocked space
        if(m[newx][newy]==0) return false;
        // valid case
        return true;
    }
    
    void solve(vector<vector<int>> &m, vector<vector<bool>> &visited, int n, vector<string> &ans, int srcx, int srcy, int destx, int desty, string output){
        // base case: rat reached destination
        if(srcx==destx && srcy==desty){
            ans.push_back(output);
            return;
        }

        // Movement
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        char move[]={'U','D','L','R'};
        for(int i=0; i<4;i++){
            int newx=srcx+dx[i];
            int newy=srcy+dy[i];
            char movement=move[i];
            if (isSafe(newx, newy, m, visited,n)){
                visited[newx][newy]=true;
                output.push_back(movement);
                solve(m, visited, n, ans, newx, newy, destx, desty, output);
                // revert visited while going back-> backtracking
                output.pop_back();
                visited[newx][newy]=false;
            }
        }

        // UP
        // int newx = srcx-1;
        // int newy = srcy;
        // if(isSafe(newx, newy, m, visited, n)){
        //     visited[newx][newy]=true;
        //     solve(m, visited, n, ans, newx, newy, destx, desty, output+"U");
        //     // revert visited while going back-> backtracking
        //     visited[newx][newy]=false;
        // }
        // // DOWN
        // newx = srcx+1;
        // newy = srcy;
        // if(isSafe(newx, newy, m, visited, n)){
        //     visited[newx][newy]=true;
        //     solve(m, visited, n, ans, newx, newy, destx, desty, output+"D");
        //     // revert visited while going back-> backtracking
        //     visited[newx][newy]=false;
        // }
        // // LEFT
        // newx = srcx;
        // newy = srcy-1;
        // if(isSafe(newx, newy, m, visited, n)){
        //     visited[newx][newy]=true;
        //     solve(m, visited, n, ans, newx, newy, destx, desty, output+"L");
        //     // revert visited while going back-> backtracking
        //     visited[newx][newy]=false;
        // }
        // // RIGHT
        // newx = srcx;
        // newy = srcy+1;
        // if(isSafe(newx, newy, m, visited, n)){
        //     visited[newx][newy]=true;
        //     solve(m, visited, n, ans, newx, newy, destx, desty, output+"R");
        //     // revert visited while going back-> backtracking
        //     visited[newx][newy]=false;
        // }
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool> > visited(n, vector<bool>(n,0));
        int srcx = 0;
        int srcy = 0;
        // forgot to mark visited[0][0]=true
        visited[0][0]=true;
        int destx = n-1;
        int desty = n-1;
        string output = "";

        // important case
        if(m[0][0]==0){
            return ans;
        }

        solve(m, visited, n, ans, srcx, srcy, destx, desty, output);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends