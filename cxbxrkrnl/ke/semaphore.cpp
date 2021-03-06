/*
 * ergo720                Copyright (c) 2022
 * cxbxr devs
 */

#include "ke.h"
#include "..\kernel.h"


EXPORTNUM(112) VOID XBOXAPI KeInitializeSemaphore
(
	PKSEMAPHORE Semaphore,
	LONG Count,
	LONG Limit
)
{
	Semaphore->Header.Type = SemaphoreObject;
	Semaphore->Header.Size = sizeof(KSEMAPHORE) / sizeof(LONG);
	Semaphore->Header.SignalState = Count;
	InitializeListHead(&Semaphore->Header.WaitListHead);
	Semaphore->Limit = Limit;
}
