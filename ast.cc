/* FILENAME IS ast.cc
*/

#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h> 
#include <stdio.h> 

Node::Node(yyltype loc) {
    location = new yyltype(loc);
    parent = NULL;
}

Node::Node() {
    location = NULL;
    parent = NULL;
}



/* HERE THE PRINT METHOD IS USED TO PRINT THE NODES OF TREE.
* WE WILL FIRST PRINT THE LINE NUMBER WHICH WILL HELP IUS TO MATCH THE PARSE TREE
* BACK TO THE SOURCE CODE. AFTER THIS IT WILL ADD PROPER NUMBERS OF INDENT AND PRINTS 
* THE NAME OF THE NODE
*/
void Node::Print(int indentLevel, const char *label) {
    const int numSpaces = 3;
    printf("\n");
    if (GetLocation())
        printf("%*d", numSpaces, GetLocation()->first_line);
    else
        printf("%*s", numSpaces, "");
    printf("%*s%s%s: ", indentLevel*numSpaces, "",
           label? label : "", GetPrintNameForNode());
   PrintChildren(indentLevel);
}

Identifier::Identifier(yyltype loc, const char *n) : Node(loc) {
    name = strdup(n);
}

void Identifier::PrintChildren(int indentLevel) {
    printf("%s", name);
}



