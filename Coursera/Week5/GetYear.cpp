#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <string>
#include <iomanip>
#include <sstream>
#include <set>

using namespace std;

class Date {
public:
    Date() {
        year = -1;
        month = -1;
        day = -1;

    }
    Date(int new_year, int new_month, int new_day) {
        year = new_year;
        if (new_month > 12 || new_month <= 0) {
            throw invalid_argument("Month value is invalid: " + to_string(new_month));
        }
        month = new_month;
        if (new_day > 31 || new_day <= 0) {
            throw invalid_argument("Day value is invalid: " + to_string(new_day));
        }
        day = new_day;
    }
    int GetYear() const {
      return year;
    }
    int GetMonth() const {
      return month;
    }
    int GetDay() const {
      return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            if (lhs.GetDay() >= rhs.GetDay()) {
                return false;
            } else {
                return true;
            }
        } else if (lhs.GetMonth() < rhs.GetMonth()) {
            return true;
        } else {
            return false;
        }

    }
    else if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    } else {
        return false;
    }
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
      if (events.find(date) == events.end()) {
          events[date] = event;
      }
  }
  bool DeleteEvent(const Date& date, const string& event) {
      if (events.count(date) == 0) {
          return false;
      } else {
          events.erase(date);
          return true;
      }
  }
  int  DeleteDate(const Date& date) {
      int result = 0;
      if (events.count(date) > 0) {
          events.erase(date);
          result++;
      }
      for (auto& item : events) {
          Date tempDate(item.first.GetYear(), item.first.GetMonth(),
                        item.first.GetDay());
          if (tempDate < date) {
              events.erase(tempDate);
              result++;
          }
          else {
              return result;
          }
      }
      return result;
  }

set <string> Find(const Date& date) const {
    set <string> allEvents;
    for (auto& item : events) {
        Date tempDate(item.first.GetYear(), item.first.GetMonth(),
                      item.first.GetDay());
        if (date < tempDate) {
            return allEvents;
        }
        else {
            allEvents.insert(item.second);
        }
    }
    return allEvents;
  }
  
  void Print() const {
      for (const auto& item : events) {
          cout << setfill('0') << setw(4) << item.first.GetYear() << "-"
               << setfill('0') << setw(2) << item.first.GetMonth() << "-"
               << setfill('0') << setw(2) << item.first.GetDay() << "-"
               << item.second << endl;
      }
  }

private:
    map<Date, string> events;
};

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
      stringstream stream(command);
      stringstream copyStream(command);
      string musor;
      getline(copyStream, musor, ' ');
      if (command.size() == 0) {
          continue;
      }
      int year;
      int month;
      int day;
      string event = "";
      string request;
      stream >> request;
      stream.ignore(1);
      try {
          if (request == "Add") {
              string error;
              int count = 0;
              getline(copyStream, error, ' ');
              if (stream.peek() < '0' || stream.peek() > '9') {
                  count++;
              }
              stream >> year;
              if (stream.peek() != '-') {
                  count++;
              }
              stream.ignore(1);
              stream >> month;
              if (stream.peek() != '-') {
                  count++;
              }
              stream.ignore(1);
              stream >> day;
              if (stream.peek() != ' ') {
                  count++;
              }
              if (count != 0) {
                  throw invalid_argument("Wrong date format: " + error);
              }
              Date date(year, month, day);
              stream.ignore(1);
              stream >> event;
              db.AddEvent(date, event);
          }
          else if (request == "Print") {
              db.Print();
          }
          else if (request == "Del") {
              string error;
              int count = 0;
              getline(copyStream, error, ' ');
              if (stream.peek() < '0' || stream.peek() > '9') {
                  count++;
              }
              stream >> year;
              if (stream.peek() != '-') {
                  count++;
              }
              stream.ignore(1);
              stream >> month;
              if (stream.peek() != '-') {
                  count++;
              }
              stream.ignore(1);
              stream >> day;
              if (count != 0) {
                  throw invalid_argument("Wrong date format: " + error);
              }
              Date date(year, month, day);
              stream.ignore(1);
              stream >> event;
              if (event.size() != 0) {
                  if (db.DeleteEvent(date, event)) {
                      cout << "Deleted successfully" << endl;
                  }
                  else {
                      cout << "Event not found" << endl;
                  }
              }
              else {
                  cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
              }
          }
          else if (request == "Find") {
              string error;
              int count = 0;
              getline(copyStream, error, ' ');
              if (stream.peek() < '0' || stream.peek() > '9') {
                  count++;
              }
              stream >> year;
              if (stream.peek() != '-') {
                  count++;
              }
              stream.ignore(1);
              stream >> month;
              if (stream.peek() != '-') {
                  count++;
              }
              stream.ignore(1);
              stream >> day;
              if (count != 0) {
                  throw invalid_argument("Wrong date format: " + error);
              }
              Date date(year, month, day);
              set <string> result;
              result = db.Find(date);
              for (auto s : result) {
                  cout << s << endl;
              }
          }
          else {
              throw invalid_argument("Unknown command: " + request);
          }

      }
      catch (invalid_argument& error) {
          cout << error.what();
          break;
      }
  }

  return 0;
}