#include <iostream>
#include <cstring>
using namespace std;

// --------- 1. Define Date and AttendanceRec Structs ---------
struct Date {
    int day, month, year;
};

struct AttendanceRec {
    char studentID[10];
    Date* date;
    bool present;
};

// --------- 2. Abstract Class ReportBase ---------
class ReportBase {
public:
    virtual void generate(const AttendanceRec* recs, int n) = 0;
    virtual ~ReportBase() {}
};

// --------- 3. DailyReport Class: Counts Total Present ---------
class DailyReport : public ReportBase {
public:
    void generate(const AttendanceRec* recs, int n) override {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if ((recs + i)->present)
                ++count;
        }
        cout << "Daily Report: " << count << " students were present.\n";
    }
};

// --------- 4. MonthlyTrendReport Class: Detects Presence Trends by Day ---------
class MonthlyTrendReport : public ReportBase {
public:
    void generate(const AttendanceRec* recs, int n) override {
        int days[31] = {0}; // Track days 1–31

        for (int i = 0; i < n; ++i) {
            const AttendanceRec* rec = recs + i;
            if (rec->present && rec->date->day >= 1 && rec->date->day <= 31)
                days[rec->date->day - 1]++;
        }

        cout << "Monthly Trend Report:\n";
        for (int i = 0; i < 31; ++i) {
            if (days[i] > 0)
                cout << "  Day " << (i + 1) << ": " << days[i] << " present\n";
        }
    }
};

// --------- 5. Add and Remove Record Functions ---------
void addRecord(AttendanceRec*& recs, int& size, const AttendanceRec& newRec) {
    AttendanceRec* newArr = new AttendanceRec[size + 1];
    for (int i = 0; i < size; ++i)
        newArr[i] = recs[i];

    newArr[size] = newRec;
    recs = newArr;
    ++size;
}

void removeRecord(AttendanceRec*& recs, int& size, int index) {
    if (index < 0 || index >= size) return;

    AttendanceRec* newArr = new AttendanceRec[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index)
            newArr[j++] = recs[i];
    }
    delete[] recs;
    recs = newArr;
    --size;
}

// --------- 6. Main Program ---------
int main() {
    int size = 0;
    AttendanceRec* recs = NULL;

    // Create sample dates
    Date* d1 = new Date{1, 6, 2025};
    Date* d2 = new Date{1, 6, 2025};
    Date* d3 = new Date{2, 6, 2025};
    Date* d4 = new Date{3, 6, 2025};

    // Create attendance records
    AttendanceRec r1 = {"ST001", d1, true};
    AttendanceRec r2 = {"ST002", d2, false};
    AttendanceRec r3 = {"ST003", d3, true};
    AttendanceRec r4 = {"ST004", d4, true};

    // Add records
    addRecord(recs, size, r1);
    addRecord(recs, size, r2);
    addRecord(recs, size, r3);
    addRecord(recs, size, r4);

    // Create report objects
    ReportBase** reports = new ReportBase*[2];
    reports[0] = new DailyReport();
    reports[1] = new MonthlyTrendReport();

    // Generate reports using polymorphism
    for (int i = 0; i < 2; ++i) {
        reports[i]->generate(recs, size);
        cout << endl;
    }

    // Cleanup
    for (int i = 0; i < size; ++i)
        delete recs[i].date;
    delete[] recs;

    for (int i = 0; i < 2; ++i)
        delete reports[i];
    delete[] reports;

    return 0;
}

