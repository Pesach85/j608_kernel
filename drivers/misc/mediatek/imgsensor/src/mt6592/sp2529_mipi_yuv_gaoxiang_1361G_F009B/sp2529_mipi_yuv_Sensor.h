/*****************************************************************************
 *
 * Filename:
 * ---------
 *   sensor.h
 *
 * Project:
 * --------
 *   DUMA
 *
 * Description:
 * ------------
 *   Header file of Sensor driver
 *
 *
 * Author:
 * -------
 *   PC Huang (MTK02204)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 03 31 2010 jianhua.tang
 * [DUMA00158728]S5K8AAYX YUV sensor driver 
 * .
 *
 * Feb 24 2010 mtk01118
 * [DUMA00025869] [Camera][YUV I/F & Query feature] check in camera code
 * 
 *
 * Aug 5 2009 mtk01051
 * [DUMA00009217] [Camera Driver] CCAP First Check In
 * 
 *
 * Apr 7 2009 mtk02204
 * [DUMA00004012] [Camera] Restructure and rename camera related custom folders and folder name of came
 * 
 *
 * Mar 26 2009 mtk02204
 * [DUMA00003515] [PC_Lint] Remove PC_Lint check warnings of camera related drivers.
 * 
 *
 * Mar 2 2009 mtk02204
 * [DUMA00001084] First Check in of MT6516 multimedia drivers
 * 
 *
 * Feb 24 2009 mtk02204
 * [DUMA00001084] First Check in of MT6516 multimedia drivers
 * 
 *
 * Dec 27 2008 MTK01813
 * DUMA_MBJ CheckIn Files
 * created by clearfsimport
 *
 * Dec 10 2008 mtk02204
 * [DUMA00001084] First Check in of MT6516 multimedia drivers
 * 
 *
 * Oct 27 2008 mtk01051
 * [DUMA00000851] Camera related drivers check in
 * Modify Copyright Header
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* SENSOR FULL SIZE */
#ifndef __SENSOR_H
#define __SENSOR_H

#define MIPI_INTERFACE

typedef enum _SP2529MIPI_OP_TYPE_ {
        SP2529MIPI_MODE_NONE,
        SP2529MIPI_MODE_PREVIEW,
        SP2529MIPI_MODE_CAPTURE,
        SP2529MIPI_MODE_QCIF_VIDEO,
        SP2529MIPI_MODE_CIF_VIDEO,
        SP2529MIPI_MODE_QVGA_VIDEO
    } SP2529MIPI_OP_TYPE;

extern SP2529MIPI_OP_TYPE SP2529MIPI_g_iSP2529MIPI_Mode;

//#define SP2529MIPI_QVGA_SIZE_PREVIEW

#define SP2529MIPI_PV_BEST_FRAME_RATE_BINNING
//#define SP2529MIPI_ADJ_H_V_BLANKING



// Reminder: Just can un-mask one macro of these 3 macros. if mask these 3 macros, then use mclk 24Mhz, pclk 48Mhz 
// for preview & capture
//#define SP2529MIPI_JPEG_MCLK12M_PCLK24M
//#define SP2529MIPI_JPEG_MCLK24M_PCLK36M 	
//#define SP2529MIPI_JPEG_MCLK24M_PCLK40M		

// Div 10 is the actual frame rate, 300 means 30fps, 75 means 7.5fps
	// Plz keep these setting un-changed
	#define SP2529MIPI_CAM_NOM_MAX_FPS				300		// 30fps
	#define SP2529MIPI_CAM_NOM_MIN_FPS				100		// 10.0fps
	#define SP2529MIPI_CAM_NIT_MAX_FPS				300		// 30fps
	#define SP2529MIPI_CAM_NIT_MIN_FPS				50		// 5.0fps

	#define SP2529MIPI_VID_NOM_FIX_FPS			250		// 30fps,can't reach 30fps
	#define SP2529MIPI_VID_NIT_FIX_FPS			150		// 15fps

///////////////////////////////////////////////////////////////////////////////
//					Configuable macro End.
//					Notices: Please don't modify the macro below this line
///////////////////////////////////////////////////////////////////////////////


// Msec / 10 is the actual frame time, 1000 means 100ms.
#define SP2529MIPI_CAM_NOM_MIN_FR_TIME			((1000 * 10 * 10) / SP2529MIPI_CAM_NOM_MAX_FPS)
#define SP2529MIPI_CAM_NOM_MAX_FR_TIME			((1000 * 10 * 10) / SP2529MIPI_CAM_NOM_MIN_FPS)
#define SP2529MIPI_CAM_NIT_MIN_FR_TIME			((1000 * 10 * 10) / SP2529MIPI_CAM_NIT_MAX_FPS)
#define SP2529MIPI_CAM_NIT_MAX_FR_TIME			((1000 * 10 * 10) / SP2529MIPI_CAM_NIT_MIN_FPS)

#define SP2529MIPI_VID_NOM_FIX_FR_TIME			((1000 * 10 * 10) / SP2529MIPI_VID_NOM_FIX_FPS)
#define SP2529MIPI_VID_NIT_FIX_FR_TIME			((1000 * 10 * 10) / SP2529MIPI_VID_NIT_FIX_FPS)



