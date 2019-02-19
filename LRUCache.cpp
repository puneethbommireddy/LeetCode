class LRUCache {
    struct ListNode{
        int key,val;
        ListNode *next,*prev;
        ListNode(int k,int v) : key(k), val(v){}
    };
    int cache_used;
    int cap;
    unordered_map<int,ListNode*> ht;
    ListNode *head,*tail;
    
    void promoteNode(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        node->prev = head->prev;
        node->next = head;
        
        head->prev->next = node;
        head->prev = node;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new ListNode(-2,-2); tail = new ListNode(-2,-2);
        tail->next = head; head->prev = tail;
        cache_used = 0;
    }
    
    int get(int key) {
        if(ht.find(key) == ht.end()) return -1;
        else{
            promoteNode(ht[key]);
            return ht[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(ht.find(key) == ht.end()){
            ListNode* node = new ListNode(key,value);
            ht[key] = node;
            node->prev = head->prev;
            node->next = head;
            head->prev->next = node;
            head->prev = node;
            cache_used++;
        }
        else{
            ht[key]->val = value;
            promoteNode(ht[key]);
        }
        if(cache_used > cap){
            ht.erase(tail->next->key);
            ListNode* temp = tail->next;
            tail->next = tail->next->next;
            tail->next->prev = tail;
            delete temp;
            cache_used--;
        }
    }
};