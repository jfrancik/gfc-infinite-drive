#include "stdafx.h"
#include "MyGame.h"

CMyGame::CMyGame(void) : 
	m_car(640, 120, "car.png", 0),
	m_front(640, 120, "wheel.png", CColor::White(), 0),
	m_rear(640, 120, "wheel.png", CColor::White(), 0),
	m_back(0, 360, "landscape.jpg", 0)

	// to initialise more sprites here use a comma-separated list
{
	// TODO: add initialisation here
}

CMyGame::~CMyGame(void)
{
	// TODO: add destruction code here
}

/////////////////////////////////////////////////////
// Per-Frame Callback Funtions (must be implemented!)

void CMyGame::OnUpdate()
{
	Uint32 t = GetTime();

	// parameters
	const float ACC = 3;		// forward acceleration
	const float REV = 1;		// reverse acceleration
	const float BRAKE = 10;		// braking power

	// forward and reverse acceleration
	if (IsKeyDown(SDLK_d) || IsKeyDown(SDLK_RIGHT))
		m_back.Accelerate(-ACC, 0);
	if (IsKeyDown(SDLK_a) || IsKeyDown(SDLK_LEFT))
		m_back.Accelerate(REV, 0);
	
	// brakes
	if (IsKeyDown(SDLK_SPACE))
		if (abs(m_back.GetXVelocity()) <= BRAKE) m_back.SetVelocity(0, 0);
		else m_back.Accelerate(m_back.GetXVelocity() > 0 ? -BRAKE : BRAKE, 0);

	// TODO: Set angular velocity (Omega) for the wheels
	
	// updates
	m_back.Update(t);
	m_car.Update(t);
	m_front.Update(t);
	m_rear.Update(t);

	// infinite tiles
	if (m_back.GetX() <= -2 * 1280) m_back.Move(2 * 1280, 0);
	if (m_back.GetX() >= 1280) m_back.Move(-2 * 1280, 0);
}

void CMyGame::OnDraw(CGraphics* g)
{
	// background (two tiles)
	m_back.Draw(g);
	m_back.Move(2560, 0);
	m_back.Draw(g);
	m_back.Move(-2560, 0);

	// the car
	m_car.Draw(g);
	m_front.Draw(g);
	m_rear.Draw(g);
}

/////////////////////////////////////////////////////
// Game Life Cycle

// one time initialisation
void CMyGame::OnInitialize()
{
	m_front.Move(134, -35);
	m_rear.Move(-121, -35);
}

// called when a new game is requested (e.g. when F2 pressed)
// use this function to prepare a menu or a welcome screen
void CMyGame::OnDisplayMenu()
{
	StartGame();	// exits the menu mode and starts the game mode
}

// called when a new game is started
// as a second phase after a menu or a welcome screen
void CMyGame::OnStartGame()
{
}

// called when a new level started - first call for nLevel = 1
void CMyGame::OnStartLevel(Sint16 nLevel)
{
}

// called when the game is over
void CMyGame::OnGameOver()
{
}

// one time termination code
void CMyGame::OnTerminate()
{
}

/////////////////////////////////////////////////////
// Keyboard Event Handlers

void CMyGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_F4 && (mod & (KMOD_LALT | KMOD_RALT)))
		StopGame();
	if (sym == SDLK_F2)
		NewGame();
}

void CMyGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
}


/////////////////////////////////////////////////////
// Mouse Events Handlers

void CMyGame::OnMouseMove(Uint16 x,Uint16 y,Sint16 relx,Sint16 rely,bool bLeft,bool bRight,bool bMiddle)
{
}

void CMyGame::OnLButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnLButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonUp(Uint16 x,Uint16 y)
{
}
