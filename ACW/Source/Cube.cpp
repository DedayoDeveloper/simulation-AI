#include "Cube.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

void Cube::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void Cube::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}
