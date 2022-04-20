
#include "InputCentral.hpp"

InputCentral::InputCentral()
	: _currentInput({ Input::None, "none" })
	, _event(SDL_Event())
{
}

InputCentral::InputStruct const& InputCentral::getCurrentInput() const
{
	return _currentInput;
}

SDL_Event InputCentral::getLastEvent()
{
	return _event;
}

int InputCentral::pollEvent()
{
	auto const lastInput = _currentInput;
	auto const returnValue = SDL_PollEvent(&_event);

	auto keyboardInput = _keyboardInputMap.find(_event.key.keysym.sym);
	auto mouseInput = _mouseInputMap.find(_event.button.button);

	if ((_event.type == SDL_KEYDOWN || _event.type == SDL_KEYUP) && keyboardInput != _keyboardInputMap.end())
	{
		keyboardInput->second.isPressed = _event.type == SDL_KEYDOWN;

		_currentInput = keyboardInput->second;
	}
	else if ((_event.type == SDL_MOUSEBUTTONDOWN || _event.type == SDL_MOUSEBUTTONUP) && mouseInput != _mouseInputMap.end())
	{
		mouseInput->second.isPressed = _event.type == SDL_MOUSEBUTTONDOWN;

		_currentInput = mouseInput->second;
	}
	else if (_event.type == SDL_QUIT)
	{
		_currentInput.type = Input::Quit;
	}
	else
	{
		_currentInput.type = Input::None;
	}

	// TODO: remove
	if (_currentInput.type != lastInput.type)
	{
		EZ_LOG(Logger::Level::Info, "New input: " << static_cast<int>(_currentInput.type));
	}

	return returnValue;
}
