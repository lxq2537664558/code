#include "cube.h"
#include "engine/particles/particles.h"

struct billboard_renderer : public particle_renderer_implementation
{

	billboard_renderer() : particle_renderer_implementation("billboard_renderer") {
		particle_renderer_implementations.add(this);
	}
	virtual ~billboard_renderer() { }

	void render(particle_instance *p_inst) {
		// conoutf("billboard_renderer:render(x: %2.1f y: %2.1f z: %2.1f --- vx: %2.1f vy: %2.1f vz: %2.1f --- type: %2d emitter: %3d elapsed: %4d remaining: %5d)", p_inst->o.x, p_inst->o.y, p_inst->o.z, p_inst->vel.x, p_inst->vel.y, p_inst->vel.z, p_inst->type, p_inst->emitter, p_inst->elapsed, p_inst->remaining);
		glVertex3f(p_inst->o.x, p_inst->o.y, p_inst->o.z);
	}

};

billboard_renderer *ps_renderer_billboard = new billboard_renderer();
