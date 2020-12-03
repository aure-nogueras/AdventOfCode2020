#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool correctPassword(int min, int max, char letter, string password){
    int count = 0;
    bool correct = false;
    for(auto i=0; i<password.size(); i++){
        if(password[i] == letter){
            count++;
        }
    }
    if(count >= min && count <= max){
        correct = true;
    }
    return correct;
}

bool correctPassword2(int pos1, int pos2, char letter, string password){
    int count = 0;
    bool correct = false;
    if (password[pos1-1] == letter){
        if (password[pos2-1] != letter){
            correct = true;
        }
    }
    if (password[pos2-1] == letter){
        if (password[pos1-1] != letter){
            correct = true;
        }
    }
    return correct;
}

int main(int argc, char * argv[]){
    vector<string> passwords;

    string line;
    ifstream file ("passwords.txt");
    if(file.is_open()){
        while(getline(file,line)){
            passwords.push_back(line);
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }

    int min = -1;
    int max = -1;
    char letter;
    int index;
    int counter = 0;
    string pass, iteration, prueba;
    for(auto i=0; i<passwords.size(); i++){
        index = 0;
        iteration = passwords[i];
        prueba = "";
        pass = "";
        while(iteration[index] != '-'){
            prueba += iteration[index];
            index++;
        }
        min = stoi(prueba);
        prueba = "";
        index++;
        while(iteration[index] != ' '){
            prueba += iteration[index];
            index++;
        }
        max = stoi(prueba);
        index++;
        letter = iteration[index];
        index += 3;       
        while (index < iteration.size()){
            pass += iteration[index];
            index++;
        }
        if (correctPassword2(min, max, letter, pass) == 1)
            counter++; 
    }

    cout << "Las contraseñas correctas son: " << counter << endl;

}