#include "World.h"
#include "AgentBase.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

World::World()
{
	m_Bases.push_back(new AgentBase(this, 2.f));
}

void World::AddAgent(Agent* pAgent)
{
	m_Agents.push_back(pAgent);
}

void World::Render(const IRenderHelpers& pHelper) const
{
	for (int i = 0; i < m_Bases.size(); i++)
	{
		m_Bases[i];
	}
}

void World::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}