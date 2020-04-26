#include <AbstractSyntaxTree.h>
#include <iostream>

AbstractSyntaxTree::AbstractSyntaxTree(Token token) :
	m_left(nullptr),
	m_op(token),
	m_right(nullptr),
	m_nodeType(NodeType::Num),
	m_token(token),
	m_expr(nullptr)
{
}

AbstractSyntaxTree::AbstractSyntaxTree(AbstractSyntaxTree* left, Token op, AbstractSyntaxTree* right) :
	m_left(left),
	m_op(op),
	m_right(right),
	m_nodeType(NodeType::BinOp),
	m_token(op),
	m_expr(nullptr)
{
}

AbstractSyntaxTree::AbstractSyntaxTree(Token op, AbstractSyntaxTree* expr) :
	m_left(nullptr),
	m_op(op),
	m_right(nullptr),
	m_nodeType(NodeType::UnaryOp),
	m_token(op),
	m_expr(expr)
{
}

AbstractSyntaxTree& AbstractSyntaxTree::operator=(const AbstractSyntaxTree& other)
{
	// TODO: insert return statement here

	if (&other == this)
		return *this;

	this->m_left = other.m_left;
	this->m_op = other.m_op;
	this->m_right = other.m_right;
	this->m_nodeType = other.m_nodeType;
	this->m_token = other.m_token;

	//std::swap(this->m_left, other.m_left);
	//std::swap(this->m_op, other.m_op);
	//std::swap(this->m_right, other.m_right);
	//std::swap(this->m_nodeType, other.m_nodeType);
	//std::swap(this->m_token, other.m_token);

	return *this;
}

AbstractSyntaxTree::NodeType AbstractSyntaxTree::getNodeType()
{
	return m_nodeType;
}

int AbstractSyntaxTree::getTokenValue()
{
	return m_token.getValue();
}

Token::TokenType AbstractSyntaxTree::getOpTokenType()
{
	return m_op.getType();
}

AbstractSyntaxTree* AbstractSyntaxTree::getLeft()
{
	return m_left;
}

AbstractSyntaxTree* AbstractSyntaxTree::getRight()
{
	return m_right;
}

AbstractSyntaxTree* AbstractSyntaxTree::getExpr()
{
	return m_expr;
}



