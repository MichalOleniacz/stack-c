//
// Created by Michał Oleniacz on 08/06/2023.
//

#include "utils.h"

bool inRangeEq(int val, int l, int h)
{
    if ( val >= l && val <= h)
        return true;
    return false;
}

bool inRange(int val, int l, int h)
{
    if ( val >= l && val < h)
        return true;
    return false;
}
