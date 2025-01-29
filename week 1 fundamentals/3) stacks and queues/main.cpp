#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class RegularStack{
    private:
    vector<int> arr;
    //int topIndex;

    public:

    void push(int n){
        arr.push_back(n);
    }

    int pop(){
        int output = arr.back();
        arr.pop_back();
        return output;
    }

    bool empty(){
        return arr.size() == 0;
    }
};

class RegularQueue{
    private:
    vector<int> arr;
    int frontIndex;

    public:

    RegularQueue(){
        frontIndex = 0;
    }

    void push(int n){
        arr.push_back(n);
    }

    int pop(){
        if (empty()) throw runtime_error("queue empty :(");
        return arr[frontIndex++]; // return front of queue, plus "remove" it
    }

    int peek(){
        if (empty()) throw runtime_error("queue empty :(");;
        return arr[frontIndex]; // simply show front of queue
    }

    bool empty(){
        return (frontIndex >= arr.size()); // check if queue is "empty"
    }
};

class StackBasedQueue{
    private:
    stack<int> s1; // top of this is the back of the queue, bottom-most element is front of queue
    stack<int> s2;

    public:

    void push(int n){
        s1.push(n);
    }

    void pop(){
        peek();
        s2.pop();
    }

    int peek(){
        if (s2.empty()) while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    bool empty(){
        return s1.empty() && s2.empty();
    }
};


string reverseStringStack(string s){

    if (s.length() < 2) return s;

    stack<char> reverseStack;

    for (char c : s){
        reverseStack.push(c);
    }

    string output = "";

    while (!reverseStack.empty()){
        output.push_back(reverseStack.top());
        reverseStack.pop();
    }

    return output;

}

int main(int argc,char **argv) {

    /*string s = "hello world";
    cout << reverseStringStack(s) << endl;*/

    return 0;

}