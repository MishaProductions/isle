#include "legoworld.h"

#include "legoinputmanager.h"
#include "legoomni.h"
#include "legoutil.h"
#include "mxactionnotificationparam.h"
#include "mxnotificationmanager.h"
#include "mxnotificationparam.h"
#include "mxomni.h"
#include "mxticklemanager.h"

DECOMP_SIZE_ASSERT(LegoWorld, 0xf8);

// STUB: LEGO1 0x1001ca40
LegoWorld::LegoWorld() : m_list0x68(TRUE)
{
	// TODO
	m_worldStarted = FALSE;
	m_unk0xf4 = 4;
	NotificationManager()->Register(this);
}

// FUNCTION: LEGO1 0x1001d670
MxBool LegoWorld::VTable0x5c()
{
	return FALSE;
}

// FUNCTION: LEGO1 0x1001d680
MxBool LegoWorld::VTable0x64()
{
	return FALSE;
}

// STUB: LEGO1 0x1001dfa0
LegoWorld::~LegoWorld()
{
	// TODO
}

// STUB: LEGO1 0x1001e0b0
MxResult LegoWorld::SetAsCurrentWorld(MxDSObject& p_dsObject)
{
	// TODO
	MxEntity::Create(p_dsObject);

	// TODO: Initialize list at m_unk0x9c
	VTable0x54();
	SetIsWorldActive(TRUE);

	SetCurrentWorld(this);

	return SUCCESS;
}

// FUNCTION: LEGO1 0x1001f5e0
MxLong LegoWorld::Notify(MxParam& p_param)
{
	MxLong ret = 0;
	switch (((MxNotificationParam&) p_param).GetNotification()) {
	case c_notificationEndAction: {
		MxPresenter* presenter = (MxPresenter*) ((MxEndActionNotificationParam&) p_param).GetSender();
		EndAction(presenter);
		ret = 1;
		break;
	}
	case c_notificationNewPresenter:
		TickleManager()->RegisterClient(this, 100);
		break;
	}
	return ret;
}

// STUB: LEGO1 0x1001f630
void LegoWorld::VTable0x54()
{
	// TODO
	OutputDebugString("LegoWorld::VTable0x54 STUB\n");
}

// STUB: LEGO1 0x1001fc80
void LegoWorld::FUN_1001fc80(IslePathActor* p_actor)
{
	OutputDebugString("LegoWorld::FUN_1001fc80 STUB\n");
}

// STUB: LEGO1 0x10020120
MxS32 LegoWorld::GetCurrPathInfo(LegoPathBoundary** p_path, MxS32& p_value)
{
	// TODO
	OutputDebugString("LegoWorld::GetCurrPathInfo STUB\n");
	return 0;
}

// STUB: LEGO1 0x10020220
void LegoWorld::VTable0x58(MxCore* p_object)
{
	// TODO
	OutputDebugString("LegoWorld::VTable0x58 STUB\n");
}

// STUB: LEGO1 0x10020f10
void LegoWorld::EndAction(MxCore* p_object)
{
	OutputDebugString("LegoWorld::EndAction STUB\n");
}

// STUB: LEGO1 0x10021a70
void LegoWorld::VTable0x68(MxBool p_add)
{
	// TODO
	OutputDebugString("LegoWorld::VTable0x68 STUB\n");
}

// FUNCTION: LEGO1 0x10022080
MxResult LegoWorld::Tickle()
{
	if (!m_worldStarted) {
		switch (m_unk0xf4) {
		case 0:
			m_worldStarted = TRUE;
			SetAppCursor(0);
			VTable0x50();
			return TRUE;
		case 2:
			if (FUN_100220e0() == 1)
				break;
		default:
			m_unk0xf4--;
		}
	}
	return TRUE;
}

// STUB: LEGO1 0x100220e0
undefined LegoWorld::FUN_100220e0()
{
	return 0;
}

// FUNCTION: LEGO1 0x10022340
void LegoWorld::VTable0x50()
{
	TickleManager()->UnregisterClient(this);
}

// STUB: LEGO1 0x100727e0
MxBool LegoWorld::FUN_100727e0(MxU32, Vector3Data& p_loc, Vector3Data& p_dir, Vector3Data& p_up)
{
	OutputDebugString("LegoWorld::FUN_100727e0 STUB\n");
	return FALSE;
}

// STUB: LEGO1 0x10072980
MxBool LegoWorld::FUN_10072980(MxU32, Vector3Data& p_loc, Vector3Data& p_dir, Vector3Data& p_up)
{
	OutputDebugString("LegoWorld::FUN_10072980 STUB\n");
	return FALSE;
}

// STUB: LEGO1 0x10073400
void LegoWorld::FUN_10073400()
{
	OutputDebugString("LegoWorld::FUN_10073400 STUB\n");
}

// STUB: LEGO1 0x10073430
void LegoWorld::FUN_10073430()
{
	OutputDebugString("LegoWorld::FUN_10073430 STUB\n");
}
