// gfg: First Negative in Every Window of size K

// SLIDING WINDOW PATTERN
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int k) {
    deque<long long int>q;
    vector<long long> ans;
    // store index inside queue, becoz it will tell ki current element current window me hai ya nhi
    // STEP 1: process first window
    // storing indexes of all the -ve numbers inside the first window
    for(int i = 0; i < k; i++){
        int element = A[i];
        if(element < 0){
            q.push_back(i);
        }
    }
    //STEP 2: process remaining windows -> ans/ removal/ addition
    for(int i = k; i < N; i++){
        // STEP A: ans store
        if(q.empty()) ans.push_back(0);
        else{
            int index = q.front();
            int element = A[index];
            ans.push_back(element);
        }
        // STEP B: removal of elements which are not inside current window
        if(!q.empty() && q.front() < i-k+1){
            q.pop_front();
        }
        // STEP C: addition of new element
        int element = A[i];
        if(element < 0){
            q.push_back(i);
        }
    }
    // STEP 3: last window ka answer store kro
    if(q.empty()) ans.push_back(0);
    else{
        int index = q.front();
        int element = A[index];
        ans.push_back(element);
    }
    return ans;
}