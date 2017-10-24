
#ifndef		__COMMON_H__
#define	__COMMON_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <memory.h>

#define	DEFLT_GAME_POOL_SIZE			(28)
#define	EVERY_COLORS					(16)
#define	SEVEN_TYPES						(7)
#define	ROTATE_TYPES					(4)
#define	ROTATE_MASK						(3)
#define	ZERO							(0)
#define	DEFLT_Y_POS_ONE					(1)
#define	DEFLT_Y_POS_TWO					(2)
#define	DEFLT_X_POS						(6)
#define	NEXT_TYPE						(3)
#define	ERASEDCOUNT						(4)

#define	MANAGER_Y_TYPE_1				(0)
#define	MANAGER_Y_TYPE_2				(1)
#define	MANAGER_Y_TYPE_3				(2)
#define	MANAGER_Y_TYPE_4				(3)

#define	COL_BEGIN						(2)
#define	COL_END							(14)
#define	ROW_BEGIN						(4)
#define	ROW_END							(26)

#define	BOUNDARY_MASK					(0xF000)
#define	DEFLT_Y_POS_MASK				(0xFF00)
#define	ONE_LINE_MAX_MASK				(0xFFFFU)
#define	BOX_POS_MASK_1					(0x000F)
#define	BOX_POS_MASK_2					(0x00F0)
#define	BOX_POS_MASK_4					(0x0F00)
#define	BOX_POS_MASK_8					(0xF000)
#define	BOX_MOV_MASK_0					(0x0)
#define	BOX_MOV_MASK_4					(0x4)
#define	BOX_MOV_MASK_8					(0x8)
#define	BOX_MOV_MASK_C					(0xC)
#define	RIGHT_TEXT_POS_MASK				(0xE)
#define	MAX_TEXT_POS_MASK				(0xF0)

#define	ERASER_SCORE_LVL_0				(0)
#define	ERASER_SCORE_LVL_1				(10)
#define	ERASER_SCORE_LVL_2				(30)
#define	ERASER_SCORE_LVL_3				(90)
#define	ERASER_SCORE_LVL_4				(150)

#define	PAUSE_PLAY						(13)


#endif		// __COMMON_H__




#ifndef		__PREDEFINE_H__
#define	__PREDEFINE_H__


#ifdef _MSC_VER  // M$�ı�����Ҫ���������չ�
#if _MSC_VER <= 1200  // VC6�����°汾
#error ���ǲ��ǻ�����VC6����
#else  // VC6���ϰ汾
#if _MSC_VER >= 1600  // ��˵VC10�����ϰ汾��stdint.h��
#include <stdint.h>
#else  // VC10���°汾���Լ�����int8_t��uint16_t�Լ�uint32_t
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef unsigned int	uint32_t;
#endif
#ifndef __cplusplus  // ��˵VC��û��stdbool.h������C++���룬�Լ�����bool
typedef int bool;
#define true 1
#define false 0
#endif
#endif
#else  // �����ı���������˵
#include <stdint.h>
#ifndef __cplusplus  // ����C++���룬��Ҫstdbool.h���bool
#include <stdbool.h>
#endif
#endif

#endif		// __PREDEFINE_H__




//=========================================================
// 7�ַ����4��ת״̬��4λΪһ�У�
class block
{
public:
	uint16_t gs_uTetrisTable[SEVEN_TYPES][ROTATE_TYPES];
	block()
	{
		gs_uTetrisTable[0][0] = 0x00F0U;
		gs_uTetrisTable[0][1] = 0x2222U;
		gs_uTetrisTable[0][2] = 0x00F0U;
		gs_uTetrisTable[0][3] = 0x2222U;
		// I��
		gs_uTetrisTable[1][0] = 0x0072U;
		gs_uTetrisTable[1][1] = 0x0262U;
		gs_uTetrisTable[1][2] = 0x0270U;
		gs_uTetrisTable[1][3] = 0x0232U;
		// T��
		gs_uTetrisTable[2][0] = 0x0223U;
		gs_uTetrisTable[2][1] = 0x0074U;
		gs_uTetrisTable[2][2] = 0x0622U;
		gs_uTetrisTable[2][3] = 0x0170U;
		// L��
		gs_uTetrisTable[3][0] = 0x0226U;
		gs_uTetrisTable[3][1] = 0x0470U;
		gs_uTetrisTable[3][2] = 0x0322U;
		gs_uTetrisTable[3][3] = 0x0071U;
		// J��
		gs_uTetrisTable[4][0] = 0x0063U;
		gs_uTetrisTable[4][1] = 0x0264U;
		gs_uTetrisTable[4][2] = 0x0063U;
		gs_uTetrisTable[4][3] = 0x0264U;
		// Z��
		gs_uTetrisTable[5][0] = 0x006CU;
		gs_uTetrisTable[5][1] = 0x0462U;
		gs_uTetrisTable[5][2] = 0x006CU;
		gs_uTetrisTable[5][3] = 0x0462U;
		// S��
		gs_uTetrisTable[6][0] = 0x0660U;
		gs_uTetrisTable[6][1] = 0x0660U;
		gs_uTetrisTable[6][2] = 0x0660U;
		gs_uTetrisTable[6][3] = 0x0660U;
		// O��

	}

};

