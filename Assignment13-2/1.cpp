#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class FileSystemException {
  string message;

  public:
    FileSystemException(const string& msg) : message(msg) {}
    void print() const {
      cerr << message << endl;
    }
};

class Directory;

class FileSystemObject {
  protected:
    string name;
    weak_ptr<Directory> parent;

  public:
    FileSystemObject(const string& name) : name(name) {}
    virtual ~FileSystemObject() = default;
    virtual void display(int indentLevel) const = 0;
    virtual bool isDirectory() const = 0;
    string getName() const {
      return name;
    }
    void setParent(const weak_ptr<Directory>& parentDir) {
      parent = parentDir;
    }
};

class File : public FileSystemObject {
  int size;

  public:
    File(const string& name, int size) : FileSystemObject(name), size(size) {}
    void display(int indentLevel) const {
      cout << string(indentLevel, ' ') << "File: " << name << " (" << size << " bytes)" << endl;
    }
    bool isDirectory() const {
      return false;
    }
};

class Directory : public FileSystemObject {
  vector<shared_ptr<FileSystemObject>> contents;

  public:
    Directory(const string& name) : FileSystemObject(name) {}
    void add(const shared_ptr<FileSystemObject>& obj, const shared_ptr<Directory>& self) {
      for (const auto& item : contents) {
        if (item->getName() == obj->getName()) {
          throw FileSystemException("Cannot add '" + obj->getName() + "': Duplicate name");
        }
      }
      obj->setParent(self);
      contents.push_back(obj);
    }
    void remove(const string& name) {
      auto it = find_if(contents.begin(), contents.end(), [&name](const shared_ptr<FileSystemObject>& obj) {
        return obj->getName() == name;
      });
      if (it == contents.end()) {
        throw FileSystemException("Cannot remove '" + name + "': File or directory not found.");
      }
      contents.erase(it);
    }
    void display(int indentLevel) const {
      cout << string(indentLevel, ' ') << "Directory: " << name << endl;
      for (const auto& item : contents) {
        item->display(indentLevel + 2);
      }
    }
    bool isDirectory() const {
      return true;
    }
    shared_ptr<FileSystemObject> find(const string& name) {
      for (const auto& item : contents) {
        if (item->getName() == name) {
          return item;
        }
        if (item->isDirectory()) {
          auto dir = dynamic_pointer_cast<Directory>(item);
          auto found = dir->find(name);
          if (found) {
            return found;
          }
        }
      }
      return nullptr;
    }
};

int main() {
  try {
    // Create root directory
    std::shared_ptr<Directory> root(new Directory("root"));
    // Add files to root
    root->add(std::shared_ptr<File>(new File("file1.txt", 100)), root);
    root->add(std::shared_ptr<File>(new File("file2.txt", 200)), root);
    // Add subdirectory to root
    std::shared_ptr<Directory> subDir(new Directory("subdir"));
    root->add(subDir, root);
    // Add files to subdirectory
    subDir->add(std::shared_ptr<File>(new File("file3.txt", 300)), subDir);
    // Display file system
    std::cout << "File system structure:\n";
    root->display(0);
    // Attempt to add a duplicate file to root (should throw exception)
    try {
      root->add(std::shared_ptr<File>(new File("file1.txt", 150)), root);
    }
    catch (const FileSystemException& e) {
      e.print();
    }
    // Attempt to add a duplicate directory to root (should throw exception)
    try {
      root->add(std::shared_ptr<Directory>(new Directory("subdir")), root);
    }
    catch (const FileSystemException& e) {
      e.print();
    }
    // Attempt to remove a non-existent file (should throw exception)
    try {
      root->remove("nonexistent.txt");
    }
    catch (const FileSystemException& e) {
      e.print();
    }
    // Remove a file
    root->remove("file1.txt");
    // Remove a subdirectory
    root->remove("subdir");
    // Display file system after removals
    std::cout << "\nFile system after removals:\n";
    root->display(0);
    // Attempt to display a removed directory (should not find it)
    std::shared_ptr<FileSystemObject> removedDir = root->find("subdir");
    if (!removedDir) {
      std::cout << "\nSubdirectory 'subdir' not found after removal." << std::endl;
    }
  }
  catch (const FileSystemException& e) {
    e.print();
  }
  return 0;
}
