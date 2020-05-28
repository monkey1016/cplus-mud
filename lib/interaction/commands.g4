/**
 * Basic grammar for parsing some simple commands
 */
grammar commands;
startRule : command EOF;

direction: DirEast
  | DirWest
  | DirNorth
  | DirSouth
  | DirNortheast
  | DirNorthwest
  | DirSoutheast
  | DirSouthwest
  | DirUp
  | DirDown
  | DirOut
  | DirIn;

cmdMoveDirection: CmdMovement direction;
cmdEnterBuilding: CmdEnter Building | CmdMovement DirIn;
playerHealth: Health;
entityHealth: Health Entity;

command: cmdMoveDirection | cmdEnterBuilding | playerHealth | entityHealth;

// Movement
CmdMovement: 'go' | 'move' | 'mv' | 'g';
CmdEnter: 'enter' | 'en';

// Direction
DirEast: 'east' | 'e';
DirWest: 'west' | 'w';
DirNorth: 'north' | 'n';
DirSouth: 'south' | 's';
DirSouthwest: 'southwest' | 'sw';
DirNorthwest: 'northwest' | 'nw';
DirNortheast: 'northeast' | 'ne';
DirSoutheast: 'southeast' | 'se';
DirIn: 'inside' | 'in';
DirOut: 'outside' | 'out';
DirUp: 'up' | 'u';
DirDown: 'down' | 'd';

//Interaction
Get: 'get' | 'pickup' | 'pick';

Entity: [A-Za-z]+;

Health: 'health';

// Items

// Structures
Building: 'building';
//WHITESPACE: [ \n\t\r]+ -> skip;
Whitespace: (' ')+ -> skip;


// direction: DIREAST | DIRWEST
//   | DIRNORTH| DIRSOUTH
//   | DIRSOUTHWEST | DIRNORTHWEST
//   | DIRNORTHEAST | DIRSOUTHEAST
//   | DIRIN | DIRUP | DIRDOWN;

// Parser
