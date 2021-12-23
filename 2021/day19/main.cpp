#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/string.h"
#include <cstdlib>
#include <map>


class Point{
public:
	Point(int xStart, int yStart, int zStart): x(xStart), y(yStart), z(zStart) {
	};
	~Point() {

	};
	int x;
	int y; 
	int z;
	void show() {
		logger(x << '/' << y << '/' << z);
	}
	double distanceTo(Point p) {
		int xdiff = abs(p.x-x);
		int ydiff = abs(p.y-y);
		int zdiff = abs(p.z-z);
		return (sqrt(xdiff*xdiff + ydiff*ydiff + zdiff*zdiff));
		
	}
	double distance() {
		return (sqrt(x*x + y*y + z*z));
	}
};

int main() {
	std::vector<std::string> data = readFile("../test.txt");

	int part1 = 0;
	int part2 = 0;

	if (data.size() == 0) {
		return 1;
	}

	std::vector<std::vector<Point>> sonars;
	int scannerNr = -1;
	for (auto line : data) {
		std::vector<std::string> items;
		if (find(line, "---")) {
			scannerNr++;
			logger("new scannerNr:" << scannerNr);
			std::vector<Point> p{};
			sonars.push_back(p);		
		}
		else if (find(line, "," )) {
			split_str(line, ',', items);

			Point p{ stoi(items.at(0)), stoi(items.at(1)), stoi(items.at(2))};
			sonars.at(scannerNr).push_back(p);	
		}
	}

	for (auto sonar : sonars) {
		logger(" new sonar ");
		Point position{0,0,0};
		std::vector<double> distance;
		for (Point scans : sonar) {
			//scans.show();
			distance.push_back(scans.distanceTo(position));
			//logger("distance:" << scans.distanceTo(position));
			position = scans;	
		}
		std::sort(distance.begin(), distance.end());
		for (double dis : distance  ) {
			logger(dis);
		}
	}


	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
