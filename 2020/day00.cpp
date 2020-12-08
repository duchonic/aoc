#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <set>

struct Person{
	char name;
	std::set<Person> child;
};

inline bool operator<(const Person& p1, const Person& p2){
  return p1.name < p2.name;
}

void show(Person p){
	std::cout << p.name << std::endl;
	if(p.child.size()){
		for(Person child: p.child){
			std::cout << " - ";
			show(child);
		}
	}
}

int main(){
	std::ifstream inputFile("day00.txt");        // Input file stream object

	if (inputFile.good()) {

		std::set<Person> family;
		char name, childname;
		while(inputFile >> name >> childname){
			//std::cout << name << ' ' << childname << std::endl;
			Person actual;
			Person child;
			actual.name = name;
			child.name = childname;
			actual.child.insert(child);

			for(Person person : family){
				for(Person child: person.child){
					if (child.name == name){
						std::cout << "found a child" << std::endl;
						child.child.insert(actual);
					}
				}
			}
			family.insert(actual);
		}


		for(Person p : family){
			show(p);
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}


	return 0;
}

