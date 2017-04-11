#include<iostream>
#include<set>


using namespace std;


int countPairs( int*A , int n);

int main(int argc, char** argv)
{
    int arr[] = {6 ,2 ,4 ,12 ,5 ,3} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout <<"Count Pairs:"<< countPairs(arr, n) <<endl;
    return 0;
    
   
return 0;
}


int countPairs( int*A , int n)
{
    set<int> Hash;
    int count = 0;
    for ( int i =0 ; i < n; i++ )
    {
        Hash.insert(A[i] );
    }
    
    // Find product
    for ( int j =0 ; j < n ; j++ )
    {
        for( int k = j+1; k < n; k++ )
        {
            int prod = A[j] * A[k];
            if ( Hash.count( prod ) )
            {
                count++;
            }
        }
    }

    return count;
}

