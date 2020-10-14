This program starts by printing out to the screen a SHORT description of what the program will do. Then the program should prompt the interactive user for the number of vertices for this set up. For this assignment, that number of vertices must be an integer between 2 and 7 inclusive. (That is, the only allowed integers are 2, 3, 4, 5, 6, and 7.) If the user enters anything else, give a descriptive error message, and reprompt until a legal integer is entered. Call the number of vertices chosen V. 
Next, your program should ask for how many edges. Call this number E. E has to be an integer, and must be at least (V-1). For now, I won’t specify a maximum, although there is a maximum because of constraints described below. (Can you figure it out? It isn’t required that you do figure it out, but I’ll be impressed if you do.)
Your program should prompt for E; if the interactive user gives something inappropriate, give a descriptive error message, and reprompt until you get a legal E. 
The graph of vertices and edges should be connected. (That is, there should be a path of edges from any two vertices.) If you are feeling ambitious, you could make sure the interactive user specifies a connected graph; however, I do NOT require that for this program.
Once you have an acceptable V and E, prompt the interactive user for a starting number for each vertex. This must be an integer. As before, when you prompt the user, and the user enters something inappropriate, give a descriptive error message and reprompt.
Once each vertex has a starting number (a pile of dollars), then prompt for the E edges. The interactive user is prompted for the letter of two vertices to designate an edge. There are plenty of ways to do this, but we’ll require this way: Prompt the user for a two character string. Each character should be a vertex in your setup. (Allow either upper case or lower case for each vertex.) For example, if V is 2, then “a”, “b”, “A”, or “B” are the only legal characters when designating an edge. The order is immaterial. If V is 2, then “AB”, “aB”, and “bA” are examples of a legal edge. If the user inputs an illegal edge, give a helpful error message and reprompt. Once an edge has been established between two vertices, it is incorrect to add a SECOND edge between those two vertices, and your program should detect that. If the interactive user tries to add an existing edge, give a descriptive error message, and reprompt. 
A vertex may NOT have an edge to itself. Thus “AA” is an illegal edge. If an interactive user tries to give an illegal “edge to self,” then your program should (all together now) give a descriptive error message and reprompt.
Once the interactive user has defined a legal game board with V vertices and E edges, your program should enable the interactive user to make “moves” in the dollar game. You should repeatedly prompt the user for a vertex or the character Q. If the user enters Q or q, the program quits. If the user enters a character that is neither a vertex or a Q (again, upper or lower case allowed), then the program gives a descriptive error message and reprompts. 
If the user enters a correct vertex, call it X, then the program “makes a move” by moving $1 from X to any vertex connected to X by an edge, and by updating the numbers associated with X and the vertices connected to X. (X goes down the number of vertices to which it is connected, and each of the connected vertices goes up by one.) After each move, your program should list each vertex and its current number of dollars (which can be positive, negative, or zero). Then the program reprompts for the next “move” (that is, the next vertex from which dollars will be sent). The interactive user keeps playing until she/he quits by entering Q or q.
When the interactive user quits the game, your program should write on the screen how many moves the user made (not counting the ending Q), the final dollar counts, and whether or not the interactive user “won.” The interactive user wins by having each vertex with a non-negative number of dollars in the final configuration. 
If your program detects a winning configuration while the user is playing, it should announce that when printing out the configuration after a move or at the start of a game. (Yes, you could make the initial configuration already a winner; not too interesting, but possible.) However, your program should NOT force the user to quit when a win is detected. (That is, don’t end a game until the interactive user explicitly asks for the end with a Q or q.)
