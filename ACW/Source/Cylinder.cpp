#include "Cylinder.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

void Cylinder::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void Cylinder::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}

