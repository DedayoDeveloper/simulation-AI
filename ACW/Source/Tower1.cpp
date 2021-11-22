#include "Tower1.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

void Tower1::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void Tower1::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}