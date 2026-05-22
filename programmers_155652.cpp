#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {    
    for(char& c : s)
    {
        int t = 0;
        while(t < index)
        {   
             c += 1;
            
            if('z' < c)
                c = 'a';

            if(skip.find(c) == string::npos)
                t+=1;
        }
    }
    
    return s;
}