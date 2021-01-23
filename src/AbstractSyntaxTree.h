#ifndef PANDA_ABSTRACTSYNTAXTREE
#define PANDA_ABSTRACTSYNTAXTREE

#include <string>
#include <vector>
#include <Token.h>

class AbstractSyntaxTree
{
public:
	enum class NodeType
	{
		Num = 0x01,
		BinOp,
		UnaryOp,
		Compound,
		Assign,
		Var,
		NoOp,
		Program,
		Block,
		VarDecl,
		Type
	};

	AbstractSyntaxTree();
	~AbstractSyntaxTree() {}

	virtual NodeType getNodeType() = 0;

};


#endif // PANDA_ABSTRACTSYNTAXTREE