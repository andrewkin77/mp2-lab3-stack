#include "calculator.h"

TCalculator::TCalculator() :st_c(), st_d()
{}

TCalculator::TCalculator(const TCalculator& calc)
{
	expr = calc.expr;
	postfix = calc.postfix;
	st_c = calc.st_c;
	st_d = calc.st_d;
}

void TCalculator::SetExpr(string _expr)
{
	expr = _expr;
	if (check())
		ToPostfix();
}

string TCalculator::GetExpr()
{
	return expr;
}

bool TCalculator::check()
{
	st_c.clear();
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '(')
			st_c.push('(');
		if (expr[i] == ')') {
			if (st_c.IsEmpty())
				return false;
			else
			st_c.pop();
		}
	}
	return st_c.IsEmpty();
}

void TCalculator::ToPostfix()
{
		string str = "(";
		str += expr;
		str += ")";
		st_c.clear();
		postfix = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				st_c.push(str[i]);
			if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.')) {
				postfix += str[i];
			}
			if (str[i] == ')') {
				char tmp = st_c.pop();
				while (tmp != '(') {
					postfix += tmp;
					tmp = st_c.pop();
				}
			}
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
				postfix += " ";
				char tmp = st_c.pop();
				while (prior(str[i]) <= prior(tmp)) {
					postfix += tmp;
					tmp = st_c.pop();
				}
				st_c.push(tmp);
				st_c.push(str[i]);
			}
		}
}

int TCalculator::prior(char c)
{
	switch (c) {
	case  '(': return 0;
	case  '+': return 1;
	case  '-': return 1;
	case  '*': return 2;
	case  '/': return 2;
	case  '^': return 3;
	case  ')': return 4;
	}
}


double TCalculator::calc()
{
	st_d.clear();
	char* tmp;
	double res;
	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			double d = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			st_d.push(d);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double op1, op2;
			op2 = st_d.pop();
			op1 = st_d.pop();
			switch (postfix[i]) {
			case '+':
				res = op1 + op2; break;
			case '-':
				res = op1 - op2; break;
			case '*':
				res = op1 * op2; break;
			case '/':
				res = op1 / op2; break;
			case '^':
				res = pow(op1 ,op2); break;
			}
			st_d.push(res);
		}
	}
	res = st_d.pop();
	return res;
}