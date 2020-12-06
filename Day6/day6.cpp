#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

// Number of questions to which anyone answered yes
int countQuestions(string questions){
    set<char> total;
    for(char element: questions){
        if(element !=  ' '){
            total.insert(element);
        }
    }
    return total.size();
} 

// Number of questions to which everyone answered yes
int countAllYesQuestions(string questions){
    map <char, int> yesQuestions;
    int total = 0;
    int people = 0;
    if(questions.find(" ") != string::npos){
        for(char element: questions){
            if(element != ' '){
                if(yesQuestions.find(element) == yesQuestions.end()){
                    yesQuestions.insert(pair<char,int>(element,1));
                }else{
                    int count = yesQuestions[element];
                    yesQuestions[element] = count+1;
                }
            }else{
                people++;
            }
        }
        map<char,int>::iterator it = yesQuestions.begin();
        while(it != yesQuestions.end()){
            if((*it).second == people){
                total++;
            }
            it++;
        }
    }else{
        total = questions.length();
    }
    return total;
}

// Bool to indicate if we count the yes answered by anyone or everyone
int sumQuestions(vector<string> groupQuestions, bool everyone){
    int sum = 0;
    for(string questions: groupQuestions){
        if(!everyone){
            sum += countQuestions(questions);
        }else{
            sum += countAllYesQuestions(questions);
        }
    }
    return sum;
}

int main(int argc, char * argv[]){

    string line;
    vector<string> groupQuestions;
    int index = 0;
    int counter = 0;
    ifstream file ("questions.txt");
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
    
    groupQuestions.resize(counter+1);

    file.open("questions.txt", ifstream::in);
    
    if(file.is_open()){
        while(getline(file,line)){
           if(line.length() != 0){
               groupQuestions[index] += line + " ";
           }else{
               index++;
           }  
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }

    // Number of questions to which anyone answered yes
    cout << "La suma total de preguntas respondidas por alguien  es " << sumQuestions(groupQuestions, false) << endl;

    // Number of questions to which everyone answered yes
    cout << "La suma total de preguntas respondidas por todos es " << sumQuestions(groupQuestions, true) << endl;


}
