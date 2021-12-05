/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
    */

#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/string.h"


std::vector< std::array< std::array<int, 6> , 6>> cards;
std::vector<std::string> sequence;

static void printCards() {
	for (auto card : cards){
		logger("cards:")
		for (auto line : card) {
			for (auto nr : line) {
				std::cout << nr << ' '; 
			}
			std::cout << std::endl;
		}
	}
}

static void checkCards() {
	for (auto check : sequence) {
		logger(" ");
		logger("check for: " << check);
		int cardNumber = -1;
		std::vector<int> eraseCard;
		for (auto card : cards){
			cardNumber++;
			int lineNumber = -1;
			//for (auto line : card) {
			for (int line=0; line<5; line++) {
				lineNumber++;
				int match = 0;
				//int actualNumber = 0;
				//for (auto nr : line) {
				for (int actualNumber = 0; actualNumber < 5; actualNumber++) {
					//actualNumber++;
					if (stoi(check) == cards.at(cardNumber).at(lineNumber).at(actualNumber) ) {
						cards.at(cardNumber).at(lineNumber).at(actualNumber) = -1;
						cards.at(cardNumber).at(lineNumber).at(5)++;
						cards.at(cardNumber).at(5).at(actualNumber)++;
						if (cards.at(cardNumber).at(lineNumber).at(5) == 5 ||
							cards.at(cardNumber).at(5).at(actualNumber) == 5 ) {
							eraseCard.push_back(cardNumber);
							int sum = 0;
							//for (auto line : cards.at(cardNumber)) {
							for (int y=0; y<5; y++) {
								for (int index=0; index<5; index++){
									if ( cards.at(cardNumber).at(y).at(index) != -1 ) {
										sum += cards.at(cardNumber).at(y).at(index);
									}
								}
							}
							logger( "found it, actual check:" << check);
							logger( "sum : " << sum);
							logger( stoi(check) * sum );
						}
					}
				}
			}
		}

		auto iterator = std::remove_if(cards.begin(), cards.end(), [](std::array< std::array<int,6>,6> card){
			for ( auto nr : card.at(5)) {
				if (nr >= 5) {
					return true;
				}
			}
			
			for ( auto line : card) {
				if (line.at(5) >= 5) {
					return true;
				}
			}
			return false;
		} );
		cards.erase(iterator, cards.end());
		if (cards.size() == 0) {
			return;
		}	
	}	
}

int main() {
	std::vector<std::string> data = readstuff();

	split_str(data.front(), ',', sequence);
	logger("sequence:");
	for (auto nr : sequence) {
		std::cout << nr << ' ';
	}
	std::cout << std::endl;

	int actualCard = -1;
	for (int line=2; line < data.size(); line+= 6) {
		std::array<std::array<int, 6>,6> empty;
		cards.push_back(empty);
		actualCard++;	
		for (int y=0; y<5; y++) {
			std::stringstream ss(data.at(line+y));
			cards.at(actualCard).at(y).at(5) = 0;
			for (int count=0; count < 5; count++) {
				int number;
				ss >> number;
				cards.at(actualCard).at(y).at(count) = number;
				cards.at(actualCard).at(5).at(count) = 0;
			}
		}
	}

	//printCards();
	checkCards();

	int16_t part1 = 0;
	int16_t part2 = 0;

	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;

	return 0;
}
