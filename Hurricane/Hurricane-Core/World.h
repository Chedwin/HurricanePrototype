#pragma once

//#include <ode/ode.h>
//#include "PhysicsODE.h"
#include "Matrix.h"
#include "Window.h"
#include "Texture.h"

using namespace MATH;

class World {
public:
	World(Window* w) : windowPtr(w) {

	}
	virtual ~World() {

	}

	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render(const Matrix4& projection) = 0;

public:

protected:
	Texture* worldMap;
	Window* windowPtr;
};
