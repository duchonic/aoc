#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <set>

struct Person{
	char name;
	std::vector<Person> child;
};

inline bool operator<(const Person& p1, const Person& p2){
  return p1.name < p2.name;
}

void show(Person p, int childs){
	std::cout << p.name << std::endl;
	if(p.child.size()){
		for(Person child: p.child){
			for(int spaces=0;spaces<childs;spaces++){
				std::cout << ' ';
			}
			show(child, childs+1);
		}
	}
}

void checkParents(Person &parent, Person child){
	std::cout << "check : " << parent.name << std::endl;
	if(parent.child.size()){
		// has some childrens ... 
		for(Person &childrenName : parent.child){
			// search the childrens ...
			if( childrenName.name == child.name ){
				std::cout << "parent found : " << childrenName.name << std::endl;	
				std::cout << "check children of : " << childrenName.name << std::endl; 
				//check childs of found parent
				bool notAChild = true;
				for(auto check : childrenName.child){
					std::cout << "check " << check.name << " == " << childrenName.name << std::endl;
					if(check.  == childrenName.name){
						std::cout << "already a child" << std::endl;
						notAChild = false;
					}
				}
				if(notAChild){
					Person newChild;
					newChild.name = child.child.at(0).name;
					childrenName.child.push_back(newChild);

					break;
				}
			}
			checkParents(childrenName, child);
		}

	}
	
}


int main(){
	std::ifstream inputFile("day00.txt");        // Input file stream object
	if (inputFile.good()) {

		Person genesis;

		genesis.name = 'x';

		char name, childname;
		while(inputFile >> name >> childname){
			Person actual;
			Person child;
			actual.name = name;
			child.name = childname;
			actual.child.push_back(child);

			std::cout << "got entry:" << std::endl;
			show(actual, 1);

			genesis.child.push_back(actual);

			checkParents(genesis, actual);

			std::cout << "show genesis" << std::endl;
			show(genesis, 1);
		}


		
	}
	else{
		std::cout << "file not found" << std::endl;
	}




	std::cout << "some stuff to test:::" << std::endl;

	Person genesis;
	genesis.name = 'a';
	
	Person child_b;
	child_b.name = 'b';
	Person child_c;
	child_c.name = 'c';


	Person grandchild;
	grandchild.name = 'c';
	child_b.child.push_back(grandchild);
	child_c.child.push_back(grandchild);
	genesis.child.push_back(child_b);
	genesis.child.push_back(child_c);

	
	show(genesis, 1);

	std::cout << "genesis childs" << std::endl;
	for(auto child : genesis.child){
		std::cout << child.name << std::endl;
	}


	return 0;

}

