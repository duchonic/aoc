#include <iostream>
#include <string>
#include <cassert>
#include <vector>


struct stats{
  int hitPoints;
  int damage;
  int armor;
  int costSpent;
};

struct item{
  int cost;
  int damage;
  int armor;
};

stats startStats(void){
  return {100,8,2,0};
}

/**
Weapons:    Cost  Damage  Armor
Dagger        8     4       0 +8     -> 2
Shortsword   10     5       0 +2     -> 2
Warhammer    25     6       0 +15    -> 4.1666
Longsword    40     7       0 +15    -> 5.714
Greataxe     74     8       0 +34    -> 9.25

Rings:      Cost  Damage  Armor
left hand
Damage +1    25     1       0 +25    -> 25
Damage +2    50     2       0 +25    -> 25
Damage +3   100     3       0 +50    -> 33.333

Armor:      Cost  Damage  Armor
Leather      13     0       1 +13	 -> 13
Chainmail    31     0       2 +18	 -> 15.5
Splintmail   53     0       3 +22 	 -> 17.666
Bandedmail   75     0       4 +22    -> 18.75
Platemail   102     0       5 +27	 -> 20.4

Rings:      Cost  Damage  Armor
right hand
Defense +1   20     0       1 +25    -> 20
Defense +2   40     0       2 +20	 -> 20
Defense +3   80     0       3 +40    -> 26.666



*/
item getStat(std::string name){
  if(name == "Dagger")
    return {8,4,0};
  else if(name == "Shortsword")
    return {10,5,0};
  else if(name == "Warhammer")
    return {25,6,0};
  else if(name == "Longsword")
    return {40,7,0};
  else if(name == "Greataxe")
    return {74,8,0};
  else if(name == std::string("Leather"))
    return {13,0,1};
  else if(name == std::string("Chainmail"))
    return {31,0,2};
  else if(name == std::string("Splintmail"))
    return {53,0,3};
  else if(name == std::string("Bandedmail"))
    return {75,0,4};
  else if(name == std::string("Platemail"))
    return {102,0,5};
  else if(name == "Damage1")
    return {25,1,0};
  else if(name == "Damage2")
    return {50,2,0};
  else if(name == "Damage3")
    return {100,3,0};
  else if(name == "Defense1")
    return {20,0,1};
  else if(name == "Defense2")
    return {40,0,2};
  else if(name == "Defense3")
    return {80,0,3};
  else
    assert(0);
}

void printStat(stats p){
	std::cout << "hitPoints: " << p.hitPoints << " damage: " << p.damage <<
				 " armor: " << p.armor << " spent: " << p.costSpent << std::endl;
}

void doBattle(std::vector<std::string> stuff){
	stats enemyStats = startStats();
    stats playerStats = {100,0,0,0};

	int round = 1;
	while((playerStats.hitPoints > 0) && (enemyStats.hitPoints > 0)){
		std::cout << "round: " << round++ << std::endl;

		if(stuff.size()){
			std::string itemString = stuff.back();
			stuff.pop_back();
			std::cout << "buyd item: " << itemString << std::endl;
			item act = getStat(itemString);
			playerStats.costSpent += act.cost;
			playerStats.damage += act.damage;
			playerStats.armor += act.armor;
		}

		std::cout << "enemyStats";
		printStat(enemyStats);
		std::cout << "playerStats";
		printStat(playerStats);

		int damage = playerStats.damage - enemyStats.armor;
		if(damage <= 0){
			damage = 1;
		}
		enemyStats.hitPoints -= damage;
		if(enemyStats.hitPoints <= 0){
			std::cout << "enemy looses" << std::endl;
			std::cout << "cost for win: " << playerStats.costSpent << std::endl;
			break;
		}

		damage = enemyStats.damage - playerStats.armor;
		if(damage <= 0){
			damage = 1;
		}
		playerStats.hitPoints -= damage;
		if(playerStats.hitPoints <= 0){
			std::cout << "player looses" << std::endl;
			break;
		}
	}
	std::cout << "enemyStats";
	printStat(enemyStats);
	std::cout << "playerStats";
	printStat(playerStats);
}

int main(){
	std::cout << "hello day 21 of 2015" << std::endl;

	std::vector<std::string> stuff;

	stuff.push_back("Damage3");     // ring left
	stuff.push_back("Defense3"); 	// ring right
	//stuff.push_back("Chainmail");  	// armor not mandatory
	stuff.push_back("Dagger"); 		// weapon

	doBattle(stuff);

	return 0;
}

/**

part 1
114 too high
105 too high

93 not the right answer
91 is correct ->

part2
145 to low
170 not correct
188 too high

*/
