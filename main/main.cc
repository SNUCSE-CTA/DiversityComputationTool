/**
 * @file main.cc
 *
 */

#include "common.h"
#include "graph.h"
#include "util.h"

int main(int argc, char* argv[]) {
  using std::cout, std::cerr, std::endl;
  using std::string;
  using std::vector;

  if (argc < 4) {
    cerr << "Usage: ./program <data graph file> <query graph file> "
            "<embedding file>\n";
    return EXIT_FAILURE;
  }

  string data_file_name = argv[1];
  string query_file_name = argv[2];
  string embedding_file_name = argv[3];

  cout << "Reading data graph: " << data_file_name << endl;
  Graph data(data_file_name);

  cout << "Reading query graph: " << query_file_name << endl;
  Graph query(query_file_name, true);

  cout << "Reading embedding file: " << embedding_file_name << endl;
  vector<vector<Vertex>> embeddings = util::ReadEmbeddings(embedding_file_name);

  cout << endl;

  cout << "Computing Coverage..." << endl;
  cout << "Coverage of " << embeddings.size() << " embeddings: ";
  cout << util::GetCoverage(data, query, embeddings) << endl;

  cout << "Computing Content-Based Diversity..." << endl;
  cout << "Based on Hamming Similarity: ";
  cout << util::GetContentBasedDiversity(data, query, embeddings,
                                         util::HammingSimilarity)
       << endl;

  cout << "Based on Jaccard Similarity: ";
  cout << util::GetContentBasedDiversity(data, query, embeddings,
                                         util::JaccardSimilarity)
       << endl;
  cout << endl;

  vector<vector<Edge>> edge_embeddings =
      util::GetEdgeEmbeddings(data, query, embeddings);

  cout << "Computing Edge Coverage..." << endl;
  cout << "Coverage of " << edge_embeddings.size() << " embeddings: ";
  cout << util::GetCoverage(data, query, edge_embeddings) << endl;

  cout << "Computing Content-Based Edge Diversity..." << endl;
  cout << "Based on Hamming Similarity: ";
  cout << util::GetContentBasedDiversity(data, query, edge_embeddings,
                                         util::HammingSimilarity)
       << endl;

  cout << "Based on Jaccard Similarity: ";
  cout << util::GetContentBasedDiversity(data, query, edge_embeddings,
                                         util::JaccardSimilarity)
       << endl;

  return EXIT_SUCCESS;
}
