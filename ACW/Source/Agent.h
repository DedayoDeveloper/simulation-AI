#pragma once
#include "GameEntity.h"

class AgentBase;

class Agent : public GameEntity

{
private:
	AgentBase* m_Base;

public:
	Agent(AgentBase* pBase) {
		m_Base = pBase;
	}
	void Render(const IRenderHelpers&) const;
	void RenderGui(const IGuiHelpers&);
	void Update(float pDeltaTime);
};

