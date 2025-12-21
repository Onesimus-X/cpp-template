extends Node


func _ready() -> void:
	var example := ExampleClass.new()
	example.print_type(example)


func _on_gd_hover_position_changed(node: Object, new_pos: Vector2) -> void:
	print("the position of " + node.get_class() + " is now " + str(new_pos))
