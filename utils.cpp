#include "utils.h"
//take an input file and create all the bucket files
void create_buckets(const string& filename)
{
}

string get_line_fasta(ifstream& in)
{
	while (not in.eof()){
	}
}

vector<string> get_super_kmers(const string& line)
{
	string super_q_gram;
	string q_gram;
	minimizer mini;
	minimizer prev_mini(0);
	vector<string> super_q_grams;
	for (uint i(0); i < line.size() - qgram_size + 1; ++i)
	{
		q_gram = line.substr(i, qgram_size);
		mini = get_minimizer(q_gram);
		if (mini != prev_mini or super_q_grams.empty())
		{
			super_q_grams.push_back(q_gram);
			prev_mini = mini;
		}
		else 
		{
			super_q_grams.back() += q_gram.back();
		}
	}
	return super_q_grams;
}

minimizer get_minimizer(string)
{
}

void super_kmer_to_buckets(const string& super_kmer_file)
{
}
