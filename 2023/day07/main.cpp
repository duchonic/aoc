/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-07
 * 
 * @copyright codestation (c) 2023
 *                   _                 _             _       __
 *   ___    ___    _| |   ___    ___  | |_    _ _   | |_    (__)   ___    _ _   
 *  / _ |  / _ \  /_` |  / -_)  (_-<  |  _|  /_` |  |  _|   |  |  / _ \  | ' \ 
 *  \___|  \___/  \_,_|  \___|  /__/   \__|  \_,_|   \__|   |__|  \___/  |_||_|
 * /""""\_/""""\_/""""\_/".."\_/""""\_/""""\_/""""\_/""""\_/""""\_/""""\_/""""\
 * -0--0-=-0--0-=-0--0-=-0xx0-=-0--0-=-0--0-=-0--0-=-0--0-=-0--0-=-0--0-=-0--0-
*/

#include "help/help.h"
#include "help/math.h"
#include "help/bitwise.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/plot.h"

#include <algorithm>


std::vector<std::pair<std::string, int>> sort_cards(std::vector<std::pair<std::string, int>> &cards) {
    std::sort(cards.begin(), cards.end(), [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
		//std::array<char, 13> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
		// part 2, Joker is the lowest card
		std::array<char, 13> ranks = {'J', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'A'};
		for (int pos = 0; pos < 5; pos++) {
			auto rankA = std::find(ranks.begin(), ranks.end(), a.first.at(pos));
			auto rankB = std::find(ranks.begin(), ranks.end(), b.first.at(pos));
			if (rankA < rankB) {
				return true;
			} else if (rankA > rankB) {
				return false;
			}
		}
		return false;
	});
	return cards;
}

/**
 * @brief solves the problem
 */
static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 0;

	std::vector<std::pair<std::string, int>> fiveOfaKind;
	std::vector<std::pair<std::string, int>> fourOfaKind;
	std::vector<std::pair<std::string, int>> fullHouse;
	std::vector<std::pair<std::string, int>> treeOfaKind;
	std::vector<std::pair<std::string, int>> twoPairs;
	std::vector<std::pair<std::string, int>> onePair;
	std::vector<std::pair<std::string, int>> highCard;

	for (auto line : input) {
		std::vector<std::string> parts;
		split_str(line, ' ', parts);

		bool twoCards = false;
		bool treeCards = false;
		bool foundCard = false;

		std::pair<std::string, int> card = {parts.at(0), std::stoi(parts.at(1))};
		std::array<char, 13> ranks = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'A'};

		std::string::difference_type jokers = std::count(parts.at(0).begin(), parts.at(0).end(), 'J');
		for (auto rank : ranks) {
			std::string::difference_type n = std::count(parts.at(0).begin(), parts.at(0).end(), rank);

			if (n == 5) {
				fiveOfaKind.push_back( card ); 
				foundCard = true;
				break;
			} else if (n == 4) {
				if (jokers == 1) {
					fiveOfaKind.push_back( card ); 
				}	
				else {
					fourOfaKind.push_back( card ); 
				}
				foundCard = true;
				break;
			} else if (n == 3) {
				if (twoCards) {
					if (jokers == 2 || jokers == 3) {
						fiveOfaKind.push_back( card ); 
					}
					else {
						fullHouse.push_back( card ); 
					}
					foundCard = true;
					break;
				} else {
					treeCards = true; 
				}
			} else if (n == 2) {
				if (treeCards) {
					if (jokers == 2 || jokers == 3) {
						fiveOfaKind.push_back( card ); 
					}
					else {
						fullHouse.push_back( card ); 
					}
					foundCard = true;
					break;
				} else if (twoCards) {
					if (jokers == 1) {
						fullHouse.push_back( card );
					}
					else if (jokers == 2) {
						fourOfaKind.push_back( card );
					}
					else {
						twoPairs.push_back( card );
					}
					foundCard = true;
					break;
				} else {
					twoCards = true;
				}
			}
		}
		if (foundCard) {
			continue;
		}
		else if (twoCards) {
			if (jokers == 1) {
				treeOfaKind.push_back( card ); 
			}
			else if (jokers == 2) {
				fourOfaKind.push_back( card ); 
			}
			else if (jokers == 3) {
				fiveOfaKind.push_back( card ); 
			}
			else {
				onePair.push_back( card ); 
			}
		} else if (treeCards) {
			if (jokers == 1) {
				fourOfaKind.push_back( card ); 
			}
			else if (jokers == 2) {
				fiveOfaKind.push_back( card ); 
			}
			else {
				treeOfaKind.push_back( card ); 
			}
		} else {
			if (jokers == 1) {
				onePair.push_back( card ); 
			}
			else if (jokers == 2) {
				treeOfaKind.push_back( card ); 
			}
			else if (jokers == 3) {
				fourOfaKind.push_back( card ); 
			}
			else if (jokers == 4) {
				fiveOfaKind.push_back( card ); 
			}
			else if (jokers == 5) {
				fiveOfaKind.push_back( card ); 
			}
			else {
				highCard.push_back( card ); 
			}
		}
	}

	int rank_end = 1;
	highCard = sort_cards(highCard);
	for (auto high : highCard) {
		returnValue += high.second * rank_end++;
	}

	onePair = sort_cards(onePair);
	for (auto pair : onePair) {
		returnValue += pair.second * rank_end++;
	}

	twoPairs = sort_cards(twoPairs);
	for (auto pair : twoPairs) {
		returnValue += pair.second * rank_end++;
	}

	treeOfaKind = sort_cards(treeOfaKind);
	for (auto tree : treeOfaKind) {
		returnValue += tree.second * rank_end++;
	}

	fullHouse = sort_cards(fullHouse);
	for (auto full : fullHouse) {
		returnValue += full.second * rank_end++;
	}

	fourOfaKind = sort_cards(fourOfaKind);
	for (auto four : fourOfaKind) {
		returnValue += four.second * rank_end++;
	}

	fiveOfaKind = sort_cards(fiveOfaKind);
	for (auto five : fiveOfaKind) {
		returnValue += five.second * rank_end++;
	}

	return returnValue;	
}

int main() {
	std::vector<std::string> data = readstuff();
	std::cout << "2023 day05 solve part 1" << std::endl;
	int64_t part1 = solve(data, false);
	std::cout << "part1 : " << part1 << std::endl;
	return 0;

	std::cout << "2023 day05 solve part 2" << std::endl;
	int64_t part2 = solve(data, true);
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
