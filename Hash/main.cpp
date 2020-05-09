//
//  main.cpp
//  Hash
//
//  Created by Somnath Saha on 5/7/20.
//  Copyright © 2020 Somnath Saha. All rights reserved.
//

#include <iostream>
#include <random>
#include "hash.hpp"

/*
 Compile: g++ main.cpp hash.cpp -std=c++11
 Execution: ./a.out
*/

int random(int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd()); // Generator
    std::uniform_int_distribution<> dis(x,y);
    return dis(gen);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Simple Implementation of Hash"<<endl;
    // Instantiation of Hash
    Hash* h =  new Hash(5);
    int index = 0;
    while(index < 20){
        int data = random(0,15);
        cout<<data<<",";
        h->insert(data);
        index++;
    }
    cout<<endl;
    h->display();
    
    
    // Test1- Find & Count values.
    for ( int index = 0 ; index < 5; index++){
        string found =h->find(index)? "True": "False";
        cout<<"find:"<<index<<":"<<found<<endl;
        cout<<"count:"<<index<<":"<<h->count(index)<<endl;
    }
    
    // Test2- Clear Hash.
    h->clear();
    string passed = h->size()? "Failed": "Passed";
    cout<<"Clear:"<<passed<<endl;
    h->display();

    delete h;
    return 0;
}
