#include <iostream>
#include "IntegerQueue.h"
using namespace std;

//initialization when IntegerQueue datatype is declared
//head and tail remains same because size is zero, a array of size two is allocated
IntegerQueue::IntegerQueue(){
  head = tail = 0;
  data = new int[length = 2];
}

//in this copying constructor, it copies off head and tail from the passed in queue
//head, tail and length is copied; similarly the elements of the array in queue is also copied parallely
IntegerQueue::IntegerQueue(const IntegerQueue& q){
  head = q.head;
  tail = q.tail;
  data = new int[length = q.length];
  for (int i = 0; i < length; i++)
    data[i] = q.data[i];
}

//when destructed, all the memmories are deallocated; head, tail and length are set to 0.
IntegerQueue::~IntegerQueue(){
  delete [] data;
  length = head = tail = 0;
}


//a integer data is pushed to array at tail from 1st to 3rd line
void IntegerQueue::push(int a){
  data[tail++] = a;
  if(tail == length)
    tail = 0;
//if the head is at the tail after data is pushed, the array is full of integer data; now the array size is doubled for future data push
//afterwards, all the data from the old array is copied to the new array; the name of old pointer is directed to the new pointer
//head, tail and length is set to appropriate values
  if (head == tail){
    int* temp = new int[length*2];
    for (int i = 0; i < length; i++)
      (temp[i] = pop());
    delete [] data;
    data = temp;
    head = 0;
    tail = length;
    length *= 2;
  }
}

//returns the oldest value from the array and sets head to appropriate value
int IntegerQueue::pop(){
  int i = data[head++];
  if(head == length)
    head = 0;
  return i;
}

//if head is at the same position as of tail, it is empty as it has no value; and the result is returned accordingly
bool IntegerQueue::empty() const {
  return (head==tail);
}

//size is the difference between head and tail and if it wrapped, the size is difference added with the total length of the array
int IntegerQueue::size() const {
    return (tail - head + length*(head>tail));
}

//copies everything off of passed in queue to the queue to be assigned like copying constructor
//in midst of copying, the memmory is deleted and new memmory is allocated
//at the end, address of this IntQueue is returned
const IntegerQueue& IntegerQueue::operator=(const IntegerQueue& q){
  if (&q == this)
    return *this;
  this->head = q.head;
  this->tail = q.tail; 
  delete [] this->data;
  this->data = new int [this->length = q.length];
  for (int i = 0; i < this->length; i++)
    this->data[i] = q.data[i];
  return *this;
}

//pops out the values from the q that is passed in as a copy and attached to out stream
//uses some judgment calls on weather to add "," and "{/}" or not
ostream& operator<<(ostream& out, IntegerQueue q){
 out << "{";
 while (!q.empty()){
   out << q.pop();
   if(!q.empty())
    out << ",";
 }
 out << "}";
 return out;
}

// IntegerQueue dup(IntegerQueue a)
// {
//     IntegerQueue result;
//     while (!a.empty()) {
//         int x = a.pop();
//         result.push(x);
//         result.push(x);
//     }
//     return result;
// }

// void print(IntegerQueue *a, int n)
// {
//     for (int i=0; i<n; i++)
//         cout << a[i] << endl;
// }

// int main()
// { 
//     IntegerQueue q;
//     for (int i=0; i<10; i++)
//         q.push(i);

//     IntegerQueue r = q;
//     IntegerQueue s(q);
//     IntegerQueue t;
//     t = q;

//     IntegerQueue a[10];
 
//     for (int i=0; i<10; i++)
//         for (int j=0; j<i; j++)
//             a[i].push(j);
 
//     s = dup(a[9]);
//     t = dup(a[4]);
//     a[7] = IntegerQueue();
 
//     IntegerQueue b[8] = {q,r,s,t,a[1],a[3],dup(a[5])};
 
//     cout << "q = " << q << endl;
//     cout << "r = " << r << endl;
//     cout << "s = " << s << endl;
//     cout << "t = " << t << endl;
 
//     print(a,10);
//     print(b,8);
// }


// int main()
// {
//     IntegerQueue q;
//     q.push(7);
//     q.push(5);
//     q = q;
//     cout << q.pop();
// }