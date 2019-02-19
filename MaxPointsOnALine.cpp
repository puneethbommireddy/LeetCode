class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() == 0) return 0;
        if(points.size() == 1) return 1;
        
        int max_points = 2;
        for(int i=0;i<points.size();i++)
        {
            int cur_max = 1; int n_same_point = 0;
            unordered_map<long double,int> ht;
            for(int j=i+1;j<points.size();j++)
            {
                long double slope;
                if (points[j].y == points[i].y && points[j].x == points[i].x) { ++n_same_point; continue; }
                else if(points[j].x == points[i].x) slope = numeric_limits<double>::infinity();
                else slope = (long double) (points[j].y - points[i].y)/(points[j].x - points[i].x);
                
                auto it = ht.find(slope);
                if (it == ht.end()) { ht.insert({slope,2}); if(cur_max == 1) cur_max = 2; }
                else { ++(it->second); cur_max = max(cur_max,it->second); }
            }
            max_points = max(max_points,cur_max+n_same_point);
        }
        return max_points;
    }
};