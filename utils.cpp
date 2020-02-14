#include "utils.h"
//take an input file and create all the bucket files
void create_buckets(const string& filename)
{
    ifstream in(filename);
    string line;
    ofstream super_kmer_files;
    for(uint i(0);i<bucket_number;++i)
    {
        super_kmer_files.push_back("superkmer"+to_string(i));
    }
    while(not in.eof())
    {
        line=get_line_fasta(in);
    }
}

string get_line_fasta(ifstream& in)
{
    string line;
    getline(in,line);
    getline(in,line);
    return line;
}

vector<string> get_super_kmers(const string& line)
{
}

minimizer get_minimizer(const string&)
{
}

void super_kmer_to_buckets(const string& super_kmer_file)
{
}
