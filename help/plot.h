#pragma once

#include <vector>
//#include "matplot/matplot.h"

class CustomPlotter {
    public:
    CustomPlotter() {
        std::cout << "plot constuctor";    
        data_x.clear();
        data_y.clear();
        time = 0.0;
    }
    void add(double value) {
        data_x.push_back(time);
        data_y.push_back(value);
        time += 1.0;
    }
    void print() {
        for (auto item: data_y) {
        }
    }
    private:
        std::vector<double> data_x;
        std::vector<double> data_y;
        double time;
};

/*
void plotter(std::vector<double> x, std::vector<double> y) {
    using namespace matplot;
	plot(x, y);
    show();
	while(true) ;

}
*/