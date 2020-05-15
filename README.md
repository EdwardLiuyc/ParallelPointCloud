# ParallelPointCloud

## motivation

1. I want a pointcloud type that can be inited with any amount of dims  
  for instance :  
  3 dims : x, y, z  
  4 dims : x, y, z, time or intensity or gray scale ...  
  even a pointcloud with ORB descriptor (optional)  

2. I want a pointcloud type that i can define channels (even dynamicly) and I can easily access any channel data with operator[] or something like `.at("channel name")`

3. I want it to be thread-safe and lock free

## Todos
- benchmark on std::vector vs tbb::concurrent_vector vs pcl
- parallel transform on pointcloud
- parallel filtering