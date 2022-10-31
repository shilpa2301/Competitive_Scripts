class Solution {
public:
    vector<unordered_set<int>> make_graph(int n, vector<vector<int>> &trust)
    {
        vector<unordered_set<int>> graph(n);
        for(auto individual_pair: trust)
        {
            
            graph[individual_pair[1]-1].insert(individual_pair[0]-1);
        }
        return graph;
    }
    
    vector<int> calc_indegrees(vector<unordered_set<int>> &graph, int n)
    {
        vector<int> indegrees(n,0);
        //int rows=graph.size();
        int x=0;
        for(auto i : graph)
        {
            indegrees[x++]=i.size();
        }
        return indegrees;
    }
    
    vector<int> calc_outdegrees(vector<unordered_set<int>> &graph, int n)
    {
        vector<int> outdegrees(n,0);
        //int rows=graph.size();
        for(auto i : graph)
        {
            for(int j: i)
            {
                outdegrees[j]++;
            }
        }
        return outdegrees;
    }
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> graph=make_graph(n, trust);
        vector<int> indegrees=calc_indegrees(graph, n);
        vector<int> outdegrees=calc_outdegrees(graph,n);
        
        int i;
        for(i=0; i<n; i++)
        {
            if(indegrees[i]== n-1 && outdegrees[i]==0)
                return i+1;
        }
        return -1;
    }
};