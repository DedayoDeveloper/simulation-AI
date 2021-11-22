#pragma once
#include "GameEntity.h"

class Tower1 : public GameEntity
{
private:

public:
	void Render(const IRenderHelpers&) const;
	void RenderGui(const IGuiHelpers&);
};

