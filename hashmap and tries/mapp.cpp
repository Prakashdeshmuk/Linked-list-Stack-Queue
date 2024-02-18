#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    unordered_map<string,int>mapping;

    pair<string,int> p1 = {"Prakash",25};
    pair<string,int>p2("athrav",99);

    pair<string,int>p3;
    p3.first = "bhushan";
    p3.second = 99;



    mapping.insert(p1);
    mapping.insert(p2);
    mapping.insert(p3);

    mapping["Harshad"] = 67;

    cout << "Size " << mapping.size() << endl;

    // access in the mapp

    cout << mapping.at("Prakash") << endl;
    cout << mapping["Harshad"] << endl;



    // search in the mapp

    if(mapping.find("Prakash")!=mapping.end())
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }


    string str1 = "lovebabber";

    map<char,int>freq;

    for(auto ch:str1)
    {
        freq[ch]++;
    }

    for(auto it:freq)
    {
        cout << it.first << "->" << it.second << endl;
    }



    int i = '2'-'0';
    cout << i << endl; 

}