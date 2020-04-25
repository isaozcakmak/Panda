#include <AbstractSyntaxTree.h>
#include <iostream>

AbstractSyntaxTree::AbstractSyntaxTree(Token token) :
	m_left(*this),
	m_op(token),
	m_right(*this),
	m_nodeType(NodeType::Num),
	m_token(token)
{
}

AbstractSyntaxTree::AbstractSyntaxTree(AbstractSyntaxTree& left, Token op, AbstractSyntaxTree& right) :
	m_left(left),
	m_op(op),
	m_right(right),
	m_nodeType(NodeType::BinOp),
	m_token(op)
{
}

AbstractSyntaxTree& AbstractSyntaxTree::operator=(AbstractSyntaxTree other)
{
	// TODO: insert return statement here

	if (&other == this)
		return *this;

	std::swap(this->m_left, other.m_left);
	std::swap(this->m_op, other.m_op);
	std::swap(this->m_right, other.m_right);
	std::swap(this->m_nodeType, other.m_nodeType);
	std::swap(this->m_token, other.m_token);

	return *this;
}



