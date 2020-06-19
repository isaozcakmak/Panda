#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeVarNode.h>
#include <iostream>

AbstractSyntaxTreeVarNode::AbstractSyntaxTreeVarNode(Token token) :
	m_nodeType(NodeType::Var),
	m_token(token)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeVarNode::getNodeType()
{
	return m_nodeType;
}

double AbstractSyntaxTreeVarNode::getTokenValue()
{
	if (m_token.getType() == Token::TokenType::Integer ||
		m_token.getType() == Token::TokenType::IntegerConst)
	{
		return m_token.getInteger();
	}
	else if (m_token.getType() == Token::TokenType::Real ||
		m_token.getType() == Token::TokenType::RealConst)
	{
		return m_token.getDouble();
	}

	return 0.0;
}

std::string AbstractSyntaxTreeVarNode::getTokenString()
{
	return m_token.getString();
}

