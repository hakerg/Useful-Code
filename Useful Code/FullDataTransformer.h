#pragma once
#include "DataTransformer.h"
template <class DataType, class TransformedDataType> class FullDataTransformer :
	public DataTransformer<DataType, DataType>
{
public:

	DataTransformer<DataType, TransformedDataType> * Transformer;
	DataTransformer<TransformedDataType, DataType> * ReverseTransformer;


	FullDataTransformer(DataTransformer<DataType, TransformedDataType> * transformer, DataTransformer<TransformedDataType, DataType> * reverseTransformer)
		: Transformer(transformer), ReverseTransformer(reverseTransformer) {}
	virtual ~FullDataTransformer() {}

	// Odziedziczono za poœrednictwem elementu DataTransformer
	virtual DataType GetOutput(const DataType & input) const override
	{
		return ReverseTransformer->GetOutput(Transformer->GetOutput(input));
	}
};

