
#include "YFastTrie.h"
#include "VEB.h"

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <iterator>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;



int main(){

  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double deltatime;
  int data[10000];
  int data2[100000];
  ifstream input ("input.txt");
  ifstream input2 ("input3.txt");
  
  if (input.is_open())
    {
      for(int i = 0; i<10000; i++)
	{
	  input >> data[i];
	}
    }

  else cout << "Unable to open file"; 

  if (input2.is_open())
    {
      for(int i = 0; i<100000; i++)
	{
	  input2 >> data2[i];
	}
    }

  else cout << "Unable to open file";

  //test the xtrie
  MyXFast trie(10000);
  start = chrono::steady_clock::now(); 
  for(int i = 0; i<10000; i++)
    {
      trie.insert(data[i]);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "X trie time to insert 10,000: " << deltatime << endl;

  start = chrono::steady_clock::now(); 
  for(int i = 0; i<100000; i++)
    {
      trie.insert(data2[i]);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();


  cout << "X trie time to insert 100,000: " << deltatime << endl;


  start = chrono::steady_clock::now(); 
  for(int i = 0; i<10000; i++)
    {
      trie.find(data[i]);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "X trie time to find 10,000: " << deltatime << endl;

  
  start = chrono::steady_clock::now(); 
  for(int i = 0; i<100000; i++)
    {
      trie.find(data2[i]);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "X trie time to find 100,000: " << deltatime << endl;
  

  cout << "Completed X trie" << endl;



  //test the yfast
  MyYFast ytrie(10000);
  start =  chrono::steady_clock::now();
  for(int i = 0; i<10000; i++)
    {
      ytrie.insert(data[i],2);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "Y trie time to insert 10,000: " << deltatime << endl;

  start =  chrono::steady_clock::now();
  for(int i = 0; i<100000; i++)
    {
      ytrie.insert(data2[i],2);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "Y trie time to insert 100,000: " << deltatime << endl;
  

  start =  chrono::steady_clock::now();
  for(int i = 0; i<10000; i++)
    {
      ytrie.find(data[i]);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "Y trie time to find 10,000: " << deltatime << endl;


  start =  chrono::steady_clock::now();
  for(int i = 0; i<100000; i++)
    {
      ytrie.find(data2[i]);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "Y trie time to delete 100,000: " << deltatime << endl;


  cout << "Complete Y trie" << endl;



  MyVEBTree tree(1000);
  start = chrono::steady_clock::now(); 
  for(int i = 0; i<10000; i++)
    {
      tree.insert(data[i]);
    }
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  deltatime = (double) difference_in_time.count();

  cout << "VEB tree time to insert: " << deltatime << endl;
  return 0;
}
