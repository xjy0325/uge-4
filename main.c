#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Declare Constant
const int GameChance = 7;

// Long Opening
int WelcomeMessage(void) {
  puts("Welcome to 🪨  ✂️  🗒️  🖖  🦎 !\n");
  puts("(s) Single player\n(e) Exit\n");
  puts("Select an item:");
  return 0;
}

// Game Part
void Game() {
  // prompt
  puts("Select a shape:\n0🪨  || 1🦎  || 2✂️  || 3🗒️  || 4🖖 :");

  // declare variables
  int PlayerCounter = 0, AgentCounter = 0;
  int GameInput = 0, digit = 0;

  do {
    // readin and deal with input
    GameInput = getchar();
    if (GameInput == EOF) {
      puts("EOF.");
    }
    while (getchar() != '\n')
      ;
    digit = GameInput - '0';
    // deal with invalid GameInput
    while (digit < 0 || digit > 4) {
      printf("❌ Shape key %d does not exist.Try again.\n", digit);
      GameInput = getchar();
      while (getchar() != '\n')
        ;
      digit = GameInput - '0';
    }

    // generate random move from computer
    srand(time(NULL));
    int destiny = rand() % 4;
    printf("Agent: %d\n", destiny);

    // comparison
    int comparison = digit - destiny;
    if (comparison == 0) {
    } else if (comparison == -4 || comparison == -2 || comparison == 1 ||
               comparison == 3) {
      PlayerCounter++;
    } else {
      AgentCounter++;
    }

    // output score
    printf("👫\t vs 🤖\t\n%d\t%d\t\n", PlayerCounter, AgentCounter);
  } while (PlayerCounter < 7 && AgentCounter < 7);

  // output winner
  if (PlayerCounter < AgentCounter) {
    puts("🤖 Agent won !");
  } else {
    puts("🤖 Player won !");
  }
}

// Main Menu
int main() {
  WelcomeMessage();
  // readin 1st user input
  int input = getchar();

  // examinate input and deal with buffer
  if (input == EOF) {
    puts("EOF.\n");
    return 0;
  }
  while (getchar() != '\n')
    ;

  // deal with input
  while (1)
    switch (input) {
    case 's':
      puts("Starting game 🎉");
      Game();
      return 0;

    case 'e':
      puts("EXIT GAME");
      return 0;

    // other incalid input
    default:
      puts("Invalid input. Please enter again:");
      input = getchar();
      while (getchar() != '\n')
        ;
      break;
    }

  return 0;
}
