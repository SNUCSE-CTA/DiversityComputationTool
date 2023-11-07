/**
 * @file graph.h
 *
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "common.h"

class Graph {
 public:
  explicit Graph(const std::string& filename, bool is_query = false);
  ~Graph();

  inline int32_t GetGraphID() const;

  inline size_t GetNumVertices() const;
  inline size_t GetNumEdges() const;
  inline size_t GetNumLabels() const;

  inline size_t GetLabelFrequency(Label l) const;
  inline size_t GetNeighborLabelFrequency(Vertex v, Label l) const;

  inline size_t GetDegree(Vertex v) const;

  inline size_t GetNeighborStartOffset(Vertex v) const;
  inline size_t GetNeighborEndOffset(Vertex v) const;

  inline size_t GetNeighborStartOffset(Vertex v, Label l) const;
  inline size_t GetNeighborEndOffset(Vertex v, Label l) const;

  inline Label GetLabel(Vertex v) const;
  inline Vertex GetNeighbor(size_t offset) const;

  inline bool IsNeighbor(Vertex u, Vertex v) const;

 private:
  int32_t graph_id_;

  size_t num_vertices_;
  size_t num_edges_;
  size_t num_labels_;

  std::vector<size_t> label_frequency_;

  std::vector<size_t> start_offset_;
  std::vector<std::pair<size_t, size_t>> start_offset_by_label_;

  std::vector<Label> label_;
  std::vector<Vertex> adj_array_;

  Label max_label_;
};

/**
 * @brief Returns the ID of the graph.
 *
 * @return int32_t
 */
inline int32_t Graph::GetGraphID() const { return graph_id_; }

/**
 * @brief Returns the number of vertices |V| of the graph.
 *
 * @return size_t
 */
inline size_t Graph::GetNumVertices() const { return num_vertices_; }
/**
 * @brief Returns the number of edges |E| of the graph.
 *
 * @return size_t
 */
inline size_t Graph::GetNumEdges() const { return num_edges_; }
/**
 * @brief Returns the number of distinct labels |Σ| of the graph.
 *
 * @return size_t
 */
inline size_t Graph::GetNumLabels() const { return num_labels_; }

/**
 * @brief Returns the frequency of the label l in the graph.
 *
 * @param l label id.
 * @return size_t
 */
inline size_t Graph::GetLabelFrequency(Label l) const {
  return label_frequency_[l];
}
/**
 * @brief Returns the number of neighbors of v with label l.
 *
 * @param v vertex id.
 * @param l label id.
 * @return size_t
 */
inline size_t Graph::GetNeighborLabelFrequency(Vertex v, Label l) const {
  return GetNeighborEndOffset(v, l) - GetNeighborStartOffset(v, l);
}
/**
 * @brief Returns the degree of the vertex v.
 *
 * @param v vertex id.
 * @return size_t
 */
inline size_t Graph::GetDegree(Vertex v) const {
  return start_offset_[v + 1] - start_offset_[v];
}
/**
 * @brief Returns the start offset of v's neighbor in adjacent array.
 *
 * @param v vertex id.
 * @return size_t
 */
inline size_t Graph::GetNeighborStartOffset(Vertex v) const {
  return start_offset_[v];
}
/**
 * @brief Returns the end offset of v's neighbor in adjacent array.
 *
 * @param v vertex id.
 * @return size_t
 */
inline size_t Graph::GetNeighborEndOffset(Vertex v) const {
  return start_offset_[v + 1];
}

/**
 * @brief Returns the start offset of the neighbor of v with label l. If there
 * is no neighbors of v with label l, it returns 0.
 *
 * @param v vertex id.
 * @param l label id of v's neighbor.
 * @return size_t
 */
inline size_t Graph::GetNeighborStartOffset(Vertex v, Label l) const {
  return start_offset_by_label_[v * (max_label_ + 1) + l].first;
}
/**
 * @brief Returns the end offset of the neighbor of v with label l. If there is
 * no neighbor of v with label l, it returns 0.
 *
 * @param v vertex id.
 * @param l label of v's neighbor.
 * @return size_t
 */
inline size_t Graph::GetNeighborEndOffset(Vertex v, Label l) const {
  return start_offset_by_label_[v * (max_label_ + 1) + l].second;
}

/**
 * @brief Returns the label of the vertex v.
 *
 * @param v vertex id.
 * @return Label
 */
inline Label Graph::GetLabel(Vertex v) const { return label_[v]; }
/**
 * @brief Returns the neighbor of a vertex v from the offset where the offset is
 * in half-open interval [GetNeighborStartOffset(v), GetNeighborEndOffset(v))
 * or [GetNeighborStartOffset(v, l), GetNeighborEndOffset(v, l)).
 *
 * @param offset
 * @return Vertex
 */
inline Vertex Graph::GetNeighbor(size_t offset) const {
  return adj_array_[offset];
}

/**
 * @brief Returns true if there is an edge between u and v, otherwise return
 * false.
 *
 * @param u vertex id.
 * @param v vertex id.
 * @return bool
 */
inline bool Graph::IsNeighbor(Vertex u, Vertex v) const {
  if (GetNeighborLabelFrequency(u, GetLabel(v)) >
      GetNeighborLabelFrequency(v, GetLabel(u)))
    std::swap(u, v);
  auto it = std::lower_bound(
      adj_array_.begin() + GetNeighborStartOffset(u, GetLabel(v)),
      adj_array_.begin() + GetNeighborEndOffset(u, GetLabel(v)), v,
      [this](Vertex u, Vertex v) {
        if (GetDegree(u) != GetDegree(v))
          return GetDegree(u) > GetDegree(v);
        else
          return u < v;
      });
  size_t offset = it - adj_array_.begin();
  return offset >= GetNeighborStartOffset(u, GetLabel(v)) &&
         offset < GetNeighborEndOffset(u, GetLabel(v)) && *it == v;
}

#endif  // GRAPH_H_
