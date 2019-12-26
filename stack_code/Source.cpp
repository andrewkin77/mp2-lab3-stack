#include "calculator.h"
#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	TCalculator c;
	c.SetExpr("2 + 2");
	cout << c.calc();
	_getch();
}