# Approach

We can solve this problem using trie datastructure & DFS(Depth First Search). With all the given strings build a trie, each trie node has two attributes
1. Pointer to next 26 characters
2. Whether any string end on that character or not.
Once we build it, we will interate over all the strings one by one, for any string s check all its characters, if any point in time if substring(prefix of string s) ends then we will check if suffix can be found.

# Execution
This program is in c++, there is only one file [solution.cpp](https://github.com/Priti-12171/word-composition/blob/main/solution.cpp). Code will read the input from input1.txt [here](https://github.com/Priti-12171/word-composition/blob/main/solution.cpp#L49). We can change the file name to any other desired file. Currently output is in console but we can uncomment [line](https://github.com/Priti-12171/word-composition/blob/main/solution.cpp#L50) to output in file.
Output will contain the longest and second longest compound string and the execution time of code.
