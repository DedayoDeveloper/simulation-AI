#pragma once
#include "GameEntity.h"
#include <vector>

using namespace std;

class Agent;
class AgentBase;

class World :
    public GameEntity
{
private:
    vector<Agent*> m_Agents;
    vector<AgentBase*> m_Bases;
public:
    World();
    void AddAgent(Agent* pAgent);
    void AddBase(AgentBase* pBase);

    void Render(const IRenderHelpers&) const;
    void RenderGui(const IGuiHelpers&);
};

