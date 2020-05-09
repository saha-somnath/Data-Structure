//
//  hash.cpp
//  Hash
//
//  Created by Somnath Saha on 5/8/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

#include "hash.hpp"


Hash::~Hash()
{
    cout<<"Destructor"<<endl;
    clear();
    _values.clear();
}

/*
 Insert the elements in a sorted order
 */
bool Hash::insert(int value)
{
    // Modulo function
    int mod = value % _keys;
    Node* ptr = _values[mod];
    Node* node = new Node(value);
    if( ptr ){
        // First element
        if( value < ptr->_data){
            node->next = ptr;
            _values[mod] = node;
            
        } else {
            Node* prev = ptr;
            ptr = ptr->next;
            while(ptr){
                if( value < ptr->_data){
                    break;
                }
                prev = ptr;
                ptr = ptr->next;
            }
            node->next = ptr;
            prev->next = node;
        }
    } else{
        _values[mod] = node;
    }
    _size++;
    return true;
}

/*
 Count the matching element in Hash.
 */
uint32_t Hash::count(int value){
    int mod = value % _keys;
    Node* ptr = _values[mod];
    uint32_t total_matched_elements = 0;
    while( ptr ){
        if ( ptr->_data == value){
            total_matched_elements++;
        }
        if (ptr->_data > value ){
            break;
        }
        ptr = ptr->next;
    }
    return total_matched_elements;
}
/*
 Return taotal elements of Hash.
 */
uint32_t Hash::size(){
    return _size;
}
/*
 Find the specified value
 */
bool Hash::find(int value)
{
    int mod = value % _keys;
    Node* ptr = _values[mod];
    while( ptr ){
        if ( ptr->_data == value){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
/*
 Clear all elements of Hash
 */
void Hash::clear()
{
    int index = 0;
    while(index < _keys){
        Node* head = _values[index];
        while(head){
            Node* ptr = head;
            cout<<head->_data<<"->";
            head =head->next;
            delete ptr;
            ptr = NULL;
            _size--;
        }
        _values[index] = NULL;
        cout<<"NULL"<<endl;
        index++;
    }
}

/*
 Display all elements of Hash.
 */
void Hash::display()
{
    int index = 0;
    while(index < _keys){
        Node* ptr = _values[index];
        cout<<":"<<index<<": ";
        while(ptr){
            cout<<ptr->_data<<"->";
            ptr = ptr->next;
        }
        cout<<"NULL"<<endl;
        index++;
    }
}
