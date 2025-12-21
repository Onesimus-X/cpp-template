#include "hover_sprite.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDHover::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_amplitude"), &GDHover::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &GDHover::set_amplitude);

	ClassDB::bind_method(D_METHOD("get_speed"), &GDHover::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &GDHover::set_speed);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,20,0.01"), "set_speed", "get_speed");
}

GDHover::GDHover() {
	// Initialize any variables here
	time_passed = 0.0;
	amplitude = 10.0;
	speed = 1.0;
}

GDHover::~GDHover() {
	// Add your cleanup here
}

void GDHover::_process(double delta) {
	time_passed += speed * delta;

	//Vector2 new_position = Vector2(10 + (10.0 * sin(time_passed * 2.0)), 10 + (10.0 * cos(time_passed * 1.5)));

	Vector2 new_position = Vector2(
		amplitude + (amplitude * sin(time_passed * 2.0)),
		amplitude + (amplitude * cos(time_passed * 1.5))
	);

	set_position(new_position);
}

void GDHover::set_amplitude(const double p_amplitude) {
	amplitude = p_amplitude;
}

double GDHover::get_amplitude() const {
	return amplitude;
}

void GDHover::set_speed(const double p_speed) {
	speed = p_speed;
}

double GDHover::get_speed() const {
	return speed;
}


