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
 * @file svg_test4.cpp Tests that axes are correct
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
	
	double x = 0;
	double y = 0;
	img1.addArray(1, &x, &y);
	
	x = 10; y = 10;
	img1.addArray(1, &x, &y);

	const size_t RANDLEN = 128;
	double xvals[RANDLEN];
	double yvals[RANDLEN];
	// rising line
	for(size_t ii=0; ii<RANDLEN; ii++) {
		xvals[ii] = ii/(double)RANDLEN;
		yvals[ii] = ii/(double)RANDLEN;
	}
	img1.addArray(RANDLEN, xvals, yvals);
	
	// falling line
	for(size_t ii=0; ii<RANDLEN; ii++) {
		xvals[ii] = ii/(double)RANDLEN;
		yvals[ii] = -ii/(double)RANDLEN;
	}
	img1.addArray(RANDLEN, xvals, yvals);
	
	img1.write("test4-1.svg");

	return 0;
}


