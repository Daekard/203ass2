#include <iostream>
#include <ctime>

#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;

void get_max_words(ifstream& fin, int& wordlen, int& numwords);
int cmp(const void* a, const void* b);
int tcmp(const void* a, const void* b);

int main(int argc, char* argv[])
{
	/*file reading and preprocessing*/
	if(argc != 5)
	{
		cerr << "usage: " << argv[0] 
			<< " infile outfile timesfile ntests" << endl;
		exit(EXIT_FAILURE);
	}

	ifstream fin(argv[1]);
	if(fin.fail())
	{
		cerr << "Error: failed to open file " << argv[1] 
			<< " for input" << endl;
		exit(EXIT_FAILURE);
	}
	int ntests = atoi(argv[4]);
	
	int stringlen, numwords;
	get_max_words(fin, stringlen, numwords);
	++stringlen; //to hold strterm 

	int len = numwords*stringlen;
	char* initial = new char[len];
	char* word = initial;
	for(int i=0; i<numwords; i++, word+=stringlen)
	{
		fin >> word;
	}		

	char* temp = new char[len];
	
	/*
	At this point, everything should be in the initial array
	The temporary array should be declared but not filled
	*/
	
	clockid_t cpu;
	timespec start, end;
	long time[ntests];
	if(clock_getcpuclockid(0, &cpu) != 0)
	{
		cerr << "Error: could not get cpu clock" << endl;
		exit(EXIT_FAILURE);
	}
		
	for(int i=0; i<ntests; i++)
	{
		/*start timer*/
		if(clock_gettime(cpu, &start) == -1)
		{
			cerr << "Error: could not get start time" << endl;
			exit(EXIT_FAILURE);
		}

		/*copy from initial array to temporary array*/
		for(int k=0; k<len; k++)
			temp[k] = initial[k];
		/*sort temporary array*/
     		qsort(temp, numwords, stringlen, cmp);

		/*stop timer*/
		if(clock_gettime(cpu, &end) == -1)
		{
			cerr << "Error: could not get end time" << endl;
			exit(EXIT_FAILURE);
		}

		/*time per trial in nanoseconds*/
		time[i] = (end.tv_sec - start.tv_sec)*1000000000 + 
			end.tv_nsec - start.tv_nsec;
	}
	/*output sorted temporary array*/
     	qsort(time, ntests, sizeof(long), tcmp);
	ofstream fout(argv[2]);
	word = temp;
	for(int i=1; i<=numwords; i++, word+=stringlen)
	{
		if(i%10 == 0)
			fout << word << endl;
		else
			fout << word << " ";
	}		
	/*output time required for test*/
	ofstream ftimes(argv[3]);
	for(int i=0; i<ntests; i++)
		ftimes << time[i] << endl;

	delete[] initial;
	delete[] temp;
}



void get_max_words(ifstream& fin, int& wordlen, int& numwords)
{
	char c;
	int count=0;
	wordlen = numwords = 0;

	while(fin.good() && fin.get(c) && isspace(c)){;} //skip leading space
	while(fin.good())
	{
		++numwords;
		while(fin.good() && !isspace(c)) 
		{
			++count;
			fin.get(c);
		}
		if(count > wordlen)
			wordlen = count;
		count = 0;
		while(fin.good() && fin.get(c) && isspace(c)){;} //skip space
	}	
	if(count > wordlen)
		wordlen = count;
	fin.clear();
	fin.seekg(0, ios::beg);
}


int cmp(const void* a, const void* b)
{
	int alen = strlen(reinterpret_cast<const char*>(a));
	int blen = strlen(reinterpret_cast<const char*>(b));
	if(alen < blen)
		return false;
	else if(blen < alen)
		return true;
	else
		return strcmp(reinterpret_cast<const char*>(a),
				reinterpret_cast<const char*>(b));
		
}

int tcmp(const void* a, const void* b)
{
	return *(reinterpret_cast<const long*>(a)) > 
		*(reinterpret_cast<const long*>(b));
}
