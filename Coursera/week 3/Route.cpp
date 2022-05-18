//
// Created by Nikit on 26/10/2021.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ComputeDistance(const string& source, const string& destination) {
    return source.length() - destination.length();
}

class Route {
public:
    Route() {
        source = "Moscow";
        destination = "Saint Petersburg";
        UpdateLength();
        cout << "Default constructed\n";
    }
    Route(const string& new_source,
          const string& new_destination) {
        source = new_source;
        destination = new_destination;
        UpdateLength();
        cout << "Constructed\n";
    }
    ~Route() {
        for (const string& entry : compute_distance_log) {
            cout << entry << "\n";
            cout << "Destructed\n";
        }
    }
    string GetSource() const {
        return source;
    }
    string GetDestination() const {
        return destination;
    }
    [[nodiscard]] int GetLength() const {
        return length;
    }
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
        length = ComputeDistance(source, destination);
        compute_distance_log.push_back(
                source + " - " + destination
                );
    }
    string source;
    string destination;
    int length;
    vector<string> compute_distance_log;
};

void PrintRoute(const Route& route) {
    cout << route.GetSource() << " - " <<
         route.GetDestination() << endl;
}

void ReverseRoute(Route& route) {
    string old_source = route.GetSource();
    string old_destination = route.GetDestination();
    route.SetSource(old_destination);
    route.SetDestination(old_source);
}


int main() {
//    Route route("Zvenigorod", "Istra");
//    cout << "Route from Zvenigorod to Istra " <<
//        "has length " << route.GetLength() << "\n";
//    Route route1;
//    PrintRoute(Route());
//    PrintRoute({});
//    PrintRoute({"Pskov", "Praha"});
//    vector<Route> routes;
//    routes.push_back({"Pskov", "Praha"});
//    route.SetSource("Moscow");
//    route.SetDestination("Vologda");
//    PrintRoute(route);
//    ReverseRoute(route);
//    PrintRoute(route);
//    ReverseRoute(route);
//    PrintRoute(route);
//    Route route1;
//    route1.SetSource("Saint Petersburg");
//    route1.SetDestination("Praha");
//    PrintRoute(route1);
//    Route route("Moscow", "Saint Petersburg");
//    route.SetSource("Vyborg");
//    route.SetDestination("Vologda");
    cout << 1 << "\n";
    Route route;
    cout << 2 << "\n";
    return 0;
}