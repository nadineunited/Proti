#ifndef UTILS
#define UTILS

#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>



using namespace std;



typedef  __uint128_t qgram;
typedef  uint32_t minimizer;



//~ uint qgram_size;
//~ uint minimizer_size;
//~ uint bucket_number;
static uint qgram_size(20);
static uint minimizer_size(4);
static uint bucket_number(160000);



//take an input file and create all the bucket files
void create_buckets(const string& filename);
string get_line_fasta(ifstream& in);
pair<vector<string>, qgram> get_super_kmers(const string& line);
qgram get_minimizer(string&);
void super_kmer_to_buckets(const string& super_kmer_file);
qgram string_to_qgram(string& mini);

#endif
