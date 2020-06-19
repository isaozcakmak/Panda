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
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeProgramNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeBlockNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarDeclarationNode.h>
#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeTypeNode.h>
#include <Utility/HelperMethods.h>

class NodeVisitor
{
public:
	NodeVisitor();
	~NodeVisitor() {}

	double visit(AbstractSyntaxTree* node);
	std::unordered_map<std::string, double> getVariables();
	void printVariables();

private:
	double visitNum(AbstractSyntaxTree* node);
	double visitBinOp(AbstractSyntaxTree* node);
	double visitUnaryOp(AbstractSyntaxTree* node);
	void visitCompound(AbstractSyntaxTree* node);
	void visitAssign(AbstractSyntaxTree* node);
	double visitVar(AbstractSyntaxTree* node);
	void visitNoOp(AbstractSyntaxTree* node);
	void visitProgram(AbstractSyntaxTree* node);
	void visitBlock(AbstractSyntaxTree* node);
	void visitVarDecleration(AbstractSyntaxTree* node);
	void visitType(AbstractSyntaxTree* node);

private:
	std::unordered_map<std::string, double> m_variables;
};


#endif // PANDA_NODEVISITOR