#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getLines(string file_name) {
    ifstream input_file(file_name);
    vector<string> lines;

    if (!input_file.is_open())
      return lines;

    string line;    
    while (getline(input_file, line)){
        lines.push_back(line);
    }

    return lines;
}

int computeCountOfAscendingDepths(string file_name){
    auto lines = getLines(file_name);
    int increasing_count = 0;
    for (auto count = 0; count < lines.size(); count++) {
       if (count == 0)
        continue;

       if (stoi(lines[count]) > stoi(lines[count - 1])) 
          increasing_count++;  
    }

    return increasing_count;
}

int main ()
{
 cout << "Hello World" << endl;
 cout << computeCountOfAscendingDepths("input.txt") << endl;
}