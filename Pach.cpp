#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>
using namespace std;

vector <string> list_files(string dir)
{
    vector <string> result;
    for (const auto& entry : filesystem::directory_iterator(dir))
        result.push_back(entry.path().string().substr(5));
    return result;
}

pair <int, int> split(string data)
{
    auto pos = data.find(" ");
    return make_pair(stoi(data.substr(0, pos)),
                     stoi(data.substr(pos + 1)));
}

int main()
{
    vector <string> data = list_files("data");
    string buf;
    pair <int, int> portion;
    for (string x : data)
    {
        ifstream file("/data/" + x);         
        getline(file, buf);
        vector <pair <int, int>> items;
        double capacity = split(buf).second;
        while (getline(file, buf))
            items.push_back(split(buf));
        sort(items.begin(), items.end(), [](pair <int, int> a, pair <int, int> b)
            {return (double)a.second / a.first > (double)b.second / b.first; });

    }
}