// =============================================================================
// ��ʼ״̬����Ϸ��
// ÿ��Ԫ�ر�ʾ��Ϸ�ص�һ�У��±�������Ϸ�صײ�
// ���˸���2��1���ײ�2ȫ��Ϊ1�����ڽ�����ײ���
// ����һ����Ϸ�صĿ��Ϊ12��
// �����Ҫ��ͳ��10�У�ֻ���������1���ɣ�0xE007������Ȼ��ʾ��ز���ҲҪ��֮�Ķ�
// ��ĳ��Ԫ��Ϊ0xFFFFUʱ��˵�������ѱ�����
// ����4�����ڸ����飬����ʾ����
// �ٳ�ȥ�ײ�2�У���ʾ��������Ϸ�ظ߶�Ϊ22��
class pool
{
public:
	uint16_t gs_uInitialTetrisPool[DEFLT_GAME_POOL_SIZE];
	pool()
	{
		gs_uInitialTetrisPool[0] = 0xC003U;
		gs_uInitialTetrisPool[1] = 0xC003U;
		gs_uInitialTetrisPool[2] = 0xC003U;
		gs_uInitialTetrisPool[3] = 0xC003U;
		gs_uInitialTetrisPool[4] = 0xC003U;
		gs_uInitialTetrisPool[5] = 0xC003U;
		gs_uInitialTetrisPool[6] = 0xC003U;
		gs_uInitialTetrisPool[7] = 0xC003U;
		gs_uInitialTetrisPool[8] = 0xC003U;
		gs_uInitialTetrisPool[9] = 0xC003U;
		gs_uInitialTetrisPool[10] = 0xC003U;
		gs_uInitialTetrisPool[11] = 0xC003U;
		gs_uInitialTetrisPool[12] = 0xC003U;
		gs_uInitialTetrisPool[13] = 0xC003U;
		gs_uInitialTetrisPool[14] = 0xC003U;
		gs_uInitialTetrisPool[15] = 0xC003U;
		gs_uInitialTetrisPool[16] = 0xC003U;
		gs_uInitialTetrisPool[17] = 0xC003U;
		gs_uInitialTetrisPool[18] = 0xC003U;
		gs_uInitialTetrisPool[19] = 0xC003U;
		gs_uInitialTetrisPool[20] = 0xC003U;
		gs_uInitialTetrisPool[21] = 0xC003U;
		gs_uInitialTetrisPool[22] = 0xC003U;
		gs_uInitialTetrisPool[23] = 0xC003U;
		gs_uInitialTetrisPool[24] = 0xC003U;
		gs_uInitialTetrisPool[25] = 0xC003U;
		gs_uInitialTetrisPool[26] = 0xFFFFU;
		gs_uInitialTetrisPool[27] = 0xFFFFU;
	}
};



class data
{
public:
	typedef struct TetrisManager  // ����ṹ��洢��Ϸ�������
	{
		uint16_t pool[DEFLT_GAME_POOL_SIZE];  // ��Ϸ��
		int8_t x;  // ��ǰ����x���꣬�˴�����Ϊ�������Ͻ�����
		int8_t y;  // ��ǰ����y����
		int8_t type[NEXT_TYPE];  // ��ǰ����һ��������һ����������
		int8_t orientation[NEXT_TYPE];  // ��ǰ����һ��������һ��������ת״̬
		unsigned score;  // �÷�
		unsigned erasedCount[ERASEDCOUNT];  // ������
		unsigned erasedTotal;  // ��������
		unsigned tetrisCount[SEVEN_TYPES];  // ��������
		unsigned tetrisTotal;  // ��������
		bool dead;  // ��
	} TetrisManager;

