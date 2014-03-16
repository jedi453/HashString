HashString
==========

A Hash Table for String Keys and Values in C.
---------------------------------------------
This Project is a Simple and (Hopefully) Straightforward Implementation of a Hash Table in C
with Functions to Add, Remove, and Find Entries within the Hash Table.

A Macro is Also Included to Iterate over all Entries of the Table ( in a "Random" Order ).
Like a Loop Would.

I've tried to Design this Code to be Re-usable, so if you want to Use this in your own C Programs,
you can #include "HashString.h" and Compile HashString.c into Your Program.
main.c is Unnecessary to Include in Derived Programs.

Example Usage
---------------
I've included an Example Implementation that has a Command Line Interface that Prompts the User
so that One may Interact with a Hash Table ( It's in main.c ).
It's Included Here to Demonstrate How to Use the Functions in HashString.c

License
-------
This Code is Released Under the MIT License. See the LICENSE file for Details.


Resources and Thanks
--------------------
Although the Code Here was Created by Me, ( Except for the Hash Functions, which are Under the Public Domain )
I Drew Inspiration and Ideas from Other Resources.
Here are some of the Big Ones:
- Ian Boyd - [Hash Function Comparisons](http://programmers.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed)
- Troy D. Hanson - [uthash](http://troydhanson.github.io/uthash/ "uthash")
- Bob Burtle - [Great+Fast Hash Functions](http://burtleburtle.net/bob/hash/ "Bob Burtle - Hash Functions")
- Austin Appleby - [Murmur2 Hash](https://sites.google.com/site/murmurhash/)
- Glenn Fowler, Landon Curt Noll, Phong Vo - [FNV-1A Hash](http://www.isthe.com/chongo/tech/comp/fnv/)
- Julienne Walker - [Eternally Confuzzled](http://eternallyconfuzzled.com/tuts/datastructures/jsw_tut_hashtable.aspx)
- Spark Notes - [Basic Hash Table Implementation](http://www.sparknotes.com/cs/searching/hashtables/section3.rhtml)
- [Non-Cryptographic Hash Zoo](http://floodyberry.com/noncryptohashzoo/)
