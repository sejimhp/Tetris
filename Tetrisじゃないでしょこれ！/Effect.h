#pragma once;

# include <Siv3D.hpp>

class Snow : public IEffect
{
	struct Particle
	{
		Vec2 pos, v0;
	};

	Array<Particle> m_particles;

public:
	Snow(const Vec2& pos, int count);
	bool update(double t) override;
};

