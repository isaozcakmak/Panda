#ifndef PANDA_NODEVISITOR
#define PANDA_NODEVISITOR

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <AbstractSyntaxTree.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeNumNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeBinOpNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeUnaryOpNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeAssignNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeCompoundNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeNoOpNode.h>

class NodeVisitor
{
public:
	NodeVisitor();
	~NodeVisitor() {}

	int visit(AbstractSyntaxTree* node);
	std::unordered_map<std::string, int> getVariables();
	void printVariables();

private:
	int visitNum(AbstractSyntaxTree* node);
	int visitBinOp(AbstractSyntaxTree* node);
	int visitUnaryOp(AbstractSyntaxTree* node);
	void visitCompound(AbstractSyntaxTree* node);
	void visitAssign(AbstractSyntaxTree* node);
	int visitVar(AbstractSyntaxTree* node);
	void visitNoOp(AbstractSyntaxTree* node);

private:
	std::unordered_map<std::string, int> m_variables;
};


#endif // PANDA_NODEVISITOR