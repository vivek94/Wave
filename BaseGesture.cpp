#include "BaseGesture.hpp"
#include <iostream>

using namespace std;

gestureState BaseGesture::isGestureRecognized (ScreenPoint currentPosition)
{
    //cout << "Current position: " << currentPosition.x << " " << currentPosition.y << endl;

    if (tracking == true)
    {
        if (isFinishPosition(currentPosition) == true)
        {
            tracking = false;
            return FINISHED;
        }
        else if (isStillValid(currentPosition) == true)
        {
            prevPosition = currentPosition;
            return TRACKING_VALID;
        }
        
        tracking = false;
        return TRACKING_NOTVALID;
    }
    else
    {
        if (isStartingPosition(currentPosition) == true)
        {
            prevPosition = currentPosition;
            tracking = true;
            return STARTED;
        }

        return NOT_TRACKING;
    }
}
