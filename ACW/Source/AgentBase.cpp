
#include "World.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"
#include "AgentBase.h"

void AgentBase::Update(float pDeltaTime)
{
	m_TimeTillNextAgent = m_TimeTillNextAgent - pDeltaTime;

	if (m_TimeTillNextAgent <= 0.f)
	{
		Agent agent();
		m_World->AddAgent(&agent);
		m_TimeTillNextAgent = m_TimeBetweenAgents;
	}


}

void AgentBase::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void AgentBase::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}