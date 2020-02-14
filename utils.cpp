#include "utils.h"



//take an input file and create all the bucket files
void create_buckets(const string& filename)
{
    ifstream in(filename);
    string line;
    vector<ofstream*> super_kmer_files;
    for(uint i(0);i<bucket_number;++i)
    {
        ofstream* out=new ofstream("superkmer"+to_string(i));
        super_kmer_files.push_back(out);
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




minimizer get_minimizer(const string&)
{
	string minimizer("");
	string current;
	for (uint i(0); i < qgram.size() - minimizer_size + 1; ++i)
	{
		current = qgram.substr(i, minimizer_size);
		if (minimizer.empty() or current < minimizer)
		{
			minimizer = current;
		}
	}
	return minimizer;
}




void super_kmer_to_buckets(const string& super_kmer_file,uint indice)
{
    string line;
    ifstream in(super_kmer_file);
    ofstream out("bucket_"+to_string(indice));
    robin_hood::unordered_map<q_gram,bool>& amstram;
    while(not in.eof())
    {
        getline(in,line);
        uint i(0),j(0);
        for (; i <line.size-qgram_size;++i)
        {
            qgram leq(string_to_qgram(line.substr(i, qgram_size)));
            if(amstram.count(qgram)==0)
            {

            }
            else
            {
                out<<line.substr(j,i+qgram_size)<<endl;
                j=i+1;
            }
            amstram[leq]=true;
        }
        if(j<i)
        {
            out<<line.substr(j,i+qgram_size)<<endl;
        }
    }
}
