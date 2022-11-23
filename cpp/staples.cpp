#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str;
    string stack;
    int sumopen = 0;
    int sumclouse = 0;
    int counter = 0;
    int maxi = 0;
    getline(cin, str);
    for (int i = 0;i < size(str);i++) {
        if ((str[i] == '[') || (str[i] == '(')) {
            stack = stack + str[i];
            sumopen++;
            counter = counter + 1;
            if (counter > maxi)
                maxi = counter;
        }
        else if ((str[i] == ']') || (str[i] == ')')) {
            sumclouse++;
            counter = counter - 1;

            if (str[i] == ']') {
                if ((size(stack) > 0) && (stack.back() == '['))
                    stack.erase(size(stack) - 1, 1);
            }
            else if (str[i] == ')') {
                if ((size(stack) > 0) && (stack.back() == '('))
                    stack.erase(size(stack) - 1, 1);
            };

        }
    }
    if ((size(stack) == 0) and (sumclouse == sumopen)) {
        cout << "True" << endl;
        cout << maxi << endl;
    }

    else
        cout << "False" << endl;
}