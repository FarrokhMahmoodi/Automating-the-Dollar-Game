//LIBRARIES
#include <iostream>
#include<string>
#include<bits/stdc++.h> //for converting a string to lowercase
#include<stdio.h>
using namespace std;

//DRIVER
int main()
{
    //Description of game
    cout<<"This program automates the dollar game by first designing a graph with vertices(between 2 to 7), edges, starting number for each vertex and characters(case insensitive) that correspond to each vertex created by you.\n";
    cout<<"You are then asked to designate each edge of corresponding vertices with previously declared characters \n";
    cout<<"Then the user(you) plays the game, by being asked to make moves that adds or removes numbers between vertices until there are no negative values left on the board or if you quit.\n";

    //Local Variables
    int E, V, num; //E=number of edges, V=number of vertices, num=starting number for each vertex
    string charE; //character string to designate edge of corresponding vertices
    int count=0; //number of moves made
    string Vmove; //user input vertex to move

    cout<<"How many vertices(between 2 and 7 inclusive) would you like to have on your board?";
    cin>>V;

    //Error checking for valid input for number of vertices
    while(cin.fail() || V<2 || V>7)
    {
        cout<<"ERROR. Enter a valid integer between 2 and 7 inclusive: ";
        cin.clear();
        cin.ignore(12323556,'\n');
        cin>>V;
    }

    cout<<"How many edges would you like to have on your board?";
    cin>>E;

    //Error checking for valid input for number of edges
    while(cin.fail() || E<V-1)
    {
        cout<<"ERROR. Enter a valid number of edges: ";
        cin.clear();
        cin.ignore(12323556,'\n');
        cin>>E;
    }

    //Dynamic array for starting number of each vertex
    int *startnum= new int[V];
    for(int i=0;i<V;i++)
    {
        cout<<"Enter a starting number for each vertex: ";
        cin>>startnum[i];

    //Error checking for valid input of starting number for vertex
    while(cin.fail())
     {
        cout<<"ERROR. Enter a valid integer.\n";
        cin.clear();
        cin.ignore(12323556,'\n');
        cin>>startnum[i];
     }
    }

    //array for characters assigned to each vertex
    string *startchar=new string[V];
    startchar[0]="a";
    startchar[1]="b";
    startchar[2]="c";
    startchar[3]="d";
    startchar[4]="e";
    startchar[5]="f";
    startchar[6]="g";

    cout<<"Enter a two character string where both characters(case insensitive) correspond to numbers of vertices.\n";
    cout<<"For example, if number of vertices created was 3, you have vertex A(a), vertex B(b), vertex C(or c),etc.\n";
    cin>>charE;

    //Error checking 2 character string input
    while(cin.fail() || charE.length()!=2)
    {
        cout<<"ERROR. Enter a valid 2 character string corresponding to number of vertices.\n";
        cin.clear();
        cin.ignore(1232456,'\n');
        cin>>charE;
    }

    //Converts user input 2 character string to lower case to compare to acceptable characters
    transform(charE.begin(),charE.end(),charE.begin(),::tolower);

    //Error checking 2 character string input exists(case insensitive) with corresponding number of vertices
    while(charE!=startchar[0] || charE!=startchar[1]||charE!=startchar[2] || charE!=startchar[3] || charE!=startchar[4] || charE!=startchar[5] || charE!=startchar[6])
    {
        cout<<"ERROR. Please enter a two character string corresponding to existing number of vertices. \n";
        cout<<"For example, if the number of declared vertices is 3 than the character ""e"" does not exist. Only a,b and c exist.\n";
        cin.clear();
        cin.ignore(123546,'\n');
        cin>>charE;
    }

    //Error checking 2 character string input does not correspond a vertex to an edge itself
    for(int i=0;i<V;i++)
    {
        while(charE==startchar[i]+startchar[i])
        {
            cout<<"ERROR. Please enter a two character string that does not correspond a vertex to itself.\n";
            cout<<"For example, if the number of declared vertices is 3 you cannot declare a 2 character string of ""aa"" or ""bb"".\n";
            cin.clear();
            cin.ignore(123456,'\n');
            cin>>charE;
        }
    }

    cout<<"The game board has been created to your declared specifications.\n";

    do{
    cout<<"Don't forget to win the dollar game, all dollar(number) values have to be nonnegative integers!\n";

    cout<<"Please enter a move to make by entering a valid character of a vertex or press q to quit.";
    cin>>Vmove;
    //Convert user input to lower case to compare to valid existing characters
    transform(Vmove.begin(),Vmove.end(),Vmove.begin(),::tolower);

    //Error checking valid type input and length
      while(cin.fail()|| Vmove.length()>1)
      {
        cout<<"Please enter a valid character in the alphabet(a,b,c,etc.) assigned to a vertex.";
        cin.clear();
        cin.ignore(123324,'\n');
        cin>>Vmove;
      }

    //Error checking valid character assigned to existing vertex
      while(Vmove!=startchar[0] || Vmove!=startchar[1] || Vmove!=startchar[2] || Vmove!=startchar[3] || Vmove!=startchar[4] || Vmove!=startchar[5] || Vmove!=startchar[6])
      {
         cout<<"Please enter a valid character in the alphabet assigned to an existing vertex.";
         cin.clear();
         cin.ignore(123344,'\n');
         cin>>Vmove;
      }

      //when user makes a valid move it subtracts 1 from the numbered vertex declared by assigned character(Vmove)
      //to another numbered vertex connected to it by an edge
      for(int i=0;i<V;i++)
      {
        if(Vmove==startchar[i])
        {
            startnum[i]--; //subtract 1 from user input character to assigned vertex
            startnum[i+1]+1; //adds that 1 to an adjacent vertex
            count++; //increase move counter
        }

        //Print to screen every vertex number value after valid move change
        cout<<"Vertex "<<setw(4)<<startchar[i]<<"has "<<setw(4)<<startnum[i]<<setw(4)<<"dollars to it.\n";
      }


    }while(Vmove!="q");//user presses q to quit the game

    //Final move count
    cout<<"You have made "<<count<<" moves in the game.\n";

    //Final dollar count
    cout<<"Final Dollar counts starting from vertex ""a"" are: ";
    for(int i=0;i<V-1;i++)
    {
        cout<<setw(4)<<startnum[i]<<", ";
    }
    cout<<setw(4)<<startnum[V-1]<<".";

    //If winning configuration found
    for(int i=0;i<V;i++)
    {
        if(startnum[i]>=0 && startnum[i+1]>=0 && startnum[i+2]>=0&& startnum[i+3]>=0 && startnum[i+4]>=0 && startnum[i+5]>=0 && startnum[i+6]>=0)
        {
            cout<<"Congratulations, you have won the dollar game!\n";
        }

    }

    return 0;
}
