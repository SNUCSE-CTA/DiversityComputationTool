/**
 * @file util.h
 *
 */

#ifndef UTIL_H_
#define UTIL_H_

#include "common.h"
#include "graph.h"

namespace util {
static std::vector<std::vector<Vertex>> ReadEmbeddings(std::string &filename) {
  std::ifstream fin(filename);

  if (!fin.is_open()) {
    std::cout << "Embedding file " << filename << " not found!\n";
    exit(EXIT_FAILURE);
  }

  std::vector<std::vector<Vertex>> embeddings;

  char type;
  size_t num_vertices;

  fin >> type >> num_vertices;

  while (fin >> type) {
    embeddings.emplace_back(num_vertices);

    for (size_t i = 0; i < num_vertices; ++i) {
      fin >> embeddings.back()[i];
    }
  }

  return embeddings;
}

template <typename Element>
static size_t GetCoverage(Graph &G, Graph &q,
                          std::vector<std::vector<Element>> &embeddings) {
  std::set<Element> cov;
  for (size_t i = 0; i < embeddings.size(); ++i) {
    for (Element v : embeddings[i]) {
      cov.insert(v);
    }
  }

  return cov.size();
}

template <typename Element>
static double GetContentBasedDiversity(
    Graph &G, Graph &q, std::vector<std::vector<Element>> &embeddings,
    double (*sim)(std::vector<Element> &, std::vector<Element> &)) {
  double div = 0;
  size_t num = 0;

  for (size_t i = 0; i < embeddings.size() - 1; ++i) {
    for (size_t j = i + 1; j < embeddings.size(); ++j) {
      div += sim(embeddings[i], embeddings[j]);
      num += 1;
    }
  }

  return div / num;
}

template <typename Element>
double HammingSimilarity(std::vector<Element> &emb1,
                         std::vector<Element> &emb2) {
  double res = 0;
  for (size_t i = 0; i < emb1.size(); ++i) {
    if (emb1[i] != emb2[i]) {
      res += 1;
    }
  }
  res = 1.0 - res / emb1.size();
  return res;
}

template <typename Element>
double JaccardSimilarity(std::vector<Element> &emb1,
                         std::vector<Element> &emb2) {
  double res = 0;
  std::vector<Element> s1, s2;
  for (size_t i = 0; i < emb1.size(); ++i) {
    s1.push_back(emb1[i]);
    s2.push_back(emb2[i]);
  }
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  std::vector<Element> union_, intersect_;

  std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),
                 std::back_inserter(union_));
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                        std::back_inserter(intersect_));

  res = (double)(intersect_.size()) / union_.size();
  return res;
}

static std::vector<std::vector<Edge>> GetEdgeEmbeddings(
    Graph &G, Graph &q, std::vector<std::vector<Vertex>> &embeddings) {
  std::vector<std::vector<Edge>> edge_embeddings(embeddings.size());

  for (Vertex u = 0; u < q.GetNumVertices(); ++u) {
    for (size_t i = q.GetNeighborStartOffset(u); i < q.GetNeighborEndOffset(u);
         ++i) {
      Vertex un = q.GetNeighbor(i);
      if (u > un) continue;
      for (size_t j = 0; j < embeddings.size(); ++j) {
        Vertex v = embeddings[j][u];
        Vertex vn = embeddings[j][un];
        edge_embeddings[j].emplace_back(v, vn);
      }
    }
  }

  return edge_embeddings;
}
}  // namespace util

#endif  // UTIL_H_
