#ifndef INPUT_CENTRAL_HPP
#define INPUT_CENTRAL_HPP

#include "Logger.hpp"

#include <map>
#include <SDL_events.h>
#include <string>

class InputCentral
{
public:
	InputCentral();

	enum class Input
	{
		Up,
		Down,
		Left,
		Right,
		Jump,
		MouseLeft,
		MouseMiddle,
		MouseRight,

		Quit,
		None
	};

	struct InputStruct
	{
		Input type;
		std::string debug;
		bool isPressed = false;
	};

	InputStruct const& getCurrentInput() const;
	SDL_Event getLastEvent();
	int pollEvent();

private:
	InputStruct _currentInput;
	SDL_Event _event;

	std::map<SDL_Keycode, InputStruct> _keyboardInputMap =
	{
		{SDL_KeyCode::SDLK_w, {Input::Up, "Up"}},
		{SDL_KeyCode::SDLK_s, {Input::Down, "Down"}},
		{SDL_KeyCode::SDLK_a, {Input::Left, "Left"}},
		{SDL_KeyCode::SDLK_d, {Input::Right, "Right"}},
		{SDL_KeyCode::SDLK_SPACE, {Input::Jump, "Jump"}}
	};

	std::map<int, InputStruct> _mouseInputMap =
	{
		{SDL_BUTTON_LEFT, {Input::MouseLeft, "MouseLeft"}},
		{SDL_BUTTON_MIDDLE, {Input::MouseMiddle, "MouseMiddle"}},
		{SDL_BUTTON_RIGHT, {Input::MouseRight, "MouseRight"}}
	};
};

#endif