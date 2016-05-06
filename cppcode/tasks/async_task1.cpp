#include <iostream>     // cout
#include <future>       // async, future, launch
#include <chrono>       // chrono::milliseconds
#include <thread>       // this_thread::sleep_for

using namespace std;

void print_ten (char c, int ms) {
  for (int i=0; i<10; ++i) {
    this_thread::sleep_for (chrono::milliseconds(ms));
    cout << c;
  }
	cout<<endl;
}
void check(int d){
    cout<<"printggggggggggggggg"<<d<<endl;
}

int main ()
{
  cout << "with launch::async:\n";
  future<void> foo = async (launch::async, print_ten,'$', 100);
  future<void> bar = async (launch::async,print_ten,'@',202);
  // async "get" (wait for foo and bar to be ready):
  
 // bar.get();
 // foo.get();
  cout << "\n\n";

  cout << "with launch::deferred:\n";
  foo = async (launch::deferred,print_ten,'*',100);
  bar = async (launch::deferred,print_ten,'@',200);
  // deferred "get" (perform the actual calls):
  
 // bar.get();
  //foo.get();
  cout << '\n';

  return 0;
}

