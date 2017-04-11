#include<iostream>
#include<vector>
#include<stack>
#include<math.h>
#include<string>


using namespace std;

/*
Power Set Algorithm 2^n

*/

void powerSet(int *A, int setSize);

int main(int argc, char** argv)
{
    int A[] ={ 1,2,3};

    vector< vector<int> > sets;
    int setSize = sizeof(A)/ sizeof(A[0]);
    int n = pow(2,setSize);

    for (int i = 0; i < n ; i++ )
    {
        vector<int> s;
        for( int j=0; j <setSize; j++ )
        {
            if ( i & 1 << j )
            {   
                cout<<A[j]<<",";
                s.push_back(A[j]);
            }
        }
        sets.push_back(s);
        cout<<endl;
    }
    
    // Iterate Vector
    for ( int  i = 0; i < n ; i++ )
    {
        cout<<"{ ";
        for ( int n : sets[i])
        {
            cout<< n <<", ";
        }
        cout<<"}";
    }
     

    return 0;
}


