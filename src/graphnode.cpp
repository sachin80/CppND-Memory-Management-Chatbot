#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"
GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{

}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    // implicit move 
    _childEdges.push_back(std::unique_ptr<GraphEdge>(edge));
}

void GraphNode::MoveChatbotHere(ChatBot chatBot)
{
    _chatBot = std::move(chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{

    return _childEdges[index].get();

}
