/*********** File: HashString.h *********************************************************/
/*  Purpose: Declares HashString type to Store a Hash Table with String Keys and Values */
/*            Declares HashStringEntry to Store an Entry to a HashString and Point to   */
/*            the Next Entry                                                            */
/*            and Declares Functions for Use with HashString                            */
/*                                                                                      */
/*  Author: jedi453                                                                     */
/****************************************************************************************/



#ifndef _HASH_STRING_H
#define _HASH_STRING_H

/** @struct HashStringEntry
 *  @brief Holds an Entry in a Hash of Strings, Linked List
 *
 *  Type to Hold Hash Table Entry with String Key and Value and
 *  Point to Next Colliding ( Hash Collision ) Entry.
 *  Implemented as a Linked List Entry to Allow for Hash Collision Handling
 *
 */
struct HashStringEntry {
  char* key;    /* The Key String for this Table Entry */
  char* value;  /* The Value String for this Table Entry */
  struct HashStringEntry* next;   /* Pointer to the Next Colliding Entry ( Linked List ) */
};
typedef struct HashStringEntry HashStringEntry;


/** @struct HashString
 *  @brief Holds a Hash of String Keys and Values
 *  
 *  Type to Hold Hash Table Containing Keys and Values of type char*
 *  ( malloc'd strings ).
 *
 */
struct HashString{
  int size;   /**< The Size of the Hash Table ( Number of Unique Hash Values for Array Indecies ). */
  HashStringEntry** table;  /**< The Table of Entries ( malloc'd array of pointers to Linked List Nodes ) */
};
typedef struct HashString HashString;

/* HashString Functions */

/* Create a HashString Hash Table of Given Size */
HashString* HashString_create( int size );

/* Destroy HashString - Free all Memory Used by it and it's Entries */
void HashString_destroy( HashString* hash );

/* Hash Given String for Given Table ( Determine Array Index ) */
unsigned int HashString_hash( HashString* hash, unsigned char* key );

/* Find Entry with Given Key within Given HashString ( if any ) */
HashStringEntry* HashString_find( HashString* hash, char* key );

/* Add Entry with (copy of) Given Key, Value in Given Table */
int HashString_add( HashString* hash, char* key, char* value );

/* Removes Entry with Given Key From Given Table ( if any ) and free it's Memory */
int HashString_remove( HashString* hash, char* key );

/* Finds First Entry in Given HashString and Sets Given Pointers
 *  Towards it
 *  NOTE: Helper for HASH_STRING_ITER
 */
void HashString_firstEntry( HashString* hash, HashStringEntry** entry, int* i );


/* Finds Next Entry in Given HashString and Sets Given Pointers 
 *  to Point to it
 *  NOTE: Helper for HASH_STRING_ITER
 */
void HashString_nextEntry( HashString* hash, HashStringEntry** entry, int* i );

/** @macro HASH_STRING_ITER
 *
 *  @brief Iterates over All Entries in HashString like Loop
 *
 *  Iterates over all Entries in HashString Like a Loop
 *  Example: ( Prints Index, Key and Value for All Entries in "Random" Order )
 *
 *    HashString* hash;
 *    HashStringEntry* entry;
 *    int i;
 *
 *    // Somewhere Later, After Creating hash + Filling with Entries
 *    HASH_STRING_ITER( hash, entry, i )
 *    {
 *      printf("Index = %d\n", i);
 *      printf("Key = %s\n", entry->key);
 *      printf("Value = %s\n", entry->value);
 *    }
 *
 *  @param[in] hash HashString* to the hash to Iterate over
 *  @param[out] entry HashStringEntry** to Fill with HashString* to Current Entry
 *  @param[out] tmp int* to Fill with int to Current Working Entry
 */
#define HASH_STRING_ITER(hash, entry, i)                                                \
  (entry) = NULL;                                                                       \
  for ( HashString_firstEntry( (hash), &(entry), &(i) );                                \
    ((i) < (hash)->size) && ( (entry) != NULL );                                        \
    HashString_nextEntry((hash), &(entry), &(i)) )


#endif  /* End Main Header #ifndef */
