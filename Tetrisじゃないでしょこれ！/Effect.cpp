# include <Siv3D.hpp>

# include "Effect.h"

Snow::Snow(const Vec2& pos, int count)
	: m_particles(count){

	for (auto& particle : m_particles){
		const Vec2 v = Circular(Random(10.0, 80.0), Random(TwoPi));
		particle.pos = pos + v;
		particle.v0 = v * 2.0;
	}
}

bool Snow::update(double t) {
	for (const auto& particle : m_particles){
		const Vec2 pos = particle.pos + particle.v0 * t + 0.5* t*t * Vec2(0, 320);

		Circle(pos, 1).draw(HSV(pos.y / 4.0, 0.6, 1.0).toColorF(1.0 - t));
	}

	return t < 1.0;
}