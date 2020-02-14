#include "utils.h"



//take an input file and create all the bucket files


uint base_to_uint(char base)
{
	switch (base)
	{
		case 'G': return 0;		//Glycine		Gly
		case 'P': return 1;		//Proline		Pro
		case 'A': return 2;		//Alanine		Ala
		case 'V': return 3;		//Valine		Val
		case 'L': return 4;		//Leucine		Leu
		case 'I': return 5;		//Isoleucine		Ile
		case 'M': return 6;		//Methionine		Met
		case 'C': return 7;	    //Cysteine		Cys
		case 'F': return 8;		//Phenylalanine		Phe
		case 'Y': return 9;		//Tyrosine		Tyr
		case 'W': return 10;		//Tryptophan		Trp
		case 'H': return 11;		//Histidine		His
		case 'K': return 12;		//Lysine		Lys
		case 'R': return 13;		//Arginine		Arg
		case 'Q': return 14;		//Glutamine		Gln
		case 'N': return 15;		//Asparagine		Asn
		case 'E': return 16;		//Glutamic Acid		Glu
		case 'D': return 17;		//Aspartic Acid		Asp
		case 'S': return 18;		//Serine		Ser
		case 'T': return 19;		//Threonine		Thr
	}
	return 0;
}




void create_buckets(const string& filename)
{
    ifstream in(filename);
    string line;
    vector<ofstream*> super_kmer_files(bucket_number);

    pair<vector<string>,qgram> super_q_grams;
    minimizer index_file;
    for(uint i(0);i<bucket_number;++i)
    {
		ofstream* file = new ofstream("superkmer"+to_string(i));
        super_kmer_files.push_back(file);
    }
    while(not in.eof())
    {
        line=get_line_fasta(in);
        super_q_grams = get_super_kmers(line);
        index_file = super_q_grams.second;
        ofstream* file_tow = super_kmer_files[index_file];
        for (uint q(0); q < super_q_grams.first.size(); ++q)
        {
			*file_tow << super_q_grams.first[q] << endl;
		}
    }
}



string get_line_fasta(ifstream& in)
{
    string line;
    getline(in,line);
    getline(in,line);
    return line;
}

qgram get_minimizer(string& q_gram)
{
	string mini("");
	string current;
	for (uint i(0); i < q_gram.size() - minimizer_size + 1; ++i)
	{
		current = q_gram.substr(i, minimizer_size);
		if (mini.empty() or current < mini)
		{
			mini = current;
		}
	}
	qgram hash(string_to_qgram(mini));
	return hash;
}

pair<vector<string>, qgram> get_super_kmers(const string& line)
{
	string super_q_gram;
	string q_gram;
	qgram mini;
	qgram prev_mini(0);
	pair<vector<string>,qgram> super_q_grams;
	for (uint i(0); i < line.size() - qgram_size + 1; ++i)
	{
		q_gram = line.substr(i, qgram_size);
		mini = get_minimizer(q_gram);
		if (mini != prev_mini or super_q_grams.first.empty())
		{
			super_q_grams.first.push_back(q_gram);
			super_q_grams.second = mini;
			prev_mini = mini;
		}
		else
		{
			super_q_grams.first.back() += q_gram.back();
		}
	}
	return super_q_grams;
}


qgram string_to_qgram(const string& mini)
{
	qgram hash;
	for (uint i(0); i < mini.size(); ++i){
		hash *= 20;
		hash += base_to_uint(mini[i]);
	}
	return hash;
}






    void super_kmer_to_buckets(const string& super_kmer_file,uint indice)
    {
        string line;
        ifstream in(super_kmer_file);
        ofstream out("bucket_"+to_string(indice));
        robin_hood::unordered_map<qgram,bool> amstram;
        while(not in.eof())
        {
            getline(in,line);
            uint i(0),j(0);
            for (; i <line.size()-qgram_size;++i)
            {
                qgram leq(string_to_qgram(line.substr(i, qgram_size)));
                if(amstram.count(leq)==0)
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
