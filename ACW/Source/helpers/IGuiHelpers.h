#pragma once

class GameEntity;
class Cube;
class Camera;

class IGuiHelpers
{
public:
	virtual void RenderGui(GameEntity*) const = 0;
	virtual void RenderGui(Cube*) const = 0;
	virtual void RenderGui(Camera*) const = 0;
};