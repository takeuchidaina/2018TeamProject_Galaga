#pragma once
#pragma once
#ifndef _INGAME_MGR_INCLUDE_
#define _INGAME_MGR_INCLUDE_


#include "Singleton.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "ShotMgr.h"
#include "hit.h"
#include "Struct.h"

class cPlayer;

class cInGameMgr : public cSingleton <cInGameMgr> {
	cInGameMgr();
	friend cSingleton <cInGameMgr>;
public:
	typedef enum {
		eBefore,	//���ۃQ�[�����n�܂�O�̂���
		eInGame,	//�Q�[�����
		eDeath,		//�v���C���[���S
		eRevival,	//�v���C���[�����@����Ȃ�����
		ePause,		//�|�[�Y���
		eTractor,	//����Ƃ�ꒆ
		ePReturn,	//�v���C���[�A��
		eResult,	//���U���g���
		eNextStage,	//���̃X�e�[�W��

					//�l����
					eInGameNone
	}eInGameScene;

private:
//	cEnemyMgr EnemyMgr;

	eInGameScene sceneflag;
	eInGameScene next_Sceneflag;
	eInGameScene Before_Sceneflag;

	void Init_Module(eInGameScene scene);
	void End_Module(eInGameScene scene);

	~cInGameMgr();



public:

	void Update();
	void Draw();
	void ChangeScene(eInGameScene scene);


};

#endif