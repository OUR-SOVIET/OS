/*
 * PROJECT:     ReactOS Print Spooler Service
 * LICENSE:     GNU GPLv2 or any later version as published by the Free Software Foundation
 * PURPOSE:     Functions for managing print jobs
 * COPYRIGHT:   Copyright 2015 Colin Finck <colin@reactos.org>
 */

#include "precomp.h"

DWORD
_RpcAddJob(WINSPOOL_PRINTER_HANDLE hPrinter, DWORD Level, BYTE* pAddJob, DWORD cbBuf, DWORD* pcbNeeded)
{
    DWORD dwErrorCode;

    dwErrorCode = RpcImpersonateClient(NULL);
    if (dwErrorCode != ERROR_SUCCESS)
    {
        ERR("RpcImpersonateClient failed with error %lu!\n", dwErrorCode);
        return dwErrorCode;
    }

    dwErrorCode = AddJobW(hPrinter, Level, pAddJob, cbBuf, pcbNeeded);
    if (dwErrorCode != ERROR_SUCCESS)
    {
        ERR("AddJobW failed with error %lu!\n", dwErrorCode);
        RpcRevertToSelf();
        return dwErrorCode;
    }

    return RpcRevertToSelf();
}

DWORD
_RpcGetJob(WINSPOOL_PRINTER_HANDLE hPrinter, DWORD JobId, DWORD Level, BYTE* pJob, DWORD cbBuf, DWORD* pcbNeeded)
{
    DWORD dwErrorCode;

    dwErrorCode = RpcImpersonateClient(NULL);
    if (dwErrorCode != ERROR_SUCCESS)
    {
        ERR("RpcImpersonateClient failed with error %lu!\n", dwErrorCode);
        return dwErrorCode;
    }

    dwErrorCode = GetJobW(hPrinter, JobId, Level, pJob, cbBuf, pcbNeeded);
    if (dwErrorCode != ERROR_SUCCESS)
    {
        ERR("GetJobW failed with error %lu!\n", dwErrorCode);
        RpcRevertToSelf();
        return dwErrorCode;
    }

    return RpcRevertToSelf();
}

DWORD
_RpcScheduleJob(WINSPOOL_PRINTER_HANDLE hPrinter, DWORD JobId)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}

DWORD
_RpcSetJob(WINSPOOL_PRINTER_HANDLE hPrinter, DWORD JobId, WINSPOOL_JOB_CONTAINER* pJobContainer, DWORD Command)
{
    UNIMPLEMENTED;
    return ERROR_INVALID_FUNCTION;
}
