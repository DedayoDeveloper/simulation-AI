#include "Tower2.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

void Tower2::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void Tower2::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}