#pragma once
#include "GameEntity.h"

class Sphere : public GameEntity
{
private:

public:
	void Render(const IRenderHelpers&) const;
	void RenderGui(const IGuiHelpers&);
};

