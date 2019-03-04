
typedef struct listNode Node;
struct listNode{
    int val;
    Node *prev, *next, *alter;
};

class MinStack {
public:
    /** initialize your data structure here. */
    
    /* solution 2 */
    //利用儲存差值去得知top(), 
    //利用減去差值去更新min
    //使得getMin達到O(1)
    long long int min; //avoid overflow or underflow
    stack<long long int> s;
    
    MinStack() {
        min = INT_MIN;
    }
    
    void push(int x){
        if(s.empty()){
            s.push(0); min = x;
        }else{
            s.push(x - min);
            if(x < min){
                min = x;
            }
        }
    }
    
    void pop(){
        if(!s.empty()){
            long long int t = s.top();
            s.pop();
            if(t < 0){
                //update min value
                min -= t;
            }
        }
    }
    
    int top(){
        if(s.empty()) return INT_MIN;
        long long int t;
        t = s.top();
        return int(t < 0 ? min : min + t);
    }
    
    int getMin(){
        return int(min);
    }
    
    /* solution 1 */
    //two linked list
    //one for stack
    //another for insertion list
//     Node *stack;
//     Node *head, *tail;
    
//     MinStack() {
//         stack = head = tail = NULL;
//     }
    
//     Node* newListNode(int x){
//         Node* tmp;
//         tmp = (Node*) calloc(1, sizeof(Node));
//         if(tmp == NULL)
//             return NULL;
//         tmp->val = x;
//         tmp->prev = tmp->next = NULL;
//         return tmp;
//     }
    
//     Node* add_list(int x){
//         Node *tmp, *prev;
//         //head -> ... -> ... -> tail
//         if(head == NULL){
//             tmp = tail = head = newListNode(x);
//         }else{
//             //insertion list
//             prev = tmp = head;
//             while(tmp != NULL && tmp->val < x) prev = tmp, tmp = tmp->next;
            
//             if(tmp == NULL){
//             //tmp == NULL, tail
//                 tmp = tail = prev->next = newListNode(x);
//                 prev->next->prev = prev;
                
//             }else if(tmp->prev == NULL){
//             //prev == NULL, head
//                 tmp->prev = newListNode(x);
//                 head = tmp;
//                 tmp->prev->next = head;
//                 head = tmp->prev;
                
//                 tmp = tmp->prev;
//             }else{
//             //prev != NULL, in the middle
//                 prev = tmp->prev;
//                 tmp->prev = newListNode(x);
//                 tmp->prev->next = tmp;
//                 tmp->prev->prev = prev;
//                 prev->next = tmp->prev;
                
//                 tmp = tmp->prev;
//             }
//         }
//         return tmp;
//     }
    
//     void remove_list(Node* r){
//         if(r != NULL){
//             if(r->prev == NULL && r->next == NULL){
//                 head = tail = NULL;
//             }else if(r->next == NULL){
//                 //cout << "remove tail" << endl;
//                 r->prev->next = NULL;
//                 tail = r->prev;
//             }else if(r->prev == NULL){
//                 //cout << "remove head" << endl;
//                 r->next->prev = NULL;
//                 head = r->next;
//             }else{
//                 //both are not null
//                 r->prev->next = r->next;
//                 r->next->prev = r->prev;
//             }
//             free(r);
//         }
//     }
    
//     void print_list(){
//         Node* list = head;
//         // Node* list = tail;
//         while(list != NULL){
//             cout << list->val << ",";
//             list = list->next;
//             // list = list->prev;
//         }
//         cout << endl;
//     }
    
//     void print_stack(){
//         Node* s = stack;
//         while(s != NULL){
//             cout << s->val << ",";
//             s = s->prev;
//         }
//         cout << endl;
//     }
    
//     void push(int x) {
        
//         //for stack
//         if(stack == NULL){
//             stack = newListNode(x);
//             stack->alter = add_list(x);
//         }else{
//             Node* tmp;
//             tmp = newListNode(x);
//             tmp->prev = stack;
//             stack->next = tmp;
//             stack = tmp;
//             stack->alter = add_list(x);
//         }
//         //print_list();
//     }
    
//     void pop() {
//         if(stack == NULL) return;
//         Node* tmp;
        
//         tmp = stack;
//         stack = stack->prev;
//         if(stack != NULL)
//             stack->next = NULL;
//         remove_list(tmp->alter);
//         free(tmp);
//         //print_list();
//     }
    
//     int top() {
//         if(stack == NULL) return -1;
//         return stack->val;
//     }
    
//     int getMin() {
//         if(head == NULL) return -1;
//         return head->val;
//     }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */