/*********** File: main.c *****************************************************/
/*  Purpose: Defines main() to Provide an Interactive Prompt for Manipulating */
/*            a HashString                                                    */
/*                                                                            */
/*  Author: jedi453                                                           */
/******************************************************************************/


#include <stdio.h>    /* printf(), fprintf(), stderr, fgets(), stdin, FILE */
#include <stdlib.h>   /* strtol() */
#include <string.h>   /* strlen() */

#include "HashString.h" /* HashString and HashString_* Functions */


#define HASH_STRING_SIZE 32 /* The Table Length of the HashString to Create */

#define MAX_KEY_LEN 10    /* Maximum Length to Allow CLI Entered Key to Be */
#define MAX_VALUE_LEN 100 /* Maximum Length to Allow CLI Entered Value to Be */
#define MENU_BUFFER_LEN 10  /* Maximum Length for Buffer for Menu CLI Input */


/* Menu Options */
#define OP_INVALID  0 /* Invalid Option, Corresponds to strtol() Invalid*/
#define OP_PRINT    1 /* Print HashString */
#define OP_FIND     2 /* Find Key in HashString */
#define OP_ADD      3 /* Add Key, Value to HashString */
#define OP_REMOVE   4 /* Remove Entry with Given Key from HashString */
#define OP_QUIT     5 /* Quit from Menu */


/** @fn void fgetln( char* str, int len, FILE* fp )
 *  
 *  @brief fgets() then Remove Trailing Newline
 *
 *  Reads from FILE* fp Either a Full Line or Up to len chars,
 *  whichever comes first. If a New Line '\n' Was Read, Removes it.
 *  Can be used to get a Full Line of Input from stdin:
 *    fgetln( str, STR_LEN, stdin );
 *
 *  @param[out] str char* to String to Output to
 *  @param[in] len int, the Maximum String Length to Read, Including '\0' Terminator
 *  @param[in] fp FILE* to the File to Read Line From
 */
void fgetln( char* str, int len, FILE* fp )
{
  int i;
  fgets( str, len, fp );
  i = strlen(str)-1;
  if ( str[i] == '\n' ) str[i] = '\0';
}

/** @fn int main( int argc, char** argv )
 *
 *  @brief Provides an Interactive Prompt for Manipulating a HashString
 *
 *  Provides a Basic CLI Interface for Manipulating and Interacting 
 *  with a HashString.
 *  
 *  @return int, Exit Status
 *  @returns 0 - Upon Success
 *  @returns non-zero - Upon Failure
 */
int main( int argc, char** argv )
{
  char keyBuffer[MAX_KEY_LEN+2];      /**< Buffer for Key Input */
  char valueBuffer[MAX_VALUE_LEN+2];  /**< Buffer for Value Input */
  char menuBuffer[MENU_BUFFER_LEN+2]; /**< Buffer for Menu Input */
  HashString* hs;                     /**< HashString to Manipulate */
  HashStringEntry* entry = NULL;             /**< Entry within HashString hs */
  int option = OP_INVALID;            /**< Chosen Option from Menu */
  int keepGoing = 1;                  /**< Continue Running While True */
  int i;
  
  hs = HashString_create( HASH_STRING_SIZE );

  printf("Welcome to the Interactive Hash Table Manipulator!\n\n");

  printf("Menu Options:\n");
  printf(" %d) Print Hash of String\n", OP_PRINT);
  printf(" %d) Find Key in Hash of String\n", OP_FIND);
  printf(" %d) Add Key, Value Pair to Hash of String\n", OP_ADD);
  printf(" %d) Remove Entry with Given Key from Hash of String\n", OP_REMOVE);
  printf(" %d) Exit Menu\n", OP_QUIT);

  printf("\n");

  do
  {
    /* Prompt for + Get Menu Option */
    printf("Options: %d - print, %d - Find, %d - Add, %d - Remove, %d - Quit\n",
      OP_PRINT, OP_FIND, OP_ADD, OP_REMOVE, OP_QUIT);
    printf("Please Enter an Option:  ");
    fgetln( menuBuffer, MENU_BUFFER_LEN+1, stdin );
    option = strtol( menuBuffer, NULL, 10 );
    
    /* Perform Desired Option */
    switch ( option )
    {
      case OP_INVALID:
        /* Remove \n from menuBuffer, print Error */
        fprintf(stderr, "Invalid Option: \"%s\"\n", menuBuffer );
        break;
      case OP_PRINT:  /// TODO
        printf("Printing Hash Table:\n");
        printf(" KEY        |     VALUE\n");
        HASH_STRING_ITER( hs, entry, i )
          printf(" %10s | %-20s\n", entry->key, entry->value);
        break;
      case OP_FIND:
        printf("Finding Entry with Given Key:\n");
        printf(" Enter Key:\n  ");
        fgetln( keyBuffer, MAX_KEY_LEN+1, stdin );
        entry = HashString_find( hs, keyBuffer );
        if ( entry != NULL )
        {
          printf(" Entry Found:\n");
          printf(" Key        |    Value\n");
          printf(" %10s | %-20s\n", entry->key, entry->value);
        }
        else
          printf(" Entry Not Found.");
        break;
      case OP_ADD:
        printf("Adding Given Key, Value to Hash Table:\n");
        /* Prompt for, get Key, value */
        printf(" Enter the Key:  ");
        fgetln( keyBuffer, MAX_KEY_LEN+1, stdin );
        printf(" Enter the Value:\n  ");
        fgetln( valueBuffer, MAX_VALUE_LEN+1, stdin );
        switch (HashString_add( hs, keyBuffer, valueBuffer ))
        {
          case 0:
            printf(" Entry Added!\n");
            break;
          case 1:
            printf(" Key Already Exists, Nothing Added!\n");
            break;
          default:
            printf(" Error Adding Key, Value Pair!\n");
        }
        break;
      case OP_REMOVE:
        printf("Removing Entry:\n");
        printf(" Enter the Key to Remove: ");
        fgetln( keyBuffer, MAX_KEY_LEN+1, stdin );
        if ( HashString_remove( hs, keyBuffer ) )
          printf(" Entry Not Found.\n");
        else
          printf(" Entry Removed.\n");
        break;
      case OP_QUIT:
        keepGoing = 0;
        break;
      default:
        /* Print Error */
        fprintf(stderr, "Invalid Option: \"%s\"\n", menuBuffer );
    };

    printf("\n\n");
  } while ( keepGoing ); /* Menu Loop */
  

  HashString_destroy( hs );
  return 0;
}
