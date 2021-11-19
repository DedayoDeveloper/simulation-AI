#include "Sphere.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

void Sphere::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void Sphere::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}