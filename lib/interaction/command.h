#ifndef CLASS_COMMAND
#define CLASS_COMMAND
#include <string>
#include <map>

using namespace std;

class Command {
};

class MovementCommand : public Command {
  private:
    string direction;
  public:
    MovementCommand(string direction);
    string getDirection();
};

#endif