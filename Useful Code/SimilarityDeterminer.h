#pragma once
template <class Type, class NumType = double> class SimilarityDeterminer
{
public:
	SimilarityDeterminer() {}
	virtual ~SimilarityDeterminer() {}

	virtual NumType GetSimilarityScale(const Type & a, const Type & b) const = 0; // <0, 1>
};

