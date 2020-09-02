#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
int num = 0;
	char expression[50];
	stack<int> myStack;
	
	cout << "***************** Postfix Expression Calculator *****************" << endl;
	cout << "Separate operator and operands with eachother using spaces." << endl;
	cout << "Example: 2 5 * 2 - 4 / 2 + 1 2 ^ -\nNote: Use the caret symbol: ^ for exponent\n\nEnter your Expression: ";
	
	cin.getline(expression, 50, '\n');
	
	for(int i = 0; i < 50 && expression[i] != '\0'; i++) {
		if (expression[i] >= '0' && expression[i] <= '9') { 	// if the character is a number
			do { 												// Conversion to int
				num = num*10;
				num += (expression[i] - '0');
				i++;
			} while(expression[i] != ' ');

			// Now integer num has an operand
			myStack.push(num);
			num = 0;
		}
		else {
			if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
				int op2 = myStack.top();
                myStack.pop();
				int op1 = myStack.top();
                myStack.pop();
				int res;
				
				switch (expression[i]) {
					case '+':
						res = op1 + op2;
						break;
					case '-':
						res = op1 - op2;
						break;
					case '*':
						res = op1 * op2;
						break;
					case '/':
						res = op1 / op2;
						break;
					case '^':
						res = pow(op1, op2);
						break;
				}
				
				myStack.push(res);
			}
		}
	}
	
	cout << "Result: "  << myStack.top() << endl;

	return 0;
}

