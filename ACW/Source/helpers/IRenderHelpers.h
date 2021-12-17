#pragma once


class GameEntity;
class Cube;
class Camera;
class Sphere;
class Cylinder;
class Tower1;
class Tower2;
class AgentBase;
class Agent;

class IRenderHelpers
{
public:
	virtual ~IRenderHelpers() {}
	virtual void Init() = 0;
	virtual void SetSize(unsigned int pWidth, unsigned int pHeight) = 0;
	virtual void Render(const GameEntity*) const = 0;
	virtual void Render(const Cube*) const = 0;
	virtual void Render(const Sphere*) const = 0;
	virtual void Render(const Cylinder*) const = 0;
	virtual void Render(const Camera*) const = 0;
	virtual void Render(const Tower1*) const = 0;
	virtual void Render(const Tower2*) const = 0;
	virtual void Render(const AgentBase*) const = 0;
	virtual void Render(const Agent*) const = 0;
};
