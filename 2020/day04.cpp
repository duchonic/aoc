#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string_view>

#include <vector>

int main(){
	std::vector<std::string> numbers;
	std::ifstream inputFile("day04.txt");        // Input file stream object

	int validPassport = 0;

	if (inputFile.good()) {

		int validEntries = 0;
		for (std::string line; std::getline(inputFile, line); ) {

			std::stringstream ss(line);
			std::string token;

			if(line.size()){
				while (std::getline(ss, token, ' ')) {

					std::string key = token.substr(0,3);
					std::string value = token.substr(4, token.length()-4);



					for(auto keyCheck: {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}){
						//std::cout << key << " " << keyCheck << std::endl;
						if(key == keyCheck) {

							if(key == "byr"){
								if (std::stoi(value) >= 1920 && std::stoi(value) <= 2002){
									validEntries++;
									//std::cout << "valid: " << key << ':' << value << std::endl;
								}
								else{
									//std::cout << "NOT VALID: " << key << ':' << value << std::endl;
								}
							}
							else if(key == "iyr"){
								if(std::stoi(value) >= 2010 && std::stoi(value) <=2020){
									validEntries++;
									//std::cout << "valid: " << key << ':' << value << std::endl;
								}
								else{
									//std::cout << "NOT VALID: " << key << ':' << value << std::endl;
								}

							}
							else if(key == "eyr"){
								if( std::stoi(value) >= 2020 && std::stoi(value) <= 2030 ){
									validEntries++;
									//std::cout << "valid: " << key << ':' << value << std::endl;
								}
								else{
									std::cout << "NOT VALID: " << key << ':' << value << std::endl;
								}
							}
							else if(key == "hgt"){
								std::stringstream height(value);
								int size;

								std::string len;
								height >> size >> len;
								if(len == "cm"){
									if( size >= 150 && size <= 193 ){
										validEntries++;
										//std::cout << "valid: " << key <<':' << size << " " << len << std::endl;
									}
									else{
										//std::cout << "NOT VALID: " << key << ':' << value << std::endl;
									}
								}
								else if(len == "in"){
									if( size >= 59 && size <= 76 ){
										validEntries++;
										//std::cout << "valid: " << key << ':' << size << " " << len << std::endl;
									}
									else{
										//std::cout << "NOT VALID: " << key << ':' << value << std::endl;
									}
								}
							}
							else if(key == "hcl"){
								std::stringstream haircolor(value);
								char c;
							    long hexval;
								haircolor >> c >> std::hex >> hexval;
								if(c=='#' && hexval > 0x0fffff && hexval <= 0xffffff){
									//std::cout << "valid: " << key << ':' << value << std::endl;
									validEntries++;
								}
								else{
									//std::cout << "NOT VALID: " << key << ':' << value << std::endl;
								}
							}
							else if(key == "ecl"){
								bool check = false;
								for(auto color : {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"}){
									if(value == color){
										check = true;
										break;
									}
								}
								if(check){
										//std::cout << "valid: " << key << ':' << value << std::endl;
										validEntries++;
								}
								else{
									//std::cout << "NOT VALID: " << key << ':' << value << std::endl;
								}
							}
							else if(key == "pid"){
								std::stringstream pid(value);

								if(value.size()==9){
									bool check = true;
									for(char c : value){
										if( c < '0' || c > '9'){
											std::cout << "===============>>>>  c:" << c << ' ';
											check = false;

										}
									}
									if(check){
										//std::cout << "valid: " << key << ':' <<  value << std::endl;
										validEntries++;
									}
									else{
										//std::cout << "NOT VALID: " << key << ':' << value << std::endl;
									}
								}
							}

						}
					}
				}
			}
			else{
				//std::cout << "old passport valid entries: " << validEntries << std::endl;
				if(validEntries==7){
					validPassport++;
					//std::cout << ">>>>>>>>> VALID PASSPORT >>> newpassport:" << std::endl << std::endl;
				}
				else{
					//std::cout << line << std::endl;
					//std::cout << std::endl;
				}
				validEntries = 0;
			}
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	for(auto val:numbers){
		std::cout << val << std::endl;
	}

	std::cout << std::endl;
	std::cout << "part1: valid passports: " << validPassport << std::endl;

	std::cout << "part2:" << std::endl;
	return 0;
}

/**
 *
 *  190 to hgih
 *  199
 *  188 is the solution ¨?
 *  187 no ok
 *  186 no ok
 *  185 to low
 *
 */