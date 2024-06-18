/*
Composite Pattern:
- **Component**: Declares the common operations for both simple and complex
objects
- **Composite**: Represent complex objects that may **have children**.
(Implements the `Component` interface and defines behaviors for `adding`,
`removing`, and `accessing` child components)
- **Leaf**: A class representing leaf objects, which have **no children**.
*/
#include <iostream>
#include <string>
#include <vector>

class FileSystemComponent {
public:
  virtual ~FileSystemComponent() {}
  virtual void showDetails() const = 0;
};

class Directory : public FileSystemComponent {
private:
  std::string name;
  std::vector<FileSystemComponent *> children;

public:
  Directory(const std::string &name) : name(name) {}
  ~Directory() {
    for (auto child : children) {
      delete child;
    }
  }

  void add(FileSystemComponent *component) { children.push_back(component); }

  void remove(FileSystemComponent *component) {
    children.erase(std::remove(children.begin(), children.end(), component),
                   children.end());
  }

  void showDetails() const override {
    std::cout << "Directory: " << name << std::endl;
    for (const auto &child : children) {
      child->showDetails();
    }
  }
};

class File : public FileSystemComponent {
private:
  std::string name;

public:
  File(const std::string &name) : name(name) {}
  void showDetails() const override {
    std::cout << "File: " << name << std::endl;
  }
};

int main() {
  FileSystemComponent *file1 = new File("File1.txt");
  FileSystemComponent *file2 = new File("File2.txt");
  FileSystemComponent *file3 = new File("File3.txt");

  Directory *dir1 = new Directory("Dir1");
  Directory *dir2 = new Directory("Dir2");

  dir1->add(file1);
  dir1->add(file2);

  dir2->add(file3);
  dir2->add(dir1);

  dir2->showDetails();

  delete dir2;
  return 0;
}