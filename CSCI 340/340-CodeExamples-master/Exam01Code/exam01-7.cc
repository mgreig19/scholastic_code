#include <iostream>
#include <set>
#include <array>

int main ()
{
  std::array<int,7> given={45, 67, 12, 87, 90, 11, 34};

  for(int i = 0;i < 7;i++)
    std::cout << given[i] << " ";
  std::cout << std::endl;

  std::set<int> theset;

  for(int i=0;i<given.size();++i)
    theset.insert(given[i]);

  for(auto itr = theset.begin(); itr != theset.end(); ++itr)
    std::cout << *itr << " ";
  std::cout << std::endl;

  return 0;
}