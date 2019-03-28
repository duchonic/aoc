#include <iostream>
#include <fstream>
#include <map>
#include <set>

int main(){

  std::ifstream myfile ("day19.data");
  std::multimap<std::string, std::string> combis;
  std::set<std::string> newMolekus;

  if (myfile.is_open()){
    std::string line;
    while (getline(myfile,line)){
      if(line.size() > 0){
        //std::cout << "combis: " << line << '\n';
        std::string key = line.substr(0,line.find(' '));
        std::string value = line.substr(line.find(' '),-1);
        value.replace(0, 4, "");
        combis.insert(std::pair<std::string, std::string> (key, value));
      }
      else{
        break;
      }
    }

    std::string orginalMolekuel("");
    while (getline(myfile, line)){
      std::cout << "molekule: " << line << '\n';
      orginalMolekuel += line;
    }
    std::cout << orginalMolekuel << '\n';

    for (auto x: combis){
      std::cout << x.first << " => " << x.second << '\n';
      newMolekus.insert(orginalMolekuel+x.first+x.second);
    }
    for (auto x: newMolekus){
      std::cout << x << '\n';
    }
  }
}
