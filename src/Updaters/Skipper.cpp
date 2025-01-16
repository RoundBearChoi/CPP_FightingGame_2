#include "Skipper.h"

namespace RB::Updaters
{
    void Skipper::SetSkipFrames(unsigned int skipFrames)
    {
        _skipFrames = skipFrames;
    }

    void Skipper::ClearSkipFrames()
    {
        _skipFrames = 0;
    }

    void Skipper::SetFunction(std::function<void()> func)
    {
        _func = func;
    }

    bool Skipper::DoFixedUpdate()
    {
        _totalFrameCount++;

        if (_frameCount < _skipFrames)
        {
            _frameCount++;

            return false;
        }
        else
        {
            _frameCount = 0;

            if (_func != nullptr)
            {
                _func();
            }

            return true;
        }
    }

    unsigned int Skipper::GetTotalFixedUpdateCount()
    {
        return _totalFrameCount;
    }
}