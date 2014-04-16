#include <stdlib.h> // exit, EXIT_FAILURE
#include <string.h> // string
#include <iostream> // cout
#include <vector>   //vectors
#include <cstdio>
#include <ctime>    // Timer
#include <fstream>  //file io

//#define DEBUG 0

using namespace std;

void printFile(unsigned int num, vector<bool>& primes) {
    ofstream ofile;
    ofile.open ("list_of_primes.txt");
    if (ofile.is_open()) {
        cout << "File is open!\n";
        int counter = 0;
        for (int x = 1; x < num; x++) {
            if (primes.at(x)) {
                ofile << x << "\t";
                counter++;
                if ((counter%10) == 0)
                    ofile << "\n";
            }
        }
    } else cout << "Unable to open file...";
    ofile << endl;
    cout << endl;
    ofile.close();
}

void printSTDOUT(unsigned int num, vector<bool>& primes) {
    int counter = 0;
    for (int x = 1; x < num; x++) {
        if (primes.at(x)) {
            cout << x << "\t";
            counter++;
            if ((counter%10) == 0)
                cout << "\n";
        }
    }
    cout << endl;
}

void calcPrimes(unsigned int num) {
    cout << "Setting up...\n";
    vector<bool> primes(num,true);
    cout << "num: " << num << endl;
    unsigned int numPrimes = num - 2;
    primes.at(1) = false; // 1 is not prime
    cout << "numPrimes: " << numPrimes << endl;
    clock_t start;
    double duration;

    start = clock();

    cout << "Calculating primes...\n";
    for (unsigned int i = 2; i < num; i++) {
        for (unsigned int j = i; j <= (num/i); j++) {
            if ((i*j) < num) {
                if (primes.at(i*j) == true)
                    numPrimes--;
                primes.at(i*j) = false;
#ifdef DEBUG
                cout << "i*j=" << i*j << "\tnumPrimes=" << numPrimes << "\t primes.at(" << i*j << ")=" << primes.at(i*j) << endl;
#endif
            }
        }
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"time: "<< duration <<'\n';
    unsigned int answer;
    cout << "Finished!\n";
    cout << "Prime numbers: " << numPrimes << "\n";
    cout << "Do you want to print the list to a text file?\n";
    cout << "2) Print to file\n";
    cout << "1) print to screen\n";
    cout << "0) Do not print\n";
    cout << "Option: ";
    cin >> answer;
    if (answer == 2) {
        printFile(num, primes);
    } else if (answer == 1) {
        printSTDOUT(num, primes);
    } else if (answer == 0) {
        cout << "Not printing list\n\n";
    } else {
        cout << "Invalid answer... Not printing list\n\n";
    }
}


int main(int argc, char* argv[]) {
    unsigned int num = 0;
    while (true) {
        cout << "Enter the max number (0 to quit): ";
        cin >> num;
        if (num == 0) {
            break;
        } else {
            calcPrimes(num);
        }
    }
    return 0;
}