#include<iostream>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data=data;
        next=NULL;
    }
};
template<typename T>
class stack{
    node<T> *head;
    int size;
    public:
    stack(){

    }
    int getsize(){

    }
    bool isempty(){

    }
    void push(T element){

    }
    T pop(){

    }
    T top(){

    }
};