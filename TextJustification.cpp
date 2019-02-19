class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> ret;
        int word_idx = 0;
        while(word_idx < words.size())
        {
            int cur_len = words[word_idx].size(); vector<string> line = {};
            while(cur_len <= maxWidth)
            {
                line.push_back(words[word_idx++]);
                cur_len += words[word_idx].size() + 1; 
            }
            cur_len -= words[word_idx].size() + 1; 
            int num_spaces = maxWidth - cur_len + line.size() -1;
            int num_gaps = line.size() -1;
            string cur_line;
            for(string s:line)
            {
                cur_line += s;
                
                if(num_gaps==0) { while(cur_line.size() < maxWidth) cur_line.push_back(' '); break;}
                if(word_idx == words.size()) { cur_line.push_back(' '); num_gaps--; continue; }
                
                int spaces = ceil((num_spaces+0.0)/num_gaps);
                for(int i=0; i<spaces; i++) cur_line.push_back(' ');
                num_spaces -= spaces;
                num_gaps--;
            }
            ret.push_back(cur_line);
        }
        return ret;
    }
};