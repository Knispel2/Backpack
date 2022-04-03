#include <iostream>
#include <vector>
#include <filesystem>
using namespace std;

vector <string> list_files(string dir)
{
    vector <string> result;
    for (const auto& entry : filesystem::directory_iterator(dir))
        result.push_back(entry.path().string().substr(5));
    return result;
}

int main()
{
    auto data = list_files("data");

}