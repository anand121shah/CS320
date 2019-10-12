#include <iostream>

//IntegerQueue Object declared
class IntegerQueue{
//dynamic array is used with data pointer as the head of the array and uses wrapping to avoid unnecessary allocation of memmory
//length tells the length of total linear memmory allocated; head and tail is used as location of data in the
  private:
    int* data;
    int length;
    int head;
    int tail;
//as specified, four functions push, pop, empty, size, equal operator and print are declared
  public:
    IntegerQueue();
    IntegerQueue(const IntegerQueue& i);
    ~IntegerQueue();
    void push(int a);
    int pop();
    bool empty() const;
    int size() const;
    const IntegerQueue& operator=(const IntegerQueue& q);
    void print();
};
    //outputstream is outside of class because the return type is ostream
    std::ostream& operator<<(std::ostream& out, IntegerQueue r);