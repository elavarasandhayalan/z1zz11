
//******************************************************************************
//   
// Copyright (c) 2005 Molecular Devices
// All rights reserved.
//******************************************************************************
// Module:  GetSitesByPlate_CallBack.cpp
// Purpose: Provide functions to process data and get all Site IDs belonging to a plate
//  
/////////////////////////////////////////////////////////////////////////////////
//#include "StdAfx.h"
#include "pch.h"
#include ".\getsitesbyplate_callback.h"
#include <iostream>
using namespace std;

//==============================================================================================
// FUNCTION: Constructor
// PARAMETER: 
//		m_plarrSieIDs - pointer to array which stores all siteid returned from db.
//==============================================================================================
CGetSitesByPlate_CallBack::CGetSitesByPlate_CallBack(CArray<LONGLONG, LONGLONG>* m_plarrID,
    CArray<LPCSTR, LPCSTR>* m_plarrBatchId,
    CArray<LPCSTR, LPCSTR>* m_plarrXwells,
    CArray<LPCSTR, LPCSTR>* m_plarrYwells): m_plarrID(m_plarrID), m_plarrBatchId(m_plarrBatchId), m_plarrXwells(m_plarrXwells), m_plarrYwells(m_plarrYwells)
{   
}

//==============================================================================================
// FUNCTION: GetNextResult
// PURPOSE: Called to get next row of data
//==============================================================================================
BOOL CGetSitesByPlate_CallBack::GetNextResult(MDCS_QueryResults* pQueryRes)
{
   ASSERT(pQueryRes);
   if(!pQueryRes)
      return TRUE;

   //check if data is empty - if it is empty, function will return -LLONG_MAX 
   LONGLONG plateId = pQueryRes->GetLongValue("ID");
   LPCSTR batchId = pQueryRes->GetStringValue(LPCSTR("BATCH_ID"));
   LPCSTR xWells = pQueryRes->GetStringValue(LPCSTR("X_WELLS"));
   LPCSTR yWells = pQueryRes->GetStringValue(LPCSTR("Y_WELLS"));
   LPCSTR xPosition = pQueryRes->GetStringValue(LPCSTR("X_POSITION"));
   LPCSTR yPostion = pQueryRes->GetStringValue(LPCSTR("Y_POSITION"));
   if (plateId == -LLONG_MAX)
   {
      return TRUE;
   }
   m_plarrID->Add(plateId);
   m_plarrBatchId->Add(batchId);
   m_plarrXwells->Add(xWells);
   m_plarrYwells->Add(yWells);
   //m_plarrXPosition->Add(xPosition);
  // m_plarrYPostion->Add(yPostion);
   return TRUE;

}

