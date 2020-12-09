#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// First part
bool accumulate(vector<pair<string, int > > & instructions, vector<int> count, int & acc){
    bool loop = false;
    int index = 0;
    bool end = false;
 
    while(!loop && index < instructions.size()){
        if(count[index] < 1){
            count[index]++;
            if(instructions[index].first == "jmp"){
                int i = instructions[index].second;
                index += i;
            }else if(instructions[index].first == "acc"){
                acc += instructions[index].second;
                index++;
            }else{ // no operation
                index++;
            }
        }else{
            loop = true;
        }
    }
    if(index >= instructions.size()){
        end = true;
    }
    return end;
}

// Second part
bool endLoop(vector<pair<string, int > > & instructions, vector<int> counter, int & acc){
    bool end = false;
    for(auto i=0; i<instructions.size() && !end; i++){
        if(instructions[i].first == "jmp"){
            instructions[i].first = "nop";
            acc = 0;
            end = accumulate(instructions, counter, acc);
            if(!end){
                instructions[i].first = "jmp";
            }
        }else if(instructions[i].first == "nop"){
            instructions[i].first = "jmp";
            acc = 0;
            end = accumulate(instructions, counter, acc);
            if(!end){
                instructions[i].first = "nop";
            }
        }
    }
    return end;
}

int main(int argc, char * argv[]){

    string line;
    vector<pair<string, int > > instructions;
    ifstream file ("input.txt");
    if(file.is_open()){
        while(getline(file,line)){
            instructions.push_back(pair<string, int > (line.substr(0, 3), stoi(line.substr(4))));
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }
    int acc = 0;

    vector<int> counter;
    for(int i=0; i<instructions.size(); i++){
        counter.push_back(0);
    }
    accumulate(instructions, counter, acc);
    cout << "The accumulator value is: " << acc << endl;
    
    for(int i=0; i<instructions.size(); i++){
        counter[i] = 0;
    }
   
    int ac = 0;
    bool end = endLoop(instructions, counter, ac);
    cout << "The value of the accumulator after the program terminates is: " << ac << endl;

}