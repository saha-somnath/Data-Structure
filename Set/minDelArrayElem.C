#include<iostream>
#include<unordered_map>


using namespace std;


int main(int argc, char** argv)
{
    int array[]={ 3, 5,4,4,5,2,4};

    int aLen = sizeof(array)/sizeof(array[0]);
    unordered_map<int,int> myHash;
    for ( int i=0; i< aLen ; i++)
    {
        myHash[array[i]] += 1 ;
    }

    int maxCount = 0;
    for ( auto it=myHash.begin(); it != myHash.end(); it++ )
    {
        maxCount = max(maxCount , it->second );
        cout<<"{"<<it->first<<"} => "<<it->second<<endl;
    }

    cout <<"Max Deletion Required:" << aLen - maxCount <<endl;

return 0;
}
