#pragma once
template <class BaseType, class ApplicatorType> class Applicator
{
public:
	Applicator() {}
	virtual ~Applicator() {}

	virtual BaseType GetApplied(const BaseType & base, const ApplicatorType & applicator) const = 0;

	virtual void Apply(BaseType & base, const ApplicatorType & applicator) const
	{
		base = GetApplied(base, applicator);
	}
};

