#include <AbstractSyntaxTreeNodes/AbstractSyntaxTreeNumNode.h>
#include <iostream>

AbstractSyntaxTreeNumNode::AbstractSyntaxTreeNumNode(Token token) :
	m_nodeType(NodeType::Num),
	m_token(token)
{
}

AbstractSyntaxTree::NodeType AbstractSyntaxTreeNumNode::getNodeType()
{
	return m_nodeType;
}

double AbstractSyntaxTreeNumNode::getTokenValue()
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

