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
 * @file tga_test2.cpp Tests function plotting, 
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>

#include "test_funcs.h"
#include "basic_plot.h"

using namespace std;
using namespace npl;

int main()
{
	Plotter img1;

	// test lambda
	// note that without a valid range, we won't be doing any calculations
	img1.addFunc([](double v){return v*v;});
	img1.addFunc([](double v){return v+10;});

	// changing the range affects all set functions
	img1.setXRange(0, 10);
	img1.write("test2-1.tga");
	
	return 0;
}

