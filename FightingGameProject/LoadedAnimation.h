#pragma once

namespace RB::Animations
{
	class LoadedAnimation
	{
	public:
		LoadedAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes);
		~LoadedAnimation();

	public:

	private:
		unsigned int _widthIndexes;
		unsigned int _heightIndexes;
		unsigned int _totalIndexes;
	};
}