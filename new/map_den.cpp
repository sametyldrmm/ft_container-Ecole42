#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['a'] = 200;
  mymap['c'] = 300;
  mymap['b'] = 100;
 std::map<char,int> mymap1;

  mymap1['z'] = 200;
  mymap1['y'] = 300;
  mymap1['e'] = 100;
    std::map<std::map<char,int>,int> mymapf;
  mymapf[mymap] = 123;
  mymapf[mymap1] = 200;
  
  // show content:

    
  return 0;
}