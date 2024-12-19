#include "include/password_generator.h"

char *generate_password() {
  srand(time(NULL) + clock());

  int num_positions[] = {5, 7, 12, 14, 19};
  int cap_let_positions[] = {0,  1,  2,  3,  4,  5,  7,  8,  9,
                             10, 11, 12, 14, 15, 16, 17, 18, 19};

  int num_pos = rand() % 5;
  int cap_pos = rand() % 18;

  if (num_positions[num_pos] == cap_let_positions[cap_pos])
    cap_pos++;

  char *pass = malloc(PASSWORD_LENGTH * sizeof(char));

  int j = 0;
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    if (i == 6 || i == 13) {
      pass[i] = SEPARATOR;
      j = 0;
    } else if (i == num_positions[num_pos]) {
      pass[i] = NUMBERS[rand() % NUMBERS_LENGTH];
    } else if (j == 1 || j == 4) {
      pass[i] = VOWELS[rand() % VOWELS_LENGTH];
      j++;
    } else {
      pass[i] = CONSONANTS[rand() % CONSONANTS_LENGTH];
      j++;
    }
  }

  pass[cap_pos] = toupper(pass[cap_pos]);

  pass[PASSWORD_LENGTH] = '\0';

  return pass;
}
