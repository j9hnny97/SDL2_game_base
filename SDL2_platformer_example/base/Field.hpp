#ifndef FIELD_HPP
#define FIELD_HPP

#include <functional>
#include <vector>

template <class T>
class Field
{
public:
	Field(T const& value)
		: _value(value)
	{
	}

	void addObserver(std::function<void(T)> function)
	{
		_observerFunctions.emplace_back(function);

		function(_value);
	}

	T getValue()
	{
		return _value;
	}

	template <class newT>
	newT getValue()
	{
		return static_cast<newT>(_value);
	}

	void setValue(T const& value)
	{
		_value = value;

		for (auto const& function : _observerFunctions)
		{
			function(value);
		}
	}

	void operator=(T const& value)
	{
		setValue(value);
	}

private:
	std::vector<std::function<void(T)>> _observerFunctions;
	T _value;
};

#endif