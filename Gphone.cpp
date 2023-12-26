#include <bits/stdc++.h>
using namespace std;
/*
Imagine you have a robot that sends status messages that humans will read in real time. 
The raw messages are hard to read for a human because there are often many messages produced in short periods of time. 
One idea to make them more readable is to remove the duplicate messages over a sliding 10 second window. 
Design and implement a program to hide duplicates of any message that has already been displayed within the past 10 seconds.

Example Messages Received, with Timestamps:

10 solar panel activated
11 low battery warning
12 tire one: low air pressure
13 solar panel activated
14 low battery warning
21 solar panel activated
35 solar panel activated
Example Messages Shown to User:

10 solar panel activated
11 low battery warning
12 tire one: low air pressure
21 solar panel activated
35 solar panel activated
*/

void DeDulpicate()
{
  unordered_map<string, int> smap;
  string message;
  cout << "enter : " << endl;
  while(getline(cin, message))
  {
    istringstream iss(message);
    int ts;
    string msg;
    iss >> ts;
    iss >> msg;

    cout << ts << " " << msg << endl;
    if(!smap.count(msg) || ts - smap[msg] >= 10)
    {
      cout << message << endl;
      smap[msg] = ts;
    }
  }
}

void DeDulpicater()
{
  unordered_map<string, int> smap;
  string message;
  cout << "enter : " << endl;
  while(getline(cin, message))
  {
    istringstream iss(message);
    int ts;
    string msg;
    iss >> ts;
    iss >> msg;

    //cout << ts << " " << msg << endl;
    smap[msg] = ts;
    for(const auto &[m,t] : smap)
    {
      if(ts - t > 10)
    }

  }
  
}

void print(const unordered_map<string,int>& smap, int ts)
{
  
  for(const auto& kv : smap)
  {
    int kts = kv.second;
    string msg = kv.first;
    if(ts - kts > 10)
    {
      cout << kts << " " << msg << endl;
    }
  }
}

/*
From experience operating the robot, users have determined that there is a bug in the robot and duplicate messages are not to be trusted at all, 
and duplicate messages should be completely removed from the output if they occur within 10 seconds. Design and implement a program to completely remove the duplicate messages.

Example Messages Received:

10 solar panel activated
11 low battery warning
12 tire one: low air pressure
13 solar panel activated
14 low battery warning
21 solar panel activated
35 solar panel activated
<no more messages received for another 30 seconds>
Example Messages Shown to User:

12 tire one: low air pressure
35 solar panel activated

*/

int main()
{

  DeDulpicate();
  return 0;
}