#pragma once
#include "GameEntity.h"

class Cylinder : public GameEntity
{
private:

public:
	void Render(const IRenderHelpers&) const;
	void RenderGui(const IGuiHelpers&);
};