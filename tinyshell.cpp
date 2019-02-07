//Group Member 1 - Name: JOSHI Swapnil, UID: 3035435773
//Group Member 2 - Name: DUBEY Aryaman, UID: 3035437056

#include <iostream>
#include <stdlib.h>
#include <list>
#include <chrono>
#include <unistd.h>
#include <sys/types.h>

using namespace std;
using namespace std::chrono;

class command{
  public:
    string cmd;
    double time;
};

bool operator<(const command &a, const command &b){
  return b.time < a.time;
};

int main(){
  string Command;
  list<command> history;
  pid_t pid;
  cout << "tinyshell> ";
  while (getline(cin, Command)){
    if (Command == "exit" || Command == " exit " || Command == " exit" || Command == "exit "){
      exit(0);
    }
    else if (Command == "history" || Command == " history " || Command == " history" || Command == "history "){
      pid = fork();
      if ( pid == 0 ){
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      list<command>::iterator itr;
      int x = 0;
      cout << endl;
      for (itr = history.begin(); itr != history.end() && x != 5; itr++){
        cout << (*itr).cmd << "  " << (*itr).time << "s" << endl;
        x++;
      }
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
      command y;
      y.cmd = Command;
      y.time = (double)duration/1000.0;
      history.push_front(y);
    }
    }
    else if (Command == "history -sbu" || Command == " history -sbu " || Command == "history -sbu " || Command == " history -sbu"){
      pid = fork();
      if ( pid == 0 ){
      list<command> swap;
      swap = history;
      swap.sort();
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      list<command>::iterator itr;
      int x = 0;
      for (itr = swap.begin(); itr != swap.end() && x != 5; itr++){
        cout << (*itr).cmd << "  " << (*itr).time << "s" << endl;
        x++;
      }
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
      command y;
      y.cmd = Command;
      y.time = (double)duration/1000.0;
      history.push_front(y);
      }
    }
    else{
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      system(Command.c_str());
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
      command x;
      x.cmd = Command;
      x.time = (double)duration/1000.0;
      history.push_front(x);
    }
    cout << "tinyshell> ";
  }

}
