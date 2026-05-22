# **Machine Spirit**

This project is my first take at making my own compiler in C. This is big undertaking for me personally as i have not used C before, or made my own compiler.

---

</br>

This project is intended to be proof to myself that i **_can_** be productive and can be capable. This project is important for me.

---

</br>
Sappyness aside, further documentation will be added soon, as well a few other folder for tracking progress.

# Details

</br>

### Lexer/Scanner

The lexer/scanner takes the file input. it then will scan through each character in the source file. identifying tokens as it goes using switch statments. the token will contain the token type, its location in the source file (by character line), and the length of the tokens lexeme. this will allow the parser to look back at the source file all relevent data without having to store each lexeme in the stucture.

</br>
 
The lexer will scan each character (white spaces, comments, and new lines will be skipped). It will then compare the character to see if it matches any known keyword types, if not it will then contenue to scan to determine its literal value (note this will have to work in identifiers, checking position for identifiers will be important). Scanning to the next character will will cause the lexer to either decide that the token in complete, or needs to be evaluated further in order to indefity the full token and its length.

<span style="text-decoration:underline">for the time being white space will indicate a tokens end point</span>

it will store all the token data in an array that contains specified token structures (defined in tok_definitions). again - the token type, the location of the lexeme in the text file, and the line number, thought line number may not be stored till later.
