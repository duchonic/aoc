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

class Cave {
	private:
		int size;
	public:
		Cave(int s, std::string n): size(s), name(n) {
		}
		~Cave() {
		}

		std::vector<std::string> neighbours;
		std::string name;
		void show() {
			//std::cout << name << ':' << size << std::endl;
		}
		void add(std::string next) {
			neighbours.push_back(next);
		}
		int count(void) {
			return (neighbours.size());
		}
};


int main() {
	std::vector<std::string> data = readstuff();

	std::vector<Cave> map{Cave(0, "start"), Cave(0, "end")};

	for (auto line : data) {
		std::vector<std::string> caves;
		split_str(line, '-', caves);
		//logger("from " << caves.at(0) << " to " << caves.at(1));		
		std::string name = caves.at(0);
		std::string destination = caves.at(1);
		
		
        auto result = std::find_if( map.begin(), map.end(), [name](Cave obj){
            return obj.name == name;
        });
        if (result != map.end()) {
            result->show();
            result->add(destination);
        }
        else {
            //logger("not found, add node " << name);
		    Cave n(1, name);
            n.add(destination);
		    map.push_back(n);
        }
	}


    for (Cave c : map) {
        logger(c.name);
		for (std::string neighbour : c.neighbours) {
			logger("  " << neighbour);
		}
    }
	for ( auto run : range(1,100) ) {
		std::vector<std::string> path{"start"};
		while (true) {
			try {
				auto result = std::find_if( map.begin(), map.end(), [path](Cave obj){
					return obj.name == path.back();
				});
				if (result != map.end()) {
					logger(result->name << " to " << result->neighbours.at(0))
					path.push_back( result->neighbours.at( rand()%4 ) );
				}
				else {
					//if (path.back() == "end") {
						for (auto c : path) {
							std::cout << c << ' ';
						}
						std::cout << std::endl;
					//}
					break;
				}
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << "blub" << '\n';
				break;
			}
		}
	}

	int part1 = 0x81;
	
	std::cout << "part1 : " << part1 << std::endl;

	return 0;
}
