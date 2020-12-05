#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// We assume the strings are correct
int decodeSeatID(string seat){
    int min = 0;
    int max = 127;
    int row, col;
    for(auto i=0; i<seat.length(); i++){
        int subtract = (max-min)/2;
        if((max-min) % 2 != 0)
            subtract += 1;
        if(seat[i] == 'F' || seat[i] == 'L'){
            max = max - subtract;
        }else{
            min = min + subtract;
        }
        if(i == 6){
            row = min;
            min = 0;
            max = 7;
        }
    }
    col = min;
    return row*8+col;
}

// Find the seat with the higher ID
int biggerSeatID(vector<string> boardings){
    int max = 0;
    int prov = 0;
    for(auto i=0; i<boardings.size(); i++){
        prov = decodeSeatID(boardings[i]);
        if(prov > max){
            max = prov;
        }
    }
    return max;
}

// Find our seat
int missingSeatID(vector<string> boardings){
    set<int> seats;
    for(auto i=0; i<boardings.size(); i++){
        int number = decodeSeatID(boardings[i]);
        seats.insert(number);
    }

    bool found = false;
    set<int>::iterator it = seats.begin();
    int number = -1;
    int prev = -1;
    it++;
    while(!found &&  it != seats.end()){
        if(prev != -1 && (*it-prev) != 1){
            number = *it - 1;
            found = true;
        }
        prev = *it;
        it++;
    }
    return number;
}


int main(int argc, char * argv[]){

    string line;
    vector<string> boardings;
    int index = 0;
   
    ifstream file ("boardings.txt");

    if(file.is_open()){
        while(getline(file,line)){
            boardings.push_back(line);
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }

    cout << "El máximo ID entre los billetes es " << biggerSeatID(boardings) << endl;
    cout << "Nuestro asiento es el " << missingSeatID(boardings) << endl;
    
}
