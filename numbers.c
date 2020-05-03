#include <stdio.h>
#include "list.h"

#define NEW_LINE printf("\n");
#define ASK_VALUE "Enter a value"
#define ASK_POS "Enter a position"

void done(void)
{
  printf("Done\n\n");
}
void pos_not_found(void)
{
  printf("Position not found\n\n");
}
void not_unique(void)
{
  printf("Given value is not added because it's not unique\n\n");
}
void number_exists(void)
{
  printf("Given number exists in the list\n\n");
}
void number_not_exists(void)
{
  printf("Given number does not exists in the list\n\n");
}

void print_menu(void);
char get_command(void);
int get_value(char *);
void execute_command(char, List_ptr);

void print_menu(void)
{
  printf("Main Menu\n");
  NEW_LINE;
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
  NEW_LINE
}

char get_command(void)
{
  print_menu();
  printf("Please enter the alphabet of the operation you would like to perform: ");
  char command;
  scanf(" %c", &command);
  NEW_LINE;
  return command;
}

int get_value(char *message)
{
  int value;
  printf("%s: ", message);
  scanf("%d", &value);
  NEW_LINE;
  return value;
}

void execute_command(char command, List_ptr list)
{
  Status result;
  switch (command)
  {
  case 'a':
    result = add_to_end(list, get_value(ASK_VALUE));
    done();
    break;
  case 'b':
    result = add_to_start(list, get_value(ASK_VALUE));
    done();
    break;
  case 'c':
    result = insert_at(list, get_value(ASK_VALUE), get_value(ASK_POS));
    if (result == Success)
      done();
    else
      pos_not_found();
    break;
  case 'd':
    result = add_unique(list, get_value(ASK_VALUE));
    if (result == Success)
      done();
    else
      not_unique();
    break;
  case 'e':
    result = remove_from_start(list);
    if (result == Success)
      done();
    else
      pos_not_found();
    break;
  case 'f':
    result = remove_from_end(list);
    if (result == Success)
      done();
    else
      pos_not_found();
    break;
  case 'g':
    result = remove_at(list, get_value(ASK_POS));
    if (result == Success)
      done();
    else
      pos_not_found();
    break;
  case 'h':
    result = remove_first_occurrence(list, get_value(ASK_VALUE));
    if (result == Success)
      done();
    else
      number_not_exists();
    break;
  case 'i':
    result = remove_all_occurrences(list, get_value(ASK_VALUE));
    if (result == Success)
      done();
    else
      number_not_exists();
    break;
  case 'j':
    result = clear_list(list);
    done();
    break;
  case 'k':
    result = is_number_available(list, get_value(ASK_VALUE));
    if (result == Success)
      number_exists();
    else
      number_not_exists();
    break;
  case 'l':
    display(list);
    NEW_LINE;
    break;
  default:
    printf("Please enter a valid command\n\n");
    break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  char command = get_command();
  while (command != 'm')
  {
    execute_command(command, list);
    command = get_command();
  }
  destroy_list(list);
  printf("Program exited");
  return 0;
}