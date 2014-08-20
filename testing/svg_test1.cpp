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
 * @file svg_test1.cpp Tests array plotting functionality 
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <fstream>

#include "basic_plot.h"

using namespace std;
using namespace npl;

bool filesame(std::string in1, std::string in2)
{
	ifstream ifs1(in1.c_str(), ios::binary);
	ifstream ifs2(in2.c_str(), ios::binary);

	while(!ifs1.eof() && !ifs2.eof()) {
		unsigned char u = ifs1.get();
		unsigned char v = ifs2.get();
		if(u != v) 
			return false;
	}

	return true;
}

int main()
{
	Plotter img1;

	const size_t RANDLEN = 128;
	double rand1[RANDLEN];
	for(size_t ii=0; ii<RANDLEN; ii++) 
		rand1[ii] = ii;

	// by default, this should generate x values of 0-RANDLEN-1, and y values
	// are provided
	img1.addArray(RANDLEN, rand1);
	
	// now add an array with xvals of a log scale
	// make xvalues log
	double xvals[RANDLEN];
	double maxv = std::exp((double)RANDLEN-1.);
	for(size_t ii=0; ii<RANDLEN; ii++)  {
		xvals[ii] = std::exp((double)ii)/maxv;
	}
	img1.addArray(RANDLEN, xvals, rand1);

	// default should be 1024 x 768
	img1.write("test1-1.svg");
	img1.write(1024, 768, "test1-2.svg");

	return 0;
}


