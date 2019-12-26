#pragma once
//#include"stack.h"
#include "stack_list.h"
#include <string>
#include <math.h>
using namespace std;
class TCalculator
{
	string expr, postfix;
	TStack<char> st_c;
	TStack<double> st_d;
public:
	TCalculator();
	TCalculator(const TCalculator& calc);
	~TCalculator() {};
	void SetExpr(string _expr);
	string GetExpr();
	bool check();
	int prior(char c);
	void ToPostfix();
	string GetPostfix() {
		return postfix;
	}
	double calc();
};

