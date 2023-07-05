// This code can be found on:
// http://www.cplusplus.com/forum/beginner/206016/
#include <iostream>
#include <string>
#include <stack>


bool 
isEndBracket(char saved, char check)             // <==== checks if this is the correct end bracket
{
   return ( ( saved == '(' && check == ')' ) ||
            ( saved == '[' && check == ']' ) ||
            ( saved == '{' && check == '}' ) );
}

void 
isBalanced(std::string s)
{
    int x = s.length();
    std::stack <char> mstack;

    for (int i = 0; i < x ; i++)             // <==== x, not x-1
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            mstack.push(s[i]);
        }
        else if ( !mstack.empty() && isEndBracket( mstack.top(), s[i] ) )   // <==== check for empty first
        {
            mstack.pop();
        }
    }

    (mstack.empty()) ? std::cout << "Balanced!\n" : std::cout << "Not balanced!\n";
}

int 
main()
{
    std::string one = "(){}()";
    std::string two = "([(){}])";
    std::string three = "{{(]";
    std::string four = "()({[]})";

    isBalanced(one);
    isBalanced(two);
    isBalanced(three);
    isBalanced(four);

    return 0;
}
