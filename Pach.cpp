#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
using namespace std;

class item
{
public:
    int v, w, num;
    item(int a, int b, int c) : v(a), w(b), num(c) {}
};


vector <string> list_files(string dir)
{
    vector <string> result;
    for (const auto& entry : filesystem::directory_iterator(dir))
        result.push_back(entry.path().string().substr(5));
    return result;
}

item split(string data, int num)
{
    auto pos = data.find(" ");
    return item(stoi(data.substr(0, pos)), stoi(data.substr(pos + 1)), num);
}

int main()
{
    vector <string> data = list_files("data");
    string buf;
    int counter = 0;
    ofstream fout;
    fout.open("result.txt");
    for (string x : data)
    {
        vector <item> items;
        ifstream file("/data/" + x);         
        getline(file, buf);
        item start_data = split(buf, 0);
        double capacity = start_data.w;
        vector <short int> result(start_data.v, 0);
        while (getline(file, buf))
        {
            items.push_back(split(buf, counter));
            ++counter;
        }            
        file.close();
        sort(items.begin(), items.end(), [](item a, item b)
            {return ((double)a.v / a.w > (double)b.v / b.w) or (((double)a.v / a.w == (double)b.v / b.w) and (a.w <= b.w)); });
        int weight = 0;
        int cost = 0;
        for (auto obj : items)
            if (weight >= capacity) break;
            else
            {
                weight += obj.w;
                cost += obj.v;
                result[obj.num] = 1;
            }        
        fout << x << ": " << endl;
        fout << cost << " " << capacity - weight << endl;
        for (auto obj : result)
            fout << obj << " ";
        fout << endl;        
    }
    fout.close();
}