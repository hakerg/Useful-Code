#pragma once
class Drawable
{
public:
	Drawable();
	virtual ~Drawable();

	virtual void Draw() const = 0;
};

