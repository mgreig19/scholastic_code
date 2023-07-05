#include <iostream>
#include <map>
#include <string>

int 
main()
{

    typedef std::pair<int, std::string> intstring;
    std::map<int, std::string> mymap;

    // mymap.insert(std::make_pair(1,"yes"));
    // mymap.insert(std::make_pair(5,"no"));
    // mymap.insert(std::make_pair(2,"yes-and-no"));
    // mymap.insert(std::make_pair(10,"maybe"));
    // mymap.insert(std::make_pair(5,"NO"));

    mymap[1] = "yes";
    mymap[5] = "no";
    mymap[2] = "yes-and-no";
    mymap[10] = "maybe";
    mymap[5] = "NO";
   
    // Add order : (1, “yes”), (5, “no”), (2, “yes-and-no”), (10, “maybe”), (5, “NO”)
    // mymap.insert(intstring(1,"yes"));
    // mymap.insert(intstring(5,"no"));
    // mymap.insert(intstring(2,"yes-and-no"));
    // mymap.insert(intstring(10,"maybe"));
    // mymap.insert(intstring(5,"NO"));

    for(auto it = mymap.begin(); it != mymap.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << std::endl;
    
    for(auto mi = mymap.begin();mi != mymap.end();mi++)
        std::cout << (*mi).first << " " << (*mi).second << std::endl;
    
    std::cout << std::endl;

    // for each
    for(auto i:mymap)
        std::cout << i.first << " " << i.second << std::endl;

    return 0;
}// End of MAIN()

