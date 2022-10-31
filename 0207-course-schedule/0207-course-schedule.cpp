class Solution {
public:
    vector<unordered_set<int>> make_graph(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(auto i: prerequisites)
        {
           // cout<<"pre= "<<i[1]<<" for "<<i[0]<<endl;
            graph[i[1]].insert(i[0]);
        }
        
        return graph;
    }
    
    bool dfs_detect_cycle(vector<unordered_set<int>> &graph, int course_id, vector<bool> &visited, vector<bool> &onPath)
    {
        if(visited[course_id])
            return false;
        onPath[course_id]=true;
        visited[course_id]=true;
        for(auto neighbour : graph[course_id])
        {
            if(onPath[neighbour] || dfs_detect_cycle(graph, neighbour, visited, onPath))
                return true;
        }
         onPath[course_id]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> graph=make_graph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false), onPath(numCourses, false);
        
        int i;
        for (i=0; i<numCourses; i++)
        {
            if(!visited[i] && dfs_detect_cycle(graph, i, visited, onPath) )
                return false;
            
        }
        return true;
    }
};