# c-usage-of-temp-eff-mult
Create a voting template class that implements a voting mechanism. The class should have
two template parameters. The rst parameter (T) is a type parameter that species the type
of the "candidates", the second parameter is a non-negative integer (unsigned) that species
the number of candidates (N). The candidate type implements the default constructor and the
comparison operator (==). It can also be copied and written to a stream. The task is to
implement the following functions for the voting class:
 The class should have a constructor with one parameter. This parameter is an array of
N elements of type T. These are the candidates for the voting. Store them in the same
order. Initially, each candidate has 0 votes.
 Each candidate appears only once in the list (this does not need to be checked).
 Implement the += operator so that it can be used to vote for a candidate. Voting means
that the number of votes for a candidate is increased by one.
 If a vote is received for a candidate who was not on the list, throw an std::exception.
 Implement the ! operator that closes the vote and returns the winning candidate. If
there are multiple winners, the rst in the line should be returned.
 Closing means that if you want to vote after that, the program should throw an
std::exception.
 Implement the insertion operator (<<) so the class can be printed to an output stream.
The format is as follows: write out the candidates line by line. Each row consists of the
candidate and the number of its votes, separated by a colon.

============================================================================
second part
Specialize the voting class so that the type of the candidates is unsigned, but the size N can
still be specied as a non-negative integer (unsigned).
 The class should have a constructor with one parameter. This parameter is an unsigned
array of N elements. These are the candidates for the voting. Store them in the same
order. Initially, each candidate has 0 votes.
 Each candidate appears only once in the list (this does not need to be checked).
 Implement the += operator so that it can be used to vote for a candidate. In this case,
voting means that the number of votes for a candidate is increased by its value. For
example, if you vote for candidate 3, increase the number of its votes by 3.
 If a vote is received for a candidate who was not on the list, throw an std::exception.
 Implement the insertion operator (<<) so the class can be printed to an output stream.
The format is as follows: write out the candidates line by line. Each row consists of the
candidate and the number of its votes, separated by a colon.
 No other operators should be implemented in the class (but helper functions may be
used).

===========================================================================
Third part
Make a quote manipulator that puts the string between two quotes in quotation marks, if
it is not already in quotation marks. A string is in quotation marks if the text is between
two quotation mark characters, where the quotation mark characters are the rst and last
characters of the string (e.g. there is not even a space before the opening quotation mark or
after the closing quotation mark). It is sucient for the manipulator to operate only on a single
stream and within a single instruction.

===================================================================================

fourth part
Make a stream eector called double_space, which prints the string given in its parameter by
doubling all spaces, but not changing anything else.
For example, for cout << double_space("one.space,..two..spaces"); the output will be
one..space,....two....spaces (the spaces are represented by dots).

=====================================================

fifth part
There are pre-made classes to solve this task. The Android and iOS classes represent mobile
operating systems. The Hun and Eng classes represent the language, while the Samsung and
iPhone classes represent the brand of the phone. See task.cpp for details.
Create a template class traits called mobile_config that can be used to assemble prede-
ned congurations by specifying its type template parameter:
 for Samsung: Android operating system and Hungarian (Hun) language.
 for iPhone: iOS operating system and English (Eng) language.
Create a mobile template class with two type parameters and an unsigned parameter. The
rst parameter is the brand of the phone (Samsung or iPhone), while the second parameter
should be a mobile_config class. It has a default parameter: the conguration of the brand.
The third parameter is the version of the operation system. Its default value is 10.
 Implement a two-parametered constructor for the class. The rst parameter is a string,
the name of the phone. The second parameter is an unsigned value, the version of the
operating system. Its default value should be the third template parameter.
 Hint: any data member without a default constructor must be initialized in the
constructor initialization list.
 Implement the insertion operator (<<) so the class can be printed to an output stream.
Expected format: "name (brand, operating system, language)". For example: iPhone
13 (iPhone, iOS v13, English)
 Implement a get_os method which return the operating system. It takes no argument.

==================================================
