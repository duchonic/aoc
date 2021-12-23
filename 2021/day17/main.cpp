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
		int x;
		int y;
		int dx;
		int dy;
		int yMax;
	Point(int xStart, int yStart, int dxStart, int dyStart) : 
				x(xStart), y(yStart), dx(dxStart), dy(dyStart) {
		yMax = 0;
	};
	~Point() {
	}
	void update() {
		x += dx;
		y += dy;
		if (dx > 0) {
			dx -= 1;
		}
		dy -= 1;
		if (y > yMax) {
			yMax = y;
		}
	}
	void showPos() {
		logger( x << '/' << y << " dx/dy " << dx  << "/" << dy );
	}
	void showYMax() {
		logger( "ymax : " << yMax) ; 
	}
};

int main() {
	std::vector<std::string> data = readFile("../test.txt");
	
	int part1 = 0;
	int part2 = 0;

	if (data.size() == 0) {
		return 1;
	}

	// target area: x=20..30, y=-10..-5
	// target area: x=70..125, y=-159..-121

	for (auto dx : range(0,1200)) {
		for (auto dy : range(-1200,1200)) {
			Point bullet = Point(0,0, dx, dy);	
			//logger("test ==== >> start dxdy : " << dx << '/' << dy);
			for (auto seconds : range(0,5000) ) {
				bullet.update();
				//bullet.showPos();	
				if (bullet.y >= -159 && bullet.y <= -121 && bullet.x <= 125 && bullet.x >= 70) {
					part2++;
					logger("in target ==== >> start dxdy : " << dx << '/' << dy);
					bullet.showPos();
					bullet.showYMax();
					if (part1 < bullet.yMax) {
						part1 = bullet.yMax;
					}
					break;
				}
				else if ( bullet.y < -159 || bullet.x > 125 ) {
					break;
				}
			}	
		}
	}	



	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