	// =============================================================================
	typedef struct TetrisControl  // ����ṹ��洢�����������
	{
		bool pause;  // ��ͣ
		bool clockwise;  // ��ת����˳ʱ��Ϊtrue
		int8_t direction;  // �ƶ�����0�����ƶ� 1�����ƶ�
						   // ��Ϸ����ÿ�����ɫ
						   // ���ڴ˰汾�ǲ�ɫ�ģ�������Ϸ�������޷��洢��ɫ��Ϣ
						   // ��Ȼ�����ֻʵ�ֵ�ɫ��ģ���û��Ҫ�����������
		int8_t color[DEFLT_GAME_POOL_SIZE][EVERY_COLORS];
	} TetrisControl;
};

// =============================================================================

class game : public pool, public block, public data
{
public:
	friend unsigned _stdcall TetrisStart(void*ip);		// ��Ϸ�̺߳���

#ifndef		__GAMEDEFINE_H__
#define	__GAMEDEFINE_H__

	HANDLE g_hConsoleOutput;  // ����̨������
							  // =============================================================================
#endif		// __GAMEDEFINE_H__


							  // =============================================================================
							  // ��ʼ����Ϸ
	game() {
		uint32_t threadIDTetris;

		// ��һ����Ϸ�����߳�
		HANDLE hThreadTetris = (HANDLE)_beginthreadex(NULL,
			0,
			TetrisStart,
			this,
			CREATE_SUSPENDED,
			&threadIDTetris);


		//	ResumeThread(hThreadBGM);
		// ��Ϸ�����̺߳���

		ResumeThread(hThreadTetris);




		WaitForSingleObject(hThreadTetris, INFINITE);


		CloseHandle(hThreadTetris);


	}
	void initGame(TetrisManager *manager, TetrisControl *control)
	{
		CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };  // �����Ϣ

		g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ����̨������
		SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // ���ù������
		SetConsoleTitleA("����˹����");

