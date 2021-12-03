#pragma once

#include <vector>
#include "matplot/matplot.h"


void plotter(std::vector<double> x, std::vector<double> y) {
    using namespace matplot;
	plot(x, y);
    show();
	while(true) ;
}