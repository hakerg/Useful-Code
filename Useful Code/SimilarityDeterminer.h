#pragma once
template <class Type, class NumType = double> class SimilarityDeterminer
{
public:
	SimilarityDeterminer() {}
	~SimilarityDeterminer() {}

	virtual NumType GetSimilarityScale(const Type & a, const Type & b) = 0; // <0, 1>
};

