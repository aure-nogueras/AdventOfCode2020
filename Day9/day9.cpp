#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool checkSum(const vector<int> & numbers, int n){
    bool found = false;
    for(auto i=0; i<numbers.size() && !found; i++){
        for(auto j=0; j<numbers.size() && !found; j++){
            if(i != j && numbers[i]+numbers[j] == n){
                found = true;
            }
        }
    }
    return found;
}

int findRangeSum(const vector<int> & numbers, int n){
    bool found = false;
    int i = 0, sum = 0, start = 0;
    int min = 0, max = 0;
    while(i<numbers.size() && !found){
        if(sum < n){
            sum += numbers[i];
            if(numbers[i] < min){
                min = numbers[i];
            }
            if(numbers[i] > max){
                max = numbers[i];
            }
            i++;
        }else if(sum > n){
            sum = 0;
            start++;
            i = start;
            min = numbers[start], max = 0;
        }else{
            found = true;
        }
        
    }
    return min+max;
}

int main(int argc, char * argv[]){

    string line;
    vector<int> numbers;
    vector<int> allNumbers;
    int counter = 0, n = 0;
    ifstream file ("numbers.txt");
    if(file.is_open()){
        // We put the first 25 numbers in the vector
        while(getline(file,line) && counter < 25){
            numbers.push_back(stoi(line));
            allNumbers.push_back(stoi(line));
            counter++;
        }
        n = stoi(line);
        // If we still have numbers and we are finding the sum
        while(getline(file, line) && checkSum(numbers, n)){
            for(auto i=0; i<numbers.size()-1; i++){
                numbers[i] = numbers[i+1];
            }
            numbers[numbers.size()-1] = n;
            n = stoi(line);
            allNumbers.push_back(stoi(line));
        }
        file.close();
    }else{
        cout << "No se ha podido abrir el archivo" << endl;
    }
    
    cout << "The first number that does not have the property mentioned is: " << n << endl;
    int range = findRangeSum(allNumbers, n); // 41682220
    cout << "The sum of the min and the max number in the range that sums up " << n << " is: " << range << endl;
}