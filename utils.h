typedef qgram __uint128_t
typedef minimizer uint32_t

uint qgram_size;
uint minimizer_size;

//take an input file and create all the bucket files
void create_buckets(const string& filename);
string get_line_fasta(ifstream& in);
vector<qgram> get_super_kmers(const string& line);
minimizer get_minimizer(qgram);
void super_kmer_to_buckets(const string& super_kmer_file);
