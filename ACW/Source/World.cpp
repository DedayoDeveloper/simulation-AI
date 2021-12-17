#include "World.h"
#include "AgentBase.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"
#include "Agent.h"

World::World()
{
	m_Bases.push_back(new AgentBase(this, 2.f));
}

void World::AddAgent(AgentBase * pBase)
{
	Agent* agent = new Agent(pBase);
	m_Agents.push_back(agent);
}

void World::AddBase(AgentBase* pAgentBase)
{
	m_Bases.push_back(pAgentBase);
}

AgentBase* World::GetBase()
{
	return m_Bases[0];
}

void World::Update(float pDeltaTime)
{
	for (int i = 0; i < m_Bases.size(); i++)
	{
		m_Bases[i]->Update(pDeltaTime);
	}

	for (int i = 0; i < m_Agents.size(); i++)
	{
		m_Agents[i]->Update(pDeltaTime);
	}
}

void World::Render(const IRenderHelpers& pHelper) const
{

	for (int i = 0; i < m_Agents.size(); i++)
	{
		pHelper.Render(m_Agents[i]);
	}
}

void World::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}