# Diversity Computation Tool
## Compile and Execute 
### main program
```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./main/program <data graph file> <query graph file> <embedding file>
```

For example, in `build` directory,
```
$ ./main/program ../dataset/sample/data_graph/sample.igraph ../dataset/sample/query_graph/sample.igraph ../dataset/sample/embeddings/sample.out > output.txt
$ cat output.txt
Reading data graph: ../dataset/sample/data_graph/sample.igraph
Reading query graph: ../dataset/sample/query_graph/sample.igraph
Reading embedding file: ../dataset/sample/embeddings/sample.out

Computing Coverage...
Coverage of 2 embeddings: 5
Computing Content-Based Diversity...
Based on Hamming Similarity: 0.75
Based on Jaccard Similarity: 0.6

Computing Edge Coverage...
Coverage of 2 embeddings: 8
Computing Content-Based Edge Diversity...
Based on Hamming Similarity: 0.4
Based on Jaccard Similarity: 0.25
```
