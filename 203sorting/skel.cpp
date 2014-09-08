#include <iostream>
#include <ctime>

#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include "binaryTree.h"
#include "treeNode.h"

#define delimeter ' ';

using namespace std;

void get_max_words(ifstream& fin, int& wordlen, int& numwords);
int cmp(const void* a, const void* b);
int tcmp(const void* a, const void* b);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "usage: " << argv[0]
                << " infile outfile timesfile ntests" << endl;
        exit(EXIT_FAILURE);
    }
    /*
            deal with commandline args
            do any preprocessing (max 1 pass over file, space O(1))
            read words into initial array (1 pass over file)
     */
    int ntests = 5;//atoi(argv[4]);
    ifstream fin;
    fin.open(argv[1]);

    if (fin) {
        stringstream buffer("", ios_base::ate | ios_base::in | ios_base::out);
        string word;
        unsigned int wordCount = 0;
        unsigned int maxWordLength = 0;
        string maxWord = "";
        binaryTree* radixBins;

        while (fin >> word) {
            wordCount++;

            if (word.size() > maxWordLength) {
                maxWordLength = word.size();
                maxWord = word;
            }
            buffer << word << delimeter;
        }

        fin.close();

        string* tempArray = new string[wordCount];
        unsigned int index = 0;
        while (buffer >> word) {
            tempArray[index] = word;
            index++;
        }

        buffer.str(string());
        buffer.clear();

        /*
                At this point, everything should be in the initial array
                A temporary data structure should be declared but not filled
         */

        /*set up the timer*/
        clockid_t cpu;
        timespec start, end;
        long* times = new long[ntests];
        if (clock_getcpuclockid(0, &cpu) != 0) {
            cerr << "Error: could not get cpu clock" << endl;
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < ntests; i++) {
            
            radixBins = new binaryTree[maxWordLength];
            
            /*start the timer*/
            if (clock_gettime(cpu, &start) == -1) {
                cerr << "Error: could not get start time" << endl;
                exit(EXIT_FAILURE);
            }

            /*copy from initial array to temporary data structure*/
            /*sort data in temporary structure*/

            for (index = 0; index < wordCount; index++) {
                radixBins[tempArray[index].size() - 1].insert(tempArray[index]);
            }

            /*stop timer*/
            if (clock_gettime(cpu, &end) == -1) {
                cerr << "Error: could not get end time" << endl;
                exit(EXIT_FAILURE);
            }
            
            if (i < ntests-1){
                delete [] radixBins;
            }
            
            /*time per test in nanoseconds*/
            times[i] = (end.tv_sec - start.tv_sec)*1000000000 +
                    end.tv_nsec - start.tv_nsec;
        }
        /*output sorted temporary array*/
        /*sort times array and output it*/

        for (index = 0; index < maxWordLength; index++) {
            radixBins[index].out(buffer);
        }

        ofstream fout;
        fout.open("temp.txt");
        index = 0;
        while (buffer >> word) {
            fout << word;
            index++;
            if (index == 10) {
                fout << endl;
                index = 0;
            } else {
                fout << delimeter;
            }
        }
        fout.close();
        
        for (int i = 0; i < ntests; i++){
            cout << times[i] << endl;
        }

        cout << "max word length = " << maxWordLength << "\n" <<
                "largest word = " << maxWord << "\n" <<
                "number of words = " << wordCount << endl;
        
        delete[] times;
    }
}
