#include "pch.h"
#include"../stack_code/calculator.cpp"

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> st);
}

TEST(TStack, can_copy_stack)
{
	TStack<int> st1;
	for (int i = 0; i < 7; i++)
	{
		ASSERT_NO_THROW(st1.push(i));
	}
	//ASSERT_NO_THROW(TStack<int> st(st1));
}

TEST(TStack, can_equate_stacks_with_equal_size)
{
	TStack<int> st1;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.push(i));
	}
	TStack<int> st;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.push(i));
	}
	ASSERT_NO_THROW(st = st1);
}

TEST(TStack, can_equate_stacks_with_different_size)
{
	TStack<int> st1;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st1.push(i));
	}
	TStack<int> st(10);
	for (int i = 0; i < 7; i++)
	{
		ASSERT_NO_THROW(st.push(i));
	}
	ASSERT_NO_THROW(st = st1);
}

TEST(TStack, can_push_in_stack)
{
	TStack<int> st;
	ASSERT_NO_THROW(st.push(5));
	EXPECT_EQ(st.pop(), 5);
}


TEST(TStack, can_pop_elem_from_stack)
{
	int d;
	TStack<int> st;
	st.push(1);
	ASSERT_NO_THROW(d = st.pop());
	EXPECT_EQ(1, d);
}

TEST(TStack, cant_pop_elem_from_empty_stack)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, can_check_empty_stack)
{
	TStack<int> st;
	EXPECT_EQ(st.IsEmpty(), 1);
}


TEST(TStack, can_clear_stack)
{
	TStack<int> st;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.push(i));
	}
	st.clear();
	EXPECT_EQ(st.IsEmpty(), 1);
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> st;
	TStack<int> cpy;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.push(i));
	}
	cpy = st;
	for (int i = 4; i >= 0; i--)
	{
		EXPECT_EQ(st.pop(), i);
	}
}

TEST(TStack, can_check_top_elem_from_stack)
{
	TStack<int> st;
	for (int i = 0; i < 5; i++)
	{
		ASSERT_NO_THROW(st.push(i));
	}
	for (int i = 4; i >= 0; i--)
	{
		EXPECT_EQ(st.top(), i);
		EXPECT_EQ(st.pop(), i);
	}
}



TEST(TCalculator, can_create_calc)
{
	ASSERT_NO_THROW(TCalculator c);
}

TEST(TCalculator, can_set_expr)
{
	TCalculator c;
	ASSERT_NO_THROW(c.SetExpr("2+2"));
	EXPECT_EQ(c.GetExpr(), "2+2");
}

TEST(TCalculator, can_get_expr)
{
	TCalculator c;
	ASSERT_NO_THROW(c.SetExpr("2+2"));
	ASSERT_NO_THROW(c.GetExpr());
	EXPECT_EQ(c.GetExpr(), "2+2");
}

TEST(TCalculator, check_function_works_correctly)
{
	TCalculator c;
	c.SetExpr("((2)+(2))");
	ASSERT_NO_THROW(c.check());
	EXPECT_TRUE(c.check());
	c.SetExpr("(2)+(2))");
	ASSERT_NO_THROW(c.check());
	EXPECT_EQ(c.check(), 0);
}


TEST(TCalculator, cacl_function_works_correctly_with_plus_for_int)
{
	TCalculator c;
	c.SetExpr("5+7");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 5 + 7);
	c.SetExpr("0+7");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 7);
}

TEST(TCalculator, cacl_function_works_correctly_with_plus_for_double)
{
	TCalculator c;
	c.SetExpr("1/2+1/2");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 1);
	c.SetExpr("0+1/2");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 0.5);
	c.SetExpr("1/2+1/4");
	ASSERT_NO_THROW(c.calc());
	double sum = (1.0 / 2) + (1.0 / 4);
	EXPECT_EQ(c.calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_minus_for_int)
{
	TCalculator c;
	c.SetExpr("8-3");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 8 - 3);
	c.SetExpr("7-2");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 7 - 2);
	c.SetExpr("0-7");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), -7);
}

TEST(TCalculator, cacl_function_works_correctly_with_minus_for_double)
{
	TCalculator c;
	c.SetExpr("1/2-1/2");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 0);
	c.SetExpr("0-1/2");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), -0.5);
	c.SetExpr("1/2-1/4");
	ASSERT_NO_THROW(c.calc());
	double sum = (1.0 / 2) - (1.0 / 4);
	EXPECT_EQ(c.calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_mult_for_int)
{
	TCalculator c;
	c.SetExpr("5*7");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 5 * 7);
	c.SetExpr("0*7");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 0 * 7);
}

TEST(TCalculator, cacl_function_works_correctly_with_mult_for_double)
{
	TCalculator c;
	c.SetExpr("1/2*1/2");
	ASSERT_NO_THROW(c.calc());
	double sum = (1.0 / 2) * (1.0 / 2);
	EXPECT_EQ(c.calc(), sum);
	c.SetExpr("0*1/2");
	ASSERT_NO_THROW(c.calc());
	sum = 0 * (1.0 / 2);
	EXPECT_EQ(c.calc(), sum);
	c.SetExpr("1*1/2");
	sum = 1 * (1.0 / 2);
	EXPECT_EQ(c.calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_div_for_int)
{
	TCalculator c;
	c.SetExpr("5/7");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 5.0 / 7);
	c.SetExpr("0/7");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 0 / 7);
	c.SetExpr("5/0");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), INFINITY);
}

TEST(TCalculator, cacl_function_works_correctly_with_diff_op_for_double)
{
	TCalculator c;
	c.SetExpr("(1.1/2)/(1/2.1)");
	ASSERT_NO_THROW(c.calc());
	double sum = (1.1 / 2) / (1.0 / 2.1);
	EXPECT_EQ(c.calc(), sum);
	c.SetExpr("0/(1/2.1)");
	ASSERT_NO_THROW(c.calc());
	sum = (0 / (1 / (2.1)));
	EXPECT_EQ(c.calc(), sum);
	c.SetExpr("1/(1/2.1)");
	ASSERT_NO_THROW(c.calc());
	sum = 1 / (1.0 / 2.1);
	EXPECT_EQ(c.calc(), sum);
	c.SetExpr("(1/5.1)/0");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), INFINITY);
}

TEST(TCalculator, cacl_function_works_correctly_with_vozv_v_step_for_int)
{
	TCalculator c;
	c.SetExpr("5^0");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 1);
	c.SetExpr("0^5");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 0);
	c.SetExpr("5^2");
	ASSERT_NO_THROW(c.calc());
	double sum = pow(5, 2);
	EXPECT_EQ(c.calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_for_diff_alg_op) {
	TCalculator c;
	c.SetExpr("(5+5)*5");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 50);
	c.SetExpr("5+5*5");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 30);
	c.SetExpr("(5+5)/5");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 2);
	c.SetExpr("5+5/5");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 6);
	c.SetExpr("5+5^2/5");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), 5 + pow(5, 2) / 5);
	c.SetExpr("5/5+(2^5-1+8*7)-1");
	ASSERT_NO_THROW(c.calc());
	EXPECT_EQ(c.calc(), ((5 / 5) + ((pow(2, 5)) - 1 + 8 * 7) - 1));
}
