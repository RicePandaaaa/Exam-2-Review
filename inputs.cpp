#include <iostream>  
#include <fstream>   // For file streams
#include <sstream>   // For string streams

using std::cout, std::string, std::endl;


int main() {
    // Input file stream
    const string FILENAME = "inputs.txt";
    std::ifstream fin(FILENAME);

    // Check for valid file
    if (!fin.is_open()) {
        cout << "Invalid file name." << endl;
        return 0;
    }

    // Get number of lines
    int lines = 0;
    fin >> lines;
    // Input validation
    if (fin.fail()) {
        cout << "Invalid number of lines" << endl;
        return 0;
    }

    // IMPORTANT IF SWITCHING FROM >> to getline
    // MUST GRAB EXTRA ESCAPE SEQUENCE
    string line = " ";
    getline(fin, line);

    // Grab lines
    for (int i = 0; i < lines; ++i) {
        // String stream cus why not
        getline(fin, line);
        std::istringstream sin(line);
        string word;
        sin >> word;

        // Go until there's nothing left
        while (!sin.fail()) {
            cout << "| " << word << " |" << endl;
            sin >> word;
        }
    }

    // Close the stream
    fin.close();
}

