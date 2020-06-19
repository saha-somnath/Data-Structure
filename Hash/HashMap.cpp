//
//  main.cpp
//  HashMap
//
//  Created by Somnath Saha on 6/17/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
  A implementation of HashMap where key is of type uint32_t and value is a C string.

  Compile: g++ HashMap.cpp -std=c++11 -o HashMap
  Execution: ./HashMap
*/

struct Node{
    uint32_t _key;
    const char* _data;
    Node(uint32_t k, const char* d):_key(k),_data(d){}
};

class HashMap
{
    uint32_t _index;
    uint64_t _size;
    vector<vector<Node>> _elements;
public:
    HashMap(uint32_t i):_index(i),_size(0)
    {
        for(uint32_t index = 0 ; index< _index; index++){
            vector<Node> elm;
            _elements.push_back(elm);
        }
    }
    ~HashMap();
    void insert(uint32_t key, const char* value);
    bool erase(uint32_t key);
    bool find( uint32_t key); // Check if any element exist.
    string get(uint32_t key) const;
    uint64_t size() const {return _size;}
    void clear();
};

HashMap::~HashMap()
{
    clear();
}
void HashMap::clear()
{
    for(auto elm: _elements){
        elm.clear();
    }
    _elements.clear();
}

void HashMap::insert(uint32_t key, const char* value)
{
    // Hash Function key % index
    uint32_t index = key % _index;
    Node node(key, value);
    _elements[index].push_back(node);
    _size++;
}

bool HashMap::find(uint32_t key)
{
    uint32_t index = key % _index;
    for(auto elm: _elements[index]){
        if ( elm._key == key ){
            return true;
        }
    }
    return false;
}

bool HashMap::erase(uint32_t key)
{
    uint32_t index = key % _index;
    vector<Node>::iterator it;
    for(it=_elements[index].begin(); it != _elements[index].end(); it++){
        if ( (*it)._key == key )
        {
            _elements[index].erase(it);
            _size--;
            return true;
        }
    }
    return false;
}

string HashMap::get(uint32_t key) const
{
    string data;
    uint32_t index = key % _index;
    for(auto elm: _elements[index]){
        if ( elm._key == key )
        {
            data =  elm._data;
        }
    }
    return data;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "HashMap or Dictionary!\n";
    
    HashMap* H= new HashMap(10);
    H->insert(30, "Data1");
    H->insert(5, "Data2");
    H->insert(15, "Data3");
    cout<<H->get(30)<<","<<H->get(5)<<","<<H->get(15)<<endl;
   
    // Test1
    assert(H->size() == 3); // Check Size
    assert(H->find(15) == true); // Existing element
    assert(H->find(12) == false); // Not existing element
    assert(H->get(5) == "Data2"); // Value check.
    H->erase(5);
    assert(H->size() == 2); // Check Size
    cout<<H->get(30)<<","<<H->get(5)<<","<<H->get(15)<<endl;
    delete H;
    
    return 0;
}