		restartGame(manager, control);
	}

	// =============================================================================
	// ���¿�ʼ��Ϸ
	void restartGame(TetrisManager *manager, TetrisControl *control)
	{
		memset(manager, ZERO, sizeof(TetrisManager));  // ���������

													   // ��ʼ����Ϸ��
		memcpy(manager->pool, gs_uInitialTetrisPool, sizeof(uint16_t[DEFLT_GAME_POOL_SIZE]));
		srand((unsigned)time(NULL));  // �����������

		manager->type[1] = rand() % SEVEN_TYPES;  // ��һ��
		manager->orientation[1] = rand() & ROTATE_MASK;

		manager->type[2] = rand() % SEVEN_TYPES;  // ����һ��
		manager->orientation[2] = rand() & ROTATE_MASK;

		memset(control, ZERO, sizeof(TetrisControl));  // ���������

		giveTetris(manager);  // �趨��һ����������
		setPoolColor(manager, control);  // ���磺������ɫ
	}

	// =============================================================================
	// ��һ������
	void giveTetris(TetrisManager *manager)
	{
		uint16_t tetris;

		manager->type[0] = manager->type[1];  // ��һ��������Ϊ��ǰ
		manager->orientation[0] = manager->orientation[1];

		manager->type[1] = manager->type[2];// ����һ���÷���Ϊ��һ��
		manager->orientation[1] = manager->orientation[2];

		manager->type[2] = rand() % SEVEN_TYPES;// �����������һ������
		manager->orientation[2] = rand() & ROTATE_MASK;

		tetris = gs_uTetrisTable[manager->type[0]][manager->orientation[0]];  // ��ǰ����

																			  // ���õ�ǰ����y���꣬��֤�ո���ʱֻ��ʾ����������һ��
																			  // ����ʵ��ʹ����ҿ����Ժܿ���ٶȽ��������ڲ���ʾ�����Ķ���4����
		if (tetris & BOUNDARY_MASK)
		{
			manager->y = ZERO;
		}
		else
		{
			manager->y = (tetris & DEFLT_Y_POS_MASK) ? DEFLT_Y_POS_ONE : DEFLT_Y_POS_TWO;
		}
		manager->x = DEFLT_X_POS;  // ���õ�ǰ����x����

		if (checkCollision(manager))  // ��⵽��ײ
		{
			manager->dead = true;  // �����Ϸ����
		}
		else  // δ��⵽��ײ
		{
			insertTetris(manager);  // ����ǰ���������Ϸ��
		}

		++manager->tetrisTotal;  // ��������
		++manager->tetrisCount[manager->type[0]];  // ��Ӧ������

		printNextTetris(manager);  // ��ʾ��һ������
		printScore(manager);  // ��ʾ�÷���Ϣ
	}

	// =============================================================================
	// ��ײ���
	bool checkCollision(const TetrisManager *manager)
	{
		// ��ǰ����
		uint16_t tetris = gs_uTetrisTable[manager->type[0]][manager->orientation[0]];
		uint16_t dest = 0;

		// ��ȡ��ǰ��������Ϸ���е�����
		// ��Ϸ������x y��С������Ϣ�����͵��ߴ����16λ�޷�������
		dest |= (((manager->pool[manager->y + MANAGER_Y_TYPE_1] >> manager->x) << BOX_MOV_MASK_0) & BOX_POS_MASK_1);
		dest |= (((manager->pool[manager->y + MANAGER_Y_TYPE_2] >> manager->x) << BOX_MOV_MASK_4) & BOX_POS_MASK_2);
		dest |= (((manager->pool[manager->y + MANAGER_Y_TYPE_3] >> manager->x) << BOX_MOV_MASK_8) & BOX_POS_MASK_4);
		dest |= (((manager->pool[manager->y + MANAGER_Y_TYPE_4] >> manager->x) << BOX_MOV_MASK_C) & BOX_POS_MASK_8);

		// ����ǰ������Ŀ����������ص�����ײ������λ��Ľ����Ϊ0
		return ((dest & tetris) != ZERO);
	}

	// =============================================================================
	// ���뷽��
	void insertTetris(TetrisManager *manager)
	{
		// ��ǰ����
		uint16_t tetris = gs_uTetrisTable[manager->type[0]][manager->orientation[0]];

		// ��ǰ����ÿ4λȡ����λ����Ϸ����Ӧλ�ã�����ɲ��뷽��
		manager->pool[manager->y + MANAGER_Y_TYPE_1] |= (((tetris >> BOX_MOV_MASK_0) & BOX_POS_MASK_1) << manager->x);
		manager->pool[manager->y + MANAGER_Y_TYPE_2] |= (((tetris >> BOX_MOV_MASK_4) & BOX_POS_MASK_1) << manager->x);
		manager->pool[manager->y + MANAGER_Y_TYPE_3] |= (((tetris >> BOX_MOV_MASK_8) & BOX_POS_MASK_1) << manager->x);
		manager->pool[manager->y + MANAGER_Y_TYPE_4] |= (((tetris >> BOX_MOV_MASK_C) & BOX_POS_MASK_1) << manager->x);
	}

	// =============================================================================
	// �Ƴ�����
	void removeTetris(TetrisManager *manager)
	{
		// ��ǰ����
		uint16_t tetris = gs_uTetrisTable[manager->type[0]][manager->orientation[0]];

		// ��ǰ����ÿ4λȡ������λȡ����λ�뵽��Ϸ����Ӧλ�ã�������Ƴ�����
		manager->pool[manager->y + MANAGER_Y_TYPE_1] &= ~(((tetris >> BOX_MOV_MASK_0) & BOX_POS_MASK_1) << manager->x);
		manager->pool[manager->y + MANAGER_Y_TYPE_2] &= ~(((tetris >> BOX_MOV_MASK_4) & BOX_POS_MASK_1) << manager->x);
		manager->pool[manager->y + MANAGER_Y_TYPE_3] &= ~(((tetris >> BOX_MOV_MASK_8) & BOX_POS_MASK_1) << manager->x);
		manager->pool[manager->y + MANAGER_Y_TYPE_4] &= ~(((tetris >> BOX_MOV_MASK_C) & BOX_POS_MASK_1) << manager->x);
	}

	// =============================================================================
	// ������ɫ
	void setPoolColor(const TetrisManager *manager, TetrisControl *control)
	{
		// ������ʾ��Ϸ��ʱ����Ҫ����Ϸ�����ж�ĳһ�����з������ʾ��Ӧ�������ɫ
		// ����ֻ�����ü��ɣ�û��Ҫ���
		// ���ƶ�������һ������ʱ����

		int8_t i, x, y;

		// ��ǰ����
		uint16_t tetris = gs_uTetrisTable[manager->type[0]][manager->orientation[0]];

		for (i = 0; i < EVERY_COLORS; ++i)
		{
			y = (i >> MANAGER_Y_TYPE_3) + manager->y;  // �����õ���
			if (y > ROW_END)  // �����ײ�����
			{
				break;
			}
			x = (i & MANAGER_Y_TYPE_4) + manager->x;  // �����õ���
			if ((tetris >> i) & MANAGER_Y_TYPE_2)  // ���ĵ�С�������ڵ�ǰ��������
			{
				control->color[y][x] = (manager->type[0] | BOX_MOV_MASK_8);  // ������ɫ
			}
		}
	}

	// =============================================================================
	// ��ת����
	void rotateTetris(TetrisManager *manager, TetrisControl *control)
	{
		int8_t ori = manager->orientation[0];  // ��¼ԭ��ת״̬

		removeTetris(manager);  // ���ߵ�ǰ����

								// ˳/��ʱ����ת
		manager->orientation[0] = (control->clockwise) ? ((ori + MANAGER_Y_TYPE_2) & MANAGER_Y_TYPE_4) : ((ori + MANAGER_Y_TYPE_4) & MANAGER_Y_TYPE_4);

		if (checkCollision(manager))  // ��⵽��ײ
		{
			manager->orientation[0] = ori;  // �ָ�Ϊԭ��ת״̬
			insertTetris(manager);  // ���뵱ǰ���顣����״̬û�ı䣬����Ҫ������ɫ
		}
		else
		{
			insertTetris(manager);  // ���뵱ǰ����
			setPoolColor(manager, control);  // ������ɫ
			printCurrentTetris(manager, control);  // ��ʾ��ǰ����
		}
	}

	// =============================================================================
	// ˮƽ�ƶ�����
	void horzMoveTetris(TetrisManager *manager, TetrisControl *control)
	{
		int x = manager->x;  // ��¼ԭ��λ��

		removeTetris(manager);  // ���ߵ�ǰ����
		control->direction == 0 ? (--manager->x) : (++manager->x);  // ��/���ƶ�

		if (checkCollision(manager))  // ��⵽��ײ
		{
			manager->x = x;  // �ָ�Ϊԭ��λ��
			insertTetris(manager);  // ���뵱ǰ���顣����λ��û�ı䣬����Ҫ������ɫ
		}
		else
		{
			insertTetris(manager);  // ���뵱ǰ����
			setPoolColor(manager, control);  // ������ɫ
			printCurrentTetris(manager, control);  // ��ʾ��ǰ����
		}
	}

	// =============================================================================
	// �����ƶ�����
	void moveDownTetris(TetrisManager *manager, TetrisControl *control)
	{
		int8_t y = manager->y;  // ��¼ԭ��λ��

		removeTetris(manager);  // ���ߵ�ǰ����
		++manager->y;  // �����ƶ�

		if (checkCollision(manager))  // ��⵽��ײ
		{
			manager->y = y;  // �ָ�Ϊԭ��λ��
			insertTetris(manager);  // ���뵱ǰ���顣����λ��û�ı䣬����Ҫ������ɫ
			if (checkErasing(manager, control))  // ��⵽����
			{
				printTetrisPool(manager, control);  // ��ʾ��Ϸ��
			}
		}
		else
		{
			insertTetris(manager);  // ���뵱ǰ����
			setPoolColor(manager, control);  // ������ɫ
			printCurrentTetris(manager, control);  // ��ʾ��ǰ����
		}
	}

	// =============================================================================
	// ����ֱ�����
	void dropDownTetris(TetrisManager *manager, TetrisControl *control)
	{
		removeTetris(manager);  // ���ߵ�ǰ����
		for (; manager->y < ROW_END; ++manager->y)  // ��������
		{
			if (checkCollision(manager))  // ��⵽��ײ
			{
				break;
			}
		}
		--manager->y;  // ����һ��Ȼû����ײ

		insertTetris(manager);  // ���뵱ǰ����
		setPoolColor(manager, control);  // ������ɫ

		checkErasing(manager, control);  // �������
		printTetrisPool(manager, control);  // ��ʾ��Ϸ��
	}

	// =============================================================================
	// ���м��
	bool checkErasing(TetrisManager *manager, TetrisControl *control)
	{
		// ���е÷�
		static const unsigned scores[5] = {
			ERASER_SCORE_LVL_0,				// ���÷�
			ERASER_SCORE_LVL_1,				// ��ȥһ��10��
			ERASER_SCORE_LVL_2,				// ��������30��
			ERASER_SCORE_LVL_3,				// ��������90��
			ERASER_SCORE_LVL_4				// ��������150�� 
		};
		int8_t count = ZERO;
		int8_t k = ZERO;
		int8_t y = manager->y + MANAGER_Y_TYPE_4;  // �������ϼ��

		do
		{
			if (y < ROW_END && manager->pool[y] == ONE_LINE_MAX_MASK)  // ��Ч��������һ��������
			{
				++count;
				// ����һ�з���
				memmove(manager->pool + 1, manager->pool, sizeof(uint16_t)* y);
				// ��ɫ�����Ԫ����֮�ƶ�
				memmove(control->color[1], control->color[0], sizeof(int8_t[EVERY_COLORS]) * y);
			}
			else
			{
				--y;
				++k;
			}
		} while (y >= manager->y && k < ERASEDCOUNT);

		manager->erasedTotal += count;  // ��������
		manager->score += scores[count];  // �÷�

		if (count > ZERO)
		{
			++manager->erasedCount[count - MANAGER_Y_TYPE_2];  // ����
		}

		giveTetris(manager);  // ����һ������
		setPoolColor(manager, control);  // ������ɫ

		return (count > ZERO);
	}

	// =============================================================================
	// ������
	void keydownControl(TetrisManager *manager, TetrisControl *control, int key)
	{
		if (key == PAUSE_PLAY)  // ��ͣ/�����ͣ
		{
			control->pause = !control->pause;
		}

		if (control->pause)  // ��ͣ״̬����������
		{
			return;
		}

		switch (key)
		{
		case 'w':
		case 'W':
		case '8':
		case 72:  // ��
			control->clockwise = true;  // ˳ʱ����ת
			rotateTetris(manager, control);  // ��ת����
			break;
		case 'a':
		case 'A':
		case '4':
		case 75:  // ��
			control->direction = 0;  // �����ƶ�
			horzMoveTetris(manager, control);  // ˮƽ�ƶ�����
			break;
		case 'd':
		case 'D':
		case '6':
		case 77:  // ��
			control->direction = 1;  // �����ƶ�
			horzMoveTetris(manager, control);  // ˮƽ�ƶ�����
			break;
		case 's':
		case 'S':
		case '2':
		case 80:  // ��
			moveDownTetris(manager, control);  // �����ƶ�����
			break;
		case ' ':  // ֱ�����
			dropDownTetris(manager, control);
			break;
		case '0':  // ��ת
			control->clockwise = false;  // ��ʱ����ת
			rotateTetris(manager, control);  // ��ת����
			break;
		default:
			break;
		}
	}

	// =============================================================================
	// ��ȫ�Ƕ�λ
	void gotoxyWithFullwidth(short x, short y)
	{
		static COORD cd;

		cd.X = (short)(x << MANAGER_Y_TYPE_2);
		cd.Y = y;
		SetConsoleCursorPosition(g_hConsoleOutput, cd);
	}

	// =============================================================================
	// ��ʾ��Ϸ�ر߽�
	void printPoolBorder()
	{
		int8_t y;

		SetConsoleTextAttribute(g_hConsoleOutput, MAX_TEXT_POS_MASK);
		for (y = ROW_BEGIN; y < ROW_END; ++y)  // ����ʾ����4�к͵ײ�2��
		{
			gotoxyWithFullwidth(10, y - MANAGER_Y_TYPE_4);
			printf("%2s", "");
			gotoxyWithFullwidth(23, y - MANAGER_Y_TYPE_4);
			printf("%2s", "");
		}

		gotoxyWithFullwidth(10, y - MANAGER_Y_TYPE_4);  // �ײ��߽�
		printf("%28s", "");
	}

	// ��λ����Ϸ���еķ���
