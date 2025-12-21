#pragma once

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

class GDHover : public Sprite2D {
	GDCLASS(GDHover, Sprite2D)

private:
	double time_passed;
	double amplitude;
	double speed;

protected:
	static void _bind_methods();

// public may show up in the inspector in the
// Godot editor
public:
	GDHover();
	~GDHover();

	void _process(double delta) override;

	void set_speed(const double p_speed);
	double get_speed() const;

	void set_amplitude(const double p_amplitude);
	double get_amplitude() const;
};

} // namespace godot
