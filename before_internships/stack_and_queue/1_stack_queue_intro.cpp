#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
public:
    T content;
    Node<T>* next;
    Node(T content){
        this->content=content;
        this->next=nullptr;
    }
    Node(T content,Node<T>* next){
        this->content=content;
        this->next=next;
    }
};

//using linked_list
template<typename T>
class stackImpl{
public:
    Node<T>* current=nullptr;
    int len=0;
    void push(T x){
        Node<T>* temp=new Node(x);
        temp->next=current;
        current=temp;
        len++;
    }
    void pop(){
        if(len>0){
            Node<T>* temp=current;
            current=current->next;
            delete temp;
            len--;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
    int size(){
        return len;
    }
    T top(){
        if(current!=nullptr) return current->content;
        else {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    void printElementFromTop(){
        Node<T>* temp=current;
        while(temp!=nullptr){
            cout<<temp->content<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

template<typename T>
class queueImpl{
public:
    Node<T>* start=nullptr;
    Node<T>* end=nullptr;
    int len=0;
    void push(T x){
        if(len==0){
            Node<T>* temp=new Node(x);
            start=temp;
            end=temp;
            len++;
        }
        else{
            Node<T>* temp=new Node(x);
            end->next=temp;
            end=temp;
            len++;
        }
    }
    void pop(){
        if(len==0) cout<<"queue is empty"<<endl;
        else{
            Node<T>* temp=start;
            start=start->next;
            delete temp;
            len--;
        }
    }
    int size(){
        return len;
    }
    T top(){
        if(start==nullptr){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else return start->content;
    }
    void printElementFromTop(){
        Node<T>* temp=start;
        while(temp!=end){
            cout<<temp->content<<" ";
            temp=temp->next;
        }
        cout<<end->content<<endl;
    }
};

template<typename T>
class stackFromQueue{
public:
    queueImpl<T> q;
    void push(T x){
        if(q.size()==0) q.push(x);
        else{
            int n=q.size();
            q.push(x);
            for(int i=0;i<n;i++){
                q.push(q.top());
                q.pop();
            }
        }
    }
    void pop() {q.pop();}
    int size() {return q.size();}
    T top() {return q.top();}
    void printElementFromTop() {return q.printElementFromTop();}
};

template<typename T>
class queueFromStack{
public:
    stackImpl<T> st1,st2;
    void push(T x){
        if(st1.size()==0) st1.push(x);
        else{
            int n=st1.size();
            for(int i=0;i<n;i++){
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(x);
            for(int i=0;i<n;i++){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    void pop() {st1.pop();}
    int size() {return st1.size();}
    T top() {return st1.top();}
    void printElementFromTop() {return st1.printElementFromTop();}
};

template<typename T>
class stackFromArray{
public:
    T arr[10];
    int current=-1;
    int len=0;
    void push(T x){
        if(current==10-1){
            cout<<"stack array full"<<endl;
        }
        else{
            current++;
            arr[current]=x;
            len++;
        }
    }
    void pop(){
        if(current==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
            current--;
            len--;
        }
    }
    int size(){
        return len;
    }
    T top(){
        if(current==-1) {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[current];
        }
    }
    void printElementFromTop(){
        if(current==-1) cout<<endl;
        else{
            for(int i=current;i>=0;i--) cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};

template<typename T>
class queueFromArray{
public:
    T arr[10];
    int start=-1;
    int end=-1;
    int len=0;
    void push(T x){
        if(start==-1){
            start=0,end=0;
            arr[end]=x;
            len++;
        }
        else{
            if(len<10){
                end=(end+1)%10;
                arr[end]=x;
                len++;
            }
            else cout<<"queue full"<<endl;
        }
    }
    void pop(){
        if(len==0) cout<<"queue empty"<<endl;
        else{
            start=(start+1)%10;
            len--;
        }
    }
    int size(){
        return len;
    }
    int top(){
        if(start==-1){
            cout<<"empty queue"<<endl;
            return -1;
        }
        else return arr[start];
    }
    void printElementFromTop(){
        if(start==-1) cout<<endl;
        else{
            if(start<=end){
                for(int i=start;i<=end;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
            else{
                for(int i=start;i<10;i++){
                    cout<<arr[i]<<" ";
                }
                for(int i=0;i<=end;i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
};

int main(){
    stackImpl<int> st;
    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);
    cout<<st.top()<<endl;
    st.pop();
    st.push(7);
    cout<<st.size()<<endl;
    st.printElementFromTop();
    cout<<"==============================="<<endl;
    queueImpl<int> q;
    q.push(7);
    q.push(2);
    q.push(3);
    q.push(5);
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    q.pop();
    cout<<q.top()<<endl;
    q.printElementFromTop();
    cout<<"==============================="<<endl;
    stackFromQueue<int> st1;
    st1.push(4);
    st1.push(2);
    st1.push(3);
    st1.push(1);
    cout<<st1.top()<<endl;
    st1.pop();
    st1.push(7);
    cout<<st1.size()<<endl;
    st1.printElementFromTop();
    cout<<"==============================="<<endl;
    queueFromStack<int> q1;
    q1.push(7);
    q1.push(2);
    q1.push(3);
    q1.push(5);
    q1.pop();
    cout<<q1.top()<<endl;
    q1.pop();
    q1.pop();
    cout<<q1.top()<<endl;
    q1.printElementFromTop();
    cout<<"==============================="<<endl;
    stackFromArray<int> st2;
    st2.push(4);
    st2.push(2);
    st2.push(3);
    st2.push(1);
    cout<<st2.top()<<endl;
    st2.pop();
    st2.push(7);
    cout<<st2.size()<<endl;
    st2.printElementFromTop();
    cout<<"==============================="<<endl;
    queueFromArray<int> q2;
    q2.push(7);
    q2.push(2);
    q2.push(3);
    q2.push(5);
    q2.pop();
    cout<<q2.top()<<endl;
    q2.pop();
    q2.pop();
    cout<<q2.top()<<endl;
    q2.printElementFromTop();
    cout<<"==============================="<<endl;
    return 0;
}