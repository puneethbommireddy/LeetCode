class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].size();
        int num_words;
        vector<int> indices;
        unordered_map<string,int> uset;
        for(string& word:words){
            auto it = uset.find(word);
            if(it == uset.end()) uset[word] = 1;
            else uset[word]++;
        }
        unordered_map<string,int> ht;
        
        for(int i=0;i<word_len;++i){
            num_words = 0;
            ht.clear();
            for(int j=i;j<s.size();j+=word_len){
                auto it = uset.find(s.substr(j,word_len));
                
                if(it == uset.end()) {
                    num_words = 0;
                    ht.clear();
                    //cout<<"clear"<<j<<endl;
                }
                else
                {
                    auto it2 = ht.find(it->first);
                    if(it2 == ht.end()){
                        ++num_words;
                        ht[it->first] = 1;
                    }
                    else if (it2->second < it->second){
                        ++num_words;
                        ht[it->first]++;
                    }
                    else{
                        for(int k=j-num_words*word_len;it->first != s.substr(k,word_len);k+=word_len){
                            num_words--;
                            ht[s.substr(k,word_len)]--;
                        }
                    }
                    //cout<<it->first<<j<<num_words<<endl;
                }

                if(num_words==words.size()) indices.push_back(j-word_len*(words.size()-1));
            }
        }
        return indices;
    }
};