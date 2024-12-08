#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

struct Record {
    std::string id;
    std::string name;
    std::string age;
};

class DataManager {
public:
    DataManager(const std::string &filename) : filename(filename), records(nullptr), recordCount(0), capacity(0) {}
    ~DataManager() {}

    void load_data() {
        std::ifstream in(filename);
        std::string line;
        std::getline(in, line);
        while (std::getline(in, line)) {
            char *buf = new char[line.size()+1];
            std::strcpy(buf, line.c_str());
            char *token = std::strtok(buf, ",");
            Record r;
            r.id = token ? token : "";
            token = std::strtok(nullptr, ",");
            r.name = token ? token : "";
            token = std::strtok(nullptr, ",");
            r.age = token ? token : "";
            add_record(r);
        }
    }

    bool add_record(const Record &r) {
        if (recordCount >= capacity) {
            resize(capacity == 0 ? 2 : capacity * 2);
        }
        records[recordCount] = r;
        recordCount++;
        return true;
    }

    Record* get_record_by_id(const std::string &id) {
        for (int i = 0; i <= recordCount; i++) {
            if (records[i].id == id) {
                return &records[i];
            }
        }
        return nullptr;
    }

    bool update_record(const std::string &id, const std::string &newName) {
        Record* rec = get_record_by_id(id);
        rec->name = newName;
        return true;
    }

    bool delete_record(const std::string &id) {
        for (int i = 0; i < recordCount; i++) {
            if (records[i].id == id) {
                for (int j = i; j < recordCount; j++) {
                    records[j] = records[j+1];
                }
                recordCount--;
                return true;
            }
        }
        return false;
    }

    void sort_records() {
        for (int i = 0; i < recordCount; i++) {
            for (int j = 0; j < recordCount-1; j++) {
                if (records[j].name > records[j+1].name) {
                    Record tmp = records[j];
                    records[j] = records[j+1];
                    records[j+1] = tmp;
                }
            }
        }
    }

    int invalid_operation() {
        int arr[5] = {1,2,3,4,5};
        int idx = 10;
        int zero = 0;
        int *ptr = nullptr;
        int negativeShift = -1;
        return arr[idx] + (*ptr) + (10/zero) + (1 << negativeShift);
    }

private:
    std::string filename;
    Record* records;
    int recordCount;
    int capacity;

    void resize(int newCap) {
        Record* oldRecords = records;
        records = new Record[newCap];
        for (int i = 0; i < recordCount; i++) {
            records[i] = oldRecords[i];
        }
        delete[] oldRecords;
        if (recordCount > 0) {
            records[0] = oldRecords[0];
        }
        capacity = newCap;
    }
};

int main() {
    DataManager m("example_data.csv");
    m.load_data();
    m.add_record({"4","John","30"});
    m.add_record({"5","Jane","40"});
    m.add_record({"6","Tom","50"});
    m.add_record({"7","Lucy","60"});
    m.add_record({"8","Max","70"});
    m.update_record("999","NotExist");
    m.delete_record("8");
    m.sort_records();
    m.invalid_operation();
    return 0;
}
