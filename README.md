### Lexical Analyzer
#### Austin Hester
##### CS 4280 - P1

I am implementing option #3, that is an FSA table + table.

	The FSA table is convienently located is fsatable.c
	The FSA driver is located in fsadriver.c


A preprocessor and lexical analyzer for a programming language.

I did not pay too much attention to the language itself. 
This project was simply to extract tokens from a ```FILE*```.

```main.c``` first filters the source file using ```filter.c``` 
and ```trimline.c```, leaving out comments
and characters not in the alphabet. This creates a 
new ```wordlist_t*```. It then displays the filtered source.  
Note: This scanner completely ignores whitespace, comments, 
and any characters not in ```alphabet.c```. This means you
can type "tot^#@^al" and it would be registered as an identifier 
called "total".

Next, a ```token_t**``` is initialized and filled in using the 
```testscanner``` function. This function goes through our filtered 
word list, appending new tokens to our token list. This function 
ends on ```EOF```.  

The driver of this program is ```fsadriver.c```. It takes a 
```wordlist_t*``` and returns the next token, keeping track of 
its location in the word list. ```fsadriver``` is quite complex, 
but it is loosely based off of the psuedocode in our notes.

The driver identifies states and tokens using FSA table located 
in ```fsatable.c```. This table is essentially switch and if 
statements.

Also, I did not choose to separate keywords from identifiers yet. I plan 
on doing this one level up in the parser project.

https://github.com/ahester57/lexical-analyzer
