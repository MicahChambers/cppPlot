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
 * @file tga_test1.cpp Tests function plotting, 
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>

#include "test_funcs.h"
#include "tgaImage.h"

using namespace std;
using namespace npl;

int main()
{
	TGAImage img1;

	const size_t RANDLEN = 1024;
	double rand1[RANDLEN];
	for(size_t ii=0; ii<RANDLEN; ii++) 
		rand1[ii] = ii;

	// test lambda
	// note that default is 0-1, but that later if you set a different value, 
	// the entire range will be plotted
	img1.addFunc([](double v){return v*v;});
	img1.write("test2_1.tga");

	// test lambda with min and max
	img1.clear();
	img1.addFunc(0, 1, [](double v){return v*v;});
	img1.write("test2_2.tga");
	
	if(!filesame("test2_1.tga", "test2_2.tga")) 
		return -1;

	// changing the range affects all set functions
	img1.setRange(0, 10);
	img1.write("test2_3.tga");
	
	if(filesame("test2_1.tga", "test2_3.tga")) 
		return -1;

	return 0;
}

