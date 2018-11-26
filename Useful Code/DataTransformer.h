#pragma once

template <class InputType, class OutputType> class DataTransformer
{
public:
	DataTransformer() {}
	virtual ~DataTransformer() {}

	virtual OutputType GetOutput(const InputType & input) const = 0;

};
