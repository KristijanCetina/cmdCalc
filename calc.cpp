#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

//Function to return precedence of operators
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

//convert infix expression to postfix expression
string infixToPostfix(string s)
{
	std::stack<char> st;
	st.push('N');
	int stringLenght = s.length();
	string ns;
	for (int i = 0; i < stringLenght; i++)
	{
		// If the scanned character is an operand, add it to output string.
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			ns += s[i];
			ns += " ";
		}
		// If the scanned character is an ‘(‘, push it to the stack.
		else if (s[i] == '(')

			st.push('(');

		// If the scanned character is an ‘)’, pop and to output string from the stack
		// until an ‘(‘ is encountered.
		else if (s[i] == ')')
		{
			while (st.top() != 'N' && st.top() != '(')
			{
				char c = st.top();
				st.pop();
				ns += c;
				ns += " ";
			}
			if (st.top() == '(')
			{
				char c = st.top();
				st.pop();
			}
		}

		//If an operator is scanned
		else
		{
			while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
			{
				char c = st.top();
				st.pop();
				ns += c;
				ns += " ";
			}
			st.push(s[i]);
		}
	}
	//Pop all the remaining elements from the stack
	while (st.top() != 'N')
	{
		char c = st.top();
		st.pop();
		ns += c;
		ns += " ";
	}

	cout << "\npostfix notation: " << ns << "\n";
	return ns;
}

void calculatePostfix(std::string expression)
{
	int num = 0;
	//char expression[50];
	stack<int> myStack;

	for (int i = 0; i < 50 && expression[i] != '\0'; i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{ // if the character is a number
			do
			{ // Conversion to int
				num = num * 10;
				num += (expression[i] - '0');
				i++;
			} while (expression[i] != ' ');

			// Now integer num has an operand
			myStack.push(num);
			num = 0;
		}
		else
		{
			if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
			{
				int op2 = myStack.top();
				myStack.pop();
				int op1 = myStack.top();
				myStack.pop();
				int res;

				switch (expression[i])
				{
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

	cout << "Result: " << myStack.top() << endl;
}

int main()
{
	// string exp = "a+b*(c^d-e)^(f+g*h)-i";
	string exp = "(1+2)^3";
	cout << "for " << exp << " ";
	calculatePostfix(infixToPostfix(exp));
	return 0;
}
