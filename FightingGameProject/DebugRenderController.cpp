//#include "DebugRenderController.h"
//
//namespace RB::Render
//{
//	DebugRenderController::DebugRenderController()
//	{
//
//	}
//
//	DebugRenderController::~DebugRenderController()
//	{
//		delete _spriteRenderer;
//		delete _lineRenderer;
//	}
//
//	void DebugRenderController::Init()
//	{
//		//sprite renderer
//		_spriteRenderer = new SpriteRenderer();
//
//		_spriteRenderer->Init();
//
//		_spriteRenderer->LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteID::x_white);
//		_spriteRenderer->LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteID::white_sq_tr80);
//
//		//line renderer
//		_lineRenderer = new LineRenderer();
//
//		_lineRenderer->Init();
//	}
//
//	void DebugRenderController::OnUpdate()
//	{
//
//	}
//
//	void DebugRenderController::OnFixedUpdate()
//	{
//
//	}
//	iSpriteRenderer* DebugRenderController::GetSpriteRenderer()
//	{
//		return _spriteRenderer;
//	}
//
//	iLineRenderer* DebugRenderController::GetLineRenderer()
//	{
//		return _lineRenderer;
//	}
//}