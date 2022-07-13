#include "PlayerProxy.h"



PlayerProxy::PlayerProxy(Player* ptrPlayer)
{
	player = ptrPlayer;
}
PlayerProxy::~PlayerProxy()
{

}
void PlayerProxy::DecrementLife()
{
	player->DecrementLife();
}
unsigned PlayerProxy::GetLives()
{
	return player->GetLives();
}
unsigned PlayerProxy::GetScore()
{
	return player->GetScore();
}
void PlayerProxy::AddToScore(unsigned points)
{
	player->AddToScore(points);
}

