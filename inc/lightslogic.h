#ifndef _SIGNAL_LOGIC_
#define _SIGNAL_LOGIC_

int SystemIsReset();
void SetStatusRed();
void SetStatusAmber();
void SetStatusGreen();
void ClearStatusRed();
void ClearStatusAmber();
void ClearStatusGreen();
int GetStatusRed();
int GetStatusAmber();
int GetStatusGreen();
int LightsCycled();

#endif
