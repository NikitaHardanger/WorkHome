#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    set<string> bus_stops;
    map<set<string>, int> route;
    int q, count_stop, number_route = 0;
    string stop;
    cin >> q;
    for (q; q > 0; q--) {
        cin >> count_stop;
        for (count_stop; count_stop > 0; --count_stop) {
            cin >> stop;
            bus_stops.insert(stop);
        }
        if (!route.count(bus_stops)) {
            route[bus_stops] = ++number_route;
            cout << "New bus " << number_route << endl;
        } else {
            cout << "Already exists for " << route[bus_stops] << endl;
        }
        bus_stops.clear();
    }
    return 0;
}