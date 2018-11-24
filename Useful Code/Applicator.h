#pragma once
template <class BaseType, class ApplicatorType> class Applicator
{
public:
	Applicator() {}
	~Applicator() {}

	virtual BaseType GetApplied(const BaseType & base, const ApplicatorType & applicator) = 0;
	virtual void Apply(BaseType & base, const ApplicatorType & applicator)
	{
		base = GetApplied(base, applicator);
	}
};

