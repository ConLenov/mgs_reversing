#include "linker.h"
#include "system.h"

extern const char aSystemD[];
extern const char aDynamic[];
extern const char aVoided[];
extern const char aFailed[];
extern const char asc_800AB360[];
extern const char aAddr08x08xUnit[];
extern const char aFreeDDVoidedDM[];

extern void mg_printf_8008BBA0(const char *, ...);

extern GV_Heap gv_heaps_800AD2F0[3];

void System_debug_dump_heaps_80015BF8(unsigned int heapIdx)
{
    int maxFree;
    int voidedCount;
    int freeCount;

    int size;

    int unitCounter;
    GV_MemoryAllocation *pAllocIter;

    GV_Heap *pHeap = &gv_heaps_800AD2F0[heapIdx];

    mg_printf_8008BBA0(aSystemD, heapIdx);

    if (pHeap->mFlags & 1)
    {
        mg_printf_8008BBA0(aDynamic);
    }

    if (pHeap->mFlags & 2)
    {
        mg_printf_8008BBA0(aVoided);
    }

    if (pHeap->mFlags & 4)
    {
        mg_printf_8008BBA0(aFailed);
    }

    mg_printf_8008BBA0(asc_800AB360);
    mg_printf_8008BBA0(aAddr08x08xUnit, pHeap->mStartAddr, pHeap->mEndAddr, pHeap->mUnitsCount);
    size = pHeap->mEndAddr - pHeap->mStartAddr;

    freeCount = 0;
    voidedCount = 0;
    maxFree = 0;

    pAllocIter = &pHeap->mAllocs[0];

    for (unitCounter = pHeap->mUnitsCount; unitCounter > 0; unitCounter--)
    {
        int type = pAllocIter->mAllocType;

        unsigned char *firstSize = pAllocIter->mPDataStart;
        unsigned char *nextSize = pAllocIter[1].mPDataStart;

        int allocSize = nextSize - firstSize;

        if (type == 0)
        {
            freeCount += allocSize;
            if (maxFree < allocSize)
            {
                maxFree = allocSize;
            }
        }
        else if (type == 1)
        {
            voidedCount += allocSize;
        }

        pAllocIter++;
    }

    mg_printf_8008BBA0(aFreeDDVoidedDM,
                       freeCount,
                       size,
                       voidedCount,
                       maxFree);
}