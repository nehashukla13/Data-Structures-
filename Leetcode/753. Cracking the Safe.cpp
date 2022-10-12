class Solution {
public:
    /*
        Euler PATH (start != end) and Euler CIRCUIT (start == end)
        
        say the length of password is n, and we have k different numbers
        
        theoritically, the min length is n^k + n - 1
        
         len = n
        -----------
        |--------|    one state => 
         |--------|                other state
         
        
        we see string with length of n - 1 as a prefix (node) for new password, and the new digit we insert combined with prefix (i.e. a password string) is an edge.
        
        ex>
            (102)3
        102 ------> 023
        
        for such DAG, the best way is to traverse all nodes in the graph and each edge will be covered once (Eulerian Circuit)
        
        the criteria for a eular graph:
            - for each node, indegree == outdegree (GREAT, id == od == k)
            - the graph is a strongly connected graph
    */
    unordered_set<string> hash;
    string ans;
    int k;
    
    void dfs(string u) {
        for (int i = 0; i < k; i++) {
            auto e = u + to_string(i);
            if (!hash.count(e)) {
                hash.insert(e);
                dfs(e.substr(1));
                ans += to_string(i);
            }
        }
    }
    
    string crackSafe(int n, int _k) {
        k = _k;
        string start(n - 1, '0');
        dfs(start);
        return ans + start;
    }
};
