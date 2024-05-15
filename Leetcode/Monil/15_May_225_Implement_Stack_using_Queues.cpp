class MyStack {
    int arr[100];
    int in;
    int out;
public:
    MyStack() {
        in = -1;
        out = -1;
    }
    
    void push(int x) {
        in++;
        out++;
        arr[in]=x;
    }
    
    int pop() {
        in--;
        return arr[out--];
    }
    
    int top() {
        return arr[out];
    }
    
    bool empty() {
        if(in==-1)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */