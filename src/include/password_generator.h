#pragma once

#define PASSWORD_LENGTH 20

struct password {
    char data[PASSWORD_LENGTH + 1]; 
} typedef password_t;

password_t generate_password();