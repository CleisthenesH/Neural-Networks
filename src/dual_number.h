// Copyright 2023 Kieran W Harvie. All rights reserved.
//
// This header implements dual numbers, their arithmetic, and select functions.
// Implemented as static inline functions.
//
// Note that it is particularly easy to create dual_numbers through compound literals.
// The two code snippets are equivalent:
//
// dual_number a = (dual_number){1,2};
//
// dual_number a;
// a.r = 1;
// a.i = 2;

#ifndef DUAL_NUMBER_HEADER_GUARD
#define DUAL_NUMBER_HEADER_GUARD

#include <math.h>

typedef struct{
	double r; // For real part
	double i; // For infinitesimal part
} dual_number;

static inline dual_number dual_add(dual_number a, dual_number b)
{
	return (dual_number){a.r+b.r,a.i+b.i};
}

static inline dual_number dual_sub(dual_number a, dual_number b)
{
	return (dual_number){a.r-b.r,a.i-b.i};
}

static inline dual_number dual_mul(dual_number a, dual_number b)
{
	return (dual_number){a.r*b.r,a.r*b.i+a.i*b.r};
}

static inline dual_number dual_div(dual_number a, dual_number b)
{
	const double division_threshold = 0.0001;

	if(fabs(b.r) < division_threshold)
		return (dual_number){HUGE_VAL, HUGE_VAL};

	return (dual_number){a.r/b.r,(a.i*b.r-a.r*b.i)/(b.r*b.r)};
}

static inline dual_number dual_sin(dual_number a)
{
	return (dual_number){sin(a.r),a.i*cos(a.r)};
}

static inline dual_number dual_cos(dual_number a)
{
	return (dual_number){cos(a.r),-a.i*sin(a.r)};
}

static inline dual_number dual_exp(dual_number a)
{
	const double r = exp(a.r);
	return (dual_number){r,a.i*r};
}

static inline dual_number dual_logistic(dual_number a)
{
	const double r = 0.5*(1.0+tanh(0.5*a.r));
	return (dual_number){r,r*(1-r)};
}

static inline dual_number dual_abs(dual_number a)
{
	return (dual_number){fabs(a.r),(a.r>0?1:-1)*a.i};
}

#endif
