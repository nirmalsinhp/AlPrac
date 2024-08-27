/*
We have a cloud storage system that provides features to manage storage disks and point-in-time snapshots of disks. 
The rules for how disks and snapshots are managed are as follows:
We can create new disks.
We can take snapshots of existing disks.
We can also create a disk from an existing snapshot of the disk.
We cannot delete a snapshot if there are any child-disks created from this snapshot as source.
If they have no child-disks or all child-disks have been deleted, the snapshot can be deleted safely.
Deleting a disk first attempts to delete all dependent snapshots automatically, following the rules above.
Given a list of disk and list of snapshot objects, return a sequence of disk deletions that can be used to safely delete all disks.


*/
#include <bits/stdc++.h>
using namespace std;



class Disk
{
  public:
  int id;
  int source; // source disk or snapshot;
  bool isDisk;
 public:
  Disk(int in_id, int src, bool is_disk = true): id(in_id), source(src), isDisk(is_disk)
  {}
};

vector<bool> visited;
vector<bool> processed;
using AdjuscancyList = unordered_map<int, vector<int>>;
vector<Disk> deletionSequence(vector<Disk>& disks, vector<Disk>& snapshots)
{
  unordered_map<int, Disk> disk_map;
  AdjuscancyList al;
  for(auto d: disks)
  {
    al[d.source].push_back(d.id);
    disk_map[d.id] = d;    
  }
  for(auto d: snapshots)
  {
    al[d.source].push_back(d.id);
    //disk_map[d.id] = d;
  }
  
  visited = vector<bool>(al.size(), false);
  processed = vector<bool>(al.size(), false);
  vector<int> postOrder;
  
  for(auto s : al)
  {
    if(!visited[s.first])
    {
      dfs(al, s.first, postOrder);
    }
  }
  
  reverse(postOrder.begin(), postOrder.end());
  vector<Disk> delete_seq;
  for(auto id : postOrder)
  {
    if(disk_map.find(id) != disk_map.end())
    {
      delete_seq.push_back(disk_map[id]);
    }
  }

  return delete_seq;
  
}

void dfs(AdjuscancyList& al, int start, vector<int> & postOrder)
{
  
  visited[start] = true;
  for(auto v : al[start])
  {
    if(!visited[v])
    {
      dfs(al, v, postOrder);
    }     
    if(!processed[v])
    {
      cout << "cycle" << endl;
      return;
    }
  }
  processed[start] = true;
  postOrder.push_back(start);
}
