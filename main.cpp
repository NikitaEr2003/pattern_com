
#include <iostream>
#include <fstream>
class LogCommand {
 public:
  virtual ~LogCommand() = default;
  virtual void print(const std::string& message) = 0;
};

class LogConsole: public LogCommand {

    public:
    void print(const std::string& message) override {

        std::cout << message << std::endl;
    }

};


class LogFile : public LogCommand {

    std::string path_;

 public:
    LogFile(const std::string & path) : path_(path) {}

  
    void print(const std::string& message) override {
      
        std::ofstream _file(path_);

        if (_file.is_open()) {
        _file << message << std::endl;
        _file.close();
         
        } else {
          std::cout << "File is not open\n";
        }
    }

};

void print(LogCommand& com_, const std::string message) { 
    com_.print(message);
}

int main() { 

    LogConsole obj;
    print(obj, "Hello");
    LogFile obj1("text.txt");
    print(obj1, "Hello");

}