#define	OFFSET_X	(9)
#define	OFFSET_Y	(3)
#define	gotoxyInPool(x, y)	gotoxyWithFullwidth((x + OFFSET_X), (y - OFFSET_Y))

	// =============================================================================
	// ��ʾ��Ϸ��
	void printTetrisPool(const TetrisManager *manager, const TetrisControl *control)
	{
		int8_t x, y;

		for (y = ROW_BEGIN; y < ROW_END; ++y)  // ����ʾ����4�к͵ײ�2��
		{
			gotoxyInPool(2, y);  // ���㵽��Ϸ���еķ���
			for (x = COL_BEGIN; x < COL_END; ++x)  // ����ʾ���ұ߽�
			{
				if ((manager->pool[y] >> x) & MANAGER_Y_TYPE_2)  // ��Ϸ�ظ÷����з���
				{
					// ����Ӧ��ɫ����ʾһ��ʵ�ķ���
					SetConsoleTextAttribute(g_hConsoleOutput, control->color[y][x]);
					printf("��");
				}
				else  // û�з��飬��ʾ�հ�
				{
					SetConsoleTextAttribute(g_hConsoleOutput, 0);
					printf("%2s", "");
				}
			}
		}
	}

	// =============================================================================
	// ��ʾ��ǰ����
	void printCurrentTetris(const TetrisManager *manager, const TetrisControl *control)
	{
		int8_t x, y;

		// ��ʾ��ǰ���������ƶ�����õģ�Ϊ��ȥ�ƶ�ǰ�ķ��飬��Ҫ��չ��ʾ����
		// ���ڲ����������ƶ����ʲ���Ҫ������չ
		y = (manager->y > ROW_BEGIN) ? (manager->y - 1) : ROW_BEGIN;  // ������չһ��
		for (; y < ROW_END && y < (manager->y + 4); ++y)
		{
			x = (manager->x > COL_BEGIN) ? (manager->x - 1) : COL_BEGIN;  // ������չһ��
			for (; x < COL_END && x < (manager->x + 5); ++x)  // ������չһ��
			{
				gotoxyInPool(x, y);  // ���㵽��Ϸ���еķ���
				if ((manager->pool[y] >> x) & MANAGER_Y_TYPE_2)  // ��Ϸ�ظ÷����з���
				{
					// ����Ӧ��ɫ����ʾһ��ʵ�ķ���
					SetConsoleTextAttribute(g_hConsoleOutput, control->color[y][x]);
					printf("��");
				}
				else  // û�з��飬��ʾ�հ�
				{
					SetConsoleTextAttribute(g_hConsoleOutput, 0);
					printf("%2s", "");
				}
			}
		}
	}

	// =============================================================================
	// ��ʾ��һ��������һ������
	void printNextTetris(const TetrisManager *manager)
	{
		int8_t i;
		uint16_t tetris;

		// �߿�
		SetConsoleTextAttribute(g_hConsoleOutput, 0xF);
		gotoxyWithFullwidth(ROW_END, DEFLT_Y_POS_ONE);
		printf("�����������ש���������");
		gotoxyWithFullwidth(ROW_END, DEFLT_Y_POS_TWO);
		printf("��%8s��%8s��", "", "");
		gotoxyWithFullwidth(ROW_END, 3);
		printf("��%8s��%8s��", "", "");
		gotoxyWithFullwidth(ROW_END, 4);
		printf("��%8s��%8s��", "", "");
		gotoxyWithFullwidth(ROW_END, 5);
		printf("��%8s��%8s��", "", "");
		gotoxyWithFullwidth(ROW_END, 6);
		printf("�����������ߩ���������");

		// ��һ��������Ӧ��ɫ��ʾ
		tetris = gs_uTetrisTable[manager->type[1]][manager->orientation[1]];
		SetConsoleTextAttribute(g_hConsoleOutput, manager->type[1] | BOX_MOV_MASK_8);
		for (i = 0; i < EVERY_COLORS; ++i)
		{
			gotoxyWithFullwidth((i & MANAGER_Y_TYPE_4) + (DEFLT_GAME_POOL_SIZE - 1), (i >> MANAGER_Y_TYPE_3) + MANAGER_Y_TYPE_3);
			((tetris >> i) & MANAGER_Y_TYPE_2) ? printf("��") : printf("%2s", "");
		}

		// ����һ��������ʾ��ɫ
		tetris = gs_uTetrisTable[manager->type[2]][manager->orientation[2]];
		SetConsoleTextAttribute(g_hConsoleOutput, 8);
		for (i = 0; i < EVERY_COLORS; ++i)
		{
			gotoxyWithFullwidth((i & MANAGER_Y_TYPE_4) + (DEFLT_GAME_POOL_SIZE + 4), (i >> MANAGER_Y_TYPE_3) + MANAGER_Y_TYPE_3);
			((tetris >> i) & MANAGER_Y_TYPE_2) ? printf("��") : printf("%2s", "");
		}
	}

	// =============================================================================
	// ��ʾ�÷���Ϣ
	void printScore(const TetrisManager *manager)
	{
		static const char *tetrisName = "ITLJZSO";
		int8_t i;

		SetConsoleTextAttribute(g_hConsoleOutput, RIGHT_TEXT_POS_MASK);

		gotoxyWithFullwidth(2, 2);
		printf("���÷֣�%u", manager->score);

		gotoxyWithFullwidth(1, 6);
		printf("������������%u", manager->erasedTotal);
		for (i = 0; i < 4; ++i)
		{
			gotoxyWithFullwidth(2, 8 + i);
			printf("����%d��%u", i + 1, manager->erasedCount[i]);
		}

		gotoxyWithFullwidth(1, 15);
		printf("������������%u", manager->tetrisTotal);

		for (i = 0; i < SEVEN_TYPES; ++i)
		{
			gotoxyWithFullwidth(2, 17 + i);
			printf("��%c�Σ�%u", tetrisName[i], manager->tetrisCount[i]);
		}
	}

	// =============================================================================
	// ��ʾ��ʾ��Ϣ
	void printPrompting()
	{
		SetConsoleTextAttribute(g_hConsoleOutput, 0xB);
		gotoxyWithFullwidth(26, 10);
		printf("�����ƣ�");
		gotoxyWithFullwidth(27, 12);
		printf("�������ƶ����� A 4");
		gotoxyWithFullwidth(27, 13);
		printf("�������ƶ����� D 6");
		gotoxyWithFullwidth(27, 14);
		printf("�������ƶ����� S 2");
		gotoxyWithFullwidth(27, 15);
		printf("��˳ʱ��ת���� W 8");
		gotoxyWithFullwidth(27, 16);
		printf("����ʱ��ת��0");
		gotoxyWithFullwidth(27, 17);
		printf("��ֱ����أ��ո�");
		gotoxyWithFullwidth(27, 18);
		printf("����ͣ��Ϸ���س�");
		gotoxyWithFullwidth(25, 23);
		printf("��By: wohaaitinciu 12.12.29");
		gotoxyWithFullwidth(25, 22);
		printf("��Updated: BIOHAZARDX 15.05.17");
	}

	// =============================================================================
	// ������Ϸ
	void runGame(TetrisManager *manager, TetrisControl *control)
	{
		clock_t clockLast, clockNow;

		clockLast = clock();  // ��ʱ
		printTetrisPool(manager, control);  // ��ʾ��Ϸ��

		while (!manager->dead)  // û��
		{
			Sleep(200);			// ��CPUҲ��Ϣ��Ϣ�����������ڰ�ʵĽ���~~~
			while (_kbhit())	// �м�����
			{
				keydownControl(manager, control, _getch());  // ������
			}

			if (!control->pause)  // δ��ͣ
			{
				clockNow = clock();  // ��ʱ
									 // ���μ�ʱ�ļ������0.45��
				if (clockNow - clockLast > 0.45F * CLOCKS_PER_SEC)
				{
					clockLast = clockNow;
					keydownControl(manager, control, 80);  // ����������
				}
			}
		}
	}

	// =============================================================================
	// ����һ��
	bool ifPlayAgain()
	{
		int ch;

		SetConsoleTextAttribute(g_hConsoleOutput, MAX_TEXT_POS_MASK);
		gotoxyWithFullwidth(15, 10);
		printf("��Ϸ����");
		gotoxyWithFullwidth(13, 11);
		printf("��Y���棬��N�˳�");

		do
		{
			ch = _getch();
			if (ch == 'Y' || ch == 'y')
			{
				return true;
			}
			else if (ch == 'N' || ch == 'n')
			{
				return false;
			}
		} while (1);
	}



};

unsigned _stdcall TetrisStart(void* ip)
{
	game* pTetrisStart = (game*)ip;
	game::TetrisManager tetrisManager;
	game::TetrisControl tetrisControl;

	pTetrisStart->initGame(&tetrisManager, &tetrisControl);  // ��ʼ����Ϸ
	do
	{
		pTetrisStart->printPrompting();  // ��ʾ��ʾ��Ϣ
		pTetrisStart->printPoolBorder();  // ��ʾ��Ϸ�ر߽�
		pTetrisStart->runGame(&tetrisManager, &tetrisControl);  // ������Ϸ
		if (pTetrisStart->ifPlayAgain())  // ����һ��
		{
			SetConsoleTextAttribute(pTetrisStart->g_hConsoleOutput, SEVEN_TYPES);
			system("cls");  // ����
			pTetrisStart->restartGame(&tetrisManager, &tetrisControl);  // ���¿�ʼ��Ϸ
		}
		else
		{
			break;
		}
	} while (1);
	pTetrisStart->gotoxyWithFullwidth(0, 0);
	CloseHandle(pTetrisStart->g_hConsoleOutput);

	_endthreadex(0);

	return 0;
}















// ������



int main()
{

	game a;





	return 0;
}



