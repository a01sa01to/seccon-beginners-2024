// Code Translation by Gemini

#include <stdio.h>
#include <string.h>

#define KEY_SIZE 50
#define FLAG_SIZE 70

int main()
{
  // Initialize key array
  int key[KEY_SIZE] = {119, 20, 96, 6, 50, 80, 43, 28, 117, 22, 125, 34, 21, 116, 23, 124, 35, 18, 35, 85, 56, 103, 14, 96, 20, 39, 85, 56, 93, 57, 8, 60, 72, 45, 114, 0, 101, 21, 103, 84, 39, 66, 44, 27, 122, 77, 36, 20, 122, 7};

  // Allocate memory for user input buffer, decrypted flag array, and integer variables
  char user_input_flag[FLAG_SIZE + 1];
  char decrypted_flag[FLAG_SIZE + 1];
  int correct_flag_length = 49;
  int decrypted_flag_index = 0;
  int decryption_error = 0;

  // Prompt user to enter flag
  printf("Input FLAG: ");

  // Read user input flag
  fgets(user_input_flag, FLAG_SIZE + 1, stdin);

  // Check flag length
  int flag_length = strlen(user_input_flag) - 1; // Remove newline character
  if (flag_length != correct_flag_length)
  {
    printf("Incorrect FLAG length.\n");
    decryption_error = 1;
    goto end;
  }

  // Decrypt flag (if flag length is correct)
  for (int i = 0; i < flag_length; i++)
  {
    decrypted_flag[i] = user_input_flag[i] ^ key[i];
  }

  // Check for null terminator (if flag is decrypted)
  if (decrypted_flag[flag_length - 1] != '\0')
  {
    printf("Incorrect FLAG.\n");
    decryption_error = 1;
    goto end;
  }

  // Print decrypted flag (if flag is valid)
  decrypted_flag[flag_length] = '\0'; // Add null terminator
  printf("Correct! FLAG is %s.\n", decrypted_flag);

end:
  // Return 0 (if flag is valid) or 1 (if there is an error)
  return decryption_error;
}
