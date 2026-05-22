#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char first_word = ' ';
    int same_word_count = 0;
    int diff_word_count = 0;
    
    for(char& c : s)
    {
        if(first_word == ' ')
        {
            answer += 1;
            first_word = c;
            same_word_count = 0;
            diff_word_count = 0;
        }
        
        if(c == first_word)
            same_word_count += 1;
        else if(c != first_word)
            diff_word_count += 1;
        
        if(same_word_count == diff_word_count)
            first_word = ' ';
        
    }
    return answer;
}