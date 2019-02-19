class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
    {
        if(buildings.size()==0) return {};
        
        bool exists[buildings.size()+1];
        int cur_height = 0, height[buildings.size()];
        vector<pair<int,int>> ends,skyline;
        auto cmp = [](pair<int,int> a, pair<int,int> b){return a.second < b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> max_heap(cmp);
        
        for(int i=0;i < buildings.size();i++)
        {
            ends.push_back({i,buildings[i][0]});
            ends.push_back({i,buildings[i][1]});
            height[i] = buildings[i][2];
            exists[i] = false;
        }
        max_heap.push({buildings.size(),0});
        exists[buildings.size()] = true;
        
        sort(ends.begin(),ends.end(),cmp);
        
        for(int i=0;i<ends.size();i++)
        {
            pair<int,int> end_point = ends[i];
            int building = end_point.first;
            if(!exists[building]) max_heap.push({building,height[building]});
            exists[building] = !exists[building];

            while(!exists[max_heap.top().first]) max_heap.pop();
            if(ends[i+1].second == end_point.second) continue;
            if (cur_height != max_heap.top().second)
            {
                cur_height = max_heap.top().second;
                skyline.push_back({end_point.second,cur_height});
            }
        }
        return skyline;
    }
};