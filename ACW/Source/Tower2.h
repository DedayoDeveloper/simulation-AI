#pragma once
#include "GameEntity.h"

class Tower2 : public GameEntity
{
private:

public:
	void Render(const IRenderHelpers&) const;
	void RenderGui(const IGuiHelpers&);
};