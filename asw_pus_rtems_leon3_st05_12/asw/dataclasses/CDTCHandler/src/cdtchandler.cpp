/*
 * cdtchandler.cpp
 *
 *  Created on: Dec 29, 2023
 *      Author: opolo70
 */

#include <public/pus_services_iface_v1.h>
#include "public/cdtchandler.h"
#include "public/serialize.h"
#include "public/crc.h"
#include "public/sc_channel_drv_v1.h"

#include "public/cdtcexecctrl_iface_v1.h"

CDTCHandler::CDTCHandler() {

	mTCHandler.raw_tc_mem_descriptor.p_tc_bytes = NULL;
	mTCHandler.raw_tc_mem_descriptor.tc_num_bytes = 0;

}

void CDTCHandler::BuildFromDescriptor(CDTCMemDescriptor &descriptor) {

	tc_handler_build_from_descriptor(&mTCHandler, descriptor.mTCMemDescriptor);

}

CDTCAcceptReport CDTCHandler::DoAcceptation() {

	CDTCAcceptReport acceptReport;
	acceptReport.mAcceptReport = pus_service1_tc_acceptation(&mTCHandler);

	return acceptReport;
}

void CDTCHandler::MngTCRejection(CDTCAcceptReport &acceptReport) {

	pus_service1_tx_TM_1_2(&mTCHandler, acceptReport.mAcceptReport);

	tc_handler_free_memory(&mTCHandler);
}

//Complete TC Aceptation
void CDTCHandler::MngTCAcceptation() {

	pus_service1_tx_TM_1_1(&mTCHandler);

}

CDTCExecCtrl CDTCHandler::GetExecCtrl() {

	//Get TC type
	uint8_t type = mTCHandler.tc_df_header.type;

	CDTCExecCtrl execCtrl;
	switch (type) {

	//TODO 10 Set ST[05] & ST[12] TCs as ExecCtrlHK_FDIRTC
	case (12):
	case (5):
	case (3):
	case (4):
		execCtrl.mExecCtrl = ExecCtrlHK_FDIRTC;
		break;
	case (17):
		execCtrl.mExecCtrl = ExecCtrlPrioTC;
		break;
	case (20):
		execCtrl.mExecCtrl = ExecCtrlBKGTC;
		break;
	default:
		execCtrl.mExecCtrl = ExecCtrlBKGTC;
		break;

	}

	return execCtrl;
}

void CDTCHandler::ExecTC() {

	error_code_t error;
	error = tc_handler_start_up_execution(&mTCHandler);

	if (!error) {

		//Get TC type
		uint8_t type = mTCHandler.tc_df_header.type;

		switch (type) {

		//TODO 11 Add TC[5,X] TC[12,X] and  execution
		case (5):
			pus_service5_exec_tc(&mTCHandler);
			break;
		case (12):
			pus_service12_exec_tc(&mTCHandler);
			break;

		case (3):
			pus_service3_exec_tc(&mTCHandler);
			break;

		case (4):
			pus_service4_exec_tc(&mTCHandler);
			break;

		case (17):
			pus_service17_exec_tc(&mTCHandler);
			break;

		case (20):
			pus_service20_exec_tc(&mTCHandler);
			break;

		default:

			break;

		}

		tc_handler_free_memory(&mTCHandler);
	}

}

