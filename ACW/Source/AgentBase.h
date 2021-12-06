#pragma once
#include "GameEntity.h"

class World;

class AgentBase : public GameEntity
{
private:
	World* m_World;
	float m_TimeTillNextAgent;
	float m_TimeBetweenAgents;
public:
	AgentBase(World* pWorld, float pTimeTillNextAgent) : m_World(pWorld), m_TimeTillNextAgent(pTimeTillNextAgent), m_TimeBetweenAgents(pTimeTillNextAgent)
	{

	}
	void Update(float pDeltaTime);

	void Render(const IRenderHelpers&) const;
	void RenderGui(const IGuiHelpers&);

};

