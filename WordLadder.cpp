class Solution {
    struct node
    {
        int dist;
        bool discovered;
        int key;
        vector<int> neighbours;
        vector<int> min_path_neighbours;
    };
    bool isOneDiff(string a, string b)
    {
        int num_diff = 0;
        for(int i=0;i<a.size();i++) if(a[i] != b[i]) num_diff++;
        return num_diff == 1;
    }
    vector<vector<string>> min_paths(int t,vector<node>& graph,vector<string>& wordList)
    {
        if(t==0) return {{wordList[0]}};
        vector<vector<string>> ret;
        for(int min_node:graph[t].min_path_neighbours)
        {
            vector<vector<string>> prev_path = min_paths(min_node,graph,wordList);
            for(auto path:prev_path)
            {
                ret.push_back(path);
                ret[ret.size()-1].push_back(wordList[t]);
            }
        }
        return ret;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        wordList.insert(wordList.begin(),beginWord);
        vector<node> graph(wordList.size());
        int tgt_idx = - 1;
        for(int i=0;i<wordList.size();i++)
        {
            graph[i].key = i;
            if (wordList[i] == endWord) tgt_idx = i;
            graph[i].discovered = false;
            for(int j=i+1;j<wordList.size();j++)
            {
                if(isOneDiff(wordList[i],wordList[j]))
                {
                    graph[i].neighbours.push_back(j);
                    graph[j].neighbours.push_back(i);
                }
            }
        }
        if(tgt_idx == - 1) return {};
        queue<int> bfs_queue;
        bfs_queue.push(0);
        graph[0].discovered= true;
        graph[0].dist = 0;
        while(!bfs_queue.empty())
        {
            int cur_idx = bfs_queue.front(); bfs_queue.pop();
            int cur_dist = graph[cur_idx].dist + 1;
            for(int nbr_idx:graph[cur_idx].neighbours)
            {
                if(graph[nbr_idx].discovered == false)
                {
                    graph[nbr_idx].discovered = true;
                    graph[nbr_idx].dist = cur_dist;
                    graph[nbr_idx].min_path_neighbours = {cur_idx};
                    bfs_queue.push(nbr_idx);
                }
                else if (graph[nbr_idx].dist == cur_dist) graph[nbr_idx].min_path_neighbours.push_back(cur_idx);
            }
        }
        if (graph[tgt_idx].discovered) return min_paths(tgt_idx,graph,wordList);
        return {};
    }
};