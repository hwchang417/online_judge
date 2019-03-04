#define HASH_SIZE 10
#include <iostream>
#include <map>
#include <priority_queue>

using namespace std;

typedef struct listNode List;
struct listNode{
    int key, value;
    List* prev;
    List* next;
    int nop, nop2;
    listNode(int k, int v) : key(k), value(v) {
        prev = next = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    map<int, int> m;
    map<int, List*> list;
    List* head, *tail;
    
    LRUCache(int cap){
        tail = head = NULL;
        capacity = cap; 
        m = map<int, int>();
        list = map<int, List*>();
    }

    int get(int key) {
        
        //update order
        if(m.find(key) == m.end())
            return -1;
        
        updateList(list[key]);
        
        return m[key];
    }
    
    void addList(int key, int value){
        List* tmp;
        
        if(head == NULL){
            tail = head = new List(key, value);
            list[key] = head;
        }else{
            tmp = new List(key, value);
            list[key] = tmp;
            tail->next = tmp;
            tmp->prev = tail;
            tail = tail->next;
        }
    }
    
    void updateList(List* li){
        
        if(li == NULL) return ;
        
        if(li->prev == NULL){
            //head node
            head = head->next;
            if(head != NULL) head->prev = NULL;
            else tail = head;
        }else{
            //middle node
            if(li->next == NULL) tail = li->prev;
            else li->next->prev = li->prev;
            li->prev->next = li->next;
        }
        //list.erase(li->key);
        //addList(li->key, li->value);
        //delete li;
        
        //list.erase(li->key);
        //addList(li->key, li->value);
        if(head == NULL){
            tail = head = li;
            li->prev = li->next = NULL;
        }else{
            tail->next = li;
            li->prev = tail;
            li->next = NULL;
            tail = tail->next;
        }
    }
    
    int removeHeadList(){
        int key;
        List* tmp;
        
        if(head == NULL) return -1;
        
        tmp = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
        else tail = head;
        
        key = tmp->key;
        delete tmp;
        return key;
    }
    
    void put(int key, int value) {
        map<int, int>::iterator iter;
        iter = m.find(key);
        if(iter != m.end()){
            //update order of node
            updateList(list[key]);
            iter->second = value;
        }else if(capacity != 0){
            capacity--;
            addList(key, value);
            m[key] = value;
        }else{
            //remove oldest element in the queue
            int k = removeHeadList();
            if(k != -1){
                list.erase(k);
                m.erase(k);
            }
            m[key] = value;
            addList(key, value);
        }
        
    }
    
    ~LRUCache(){
		List *prev;
        while(head != NULL){
			prev = head, head = head->next, delete prev;
		}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

