//
//  hash.hpp
//  Hash
//
//  Created by Somnath Saha on 5/8/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

#ifndef hash_hpp
#define hash_hpp

#include <iostream>
#include <vector>
using namespace std;


struct Node
{
  int _data;
  Node* next;
  Node(int data=0):_data(data), next(NULL){}
};

class Hash
{
  int _keys; // Total number of index
  vector<Node*> _values;
  uint32_t _size;
public:
  Hash(int keys):_keys(keys),_size(0)
  {
    for(uint32_t index = 0; index < _keys; index++){
      _values.push_back(NULL);
    }
  }
  ~Hash();
  bool insert(int value);
  uint32_t count(int value); // Counts number of matching elements.
  bool find(int value);
  uint32_t size();
  void clear(); // Clear all elements of hash.
  void display();
};

#endif /* hash_hpp */
