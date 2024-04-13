#include "legopathcontroller.h"

#include "mxmisc.h"
#include "mxticklemanager.h"

DECOMP_SIZE_ASSERT(LegoPathController, 0x40)

// FUNCTION: LEGO1 0x10044f40
LegoPathController::LegoPathController()
{
	m_unk0x18 = 0;
	m_unk0x08 = NULL;
	m_unk0x0c = 0;
	m_unk0x1a = 0;
	m_unk0x1c = 0;
	m_unk0x14 = 0;
	m_unk0x1e = 0;
	m_unk0x18 = 0;
}

// STUB: LEGO1 0x10045880
void LegoPathController::VTable0x14(MxU8* p_data, Vector3& p_location, MxAtomId& p_trigger)
{
	// TODO
}

// STUB: LEGO1 0x10045b20
void LegoPathController::Destroy()
{
	// TODO
}

// STUB: LEGO1 0x10045c10
MxResult LegoPathController::Tickle()
{
	// TODO
	return SUCCESS;
}

// STUB: LEGO1 0x10046770
undefined4 LegoPathController::FUN_10046770(LegoPathActor* p_actor)
{
	return 0;
}

// FUNCTION: LEGO1 0x10046b30
MxResult LegoPathController::FUN_10046b30(LegoPathBoundary** p_path, MxS32& p_value)
{
	*p_path = m_unk0x08;
	p_value = (MxS32) m_unk0x18;
	return SUCCESS;
}

// STUB: LEGO1 0x10046bb0
void LegoPathController::FUN_10046bb0(LegoWorld* p_world)
{
	// TODO
}

// FUNCTION: LEGO1 0x10046be0
void LegoPathController::Enable(MxBool p_enable)
{
	if (p_enable) {
		TickleManager()->RegisterClient(this, 10);
	}
	else {
		TickleManager()->UnregisterClient(this);
	}
}
