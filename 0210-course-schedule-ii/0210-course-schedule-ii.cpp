class Solution {
public:
    vector<unordered_set<int>> make_graph(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(auto i:prerequisites)
        {
            graph[i[1]].insert(i[0]);
        }
        return graph;
    }
    
    vector<int> compute_indegree(vector<unordered_set<int>> &graph, int numCourses)
    {
        vector<int> indegrees(numCourses,0);
        for(auto course: graph)
        {
            for(int neighbour: course)
            {
                indegrees[neighbour]++;
            }
        }
        return indegrees;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     
        vector<int>result;
        
        vector<unordered_set<int>> graph=make_graph(numCourses, prerequisites);
        vector<int> indegrees=compute_indegree(graph, numCourses);
        
        queue<int> zero_nodes;
        int i;
        for(i=0; i<numCourses; i++)
        {
            if(!indegrees[i])
                zero_nodes.push(i);
        }
        
        for(i=0; i<numCourses; i++)
        {
            if(zero_nodes.empty())
                return {};
            int zero_node=zero_nodes.front();
            zero_nodes.pop();
            result.push_back(zero_node);
            for(auto neighbour:graph[zero_node])
            {
                if(!(--indegrees[neighbour]))
                    zero_nodes.push(neighbour);
            }
        
        }
        return result;
    }
};