//
//  main.cpp
//  PriorityQueue.cpp
//
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node
{
    T data;
    uint32_t priority;
    Node(const T d, const uint32_t p=0):data(d),priority(p){}
};

/*
 Priority que implementation based on priority
 */
template<typename T>
class Queue
{
    vector<Node<T>> heap;
    uint32_t _size;
public:
    explicit Queue():_size(0){}
    void push(T& data, uint32_t priority);
    void pop();
    T top() const;
    bool empty() const;
    uint32_t size() const { return _size;}
    void heapify_bottom_up(uint32_t index); // Bottom-Up approach
    void heapify_top_down(uint32_t index);
    void clear();
    ~Queue(){
        clear();
    }
};


/*
 Push elements based on priority ...
 - Push element at the end of the array.
 - Perform heapify to balance the tree
 */
template<typename T>
void Queue<T>::push(T& data, uint32_t priority)
{
    // Add element at the end of the array.
    heap.push_back(Node<T>(data, priority));
    // Heapify the array.
    heapify_bottom_up(heap.size() -1);
}

/*
 Heapify - a bottom up approach
 */
template<typename T>
void Queue<T>::heapify_bottom_up(uint32_t index)
{
    if( index == 0){
        return;
    }
    uint32_t root_index = 0;
    if( index % 2 == 0){
        root_index = index/2 -1;
    }else{
        root_index = index/2;
    }
    if(heap[index].priority > heap[root_index].priority){
        swap(heap[index],heap[root_index]);
        heapify_bottom_up(root_index);
    }
}

/*
 Heapify - a top-down approach
 */
template<typename T>
void Queue<T>::heapify_top_down(uint32_t index)
{
    uint32_t left_index = 2 * index + 1;
    uint32_t right_index = 2 * index + 2;
    if( left_index < heap.size() && right_index < heap.size()){
        if(heap[left_index].priority > heap[right_index].priority){
            swap(heap[left_index], heap[index]);
            heapify_top_down(left_index);
        }else{
            swap(heap[index], heap[right_index]);
            heapify_top_down(right_index);
        }
    }else if ( left_index < heap.size() ) {
        if(heap[left_index].priority > heap[index].priority ) {
            swap(heap[left_index], heap[index]);
            heapify_top_down(left_index);
        }
    }
}

/*
 Remove the max_heap element
 - Move the root element to end of array
 - Perform heapify top-down manner
*/
template<typename T>
void Queue<T>::pop()
{
    if(heap.size() == 0){
        cout<<"Empty Queue!"<<endl;
    }else{
        heap[0] = heap[heap.size() -1];
        //swap(heap[0] , heap[heap.size() -1]);
        heap.pop_back(); // Remove
        heapify_top_down(0);
    }
}

/*
 Return top elements -
 */
template<typename T>
T Queue<T>::top() const
{
    return heap[0].data;
}

/*
Check if the queue is empty- return 0 if queue is empty , else 1
*/
template<typename T >
bool Queue<T>::empty() const
{
    if(heap.size()){
        return 0;
    }
    return 1;
}

/*
 clear all elements of the priority queue
*/
template<typename T>
void Queue<T>::clear()
{
    heap.clear();
}

int main(int argc, const char * argv[]) {
   
    std::cout << "Test1 - Priority Queue with data uint32_t"<<endl;
    Queue<uint32_t> Q1 = Queue<uint32_t>();
    vector<uint32_t> data1({10,3,7,2,1,4,6});
    for(auto elm: data1){
        Q1.push(elm, elm);
    }
    
    cout<<"Front element - "<<Q1.top()<<endl;
    assert(Q1.top() == 10);
    Q1.pop();
    cout<<"Front element - "<<Q1.top()<<endl;
    assert(Q1.top() == 7);
    uint32_t new_element = 5;
    Q1.push(new_element,new_element);
    
    while(!Q1.empty()){
        cout<<Q1.top()<<", ";
        Q1.pop();
    }
    cout<<endl;
    // Test2 with data double
    cout<<"Test2 - Priority Queue with data double ... "<<endl;
    vector<double> data2({3.4,7.1,2.1,5.6,8.7,1.1});
    vector<uint32_t> priority_set2({3,7,2,5,8,1});
    int index=0;
    Queue<double> Q2= Queue<double>();
    while(index < data2.size()){
        Q2.push(data2[index], priority_set2[index]);
        index++;
    }
    cout<<"Front element - "<<Q2.top()<<endl;
    assert(Q2.top() == 8.7);
    Q2.pop();
    cout<<"Front element - "<<Q2.top()<<endl;
    assert(Q2.top() == 7.1);
    double new_element2 = 9.1;
    uint32_t new_element_priority2 = 9;
    Q2.push(new_element2,new_element_priority2);
    
    while(!Q2.empty()){
        cout<<Q2.top()<<", ";
        Q2.pop();
    }
    cout<<endl;
    // Test3 with data string
    cout<<"Test3 - Priority Queue with data string ... "<<endl;
    vector<string> data3({"Mango","Banana","Cherry","Pear","Peach","Pineapple"});
    vector<uint32_t> priority_set3({7,6,5,1,3,4});
    index=0;
    Queue<string> Q3= Queue<string>();
    while(index < data3.size()){
        Q3.push(data3[index], priority_set3[index]);
        index++;
    }
    cout<<"Front element - "<<Q3.top()<<endl;
    assert(Q3.top() == "Mango");
    Q3.pop();
    cout<<"Front element - "<<Q3.top()<<endl;
    assert(Q3.top() == "Banana");
    string new_element3 = "Apricot";
    uint32_t new_element_priority3 = 2;
    Q3.push(new_element3,new_element_priority3);
    while(!Q3.empty()){
        cout<<Q3.top()<<", ";
        Q3.pop();
    }
    cout<<endl;
    // Test4 with data user defined data
    
    
    
    return 0;
}
