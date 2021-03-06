

/* The filename is ast_decl.h

* THE PARSE TREE THAT WE ARE GONNA GENERATE USES DECL NODES WHICH ARE USED TO MANAGE DECLARATIONS
* WE HAVE 4 SUBCLASSES OF BASE CLASS SPECIFICALLY FOR DECLARATIONS OF VARIABLES, FUNCTIONS, CLASSES AND INTERFACES.

*/

#ifndef _H_ast_decl
#define _H_ast_decl

#include "ast.h"
#include "list.h"

class Type;
class NamedType;
class Identifier;
class StmtBlock;


class Decl : public Node 
{
  protected:
    Identifier *id;
  
  public:
    Decl(Identifier *name);
};

class VarDecl : public Decl 
{
  protected:
    Type *type;
    
  public:
    VarDecl(Identifier *name, Type *type);
    const char *GetPrintNameForNode() { return "VarDecl"; }
    void PrintChildren(int indentLevel);
};


class ClassDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    NamedType *extends;
    List<NamedType*> *implements;

  public:
    ClassDecl(Identifier *name, NamedType *extends, 
              List<NamedType*> *implements, List<Decl*> *members);
    const char *GetPrintNameForNode() { return "ClassDecl"; }
    void PrintChildren(int indentLevel);
};

class InterfaceDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    
  public:
    InterfaceDecl(Identifier *name, List<Decl*> *members);
    const char *GetPrintNameForNode() { return "InterfaceDecl"; }
    void PrintChildren(int indentLevel);
};

class FnDecl : public Decl 
{
  protected:
    List<VarDecl*> *formals;
    Type *returnType;
    StmtBlock *body;
    
  public:
    FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
    void SetFunctionBody(StmtBlock *b);
    const char *GetPrintNameForNode() { return "FnDecl"; }
    void PrintChildren(int indentLevel);
};


#endif
