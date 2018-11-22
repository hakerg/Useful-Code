#pragma once

template <class InputType, class OutputType> class DataTransformer
{
public:
	DataTransformer() {}
	~DataTransformer() {}

	virtual OutputType GetOutput(const InputType & input) = 0;

};
