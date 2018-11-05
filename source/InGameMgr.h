#pragma once
#pragma once
#ifndef _INGAME_MGR_INCLUDE_
#define _INGAME_MGR_INCLUDE_




class cInGameMgr {
private:
	typedef enum {
		eBefore,	//���ۃQ�[�����n�܂�O�̂���
		eInGame,	//�Q�[�����
		eRevival,	//�v���C���[����
		ePause,		//�|�[�Y���
		eTractor,	//����Ƃ�ꒆ
		ePReturn,	//�v���C���[�A��
		eResult,	//���U���g���
		eNextStage,	//���̃X�e�[�W��

		//�l����
		eInGameNone,
	}eInGameScene;

	eInGameScene sceneflag;
	eInGameScene next_Sceneflag;

	void Init_Module(eInGameScene scene);
	void End_Module(eInGameScene scene);


public:
	cInGameMgr();
	~cInGameMgr();

	void Update();
	void Draw();
	void ChangeScene(eInGameScene scene);
};

#endif