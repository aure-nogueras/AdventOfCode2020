// Required files for the passport
//    byr (Birth Year)
//    iyr (Issue Year)
//    eyr (Expiration Year)
//    hgt (Height)
//    hcl (Hair Color)
//    ecl (Eye Color)
//    pid (Passport ID)
//    not consider cid (Country ID)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int lengthToken(string text, int position, char separator){
    int posFinal = position + 1;
    char character = text.at(posFinal);
    while(character != separator && posFinal < text.length()-1){
        posFinal++;
        character = text.at(posFinal);
    }
    int longitud = posFinal - position;
    return longitud;
}

bool isValidBirthYear(int year){
    if(year >= 1920 && year <= 2002)
        return true;
    return false;
}

bool isValidIssueYear(int year){
    if(year >= 2010 && year <= 2020)
        return true;
    return false;
}

bool isValidExpirationYear(int year){
    if(year >= 2020 && year <= 2030)
        return true;
    return false;
}

bool isValidHeight(string height){
    int pos1 = lengthToken(height, 0, 'c');
    int pos2 = lengthToken(height, 0, 'i');
    int hgt;
    bool valid = false;
    if(pos1<pos2){
        hgt = stoi(height.substr(0,pos1));
        if(hgt>=150 && hgt<=193) 
            valid = true; 
    }else if(pos2<pos1){
        hgt = stoi(height.substr(0,pos1));
        if(hgt>=59 && hgt<=76) 
            valid = true; 
    }
    return valid;
}

bool isValidHairColor(string hcl){
    bool valid = false;
    set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f'};
    set<int> numbers = {0,1,2,3,4,5,6,7,8,9};
    if(hcl.at(0) == '#' && hcl.length() == 7){
        string sub = hcl.substr(1);
        for(char c: sub){
            int n = (int) c - 48;
            if(letters.find(c) != letters.end() || numbers.find(n) != numbers.end()){
                valid = true;
            }
        }
    }
    return valid;
}

bool isValidEyeColor(string ecl){
    set<string> colors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    bool valid= false;
    if(colors.find(ecl) != colors.end()){
        valid = true;
    }
    return valid;
}

bool isValidPid(string pid){
    set<int> numbers = {0,1,2,3,4,5,6,7,8,9};
    int counter = 0;
    bool valid = false;
    for(char element: pid){
        int n = (int) element - 48;
        if(numbers.find(n) != numbers.end()){
            counter++;
        }
    }
    if(counter == 9){
        valid = true;
    }
    return valid;
}

int numberValidPassports(vector<string> passports){
    int valids = 0;
    for(auto i=0; i<passports.size(); i++){
        if (passports[i].find("byr") != string::npos && passports[i].find("iyr") != string::npos && passports[i].find("eyr") != string::npos && passports[i].find("hgt") != string::npos && passports[i].find("hcl") != string::npos && passports[i].find("ecl") != string::npos && passports[i].find("pid") != string::npos){
            int length = lengthToken(passports[i], passports[i].find("byr")+4, ' ');
            int year = stoi(passports[i].substr(passports[i].find("byr")+4,length));
        
            length = lengthToken(passports[i], passports[i].find("iyr")+4, ' ');
            int issueYear = stoi(passports[i].substr(passports[i].find("iyr")+4,length));
            
            length = lengthToken(passports[i], passports[i].find("eyr")+4, ' ');
            int expirationYear = stoi(passports[i].substr(passports[i].find("eyr")+4,length));
           
            length = lengthToken(passports[i], passports[i].find("hgt")+4, ' ');
            string height = passports[i].substr(passports[i].find("hgt")+4,length);
            
            length = lengthToken(passports[i], passports[i].find("hcl")+4, ' ');
            string hairColor = passports[i].substr(passports[i].find("hcl")+4,length);
            
            length = lengthToken(passports[i], passports[i].find("ecl")+4, ' ');
            string eyeColor = passports[i].substr(passports[i].find("ecl")+4,length);
            
            length = lengthToken(passports[i], passports[i].find("pid")+4, ' ');
            string pid = passports[i].substr(passports[i].find("pid")+4,length);
             
            if(isValidBirthYear(year) && isValidIssueYear(issueYear) && isValidExpirationYear(expirationYear) && isValidHeight(height) && isValidHairColor(hairColor) && isValidEyeColor(eyeColor) && isValidPid(pid)){
                valids++;
            }
        }
    }
    return valids;
}

int main(int argc, char * argv[]){

    string line;
    vector<string> passports;
    int index = 0;
    int counter = 0;
    ifstream file ("passports.txt");

    if(file.is_open()){
        while(getline(file,line)){
            if(line.length() == 0){
                counter++;
            }
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }
    
    passports.resize(counter+1);

    file.open("passports.txt", ifstream::in);
    
    if(file.is_open()){
        while(getline(file,line)){
           if(line.length() != 0){
               passports[index] += line + " ";
           }else{
               index++;
           }  
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }

    int valids = numberValidPassports(passports);
    cout << "Hay " << valids << " pasaportes válidos. " << endl;
}
