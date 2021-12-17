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
    //~World()
    //{
    //    for (int i = 0; i < m_Agents.size(); i++)
    //    {
    //        delete m_Agents[i];
    //    }
    //}
    void AddAgent(AgentBase* pBase);
    void AddBase(AgentBase* pBase);
    void Update(float pDeltaTime);
    void Render(const IRenderHelpers&) const;
    void RenderGui(const IGuiHelpers&);
    AgentBase* GetBase();
};

