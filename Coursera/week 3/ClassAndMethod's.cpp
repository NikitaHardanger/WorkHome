//
// Created by Nikit on 20/10/2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Route{
public:
    string& GetSource() { return source; }
    string GetDestination() { return destination; }
    int GetLength() { return length; }
    void SetSource(const string& new_source) {
        source = new_source;
        UpdateLength();
    }
    void SetDestination(const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }
private:
    void UpdateLength() {
//        length = ComputeDistance(source, destination);
    }
    string source;
    string destination;
    int length;
};

int main() {
    Route route;
    route.SetSource("Saint Petersburg");
    route.SetDestination("Praha");
    cout << "Route from " <<
            route.GetSource() << " to " <<
            route.GetDestination() << " is " <<
            route.GetLength() << " meters long";
    return 0;
}