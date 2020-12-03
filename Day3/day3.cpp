#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int countTrees(string ** trees, int rows, int columns, int right, int down){
    int i = 0;
    int j = 0;
    int numberTrees = 0;
    do {
        if (trees[i][j] == "#"){
            numberTrees++;
        }
        i += down;
        j += right;
        j = j%columns;
    } while(i < rows && j < columns);
    return numberTrees;
}

int main(int argc, char * argv[]){
    string **trees;

    string line;
    int counter = 0;
    ifstream file ("trees.txt");
    if(file.is_open()){
        while(getline(file,line)){
           counter++; 
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }

    cout << "Hay " << counter-1 << " líneas." << endl;
    int rows = counter-1;
    trees = new string*[rows];
    counter = 0;
    file.open("trees.txt", ifstream::in);
    int columns = 0;
    if(file.is_open()){
        while(getline(file,line)){
            if(line.length() > 0){
                columns = line.length();
                trees[counter] = new string[line.length()];
                for(auto i=0; i<line.length(); i++){
                    trees[counter][i] = line[i];
                }
            }
            counter++;
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    } 

    // Contar árboles
    int numberTreesOne = countTrees(trees, rows, columns, 1, 1);
    int numberTreesTwo = countTrees(trees, rows, columns, 3, 1);
    int numberTreesThree = countTrees(trees, rows, columns, 5, 1);
    int numberTreesFour = countTrees(trees, rows, columns, 7, 1);
    int numberTreesFive = countTrees(trees, rows, columns, 1, 2);

    cout << "El número de árboles encontrados en el trayecto es " << numberTreesOne << " " << numberTreesTwo << " " << numberTreesThree << " " << numberTreesFour << " " << numberTreesFive << endl;

    unsigned int multiplicationTrees = numberTreesOne*numberTreesTwo*numberTreesThree*numberTreesFour*numberTreesFive;
    cout << "La multiplicación da: " << multiplicationTrees << endl;

    // Liberar memoria
    for(auto i=0; i<rows; i++){
        delete [] trees[i];
    }
    delete [] trees;
}