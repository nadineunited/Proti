#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "robin_hood.h"




using namespace std;



typedef  __uint128_t qgram;
typedef  uint32_t minimizer;



uint qgram_size(20);
uint minimizer_size(4);
uint bucket_number(160000);



//take an input file and create all the bucket files
void create_buckets(const string& filename);
string get_line_fasta(ifstream& in);
vector<string> get_super_kmers(const string& line);
minimizer get_minimizer(string);
void super_kmer_to_buckets(const string& super_kmer_file);
