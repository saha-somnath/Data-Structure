#include<iostream>
#include<map>
#include<vector>

using namespace std;


int main()
{
    int A[] = { 3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};


    map<int, vector<int> > myMap;

    int aSize = sizeof(A)/sizeof(A[0]);
    
    for( int i =0; i < aSize; i++ )
    {
        vector<int> v;
        if(  myMap.find(A[i]) == myMap.end())
        {
            v.push_back(0); // Length
            v.push_back(i); // Index
            myMap[A[i]]  =  v;

        }
        else
        {
            // find the length
            int dist = myMap[A[i]][0];
            int index= myMap[A[i]][1];
            if ( dist < (i - index))
            {
                 myMap[A[i]][0] = (i - index);
                 //myMap[A[i]][1] = i;  // Comment out if want to calculate distance from first occurance of element
    
            }
        }
    }

    map<int, vector<int> >::iterator it;
    for( it = myMap.begin(); it != myMap.end(); it++ )
    {
        cout<< it->first <<"=>" << (it->second)[0]<<endl;;

    }
return 0;
}
