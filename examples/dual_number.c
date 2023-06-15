// Copyright 2023 Kieran W Harvie. All rights reserved.

#include <stdio.h>
#include "dual_number.h"

// A dual_number function corresponding to f(x,y) = cos(xy)+y
dual_number func(dual_number x, dual_number y)
{
	return dual_add(dual_cos(dual_mul(x,y)),y);
}

void main()
{
	// Define two operands
	const dual_number a = (dual_number){1,1};
	const dual_number b = (dual_number){2,2};

	printf("Operands:\n"
		"\ta=(%lf,%lf)\n"
		"\tb=(%lf,%lf)\n",
		a.r,a.i,b.r,b.i);

	// Basic operations
	const dual_number add = dual_add(a,b);
	const dual_number sub = dual_sub(a,b);
	const dual_number mul = dual_mul(a,b);
	const dual_number div = dual_div(a,b);

	printf("\nBasic Operations:\n"
		"\ta+b=(%lf,%lf)\n"
		"\ta-b=(%lf,%lf)\n"
		"\ta*b=(%lf,%lf)\n"
		"\ta/b=(%lf,%lf)\n",
		add.r,add.i,
		sub.r,sub.i,
		mul.r,mul.i,
		div.r,div.i);

	// Division Failsafe
	const dual_number div_fail = dual_div((dual_number){1,2},(dual_number){0,1});

	printf("\nDivision Failsafe:\n"
		"\t(1,2)/(0,1)=(%lf,%lf)\n",
		div_fail.r, div_fail.i);

	// Basic Functions
	const dual_number sin = dual_sin(a);
	const dual_number cos = dual_cos(b);
	const dual_number exp = dual_exp(b);

	printf("\nBasic Functions:\n"
		"\tsin(a)=(%lf,%lf)\n"
		"\tcos(a)=(%lf,%lf)\n"
		"\texp(b)=(%lf,%lf)\n",
		sin.r,sin.i,
		cos.r,cos.i,
		exp.r,exp.i);

	// Logistic Function
	const dual_number logi_a = dual_logistic(a);
	const dual_number logi_b = dual_logistic(b);

	printf("\nLogistic Function:\n"
		"\tLogistic(a)=(%lf,%lf)\n"
		"\tLogistic(b)=(%lf,%lf)\n",
		logi_a.r,logi_a.i,
		logi_b.r,logi_b.i);

	// Complex function
	const dual_number partial_x = func((dual_number){0,1},(dual_number){1,0});
	const dual_number partial_y = func((dual_number){0,0},(dual_number){1,1});

	printf("\nComplex Function f(x,y) = cos(xy)+y:\n"
		"\tf((0,1),(1,0))=(%lf,%lf)\n"
		"\tf((0,0),(1,1))=(%lf,%lf)\n"
		"\n\tObserve that the infinitesimals correspond to the partial derivatives of f at x=0 and y=1.\n",
		partial_x.r,partial_x.i,
		partial_y.r,partial_y.i
		);
}
