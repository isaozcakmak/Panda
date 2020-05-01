#ifndef PANDA_NODEVISITOR
#define PANDA_NODEVISITOR

#include <string>
#include <vector>
#include <AbstractSyntaxTree.h>
#include <AbstractSyntaxTreeNumNode.h>
#include <AbstractSyntaxTreeBinOpNode.h>
#include <AbstractSyntaxTreeUnaryOpNode.h>

class NodeVisitor
{
public:
	NodeVisitor();
	~NodeVisitor() {}

	int visit(AbstractSyntaxTree* node);

private:
	int visitNum(AbstractSyntaxTree* node);
	int visitBinOp(AbstractSyntaxTree* node);
	int visitUnaryOp(AbstractSyntaxTree* node);

};


#endif // PANDA_NODEVISITOR