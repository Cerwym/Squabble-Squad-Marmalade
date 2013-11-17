#ifndef TRANSITIONMANAGER_H_
#define TRANSITIONMANAGER_H_

#include "IwGx.h"

class TransitionManager
{
public:
	void Init();
	void FinishTransition();

	bool TransitionOut(CIw2DImage* img, double speed);
	bool TransitionIn(CIw2DImage* img, double speed);
	bool TransitionBetween(CIw2DImage* start, CIw2DImage* end, double speed);

private:
	CIwTexture* CaptureScreen();
	bool isFinished();
	void Fade(double transitionSpeed);
	void Fade(CIwTexture* start, CIwTexture* end, double transitionSpeed);
	void CaptureStartScreen();
	void CaptureEndScreen();

	CIwTexture* m_StartTexture;
	CIwTexture* m_EndTexture;
	CIwMaterial* startMat;
	CIwMaterial* endMat;

	double m_alphaValue;
	bool m_HasStarted;
};

#endif TRANSITIONMANAGER_H_
