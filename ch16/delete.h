#pragma once

namespace cp5
{
	struct Delete
	{
		template<typename T>
		auto operator() (T* p) const
		{
			delete p;
		}
	};
}