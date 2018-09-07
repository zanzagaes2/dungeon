#include <climits>
#include <iostream>
#include <string>

// Dimensions of the board.
static struct {
  int Xdimension = 10;
  int Ydimension = 5;
} board;

// Player coordinates.. They change each time the character moves.
// It holds that: 0 <= Player.Xdimension <= board.Xdimension
// 		  0 <= Player.Ydimension <= board.Ydimension
struct Player {
  int Xdimension;
  int Ydimension;
};

// Possible directions. WRONG_DIRECTION is used to report incorrect input
enum Direction { RIGHT, LEFT, TOP, BOTTOM, WRONG_DIRECTION };

Direction askDirection();
void movePlayer(Player &, Direction);
void drawBoard(Player);

int main() {
  Player alvaro;
  alvaro.Xdimension = 0;
  alvaro.Ydimension = 2;

  int turnos = INT_MAX; // Number of turns
  for (int i = 0; i <= turnos; i++) {
    drawBoard(alvaro);
    Direction direction;
    do {
      direction = askDirection();
      std::cout << std::endl;
    } while (direction == WRONG_DIRECTION);
    movePlayer(alvaro, direction); // Changes position of the player
    std::cout << "\x1B[2J\x1B[H";  // Resets terminal after printing.
  }
}

Direction askDirection() {

  // Asks the user to input a direction and returns it.
  // Precondition: -
  // Poscondition:
  // Return: a Direction value containing the direction chosen or
  // WRONG_DIRECTION.

  std::cout << "Select [L]eft, [R]ight, [T]op or [B]ottom: ";
  char answer;
  std::cin.get(answer);

  Direction chosenDirection;
  switch (std::toupper(answer)) {
  case 'L':
    chosenDirection = LEFT;
    break;
  case 'R':
    chosenDirection = RIGHT;
    break;
  case 'T':
    chosenDirection = TOP;
    break;
  case 'B':
    chosenDirection = BOTTOM;
    break;
  default:
    chosenDirection = WRONG_DIRECTION;
  }
  return chosenDirection;
}

void movePlayer(
    /* inout */ Player &player,   // Player of the game
    /* in */ Direction direction) // Direction previously chosen.
                                  // It is represented by a Direction object,
                                  // different from WRONG_DIRECTION.

// Moves player in the chosen direction, by altering its coordinates. If the
// player would finish out of the board, no movement is made.

// Precondition: 0 <= Player.Xdimension <= board.Xdimension &&
//		  0 <= player.Ydimension <= board.Ydimension  &&
//		  board.Xdimension > 0 	&& board.Ydimension > 0 &&
//		  direction in {LEFT; RIGHT; TOP; BOTTOM} &&
// Postcondition: player coordinates have been altered &&
//		  player remains inside the board.
{
  switch (direction) {
  case RIGHT:
    if (player.Xdimension < board.Xdimension)
      player.Xdimension += 1;
    break;
  case LEFT:
    if (player.Xdimension > 0)
      player.Xdimension -= 1;
    break;
  case TOP:
    if (player.Ydimension > 0)
      player.Ydimension -= 1;
    break;
  case BOTTOM:
    if (player.Ydimension < board.Ydimension)
      player.Ydimension += 1;
    break;
  }
}

void drawBoard(
    /* in */ Player player) // The player. Its coordinates are drawn in the map.

// Draws a (board.Xdimension * board.Ydimension) grid.
// "." represents blank spaces &&
// "P" represents the player

// Precondition: 0 <= Player.Xdimension <= board.Xdimension &&
//		  0 <= player.Ydimension <= board.Ydimension  &&
//		  board.Xdimension > 0 	&& board.Ydimension > 0 &&
// Postcondition: The grid has been drawn.
{
  for (int i = 0; i <= board.Ydimension; i++) {
    for (int j = 0; j <= board.Xdimension; j++) {
      if (j == player.Xdimension && i == player.Ydimension) {
        std::cout << "P";
        continue;
      }

      std::cout << ".";
    }
    std::cout << std::endl;
  }
}
