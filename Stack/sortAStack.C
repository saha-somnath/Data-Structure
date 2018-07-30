#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;
int main(int argc, char** argv )
{
    std::stack<int> X;
    std::stack<int> Y;

    X.push(atoi(argv[1]));    
    X.push(atoi(argv[2]));    
    X.push(atoi(argv[3]));    
    X.push(atoi(argv[4]));    
    X.push(atoi(argv[5]));    
    X.push(atoi(argv[6]));

    bool flag = true;
    
    while ( flag )
    {
        
        flag =  false;
        
        int a1 = X.top();
        X.pop();
        // Pop element from X and push to Y , keep large element into X and small element to Y
        while( ! X.empty() )
        {
            //int a1 = X.top();
            //X.pop();
            int a2 = X.top();
            X.pop();
            
            if (a1>a2)
            {
                //X.push(a1);
                Y.push(a2);
                flag = true;
            }
            else
            {
                //X.push(a2);
                Y.push(a1);
                a1 = a2; // a1 holds large element
            }
        }
        X.push(a1); // Push large element at the end
        
        /*if (! flag )
        {
            break;
        }*/
        
        // Apply same logic for Y , keeping smaller element in X
        a1 = Y.top();
        Y.pop();
        
        while( ! Y.empty() )
        {
            //int a1 = Y.top();
            //Y.pop();
            int a2 = Y.top();
            Y.pop();
            
            // Keep small element to Y and large to X
            if (a1>a2)
            {
                X.push(a1);
                //Y.push(a2);
                a1 = a2 ; // Assigning small number
            }
            else
            {
                X.push(a2);
                //Y.push(a1);
                flag = true;
            }
        }
        // At end push it to x
        X.push(a1);
        
    }
    
    // Dsiaplay Stak Elements
    while( ! X.empty() )
    {
        cout<<X.top() <<" ,";
        X.pop();
    }

    cout<<endl;
   
    return 0;
}
