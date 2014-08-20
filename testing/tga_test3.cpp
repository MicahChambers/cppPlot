/******************************************************************************
 * Copyright 2014 Micah C Chambers (micahc.vt@gmail.com)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file tga_test3.cpp Tests sinc plotting. 
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "test_funcs.h"
#include "basic_plot.h"

using namespace std;
using namespace npl;

int main()
{
	Plotter img1;

	const size_t RANDLEN = 128;
	double xvals[RANDLEN];
	double yvals[RANDLEN];
	const double PI = acos(-1);
	for(size_t ii=0; ii<RANDLEN; ii++) {
		double xx = ii*2*PI/10.+.1;
		xvals[ii] = xx;
		yvals[ii] = sin(xx)/xx;
	}

	// by default, this should generate x values of 0-RANDLEN-1, and y values
	// are provided
	img1.addArray(RANDLEN, xvals, yvals);
	
	img1.write("test3-1.tga");

	return 0;
}

