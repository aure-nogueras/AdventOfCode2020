#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

void readInput(map<string, vector<string> > & luggages, string line){
    int i = 0, espacios = 0;
    string luggage1, key;
    int punto = 0;
    bool first = true;
    vector<string> contained;
    while(punto == 0){
        while(espacios < 2){
            if(line[i] == ' '){
                espacios++;
            }
            luggage1 += line[i];
            i++;
        }
        if(luggage1 != "" && !first){
            luggages.at(key).push_back(luggage1);
        }
        if(first){
            i += 14;
            first = false;
            espacios = 0;
            key = luggage1;
            luggages.insert(pair<string, vector<string> >(luggage1, contained));
        }
        luggage1 = "";
        if(line[i] == ','){
            espacios = 0;
            i += 3;
        }else if(line[i] == '.'){
            punto = 1;
        }
        i++;
    }
}

// We assume numbers with one cipher
void readInputNumber(map<string, map<string, int> > & luggages, string line){
    int i = 0, espacios = 0;
    string luggage1, key;
    int punto = 0;
    int number = 0;
    bool first = true;
    map<string, int> contained;
    while(punto == 0){
        if(!first && espacios == 0){
            if(line[i] != 'n'){
                number = int(line[i])-48;
                i+=2;
            }else{
                number = 0;
            }
        }
        while(espacios < 2){
            if(line[i] == ' '){
                espacios++;
            }
            luggage1 += line[i];
            i++;
        }
        if(luggage1 != "" && !first){
            luggages.at(key).insert(pair<string, int> (luggage1,number));
        }
        if(first){
            i += 12;
            first = false;
            espacios = 0;
            key = luggage1;
            luggages.insert(pair<string, map<string, int> >(luggage1, contained));
        }
        
        luggage1 = "";
        if(line[i] == ','){
            espacios = 0;
            i++;
        }else if(line[i] == '.'){
            punto = 1;
        }
        i++;
    }
}

int countContainers(string bag, map<string, vector<string> > & luggages, set<string> & added){
    map<string, vector<string> >::iterator it;
    int counter = 0;
    it = luggages.begin();
    
    while(it != luggages.end()){
        for(string b: (*it).second){
            if(b == bag && added.find((*it).first) == added.end()){
                added.insert((*it).first);
                countContainers((*it).first, luggages, added);
            }
        }
        it++;
    }
    return added.size();
}

int countContained(string bag, map<string, map<string, int> > & luggages){
    map<string, map<string, int> >::iterator it;
    int counter = 0;
    it = luggages.begin();
    
    while(it != luggages.end()){
        if((*it).first == bag){
            for(pair<string, int> b: (*it).second){
                if(b.second > 1){
                    counter +=  b.second + b.second*countContained(b.first, luggages);
                }else{
                    if(b.second == 1){
                        counter += b.second + countContained(b.first, luggages);
                    }
                }
            }
        }
        it++;
    }
    return counter;
}


int main(int argc, char * argv[]){

    string line;
    map<string, vector<string> > luggages;
    map<string, map<string, int> > luggagesNumber;
    ifstream file ("luggage.txt");
    if(file.is_open()){
        while(getline(file,line)){
            readInput(luggages, line);
            readInputNumber(luggagesNumber, line);
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }

    set<string> added;
    cout << "The number of bags that can contain shiny gold bags are: " << countContainers("shiny gold ", luggages, added) << endl;
    cout << "The number of bugs contained in a shiny gold are: " << countContained("shiny gold ", luggagesNumber) << endl; 
   
    
}