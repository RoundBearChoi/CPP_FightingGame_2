#include "RenderTransparencyObj.h"

namespace RB::Render
{
    RenderTransparencyObj::RenderTransparencyObj(int totalFrames, float totalTransparency)
    {
        _totalFrames = totalFrames;
        _totalAmount = totalTransparency;
    }

    void RenderTransparencyObj::OnFixedUpdate()
    {
        
    }

    void RenderTransparencyObj::SetStart(float start)
    {
      if (_processedFrames == 0)
      {
        _start = start;
    
        //std::cout << std::endl;
        //std::cout << "setting start transparency: " << start  << std::endl;
    
        _end = start * _totalAmount;
    
        //std::cout << "setting end transparency: " << _end << std::endl;
      }
    }

    float RenderTransparencyObj::GetAmount()
    {
      if (_processedFrames == 0)
      {
        return 1.0f;
      }

      float dif = _end - _start;

      float perFrame = dif / float(_totalFrames);

      float result = perFrame * float(_processedFrames + 1);

      return _start + result;
      }
}
