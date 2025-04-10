#include "include/password_generator.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOWELS "aeiouy"
#define VOWELS_LENGTH 5

#define CONSONANTS "bcdfghjklmnqprstvwzx"
#define CONSONANTS_LENGTH 20

#define NUMBERS "0123456789"
#define NUMBERS_LENGTH 10

#define SEPARATOR '-'

password_t generate_password() {
  
  srand(time(NULL) + clock());

  int num_positions[] = {5, 7, 12, 14, 19};
  int cap_let_positions[] = {0,  1,  2,  3,  4,  5,  7,  8,  9,
                             10, 11, 12, 14, 15, 16, 17, 18, 19};

  int num_pos = rand() % 5;
  int cap_pos = rand() % 18;

  if (num_positions[num_pos] == cap_let_positions[cap_pos])
    cap_pos++;

  password_t password;

  int j = 0;
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    if (i == 6 || i == 13) {
      password.data[i] = SEPARATOR;
      j = 0;
    } else if (i == num_positions[num_pos]) {
      password.data[i] = NUMBERS[rand() % NUMBERS_LENGTH];
    } else if (j == 1 || j == 4) {
      password.data[i] = VOWELS[rand() % VOWELS_LENGTH];
      j++;
    } else {
      password.data[i] = CONSONANTS[rand() % CONSONANTS_LENGTH];
      j++;
    }
  }

  password.data[cap_pos] = toupper(password.data[cap_pos]);

  password.data[PASSWORD_LENGTH] = '\0';

  return password;
}
