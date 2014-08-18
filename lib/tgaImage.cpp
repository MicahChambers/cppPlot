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

#include "tgaImage.h"
	
TGAImage::TGAImage(size_t xres, size_t yres)
{
	clear();
	res[0] = xres;
	res[1] = yres;
}

void TGAImage::clear()
{
	res[0] = 1024;
	res[1] = 768;
	xrange[0] = NAN;
	xrange[1] = NAN;
	yrange[0] = NAN;
	yrange[1] = NAN;
	axes = false;
	
	colors.clear();
	colors.push_back(StyleT("r"));
	colors.push_back(StyleT("g"));
	colors.push_back(StyleT("b"));
	colors.push_back(StyleT("y"));
	colors.push_back(StyleT("c"));
	colors.push_back(StyleT("p"));
	colors.push_back(StyleT("-r"));
	colors.push_back(StyleT("-g"));
	colors.push_back(StyleT("-b"));
	colors.push_back(StyleT("-y"));
	colors.push_back(StyleT("-c"));
	colors.push_back(StyleT("-p"));

	curr_color = colors.begin();

	axes = false;

	funcs.clear();
	arrs.clear();
}

/**
 * @brief Writes the output image to the given file
 *
 * @param fname File name to write to.
 */
void TGAImage::write(std::string fname)
{
	write(res[0], res[1], fname);
}

/**
 * @brief Write the output image with the given (temporary) resolution.
 * Does not affect the internal resolution
 *
 * @param xres X resolution
 * @param yres Y resolution
 * @param fname Filename
 */
void TGAImage::write(size_t xres, size_t yres, std::string fname)
{

}

/**
 * @brief Sets the x range. To use the extremal values from input arrays
 * just leave these at the default (NAN's)
 *
 * @param low Lower bound
 * @param high Upper bound
 */
void TGAImage::setXRange(double low, double high)
{
	xrange[0] = low;
	xrange[1] = high;
}

/**
 * @brief Sets the y range. To use the extremal values from input arrays
 * and computed yvalues from functions, just leave these at the default
 * (NAN's)
 *
 * @param low Lower bound
 * @param high Upper bound
 */
void TGAImage::setYRange(double low, double high)
{
	yrange[0] = low;
	yrange[1] = high;
}

/**
 * @brief Sets the default resolution
 *
 * @param xres Width of output image
 * @param yres Height of output image
 */
void TGAImage::setRes(size_t xres, size_t yres)
{
	res[0] = xres;
	res[1] = yres;
}

void TGAImage::addFunc(double(*f)(double))
{
	addfFunc(*curr_color, f);
	curr_color++;
	if(curr_color == colors.end())
		curr_color = colors.begin();
}

void TGAImage::addFunc(const std::string& style, double(*f)(double))
{
	StyleT tmps(style);
	addFunc(tmps, f);
}

void TGAImage::addFunc(const std::string& style, double(*f)(double))
{
	funcs.push_back(std::make_tuple<StyleT, (double)*(double)>(style, f));
}

void TGAImage::addArray(size_t sz, double* array)
{
	std::vector<double> tmpx(sz);
	std::vector<double> tmpy(sz);
	for(size_t ii=0; ii<sz; ii++) {
		tmpx[ii] = ii;
		tmpy[ii] = array[ii];
	}
	
	arrs.push_back(std::make_tuple<StyleT,vector<double>,vector<double>(
				*curr_color, tmpx, tmpy));

	if(curr_color == colors.end())
		curr_color = colors.begin();
}

void TGAImage::addArray(size_t sz, double* xarr, double* yarr)
{
	std::vector<double> tmpx(sz);
	std::vector<double> tmpy(sz);
	for(size_t ii=0; ii<sz; ii++) {
		tmpx[ii] = xarr[ii];
		tmpy[ii] = yarr[ii];
	}

	arrs.push_back(std::make_tuple<StyleT,vector<double>,vector<double>(
				*curr_color, tmpx, tmpy));
	
	if(curr_color == colors.end())
		curr_color = colors.begin();
};

void TGAImage::addArray(const std::string& style, size_t sz, double* array)
{
	std::vector<double> tmpx(sz);
	std::vector<double> tmpy(sz);
	for(size_t ii=0; ii<sz; ii++) {
		tmpx[ii] = xarr[ii];
		tmpy[ii] = yarr[ii];
	}
	tmpstyle(style);
	arrs.push_back(std::make_tuple<StyleT,vector<double>,vector<double>(style,
				tmpx, tmpy));
}

void TGAImage::addArray(const StyleT& style, size_t sz, double* xarr, double* yarr)
{
	std::vector<double> tmpx(sz);
	std::vector<double> tmpy(sz);
	for(size_t ii=0; ii<sz; ii++) {
		tmpx[ii] = xarr[ii];
		tmpy[ii] = yarr[ii];
	}

	arrs.push_back(std::make_tuple<StyleT,vector<double>,vector<double>(
				style, tmpx, tmpy));
}

};

