#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <map>
using namespace std;

#include <unordered_map>

class Hashtable {
    std::unordered_map<const void*, const void*> htmap;

public:
    void put(const void* key, const void* value) {
        htmap[key] = value;
    }

    const void* get(const void* key) {
        return htmap[key];
    }

};


int main(int argc, char** argv)
{
    std::map<std::string, int> m;
    m["hello"] = 23;
    // check if key is present
    if (m.find("world") != m.end())
        std::cout << "map contains key world!\n";
    // retrieve
    std::cout << m["hello"] << '\n';
    std::map<std::string, int>::iterator i = m.find("hello");
    assert(i != m.end());
    std::cout << "Key: " << i->first << " Value: " << i->second << '\n';

    vector<string> codeList = { "group4", "group4", "group3", "anything", "group3" };
    vector<string> shoppingCart = { "group3", "group4", "group4", "group3", "group1", "group3"};

    //unique code for codeList
    std::map<string, int> codeMap;
    int gNumber = 0;
    for (auto code : codeList)
    {
        if (code == "anything")
        {
            codeMap[code] = -1;
        }
        else
        {
            codeMap[code] = gNumber++;
        }
    }

    int sNumber = 0;
    std::map<string, int> shoppingMap;
    for (auto item : shoppingCart)
    {
        shoppingMap[item] = sNumber++;
    }

    // Iterating the map and
    // printing ordered values
    for (auto i = shoppingMap.begin(); i
        != shoppingMap.end(); i++) {
        std::cout << i->first
            << " : "
            << i->second << '\n';
    }

    Hashtable ht;
    ht.put("Bob", "Dylan");
    int one = 1;
    ht.put("one", &one);
    std::cout << (char*)ht.get("Bob") << "; " << *(int*)ht.get("one");

    int codeListIndex = 0;
    int shoppingCartIndex = 0;
    int matchIndex = 0;
    int output = 0;

    int g1Elements, g2Elements;
    std::cout << "Please , enter the number of first group elements" << endl;
    cin >> g1Elements;
    g2Elements = codeList.size() - g1Elements;

    for (auto item : shoppingCart)
    {
        if (shoppingCart[shoppingCartIndex] == codeList[codeListIndex])
        {
            codeListIndex++; shoppingCartIndex++; ++matchIndex; 
            continue;
        }
        if (shoppingCart[shoppingCartIndex] != codeList[codeListIndex] && codeList[codeListIndex] != "anything")
        {
            if (codeListIndex > 0 && codeListIndex < g1Elements) break; //doesn't follow the group1
            if (codeListIndex > g1Elements && codeListIndex < g2Elements) break; //doesn't follow the group2
            shoppingCartIndex++; continue;
        };
        if (shoppingCart[shoppingCartIndex] != codeList[codeListIndex] && codeList[codeListIndex] == "anything")
        {
            codeListIndex++; shoppingCartIndex++; ++matchIndex; continue;
        };
       
        if (codeListIndex >= codeList.size()) break;
    }
    if (matchIndex == codeList.size()) output = 1;
    cout << "output: " << output;

    return 0;
}