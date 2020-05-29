#include <iostream>
#include <string>
#include "lib/geo/areas/base_area.h"
#include "antlr4-runtime.h"
// #include "lib/interaction/commands.h"
#include "commandsLexer.h"
#include "commandsParser.h"
#include "commandsBaseListener.h"
#include "lib/entity/player_entity.hpp"
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators

// #include "lib/interaction/command.h"
// #include "lib/interaction/scanner.h"
// #include "lib/interaction/commands-gen.tab.hpp"
// #include "lib/interaction/driver.hpp"


using namespace std;
using namespace commands;
void setupGame();

class commandsTreeShapeListener : public commandsBaseListener 
{
  public:
    void enterCommand(commandsParser::CommandContext *ctx) override
    {
      cout << "found command: " << ctx->toStringTree() << endl;
    }
};

// class  SceneBaseVisitor : public Commands {
//   public:
//     virtual antlrcpp::Any visitFile(SceneParser::FileContext *ctx) override {
//         return visitChildren(ctx);
//     }
// }

int main(int argc, char* argv[]) {

  cout << "main" << endl;

  // std::ifstream stream;
  // stream.open(argv[1]);
  string commandInput;
  // while (getline(cin, commandInput))
  // {
  //   antlr4::ANTLRInputStream input(commandInput);
  //   commandsLexer lexer(&input);
  //   antlr4::CommonTokenStream tokens(&lexer);
  //   commandsParser parser(&tokens);

  //   // antlr4::tree::ParseTree *tree = parser.command();
  //   commandsParser::CommandContext* context = parser.command();
  //   commandsTreeShapeListener listener;
  //   antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, context);
  // }

  cout << "About to setup game" << endl;
  setupGame();
  return 0;
}

void setupGame()
{
  cout << "Starting game" << endl;
  boost::uuids::random_generator generator;
  boost::uuids::uuid player_uuid = generator();

  string playerName = "Player";
  string playerDescription = "The player";
  PlayerEntity* player = new PlayerEntity(player_uuid, nullptr, &playerName, &playerDescription, 0, 0);

  player->saveEntity();
}