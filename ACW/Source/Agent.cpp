#include "Agent.h"
#include "AgentBase.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

void Agent::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void Agent::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}

void Agent::Update(float pDeltaTime)
{

}
