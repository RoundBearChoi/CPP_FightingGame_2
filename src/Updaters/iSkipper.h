#pragma once

#include <functional>

namespace RB::Updaters
{
    class iSkipper
    {
    public:
        virtual void SetSkipFrames(unsigned int skipFrames) = 0;
		virtual void ClearSkipFrames() = 0;
		virtual void SetFunction(std::function<void()> func) = 0;
		virtual bool DoFixedUpdate() = 0;
		virtual unsigned int GetTotalFixedUpdateCount() = 0;
    };
}