// It's for test only, must mark it when check in.
//#define __SW_VIDEO_ADV_RESIZER_SUPPORT__

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */
#define SP2529MIPI_SXGA_PERIOD_PIXEL_NUMS               2175         /* 2175 */
#define SP2529MIPI_SXGA_PERIOD_LINE_NUMS                1607         /* 1607 */

/* 3M RESOLUTION SIZE */
#define SP2529MIPI_IMAGE_SENSOR_3M_WIDTH				2048
#define SP2529MIPI_IMAGE_SENSOR_3M_HEIGHT				1536
/* 2M RESOLUTION SIZE */
#define SP2529MIPI_IMAGE_SENSOR_2M_WIDTH				1600
#define SP2529MIPI_IMAGE_SENSOR_2M_HEIGHT				1200
/* 1.3M RESOLUTION SIZE */
#define SP2529MIPI_IMAGE_SENSOR_1_3M_WIDTH			1280
#define SP2529MIPI_IMAGE_SENSOR_1_3M_HEIGHT			1024
/* 1.2M RESOLUTION SIZE */
#define SP2529MIPI_IMAGE_SENSOR_1_2M_WIDTH			1280
#define SP2529MIPI_IMAGE_SENSOR_1_2M_HEIGHT			960
/* 1M RESOLUTION SIZE */
#define SP2529MIPI_IMAGE_SENSOR_1M_WIDTH				1024
#define SP2529MIPI_IMAGE_SENSOR_1M_HEIGHT				768
/* SENSOR VGA SIZE */
#define SP2529MIPI_IMAGE_SENSOR_VGA_WIDTH				640
#define SP2529MIPI_IMAGE_SENSOR_VGA_HEIGHT			480
/* SENSOR QVGA SIZE */
#define SP2529MIPI_IMAGE_SENSOR_QVGA_WIDTH			320
#define SP2529MIPI_IMAGE_SENSOR_QVGA_HEIGHT			240


// Grab Window Setting for preview mode.
#define SP2529MIPI_IMAGE_SENSOR_PV_INSERTED_PIXELS    	(4)
#define SP2529MIPI_IMAGE_SENSOR_PV_INSERTED_LINES     	(4)

#define SP2529MIPI_IMAGE_SENSOR_PV_WIDTH	 				(800-8)
#define SP2529MIPI_IMAGE_SENSOR_PV_HEIGHT					(600-6)
	
// Grab Window Setting for capture mode.
#define SP2529MIPI_IMAGE_SENSOR_FULL_INSERTED_PIXELS		(4)
#define SP2529MIPI_IMAGE_SENSOR_FULL_INSERTED_LINES		(4)
	
#define SP2529MIPI_IMAGE_SENSOR_FULL_WIDTH			(1600-8)
#define SP2529MIPI_IMAGE_SENSOR_FULL_HEIGHT			(1200-6)



/* DUMMY NEEDS TO BE INSERTED */
/* SETUP TIME NEED TO BE INSERTED */


/* SENSOR READ/WRITE ID */
#define SP2529MIPI_WRITE_ID		0x60		
#define SP2529MIPI_READ_ID		0x61


//format index
#define SP2529MIPI_PV_FORMAT_INDEX   1 
#define SP2529MIPI_FULL_FORMAT_INDEX 2 

//customize
#define CAM_SIZE_QVGA_WIDTH 	320
#define CAM_SIZE_QVGA_HEIGHT 	240
#define CAM_SIZE_VGA_WIDTH 		640
#define CAM_SIZE_VGA_HEIGHT 	480
#define CAM_SIZE_05M_WIDTH 		800
#define CAM_SIZE_05M_HEIGHT 	600
#define CAM_SIZE_1M_WIDTH 		1280
#define CAM_SIZE_1M_HEIGHT 		960
#define CAM_SIZE_2M_WIDTH 		1600
#define CAM_SIZE_2M_HEIGHT 		1200
#define CAM_SIZE_3M_WIDTH 		2048
#define CAM_SIZE_3M_HEIGHT 		1536
#define CAM_SIZE_5M_WIDTH 		2592
#define CAM_SIZE_5M_HEIGHT 		1944

//
//initial config function
//
int pfInitCfg_VGA(void);
int pfInitCfg_1280X960(void);
int pfInitCfg_FULL(void);

//export functions
UINT32 SP2529MIPIOpen(void);
UINT32 SP2529MIPIControl(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *pImageWindow, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 SP2529MIPIFeatureControl(MSDK_SENSOR_FEATURE_ENUM FeatureId, UINT8 *pFeaturePara,UINT32 *pFeatureParaLen);
UINT32 SP2529MIPIGetInfo(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_INFO_STRUCT *pSensorInfo, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 SP2529MIPIGetResolution(MSDK_SENSOR_RESOLUTION_INFO_STRUCT *pSensorResolution);
UINT32 SP2529MIPIClose(void);

#define Sleep(ms) mdelay(ms)
#define RETAILMSG(x,...)
#define TEXT

#endif /* __SENSOR_H */
