#pragma once

namespace RB::Controllers
{
	class iController
	{
	public:
		iController() = default;
		virtual ~iController() = default;

	public:
		virtual size_t GetHash() = 0;

	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}