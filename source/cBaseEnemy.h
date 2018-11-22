#pragma once

#ifndef _cBaseEnemy_INCLUDE_
#define _cBaseEnemy_INCLUDE_
#include "Struct.h"
#include <math.h>
#include "DxLib.h"


/*


*/



typedef struct {
	sPos vct;               // �x�N�g���px y
	sOBJPos mainpos ;//���C����x y r onActive
	sPos target;          //�ς���ʒu���ȁH
	int targetr;
	double spd;		  //���x
	double ang;	      //�����Ă���p�x
	int* graph;		 //�}�l�[�W���[������炤�摜�̃A�h���X�p
	int dir = 1;         //1�@�E�@-1�@��
	int width;           //��
	int hight;         //����
	int count; //�ړ��J�E���g
	int moveflg; //�ړ�����t���O 
	int attackflg;//�U���t���O
	double moveang[10];//
	double countflg[10];
	
}sEnemy;

class cBaseEnemy {

protected:
	sEnemy enemy;
public:

	     cBaseEnemy();//�R���X�g���N�^
		 cBaseEnemy(double,double,double,int,double,double,int ,int*);//�����t���R���X�g���N�^�[	
		virtual ~cBaseEnemy();//�f�X�g���N�^
		virtual	int Update();//�X�V����
		virtual int Draw();//�`�揈��
		virtual void Move();//�ړ�����
		//�����
		enum eActiveType {
			StartMove,
			NoActive,
			YesActive,
			NoMove,
		};
		//�E�ɂ��邩���ɂ��邩
		enum eRF {
		RIGHT = 1,
		LEFT= -1,
	};
		//
		virtual void Update2() {
			enemy.mainpos.cx = enemy.mainpos.pos.x + (enemy.width / 2);
			enemy.mainpos.cy = enemy.mainpos.pos.y + (enemy.hight / 2);
		}

		// x
		virtual	double GetEnemyX(){
			return enemy.mainpos.pos.x;
		}
		virtual	void SetEnemyX(double x) {
			enemy.mainpos.pos.x = x;
		}
		//y
		virtual	double GetEnemyY() {
			return enemy.mainpos.pos.y;
		}
		virtual	void SetEnemyY(double y) {
			enemy.mainpos.pos.y = y;
		}
		//attackflg
		virtual	int GetEnemyAttackflg() {
			return enemy.attackflg;
		}
		virtual	void SetEnemyAttackflg() {
			enemy.attackflg = true;
		}
		//ang
		virtual	double GetEnemyAngle() {
			return enemy.ang;
		}
		virtual	void SetEnemyAngle(double ang) {
			enemy.ang = ang;
		}
		virtual	void SetEnemyAddAngle(double ang) {
			enemy.ang += ang;
		}
		//activeflg
		virtual	int GetEnemyOnActive() {
			return enemy.mainpos.onActive;
		}
		virtual	void SetEnemyOnActive() {
			if (enemy.mainpos.onActive == YesActive)enemy.mainpos.onActive = NoActive;
			else enemy.mainpos.onActive = YesActive;
		}
		//r
		virtual	double GetEnemyR(){
			return enemy.mainpos.r;
		}
		virtual	void SetEnemyR(double r) {
			enemy.mainpos.r = r;
		}
		//cx
		virtual	double GetEnemyCx() {
			return enemy.mainpos.cx;
		}
		virtual	void SetEnemyCx(double cx) {
			enemy.mainpos.cx = cx;
		}
		//cy
		virtual	double GetEnemyCy() {
			return enemy.mainpos.cy;
		}
		virtual	void SetEnemyCy(double cy) {
			enemy.mainpos.cy = cy;
		}
};

#endif // !_cBaseEnemy_INCLUDE_
